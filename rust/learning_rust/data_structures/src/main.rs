//GRAPH
/*mod graph;
use graph::*;
fn main(){
    let mut g = Graph::new();
    g.insert(0, 2, 5.65);
    g.insert(0, 2, 5.5);
    g.insert(0, 1, 5.5);
    g.printing();
    println!("{:?}, {:?}", g.first(3), g.first(2));
    println!("{}", g.is_node(4));
    for sla in 5..10{
        g.insert(0, sla, 1.0);
    }
    //g.printing();
    g.insert(0, 1, 2.0);
    g.insert(0, 1, 0.5);
    g.printing();
    println!("{:?}", g.weight(0, 1));
    println!("{:?}", g.weight(0, 4));

    println!("{:?} {:?} {:?}", g.remove(3, 0), g.remove(1, 2), g.remove(1, 0));
    for i in g.nodes(){
        print!("{i}: ");
        for j in g.neighbours(i){
            print!("{:?} ", j);
        }
        println!("");
    }    
    drop(g);
    println!("........................");
    
    let mut g = Graph::new();
    g.insert('a', 'b', 1);
    g.insert('b', 'c', 2);
    g.insert('a', 'd', 3);
    g.printing();
    println!("{:?}", g.remove('b', 'c'));
    g.printing();
    println!("{:?}", g.remove('b', 'a'));
    g.printing();

    for i in g.nodes(){
        print!("{i}: ");
        for j in g.neighbours(i){
            print!("{:?} ", j);
        }
        println!("");
    }
    println!("........................");
    let mut g = Graph::new();
    g.insert(2, 1, 1 as usize);    
    g.insert(3, 2, 1 as usize);    
    g.insert(4, 3, 1 as usize);    
    g.insert(5, 4, 1 as usize);    
    g.insert(6, 5, 1 as usize);
    g.dfs(4); //g.dfs(1);
    g.bfs(4);    
    println!("........................");

    let mut g = Graph::new();
    g.insert('a', 'b', 10);
    g.insert('a', 'c', 3);
    g.insert('a', 'd', 20);
    g.insert('b', 'c', 2);
    g.insert('b', 'd', 5);
    g.insert('c', 'e', 15);
    g.insert('d', 'e', 11);
    let v = g.dijkstra('a');
    println!("{v:#?}");
}*/
