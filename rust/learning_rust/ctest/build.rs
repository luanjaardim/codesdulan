extern crate cmake;

use cmake::Config;

//config file for build the project
fn main(){
    let dst = Config::new("libc").build();

    println!("cargo:rustc-link-search=native={}", dst.display());
    println!("cargo:rustc-link-lib=static=libc"); //linking C files
}
