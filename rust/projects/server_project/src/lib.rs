use std::thread::{self, JoinHandle};
use std::sync::{mpsc, Arc, Mutex};

pub struct ThreadPool{ 
//a data structure that has a number of idle threads waiting for new requisitions
    workers: Vec<Workers>, //a vec with all threads
    sender: Option<mpsc::Sender<Job>> //a channel to send a job for an idle thread
    //we have to wrap sender with an Option because we're gonna to need
    //the take() method on Drop implementation
}
impl ThreadPool{
    pub fn new(max_threads: usize) -> Self{
        assert!(max_threads > 0); //if zero panic!

        let (tx, rx) = mpsc::channel(); //creating a channel of communication between threads
        
        let mut pool = ThreadPool{
            workers: Vec::with_capacity(max_threads),
            sender: Some(tx)
        };

        //mpsc means "multiple producers and single consumer" so we cannot copy the rx with
        //all threads, what we can do is to share it by an Arc and guarantee it's mutual exclusion
        //by a Mutex, then we can use the same channel for all threads
        let receiver = Arc::new(Mutex::new(rx));
        
        for id in 0..max_threads{
            pool.workers.push(Workers::new(id, Arc::clone(&receiver)));            
        }
        pool
    }
    pub fn execute<F>(&self, request: F)
    where 
        F: FnOnce() + Send + 'static
    {
        self.sender.as_ref().unwrap().send(Job(Box::new(request))).unwrap();
        //sending jobs for execution
    }
}
impl Drop for ThreadPool{
    fn drop(&mut self){
    //the Drop trait needs to receive a &mut self, so we use the take method
    //to get the ownership of sender and drop it, the same will be used bellow too
        drop(self.sender.take());
        
        for workers in &mut self.workers{
            println!("shutting down worker {}", workers.id);

            if let Some(thread) = workers.th.take(){ //taking ownership
                thread.join().unwrap(); //waiting for the end of each thread execution
            }
        }
    }
    //drop only occurs when pool goes out of scope, see main.rs advice
}

struct Workers{
    id: usize, //id of the thread
    th: Option<JoinHandle<()>> //keeping the return of thread spawn alive
    //inside a Option for the same reason of ThreadPool sender's
}
impl Workers{
    fn new(id: usize, receiver: Arc<Mutex<mpsc::Receiver<Job>>>) -> Workers{
        Workers{
            id,
            th: Some(thread::spawn( move ||{
                loop{
                    let message = ((*receiver).lock().unwrap()).recv(); 
                    //receiving the job
                    //if another thread has the mutex -> waiting... (idle state)
                    //if has the mutex, but there isn't jobs -> waiting... (idle state)

                    match message {
                        Ok(job) => {
                            println!("thread {id}: received a job. start execution...");
                            (job.0)(); //executing the passed job
                            println!("thread {id}: waiting for new jobs...");
                        },
                        Err(_) => {
                        //a error will occur when we are dropping the ThreadPool
                        //and the sender was dropped
                            println!("thread {id}: disconnecting...");
                            break //exiting eternal loop, finally
                        }
                    }
                }
            }))
        }
    }
}

struct Job(Box<dyn FnOnce() + Send + 'static>);
//a job transports a closure ready to be executed
