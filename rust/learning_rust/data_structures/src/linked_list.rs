use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, Clone)]
pub struct LinkedList<T: Copy>(Rc<RefCell<Node<T>>>);

#[derive(Debug, Clone)]
struct Node<T> where T: Copy{
    next: Option<Rc<RefCell<Node<T>>>>,
    value: T
}

impl<T> LinkedList<T> where T: Copy{
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
    pub fn advance(&self) -> Option<Self> {
        match &((*((*self).0)).borrow().next) {
            None => None,
            Some( n ) => Some(LinkedList(Rc::clone(n)))
        }
    }
}

pub struct ListIntoIterator<T: Copy>(Option<LinkedList<T>>);

//pub struct LinkedList<T: Copy>(Rc<RefCell<Node<T>>>);
/*impl<T> Iterator for LinkedList<T> where T: Copy{
    type Item = T;
    fn next(&mut self) -> Option<Self::Item> {
        todo!();
    }
}*/
impl<T> Iterator for ListIntoIterator<T> where T: Copy{
    type Item = T;
    fn next(&mut self) -> Option<Self::Item> {
        if (*self).0.is_none() { return None }
        let ret = (*(*((*((*self).0.as_ref().unwrap())).0)).borrow()).value;
        (*self).0 = (*self).0.as_ref().unwrap().advance();
        Some(ret)
    }
}
impl<T> IntoIterator for LinkedList<T> where T: Copy{
    type Item = T;
    type IntoIter = ListIntoIterator<T>;
    fn into_iter(self) -> Self::IntoIter{
        ListIntoIterator(Some(self))
    }
}
