//importing some C code to Rust

#[repr(C)] //bringing C struct
pub struct Pair{
    x: i32,
    y: i32
}

#[link(name = "libc", kind = "static")] //linking C functions
extern "C"{
    fn add(x: f32, y: f32);
    fn doubler(x: i32) -> i32;
    fn new_c(x: i32, y:i32) -> Pair;
}

//this is just a way, that works, for make C code works in Rust
fn main() {
    println!("Hello, world!");
    let sla = unsafe{
        add(1.2, 3.5);
        doubler(10)
    };
    let sla2 = unsafe{
        new_c(sla, sla)
    };
    println!("{} {}", sla2.x, sla2.y);
}
