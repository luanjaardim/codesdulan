//LINKED LIST
/*mod linked_list;
use linked_list::*;

fn main(){
    let list = LinkedList::new(4); //returns the list head, first node
    list.push(1); //inserted right after the node that called the method: 4 -> 1
    //this method also returns a LinkedList with the node just inserted as the head, so we can:
    list.push(3).push(2); //here the 2 is going to be inserted after the 3
    // 4 -> 3 -> 2 -> 1
    //if we did this: list.push(3); list.push(2); (insering elements based on list node)
    //this will occur; 4 -> 2 -> 3 -> 1

    //next method returns an option of a LinkedList, so after dealing with Some(T) or None
    //we can push/pop over the list
    let new_list =  list.advance()//returns Some(3 -> 2 -> 1)
                                    .unwrap() //returns 3 -> 2 -> 1
                                    .advance() //returns Some(2 -> 1)
                                    .unwrap(); //returns 2 -> 1
    println!("{new_list:?}\n{list:?}");
    for i in list.clone().into_iter().map(|x| x*2 ){
        print!("{i} ");
    }
    println!("");
    for i in list.clone().into_iter().filter(|x| x%2 == 0 ){
        print!("{i} ");
    }
    println!("");
}*/

//GRAPH
mod graph;
use graph::*;
fn main(){
    let mut g = Graph::new();
    g.insert(0, 2, 5.65);
    g.insert(0, 2, 5.5);
    g.insert(0, 1, 5.5);
    g.printing();
    println!("{:?}, {:?}", g.first(3), g.first(2));
    println!("{}", g.is_node(4));
    for sla in 5..20{
        g.insert(0, sla, 1.0);
    }
    //g.printing();
    g.insert(0, 1, 2.0);
    g.insert(0, 1, 0.5);
    g.printing();
    println!("{:?}", g.weight(0, 1));
    println!("{:?}", g.weight(0, 4));

    println!("{:?} {:?} {:?}", g.remove(3, 0), g.remove(1, 2), g.remove(1, 0));
    drop(g);
    
    let mut g = Graph::new();
    g.insert('a', 'b', 1);
    g.insert('b', 'c', 2);
    g.insert('a', 'd', 3);
    g.printing();
    println!("{:?}", g.remove('b', 'c'));
    g.printing();
    println!("{:?}", g.remove('b', 'a'));
    g.printing();
    println!("{:?}", g.remove('d', 'a'));
    g.printing();
}
