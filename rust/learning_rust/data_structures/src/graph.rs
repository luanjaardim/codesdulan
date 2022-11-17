use std::collections::HashMap;
use std::hash::Hash;
pub struct Graph<T, U>
    where
        U: PartialOrd + PartialEq + Clone + std::fmt::Debug,
        T: Eq + Hash + Clone + std::fmt::Debug
{
    graph: HashMap<T, Vec<(T, U)>>,
    num_edges: usize
}
impl<T, U> Graph<T, U>
where
        U: PartialOrd + PartialEq + Clone + std::fmt::Debug, 
        T: PartialOrd + Eq + Hash + Clone + std::fmt::Debug
{
    pub fn new() -> Self {
        Graph{
            graph: HashMap::new(),
            num_edges: 0 as usize
        }
    }
    pub fn first(&self, node: T) -> Option<(T, U)> {
        match self.graph.get(&node){
            None => None,
            Some(v) => Some(v[0].clone())
        }
    }
    pub fn is_node(&self, node: T) -> bool {
        self.graph.contains_key(&node)
    }
    fn b_search(v: &Vec<(T, U)>, val: T) -> Option<usize> {
        let (mut l, mut r) = (0, v.len() - 1);
        let mut m;
        while l <= r {
            m = (l + r)/2;
            if v[m].0 == val { 
                while m > 0 && v[m].0 == v[m-1].0 { m -= 1; }
                return Some(m) 
            }
            else if v[m].0 > val { r = m-1; }
            else { l = m+1; }
        }
        None
    }
    pub fn weight(&self, n: T, m: T) -> Option<Vec<U>> 
    {
        if self.graph.contains_key(&n) 
        {
            let v = self.graph.get(&n).unwrap();
            if let Some(ind) = Graph::b_search(v, m.clone())
            {
                let mut vector = Vec::new();
                for i in ind .. v.len() {
                    if m == v[i].0 { vector.push(v[i].1.clone()) }
                }
                return Some(vector)
            }
        }
        None
    }
    fn push_in_order(v: &mut Vec<(T, U)>, other: T, weight: U){ //insertion sort
        //self.graph.get_mut(&n).unwrap().push((m.clone(), w.clone()));
        //self.graph.get_mut(&m).unwrap().push((n.clone(), w.clone()));

        v.push((other, weight));
        let mut j = v.len() - 1;
        let val = v[j].clone();
        while j > 0 && val < v[j-1] {
            v[j] = v[j-1].clone();
            j -= 1;
        }
        v[j] = val;
    }
    pub fn insert(&mut self, n: T, m: T, w: U){
        match (self.graph.contains_key(&n), self.graph.contains_key(&m))
        {
            (true, true) => {
                Graph::push_in_order(self.graph.get_mut(&n).unwrap(), m.clone(), w.clone());
                Graph::push_in_order(self.graph.get_mut(&m).unwrap(), n.clone(), w.clone());          
            },
            (true, false) => {
                Graph::push_in_order(self.graph.get_mut(&n).unwrap(), m.clone(), w.clone());
                self.graph.insert(m.clone(), vec![(n.clone(), w.clone())]);
            },
            (false, true) => {
                self.graph.insert(n.clone(), vec![(m.clone(), w.clone())]);
                Graph::push_in_order(self.graph.get_mut(&m).unwrap(), n.clone(), w.clone());          
            },
            (false, false) => {
                self.graph.insert(n.clone(), vec![(m.clone(), w.clone())]);
                self.graph.insert(m.clone(), vec![(n.clone(), w.clone())]);
            }
        }
        self.num_edges += 1;
    }
    pub fn remove(){

    }
    pub fn printing(&self){
        for (node, v) in self.graph.iter(){
            println!("{node:?}: {v:?}");
        }
        println!("{}", self.num_edges);
    }
    
}
