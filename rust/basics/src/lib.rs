//IMPLEMENTAÇÃO DE TRAIT PARA A PARTE DE TIPOS GENÉRICOS NA MAIN
/* 
//traits são como assinaturas de métodos que podem ser reutilizadas entre diversos tipos
//quando fazemos a implementação dela para determinado tipo
//devemos sempre colocar &self quando queremos que a função seja um método
pub trait Summary {
    fn func(&self);
    fn summarize(&self) -> String;
    fn default_func(&self) { 
        println!("Just a default function of the trait Summary.");
    }
    //métodos implementados, em vez de definidos como assinatura, podem ser utilizados sem necessariamente ser implementado
    //obs: deve existir a impl ... for ... do tipo para que ele possa utilizar os métodos padrões
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

//implementação das funções assinadas no trait Summary para o tipo NewsArticle
impl Summary for NewsArticle {
    fn func(&self){
        println!("func para NewsArticle");
    }
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

//implementação das funções assinadas no trait Summary para o tipo Tweet
impl Summary for Tweet {
    fn func(&self){
        println!("func para Tweet");
    }
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
    fn default_func(&self) { //sobrescrevendo a função para o tipo Tweet
        println!("default_func modificada na implementação para o tipo Tweet");
    }
}

//função que recebe como argumento um tipo que implemente a trait Summary, ou seja Tweet ou NewsArticle
pub fn notify<T: Summary>(item: &T) {
    println!("Breaking news! {}", item.summarize());
}
//outra forma de escrever a função acima
/*
pub fn notify(item: &impl Summary) {
    println!("Breaking news! {}", item.summarize());
}
*/

//a função prt recebe argumentos do tipo T, apenas se T possui implementação para o trait Display
//ou seja, T é um tipo que pode ser representado com {} na macro println! ou print!
pub fn prt<T: std::fmt::Display>(item: &T) {
    print!("{} ", item);
}
//já prt2 aceita apenas tipos que possuem implementação para o trait Debug (tupples, arrays, etc)
pub fn prt2<T: std::fmt::Debug> (item: &T) {
    print!("{:?} ", item);
}
//prt3 funciona apenas para aqueles tipos que implementam ambos traits, tupples, por exemplo, implementa
//Debug, mas n Display, logo ela n pode ser exibida por essa função
pub fn prt3<T: std::fmt::Debug + std::fmt::Display> (item: &T) {
    print!("{} or {:?}", item, item);
}

//cmp recebe dois argumentos de mesmo tipo e devolve o maior
//a restrição dessa vez foi apresentada com ajuda da palavra reservada
//where, ela vem antes dos {} e faz o mesmo trabalho que quando colocamos
// <T: PartialOrd>.      OBS.: o U só foi utilizado para dar um exemplo
pub fn cmp<T>(item1: T, item2: T) -> T
    where T: PartialOrd,
        // U: PartialOrd + PartialEq
{
    if item1 > item2{
        return item1
    }
    item2
}

pub struct Pair<T, U> (pub T, pub U);

impl<T, U> Pair<T, U>{ //implementando o construtor para Pair
    pub fn new(x: T, y: U) -> Self{
        Self(x, y)
    }
} //Self com S maiúsculo indica que estamos falando do tipo para o qual as funções estão
  //sendo implementadas, nesse caso Self é o mesmo que Pair<T>

impl<T> Pair<T, T>
    where T: std::fmt::Display + PartialOrd
{
    //criando uma função que compara os dois elementos do par, essa função só vai funcionar
    //se o par tiver ambos os elementos do mesmo tipo e se o tipo tiver implementação em Display
    //e PartialOrd
    pub fn cmp_and_display(&self) {
        if self.0 >= self.1 {
            println!("the first is greater or equal: {}", self.0);
        }
        else{
            println!("the second is greater: {}", self.1);
        }
    }
}

//Aqui implementamos para o tipo Pair<T> a forma de comparação que o Rust deve fazer quando
//tivermos a expressão -> Pair<T> == Pair<T>, nesse caso ele irá comparar os elementos correspondentes um a um
//perceba que se não implementarmos isso a operação == irá emitir um erro
//OBS.: n é preciso nessa implementação do pub em eq, já que eq já está no prelúdio 
impl<T: PartialEq, U: PartialEq> PartialEq for Pair<T, U>{
    //para saber a assisntura das funções de PartialEq podemos ir em Rust doc
    fn eq(&self, other: &Self) -> bool{ 
        if self.0 == other.0 && self.1 == other.1{ return true }
        false 
    }
}
*/

//TESTES COM AUXÍLIO DA CONFIG(cfg) TEST 
/* 
#[cfg(test)]
pub mod tests{
    use super::*; //para pegar as coisas fora do mod tests
    //funções de teste n pode possuir argumentos
    #[test]
    pub fn testinhos(){
        assert_eq!("alo", &"alo".to_string());
        //"alo" como &str é igual a "alo" como &String
    }
    #[test]
    pub fn is_true(){
        assert!(S("opa".to_string()) == S(String::from("opa")), "as palavras são diferentes");
        //assert! recebe uma expressão, se for verdadeira o teste passa, se for falsa falha
        //o texto como segundo argumento é como o texto de expect 
    }
    #[test]
    #[should_panic]
    pub fn testando_funcs(){
    //aqui estamos testando funções que deveriam dar panic! em alguma ocasião, nesse caso quando
    //entry é a String 90, se não der panic! então um erro é apresentado, pois esperávamos um panic!
        S::new(90.to_string());
    }
    #[test]
    pub fn test_result() -> Result<(), String>{
        //nesse caso temos um teste com retorno de result
        //o teste falha quando é devolvido um Err()
        if 2 == 4 {
            return Ok(())
        }
        Err("a matemática é a matemática né pae".to_string())
    }
}
#[derive(PartialEq)]    
pub struct S(String);
impl S{
    pub fn new(entry: String) -> Self {
        if entry == "90".to_string(){
            panic!("é 90");
        }
        Self(entry)
    }
}*/