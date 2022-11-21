use std::collections::{HashMap, HashSet, VecDeque, BinaryHeap,hash_map::Keys};
use std::hash::Hash;
use std::cmp::Reverse;

#[derive(Clone)]
pub struct Graph<T, U>
    where
        U: PartialOrd + PartialEq + Clone + std::fmt::Debug,
        T: PartialOrd + Eq + Hash + Clone + std::fmt::Debug
{
    graph: HashMap<T, Vec<(T, U)>>,
    num_nodes: usize,
    num_edges: usize,
}
impl<T, U> Graph<T, U>
where
        U: PartialOrd + PartialEq + Clone + std::fmt::Debug, 
        T: PartialOrd + Eq + Hash + Clone + std::fmt::Debug
{
    pub fn new() -> Self {
        Graph{
            graph: HashMap::new(),
            num_nodes: 0 as usize,
            num_edges: 0 as usize
        }
    }
    pub fn first(&self, node: T) -> Option<(T, U)> {
        if !self.graph.contains_key(&node) { return None }
        
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
                self.num_nodes += 1;
            },
            (false, true) => {
                self.graph.insert(n.clone(), vec![(m.clone(), w.clone())]);
                Graph::push_in_order(self.graph.get_mut(&m).unwrap(), n.clone(), w.clone());          
                self.num_nodes += 1;
            },
            (false, false) => {
                self.graph.insert(n.clone(), vec![(m.clone(), w.clone())]);
                self.graph.insert(m.clone(), vec![(n.clone(), w.clone())]);
                self.num_nodes += 2;
            }
        }
        self.num_edges += 1;
    }
    pub fn remove(&mut self, n: T, m: T) -> Option<(T, T, U)>{
    //remove the smaller edge between n and m, if there are others
        if !self.graph.contains_key(&n) || !self.graph.contains_key(&m) { return None }
        let v = self.graph.get(&n).unwrap();
        let v2 = self.graph.get(&m).unwrap();

        match (Graph::b_search(&v, m.clone()), Graph::b_search(&v2, n.clone())) {
            (Some(ind), Some(ind2)) => {
            
                let v = self.graph.get_mut(&n).unwrap();
                let (_, w) = v.remove(ind);
                if v.is_empty() { self.graph.remove(&n); self.num_nodes -= 1; }

                let v2 = self.graph.get_mut(&m).unwrap();
                v2.remove(ind2);
                if v2.is_empty() { self.graph.remove(&m); self.num_nodes -= 1; }

                self.num_edges -= 1;

                Some((n, m, w))
            },
            _ => None
        }
    }
    pub fn nodes(&self) -> Keys<T, Vec<(T, U)>>{ //iterating over all nodes in graph
        self.graph.keys()
    }
    pub fn neighbours(&self, node: &T) -> &Vec<(T, U)>{ //iterating over all linked nodes
        self.graph.get(node).expect("a valid node was expected")
    }
    pub fn dfs(&self, node: T){
        if !self.graph.contains_key(&node) { panic!("a valid node was expected"); }
        
        let mut to_visit = HashSet::new();
        for nodes in self.nodes(){
            to_visit.insert(nodes.clone());
        }
        
        to_visit.remove(&node); //first node visited
        self.aux_dfs(node, &mut to_visit);
        
        loop{ //visiting other 
            if to_visit.is_empty() { break }
            self.aux_dfs(to_visit.iter().next().unwrap().clone(), &mut to_visit);
        }        
    }
    fn aux_dfs(&self, node: T, to_visit: &mut HashSet<T>){
        //previsit()
        to_visit.remove(&node);
        for neighbours in self.neighbours(&node){
            if to_visit.contains(&neighbours.0) { self.aux_dfs(neighbours.0.clone(), to_visit); }
        }
        //posvisit
        println!("{:?} visited", node);
    }
    pub fn bfs(&self, node: T){
        if !self.graph.contains_key(&node) { panic!("a valid node was expected"); }
        
        let mut to_visit = HashSet::new();
        for nodes in self.nodes(){
            to_visit.insert(nodes.clone());
        }        
        to_visit.remove(&node); //first node visited
        self.aux_bfs(node, &mut to_visit);

        loop{ //visiting other 
            if to_visit.is_empty() { break }
            self.aux_bfs(to_visit.iter().next().unwrap().clone(), &mut to_visit);
        } 
    }
    pub fn aux_bfs(&self, node: T, to_visit: &mut HashSet<T>){
        let mut queue = VecDeque::new();
        queue.push_front(node.clone());
        while !queue.is_empty() {
            //previsit()
            let n = queue.pop_back().unwrap();

            for (neighbours, _) in self.neighbours(&n){
                if to_visit.contains(&neighbours) { 
                    queue.push_front(neighbours.clone());
                    to_visit.remove(&neighbours);
                }
            }
            //posvisit
            println!("{:?} visited", n);
        }
    }
    pub fn printing(&self){
        for (node, v) in self.graph.iter(){
            println!("{node:?}: {v:?}");
        }
        println!("{} {}", self.num_edges, self.num_nodes);
    }    
}

//TO IMPLEMENT: a Heap only with Partial Ord to make dijkstra and other
//algorithms more generics, implement Kruskal for MST and make comments
impl<T> Graph<T, usize> 
where
        T: Ord + Eq + Hash + Clone + std::fmt::Debug    
{
    pub fn dijkstra(&self, node: T) -> HashMap<T, usize>{
        if !self.graph.contains_key(&node) { panic!("a valid node was expected"); }
        
        let mut to_visit = HashSet::new(); //unvisited nodes
        let mut dist = HashMap::new(); //distances
        for nodes in self.nodes(){
            to_visit.insert(nodes.clone());
            dist.insert(nodes.clone(), usize::MAX); 
            //the initial distance is infinity(the greater it can be -> usize::MAX)
        }
                    
        let mut heap = BinaryHeap::new();
        heap.push(Reverse((0, node.clone()))); //beginning node
        //in heap the pair (node, weight) is (weight, node) for ordering purposes
        //and we are using the Reverse struct do wrap our values and create a min heap
        *dist.get_mut(&node).unwrap() = 0; //a distance between a node and itself is 0
        
        for i in 0..self.num_nodes { //one iteration per node
            let (n, _) = loop { 
            //poping the heap till find a unvisited node linked
            //with the visited one's with the smaller weight
                if heap.is_empty() { return dist }

                let (w, n) = heap.pop().unwrap().0;
                if to_visit.contains(&n) {
                    to_visit.remove(&n); 
                    break (n, w)
                }
            };
            //println!("{n:?} {w}");
            for (node, we) in self.neighbours(&n){
                if *dist.get(&node).unwrap() > we + dist.get(&n).unwrap() {
                
                    *dist.get_mut(&node).unwrap() = we + dist.get(&n).unwrap();
                    heap.push(Reverse((*dist.get(&node).unwrap(), node.clone())));
                }
            }
        }
        dist
    }
}
