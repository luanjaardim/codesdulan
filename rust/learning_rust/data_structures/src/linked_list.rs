use std::fmt::Debug;
use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, Clone)]
pub struct LinkedList<T: Clone + Debug>(Rc<RefCell<Node<T>>>);

#[derive(Debug, Clone)]
pub struct Node<T> where T: Clone + Debug{
    next: Option<Rc<RefCell<Node<T>>>>,
    value: T
}

//to implement: lenght function, From and Into traits Ex.: LinkedList::from([1, 2, 3])
impl<T> LinkedList<T> 
where 
    T: Clone + Debug
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
    pub fn push(&mut self, v: T) -> Self {
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
    pub fn pop(&mut self) -> Option<T> { 
        let (ret, new_next);
        {
            let tmp = self.0.borrow();
            (ret, new_next) = match &tmp.next {
                None => (None, None),
                Some( n ) => {
                    let mut next_node = n.borrow_mut();
                    let ret = next_node.value.clone();
                    (Some(ret), next_node.next.take())
                }
            };
        }
        self.0.borrow_mut().next = new_next;
        ret
    }
    pub fn change_value(&mut self, val: T) {
        self.0.borrow_mut().value = val;
    }
    pub fn advance(&self) -> Option<Self> {
        let tmp = self.0.borrow(); //reference to node
        match &tmp.next {
            None => None,
            Some( n ) => Some(LinkedList(Rc::clone(n)))
            //returning a list with the next node as the head
        }
    }
    pub fn insert_after(&mut self, val: T, mut ind: usize) {
        let mut tmp = self.clone();
        while ind > 0 {
            tmp = tmp.advance().expect("expected a valid index");
            ind -= 1;
        }
        tmp.push(val);
    }
    pub fn printing(&self) {
        print!("({:?})", (*self.0.borrow()).value);
        let mut tmp = self.advance();
        while let Some( n ) = tmp.as_ref() {
            print!(" -> ({:?})", n.0.borrow().value );
            tmp = tmp.unwrap().advance();
        }
        println!("");
    }
}

pub struct ListIntoIterator<T: Clone + Debug>(Option<LinkedList<T>>);

impl<T> Iterator for ListIntoIterator<T> 
where 
    T: Clone + Debug
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
    T: Clone + Debug
{
    type Item = T;
    type IntoIter = ListIntoIterator<T>;
    fn into_iter(self) -> Self::IntoIter{
        ListIntoIterator(Some(self))
    }
}
