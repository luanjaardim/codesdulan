use std::rc::Rc;
use std::cell::RefCell;
#[derive(Debug)]
pub struct LinkedList (Rc<RefCell<Node>>);

#[derive(Debug)]
struct Node{
    next: Option<Rc<RefCell<Node>>>,
    value: i32
}

impl LinkedList{
    pub fn new(v: i32) -> Self {
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
    pub fn push(&self, v: i32) -> Self {
        let mut tmp = (*((*self).0)).borrow_mut(); 
        let a = match &tmp.next {
            None => {
                let new_node = Rc::new(RefCell::new(Node { next: None, value: v }));
                tmp.next = Some(Rc::clone(&new_node));
                Rc::clone(&new_node)
            },
            Some( n ) => {
                let new_node = Rc::new(RefCell::new(Node { next: Some(Rc::clone(&n)), value: v }));
                tmp.next = Some(Rc::clone(&new_node));
                Rc::clone(&new_node)
            }
        };
        LinkedList(a)
    }
    fn pop(&self) {
        todo!();
    }
    pub fn next(&self) -> Option<Self> {
        match &((*((*self).0)).borrow().next) {
            None => None,
            Some( n ) => Some(LinkedList(Rc::clone(n)))
        }
    }
}