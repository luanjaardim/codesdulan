pub fn f1() { println!("f1 dentro de teste2, submodule de teste"); }

pub fn f2() { super::super::alo(); } //f2 volta pelo caminho que chegou a teste2 (main -> teste -> teste2 -> f2)
// e então usa a função alo()
