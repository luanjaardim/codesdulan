pub mod teste; //importando o que há dentro de teste.rs como um módulo
mod lib;

mod prin{ //prin n precisa do pub para ser visto
          //pois está no mesmo escopo de alo
    pub fn f1() { println!("f1 fora dos mod"); } //f1 está no escopo do mod prin
                                                 //para ser vista por alo devemos acessá-la através de prin
                                                 //além disso ela deve ser pub pra podermos usá-la
    pub mod m1{
        pub fn f1() { println!("f1 do mod1"); } 

        pub mod m2{
            pub fn f1() { println!("f1 do mod2"); }
            fn f2() { println!("f2 do mod2"); } //private
        }
        mod m3{ //m3 é um módulo em m1 que está privado ao nosso acesso, ele só existe dentro de m1
            fn f1() { println!("f1 do mod3"); } //private
        }
    }
}
//quando usamos crate:: devemos dar o caminho completo até o que queremos, chamado path global
//podemos usar um caminho relativo, sem o crate::, partindo do "diretório" em que a chamada está
fn alo() {
    prin::f1();
    crate::prin::m1::f1(); 
    prin::m1::m2::f1();
    teste::teste1(); 
    crate::teste::teste2::f1();
}

mod mais_testes{ //mais_testes está no mesmo escopo que prin (main.rs) os seus elementos precisam voltar no path para poder acessar seus elementos
    pub fn testando() { super::prin::f1(); }
    pub mod mais_mais_testes{
        pub fn testando() { super::super::prin::m1::f1(); } 
    }
}
//super é utilizado para fazer o caminho "voltar" dos filhos pros pais, acessando módulos que estavam antes na path


fn main()
{
//package são as pastas criadas quando usamos o comando cargo new (nome)
//dentro dos package temos o cargo.toml que é o arquivo que vai gerenciar
// as crates;
//crates são os próprios arquivos em que o código é escrito
//existem dois tipos de crates: binary crates e library crates
//binary: quando compilados geram um executável
//library: apenas uma por package, definem as funcionalidades compartilhasdas
//entre projetos, não possuem a fn main e não geram executável
//uma crate é chamada root quando ela é a main.rs ou a lib.rs de um package

//para acessar os elementos dentro de um binary(como o teste.rs nesse exemplo) importamos ele como um mod (linha 1)
//por sua vez podemos ter submodules (como o teste2.rs) que é importado em teste.rs, para ficarem corretamente definidos como
//submódulos devemos colocar eles dentro de uma pasta com o nome do módulo que os importa, nesse caso a pasta vai ter o nome de teste
//a partir disso podemos acessar funções, structs, enums ou outros mods através dos paths, que são como os diretórios de um 
//computador, navegando de "pasta em pasta" até chegar ao elemento desejado
    let a: teste::TesteStruct = teste::TesteStruct::criar_teste_struct();
    let b: teste::TesteEnum = teste::TesteEnum::Kkkk(5, 5);

//ficaram alguns wanrings do compilador, mas eles são apenas para mostrar que funções privadas nunca serão acessadas senão em seus escopos
    alo();
    println!("----------------------------");
    mais_testes::testando();
    println!("----------------------------");
    mais_testes::mais_mais_testes::testando();
    println!("----------------------------");
    crate::teste::teste2::f2();
    println!("----------------------------");
    print!("a: {} ", a.nome);
    a.qual_meu_num(); //printando o num de a, que não é acessável nesse escopo
    if let teste::TesteEnum::Kkkk(x, y) = b {
        println!("b: {}, {}", x, y);
    }

    lib::eat_at_restaurant(); //usando uma função do mod lib

    let mut palavra:String = String::new();
    //utilizando o pub use em lib
    lib::io::stdin() //para usar stdin devemos adicionar use std::io; acima da main
        .read_line(&mut palavra) //read_line recebe uma referência mutável para alterar palavra dentro da função
        .expect("Failed to read line");
    print!("{}", palavra);

    //utilizando o pub use em lib
    let _hm: lib::HashMap<String, String> = lib::HashMap::new();

    //UPDATE OF TESTE_MODULES//
    use lib::{area, volume};
    let sph = lib::Sphere::new(2.0);
    let sqr = lib::Cube::new(4.0);
    println!("Area sphere: {}, Area Cube: {}", area(&sph), area(&sqr));
    println!("Volume sphere: {}, Volume Cube: {}", volume(&sph), volume(&sqr));

    //a user personal solid that implements Dimensions
    struct RectangularSolid{
        l: f64, w: f64, h: f64
    }
    impl lib::Dimensions for RectangularSolid{
        fn area(&self) -> f64 {
            2.0*( self.l * self.h + self.l * self.w + self.w * self.h)
        }
        fn volume(&self) -> f64{
            self.l * self.w * self.h
        }
    }
    let (l, w, h) = (2.0, 3.6, 1.2);
    let rectan = RectangularSolid{ l, w, h };
    println!("Volume: {}, Area: {}", volume(&rectan), area(&rectan)); 
}
