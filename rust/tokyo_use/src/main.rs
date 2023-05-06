use tokio::time::sleep;
use std::time::Duration;

// #[tokio::main]
fn main() {
  let rt = tokio::runtime::Builder::new_multi_thread()
                                  .worker_threads(4)
                                  .enable_time()
                                  .build()
                                  .unwrap();
  let mut v = vec![];
  for i in 0..50{
    v.push(
    rt.spawn(async move { println!("{i}"); 
                                  sleep(Duration::from_secs(2)).await;
                                  println!("{i}");
                                })   
    );
  }
  rt.block_on(async move { 
    for handle in v{
      handle.await.unwrap();
    } 
  })
  // for handle in v{
  //   handle.await.unwrap();
  // }
}
