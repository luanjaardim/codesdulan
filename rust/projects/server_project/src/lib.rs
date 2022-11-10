use std::thread::{self, JoinHandle};
use std::sync::{mpsc, Arc, Mutex};

pub struct ThreadPool{
    workers: Vec<Workers>,
    sender: Option<mpsc::Sender<Job>>
}
impl ThreadPool{
    pub fn new(max_threads: usize) -> Self{
        assert!(max_threads > 0); //if zero panic!

        let (tx, rx) = mpsc::channel();
        
        let mut pool = ThreadPool{
            workers: Vec::with_capacity(max_threads),
            sender: Some(tx)
        };

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
    }
}
impl Drop for ThreadPool{
    fn drop(&mut self){
        drop(self.sender.take());
        
        for workers in &mut self.workers{
            println!("shutting down worker {}", workers.id);

            if let Some(thread) = workers.th.take(){
                thread.join().unwrap(); //waiting for the end of each thread execution
            }
        }
    }
}

struct Workers{
    id: usize,
    th: Option<JoinHandle<()>>
}
impl Workers{
    fn new(id: usize, receiver: Arc<Mutex<mpsc::Receiver<Job>>>) -> Workers{
        Workers{
            id,
            th: Some(thread::spawn( move ||{
                loop{
                    let message = ((*receiver).lock().unwrap()).recv();

                    match message {
                        Ok(job) => {
                            println!("thread {id}: received a job. start execution...");
                            (job.0)(); 
                            println!("thread {id}: waiting for new jobs...");
                        },
                        Err(_) => {
                            println!("thread {id}: disconnecting...");
                            break
                        }
                    }
                }
            }))
        }
    }
}

struct Job(Box<dyn FnOnce() + Send + 'static>);
