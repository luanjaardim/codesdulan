//#![allow(unused)]
//use rust_debug::*;
//use text_io::*;

//CLOSURES E ITERATORS
use std::{thread, time::Duration};
//importando de std ferramentas para deixar o programa parado durante um determinado tempo
fn main(){
    //closures são ferramentas do rust para guardar o corpo de uma função em uma variável, que mais a frente no código pode ser reutilizada
    //a grande força das closures pode ser expressa na sua facilidade de criação, quando comparando com funções, visto que não precisamos 
    //anotar explicitamente os tipos, o que torna mais simples a criação de funções triviais que apenas ocupariam espaço junta a outras maiores
    let closure_calculation = |x| {
        println!("calculando, carma ae");
        thread::sleep(Duration::from_secs(1)); //1 segundo parado
        x
    };

    println!("resultado chamando a função: {}\nresultado chamando a closure: {}", calculation(90), closure_calculation(90));
    //primeiro println busca ambos os valores retornados para dps printar, por isso "calculando, carma ae" aparece seguidamente, já que
    //os prints dentro da função e do closure acontecem no momento em q eles são chamados

    let closure_example = |x| calculation(x);
    //aqui uma função é utilizada para a criação da closure, dessa forma temos uma variável que chama uma função e retorna seus valores
    println!("{}", closure_example(900));

    //podemos também atribuir uam tipagem específica para as closures, mesmo que isso n seja necessário, já que os tipos 
    //são inferidos automaticamente, mas se quisermos restringir uma closure, isso pode ser útil
    let closure_example2 = |x: String| calculation(x);
    println!("{}", closure_example2("alo".to_string()));

    let x = 90;
    let equal_to_x = |value| { value == x };
    assert!(equal_to_x(90));
    //outro ponto positivo das closures é que elas conseguem capturar valores de variáveis no do ambiente, diferente das funções
    //como na closure acima que consegue compara value a x, sendo que x nunca foi definido dentro dela, logo ela está utilizando aquele
    //definido no escopo da função main, uma função, entretanto não conseguiria "encontrar" o x, o código abaixo não compilaria:
                //fn equal_to_x_func(value: i32) -> bool{ value==x }
                //assert!(equal_to_x_func(90));
    /*
    essa captura de variáveis ambientes realizada pelas closures leva em conta os conceitos de borrowing ou copy, nesse caso por estarmos usando
    x como um i32 teremos apenas uma cópia do seu valor para dentro da closure, n perdemos sua ownership, entretanto, no caso de usarmos tipos
    que não implementam copy podemmos perder a ownership, por isso temos o borrowing destes
    */
    let vec1 = vec![1, 2, 3];
    let equal_vecs = |vec2| vec2 == vec1; //vec1 é uma variável ambiente que realiza borrowing aqui
    assert!(equal_vecs(vec![1, 2, 3])); 
    println!("{:?}", vec1); //podemos utilizar novamente depois, pois possuímos sua ownership
}

fn calculation<T>(intensitivy: T) -> T {
    println!("calculando, carma ae");
    thread::sleep(Duration::from_secs(1)); //1 segundo parado
    intensitivy
} 
/* 
use rust_debug::*;
use rand::Rng;
use std::io;
fn main(){
    let mut s = String::new();
    let mut a: Vec<i32> = Vec::new();
    io::stdin().read_line(&mut s).unwrap();
    
    let nums = s.trim().split_whitespace();
    for i in nums{
        a.push(i.parse().expect("digite números"));
    }

    let b = selection_sort(a);
    println!("{:?}", b);
    //let c = bubble_sort(a);
    //println!("{:?}", c);

    let num = rand::thread_rng().gen_range(1..=100);
    println!("{}", num);

    let clos = |num, num2|{ num + num2 };
    let x = clos(90, 8);
    println!("{}", x);
}*/