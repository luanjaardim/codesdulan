mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}

        pub mod hosting_vips{
            pub fn add_to_viplist() {}
        }
    }
}

use self::front_of_house::hosting; 
//cria um atalho para hosting, traz hosting para o escopo de main
use self::front_of_house::hosting::hosting_vips::add_to_viplist as vip_list;
//com o use as podemos dar um novo nome para se referir ao path

pub fn eat_at_restaurant() {
    hosting::add_to_waitlist();
    vip_list();
}

//outros usos de " use "
pub use std::{ io, cmp::Ordering };
//trazendo para o escopo dois módulos que estavam em std, nesse caso poderíamos 
//substituir a linha acima por 2 uses: std::io e std::cmp::Ordering.

use std::cmp::{self, PartialEq};
//nesse caso é importado std::cmp e std::cmp::PartialEq

pub use std::collections::*; 
//neste todos os elementos de collections são importados

//o primeiro e último use acima estão com pub na frente, pois vamos usá-los na main

//UPDATE OF TESTE_MODULES//
//simulating OOP inheritance in Rust:
//in Rust we have a feature that can acts like a OOP inheritance,
//by the use of a trait and the reference dyn of a trait
//all types that implements a trait can be referred
pub trait Dimensions{
    fn area(&self) -> f64;
    fn volume(&self) -> f64;
}

pub struct Cube{ side: f64 }
impl Cube{
    pub fn new(side: f64) -> Self{ Self{ side } }
}
impl Dimensions for Cube{
    fn area(&self) -> f64{
        6.0 * self.side * self.side
    }
    fn volume(&self) -> f64{
        self.side * self.side * self.side        
    }
}

pub struct Sphere{ radius: f64 }
impl Sphere{
    pub fn new(radius: f64) -> Self{ Self{ radius } }
}
impl Dimensions for Sphere{
    fn area(&self) -> f64{
        4.0 * (3.1416) * self.radius.powi(2) // 4 * pi * r²
    }
    fn volume(&self) -> f64{
        (4.0/3.0) * (3.1416) * (self.radius.powi(3)) // 4/3 * pi * r³
    }
}

//we could define solid as Box<dyn Dimensions>
//means that the type of solid must implement the Dimensions trait
//dyn specifies that the methods called are dynamically dispatched,
//the compiler doesn't know the concrete type being passed,
//dyn reference contain 2 pointers: 1 to the data and 1 to a map
//with the methods pointers to call, at runtime this map(vtable) 
//is consulted to get the function pointer to, then, call the method
pub fn area(solid: &dyn Dimensions) -> f64{
    solid.area()
}
pub fn volume(solid: &dyn Dimensions) -> f64{
    solid.volume()
}
//area() and volume() are functions availables for users, them
//call the private methods, for a Sphere or Cube

//if the user decides to create his own struct and wants to use the area and volume
//functions, he can implement Dimensions, that's perfectly fine
