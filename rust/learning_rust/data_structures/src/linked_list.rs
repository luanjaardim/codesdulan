use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, Clone)]
pub struct LinkedList<T: Clone>(Rc<RefCell<Node<T>>>);

#[derive(Debug, Clone)]
struct Node<T> where T: Clone{
    next: Option<Rc<RefCell<Node<T>>>>,
    value: T
}

impl<T> LinkedList<T> 
where 
    T: Clone
{
    pub fn new(v: T) -> Self {
        LinkedList(
            Rc::new(
                RefCell::new(
                    Node{
                        next: None, 
                        value: v
                    }                
                )
            )
        )
    }
    pub fn push(&self, v: T) -> Self {
        let mut tmp = self.0.borrow_mut(); //reference to Node
        let a = match &tmp.next //checking next node
        { 
            None => { //the node is the tail of the list
                let new_node = Rc::new(RefCell::new(Node { next: None, value: v }));
                tmp.next = Some(Rc::clone(&new_node));
                Rc::clone(&new_node) //returning new_node for possible use
            },
            Some( n ) => { //there were nodes after
                let new_node = Rc::new(RefCell::new(Node { next: Some(Rc::clone(&n)), value: v }));
                //a new_node pointing to what self is pointing
                tmp.next = Some(Rc::clone(&new_node));
                Rc::clone(&new_node) //returning new_node for possible use
            }
        };
        LinkedList(a)
        //this LinkedList is attached to the new_node as it's head
    }
    pub fn pop(&mut self) {
        todo!();
    }
    pub fn advance(&self) -> Option<Self> {
        let tmp = self.0.borrow(); //reference to node
        match &tmp.next {
            None => None,
            Some( n ) => Some(LinkedList(Rc::clone(n)))
            //returning a list with the next node as the head
        }
    }
    pub fn insert_at(&mut self) {
        todo!();
    }
}

pub struct ListIntoIterator<T: Clone>(Option<LinkedList<T>>);

impl<T> Iterator for ListIntoIterator<T> 
where 
    T: Clone
{
    type Item = T;
    fn next(&mut self) -> Option<Self::Item> {
        if self.0.is_none() { return None }
        
        let list = self.0.as_ref().unwrap(); //&LinkedList<T>
        let ret = (*list.0.borrow()).value.clone(); //return value
                    
        self.0 = list.advance(); //iterator forward!!
        Some(ret)
    }
}
impl<T> IntoIterator for LinkedList<T> 
where 
    T: Clone
{
    type Item = T;
    type IntoIter = ListIntoIterator<T>;
    fn into_iter(self) -> Self::IntoIter{
        ListIntoIterator(Some(self))
    }
}
