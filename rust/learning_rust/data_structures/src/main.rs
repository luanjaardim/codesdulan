//LINKED LIST
/*mod linked_list;
use linked_list::*;
fn main(){
    let mut list = LinkedList::new(4); //returns the list head, first node
    list.push(1); //inserted right after the node that called the method: 4 -> 1
    //this method also returns a LinkedList with the node just inserted as the head, so we can:
    list.push(3).push(2); //here the 2 is going to be inserted after the 3
    // 4 -> 3 -> 2 -> 1
    //if we did this: list.push(3); list.push(2); (insering elements based on list head node)
    //this will occur; 4 -> 2 -> 3 -> 1

    //next method returns an option of a LinkedList, so after dealing with Some(T) or None
    //we can push/pop over the list
    let new_list =  list.advance()//returns Some(3 -> 2 -> 1)
                                    .unwrap() //returns 3 -> 2 -> 1
                                    .advance() //returns Some(2 -> 1)
                                    .unwrap(); //returns 2 -> 1
    new_list.printing();
    list.printing();
    for i in list.clone().into_iter().map(|x| x*2 ){
        print!("{i} ");
    }
    println!("");
    for i in list.clone().into_iter().filter(|x| x%2 == 0 ){
        print!("{i} ");
    }
    println!("");

    let mut list = LinkedList::new(4);
    list.push(3).push(2).push(1);
    let mut tmp = list.advance()
                .unwrap()
                .advance()
                .unwrap();

    let mut copy = list.clone();
    copy.push(69);
    copy.insert_after(55, 4); //index 0 does the same of push
    //insert_after counts from the head of the list that called the method, it's a relative index
    copy.printing();
    list.printing();

    list.printing();
    println!("{:?}", tmp.pop());
    list.pop();
    list.printing();

    let tmp = list.advance().unwrap(); //the head of tmp will be popped
    println!("{:?}", list.pop());
    list.printing();
    tmp.printing(); 
    //tmp was popped, but we still can acess it, but without it's previous next elements
    //tmp will have None as it's next

    list.change_value(10); //change the value of the LinkedList head's
    println!("{:?}", list.pop());
    list.printing();
}*/

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