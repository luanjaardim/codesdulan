//TIPOS BÁSICOS
/*fn main() {
    // i8 , i16 , i32, i64, i128 inteiros com x bits
    // u8 , u16 , u32, u64, u128 inteiros com x bits unsigned 
    let x:i128 = 0; //declarações com let apenas criam variáveis não modificáveis
    let mut y:u128 = 999; //mut permite que esse valor seja alterado com novas atribuições
        println!("{}", y); //a exclamção indica que é uma macro
        println!("{y}"); //é outra possibilidade de escrever 
    y = 90;
    //char, bool variables
    let c: char;
    let b: bool = false;
    
    let mut t: (u8, char) = (16, 'a'); //tupples agrupam valores, de tipos diferentes possivelmente;
        println!("{}, {}", t.0, t.1);
    t = (5, 'z'); //atribuição a t
    (_, c) = t; //atribuição a valores correspondentes em ordem aos itens de t, o _ ignora a atribuição
    t.0 = 55;   //t.0 corresponde à primeira posição de de t, u8
        println!("{x}, {y}, {c}, {b}, {}, {}", t.0, t.1);
        println!("{:?}", t); // :? servem para printar uma tupple inteira, com os ()
                             // trata-se de uma característica de certos tipos para a formatação de impressão
    let a:[u32; 9]; //declaração de um array, pode ter apenas um tipo
    a = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    let ar_slice = &a[2..4]; //fazendo um slice, pegando parte dos elementos, de a
        println!("{ar_slice:?}");
    for i in a{     //estrutura for
        print!("{} ", i); //print sem ln não pula linhas
    }
    println!("\na size: {}", a.len());

    fn alo(a: u32) -> u32{ //é uma função que recebe um u32 e devolve um u32
        a // a variável sozinha, sem ';',  no final da função representa o retorno
    }
    println!("{}", alo(100)); //printando o retorno de uma função

    //falando de strings temos dois tipos: &str e String(de std): &str é um texto imutável durante a compilação, ou seja
    //se tivermos uma palavra fixa durante o cod podemos utilizá-lo( ex.: let a = "aaaa"), entretanto com o tipo &str não podemos
    //ler uma entrada de usuário, isso porque ela não tem tamanho fixo durante a compilação
    //&str é salva na stack(mais rápida), String aloca espaço na heap

    //formas de se trabalhar com strings
    let mut s = "alo alo".to_string(); //transformando o tipo de &str para String
    let s2 = String::from("World!");
    println!("{} {}", s, s2);

    s = String::from("Hello, ");
    s.push_str(&s2); //s2 é colocado ao fim de s, a função recebe uma &str
    println!("{}", s);
    s = (&s[0..=6]).to_string(); //transformando uma slice de string(&str) em String
    let s3 = s + &s2; //concatenando strings, s perde sua ownership aqui, já s2 não (outra forma de concatenação através do operador +)
    println!("{}", s3);
    let s4 = &s3[0..5]; //slice de strings
    println!("{:?}", s4); //printando com o :? mostramos os " " no terminal

    //format! macro
    let s = "oi".to_string();
    let s2 = "hi".to_string();
    let s3 = "hola".to_string();

    let s4 = format!("{}-{}-{}.concat", s, s2, s3); //format! concatena strings e retorna a string completa, sem tirar a ownership de nenhuma das strings que foram concatenadas
    println!("{}\n{}, {}, {}", s4, s, s2, s3);

    //em rust não é permitido a atribuição para char com o index de uma string (let a: char = &s[0];)
    //a forma mais fácil de conseguir o acesso aos bits de uma string é iterando sobre ela
    //entretanto a string pura não pode ser iterada, para isso devemos converter ela em um iterador válido (.chars() -> divide em chars, .bytes() -> divide em bytes)
    for c in s3.chars(){
        print!("{} ", c);
    }
    println!("");
    for c in s3.bytes(){
        print!("{} ", c);
    }
    println!("");
    //forma estranha de conseguir apenas um char de uma string seria devolvendo uma &str daquele char
    let c = &s3[0..1];
    println!("{}", c);

    //uma excelente maneira é transformar a palavra em um vec de char
    let vec_char: Vec<_> = s3.chars().collect(); //o underline significa que o tipo não interessa, pois ele vai ser exatamente o tipo dos elementos do iterador
    //collect é um método que funciona apenas em iteradores e transforma ele em um tipo de coleção(collect) nesse caso usamos o Vec, mas poderiam ser outras
    for i in &vec_char{
        print!("{} ", i);
    }
    //agora é fácil acessar um char específico da palavra
    println!("\n{}", vec_char[2]);
}*/

//SHADOWING, REPRESENTAÇÕES EM BASES NÃO DECIMAIS, CASTING E RETORNO DE VALORES
/*fn main() {
    let x = 5;

    let x = x + 1; //shadowing x, a nova criação com o mesmo nome "ofusca" a declaração anterior

    { //novo escopo dentro de main
        let x = x * 2; //dentro desse escopo fazemos outro shadowing
        println!("x dentro do escopo: {}", x);
    }
    println!("x fora do escopo: {}",x); 
    //como saiu do escopo acima x, de dentro, é desalocado, o valor de x anterior é então "clareado"(como se o outro saísse da frente)

    //shadowing pode ser útil por exemplo para reutilizar o mesmo nome para tipos diferentes
    //pois na realidade está sendo criada uma nova variável
    {
        let x = "alo alo";
        println!("x como &str dentro do escopo: {}", x);
        let x: usize = x.len(); //shadowing x e mudando o tipo anterior, além de aproveitar o valor anterior para gerar o novo
        println!("x como usize dentro do escopo: {}", x);
    }
    println!("x como i32 fora do escopo: {}", x);

    let a:u8 = 0b10010; //binário
    let b:u8 = 0x12; //hexadecimal
    let c:u8 = 0o22; //octal
    println!("{a}, {b}, {c}");

    let alo1:u8 = 99/100; //divisão inteira arredonda pra baixo q nem C
    let alo:f32 = 99 as f32 / 100 as f32; //casting as (99.0/100.0 também funcionaria)
    println!("{}, {}", alo1, alo);

    fn plus_one(y : u8) -> u8 //função que recebe um u8 e devolve um u8
    {
        y+1
    }
    let y:u8 = { //o escopo criado está devolvendo um valor para y;
        let x:u8 = 9;
        x*2 
    //uma linha de código sem ; é chamada expression e retorna um valor, caso coloquemos ; transformamos isso num statement, que n retorna valores
    };
    {
    let y = plus_one(y);
    println!("{y}");
    }
    println!("{y}");
}*/

//CONDICIONAIS E LOOPS
/*fn main() {
    //if, else if and else expressions(ou seja, podem retornar valores)
    //só aceitam como argumento booleanos
    let b:bool = false;
    let a = 10;
    if b { println!("b é verdade"); }
    else if a != 10 { println!("b é mentira e a é diferente de 10"); }
    else { println!("b é mentira e a é 10"); }

    let a = 10;
    let b = 20;
    {
        let a = { //o escopo vai retornar um valor para a, que é retornado por if ou else
            if a > b { a }
            else { b } 
            };
        println!("{a}");
    }
    println!("{a}");

    let mut cont = 0;
    let mut a = { //cria um escopo que retornará um valor para a
      'fora: loop //inicia um loop com um "nome", uma label
      {
          let mut cont2 = 0;
          loop //loop mais interno, não precisou do nome
          {
              println!("cont: {}, cont2: {}", cont, cont2);
              
              if cont2 == 10 { break } //break do loop mais interno
              
              if cont == 2 {
                  cont2 = 10;
                  println!("{}, {}", cont, cont2);
                  break 'fora cont+cont2 }
                  //esse break se referencia ao loop mais externo, além disso ele devolve um valor (cont + cont2) para a

              cont2+=2;
          }
          cont+=1;
      } 
    };
    println!("{}", a);

    while a != 5 //while loop
    {
        a-=1;
    }
    println!("{}", a);

    let ar:[u32; 5] = [1, 2, 3, 4, 5];
    for j in ar{        //for em um iterator
        print!("{} ", j);
    }
    println!("");
    for j in 0..5{      //for em um "range", 0..=5 seria um range que inclui o 5
        print!("{} ", ar[j]);
    }
    println!("");
    for j in (0..=4).rev(){ //.rev() vai reverter o range
        print!("{} ", j);
    }
    println!("");
}*/

//OWNERSHIP JUNTO AO BORROWING DE VARIÁVEIS
/*use std::io;
fn main(){
    //ownership se trata do dententor(variável) de certo valor, em rust, assim q esse detentor sair do escopo
    //no qual foi introduzido ele tem a memória do seu conteúdo desalocada, ownership pode ser movida de uma variável para outra

    //copy, está apenas atribuindo o valor guardado por x a y, agr existem duas variáveis com o mesmo valor guardado, em espaços diferentes
    let x: u8 = 5;
    let y:u8 = x;
    println!("{x}, {y}");

    //nesse caso se tentarmos utilizar s1 depois da atribuição em s2 teremos um error
    //isso porque, para que não existam dois ponteiros apontando para um mesmo endereço na heap, evitando 2 free's no mesmo endereço,
    //s1 dá seu conteúdo, endereço de memória, para s2 e perde o direito de acessá-lo, ownership
    let s1:String = String::from("Hello, world");
    let s2 = s1;
    println!("{}", s2);

    //nesse caso temos um borrowing do conteúdo de g1, g2 pegou emprestado ele, apenas emprestado, pois em Rust
    //só existe um ownership, o que g2 tem na verdade é o endereço de g1 e não do ponteiro para o conteúdo na heap
    //isso significa que ele acessa através de g1 o conteúdo na heap, quando g2 sai de escopo a memória na heap não é liberada
    let g1:String = String::from("Hello, Boy");
    let g2:&String = &g1;
    println!("{}, {}", g1, g2);

    //no caso anterior g2 era apenas uma referência a g1, ele não poderia alterar o valor para o qual g1 aponta
    //podemos alterar isso usando &mut (uma referência que permite modificações), só pode existir uma dessas por vez
    //para um mesmo conteúdo referenciado
    let mut t1:String = String::from("Hello, Man"); //t1 deve ser mut para poder passar o &mut dele
    let t2:&mut String = &mut t1;
    t2.push_str(" or Woman");
    println!("{}", t2); //t2 e t1 não podem ser utilizados ao mesmo tempo, isso porque rust não permite que sejam utilizadas ao mesmo tempo refs
    println!("{}", t1); //mutáveis e imutáveis, já que as mutáveis interferem em ambas ao mesmo tempo
    //podemos ter quantas refs imutáveis quisermos, já que elas não se afetam
    //no exemplo acima o compilador perecbe que t2 não é mais utilizado depos do primeiro print

    //referências que perdem seus referentes não são permitidas em Rust!!
    /* let k = func();
    fn func() -> &String{
        let s:String = String::new();
        &s 
        passando a referência de s para k, mas quando a função terminar s é desalocado, então a referência não pode mais existir
    } */
    //tente tirar os comentários acima, será emitido um erro

    //cod para separar a primeira palavra de uma String lida
    fn first_word(s: &str) -> &str{ 
    //s poderia ser de tipo &String, mas como nesse caso não vamos ler ou mudá-la, podemos usar o tipo literal de string
    //o tipo de string literal é do mesmo tipo que uma slice(&str)
        let ar = s.as_bytes(); //transforma a string em um array de bytes
        let mut tam_final = ar.len(); //se não tiver espaço é uma palavra inteira
        for i in 0..ar.len() {
            if ar[i] == b' ' //b significa que vai ler como byte (ascii)
            { tam_final = i; break } //posição do espaço
        }
        &s[0..tam_final] //devolve uma slice até o fim da primeira palavra
    }
    let mut palavra:String = String::new();
    io::stdin() //para usar stdin devemos adicionar use std::io; acima da main
        .read_line(&mut palavra) //read_line recebe uma referência mutável para alterar palavra dentro da função
        .expect("Failed to read line"); //expect apenas trata erros de leitura, exibindo a mensagem para o usuário
    let slice = first_word(&palavra);
    println!("palavra: {} and slice: {}", palavra, slice);
}*/

//ENTRADA DE DADOS DO USUÁRIO
/*#[macro_use] //para poder usar as macros da crate text_io
extern crate text_io;
fn main(){
    print!("Digite algo: "); //a macro print! n possui quebra de linha ao final, então precisa receber um flush para atualizar a stdout(saída padrão de dados, o que vemos no terminal)
    std::io::Write::flush(&mut std::io::stdout()).unwrap(); //essa seria a forma mais bruta de fazer o flush
    //outra forma seria trazendo stdout e flush(implementado pelo trait Write) pro escopo com use: use std::io{self, Write}
    // e então: io::stdout().flush().unwrap();
    let mut leitura: String = "".to_string();
    io::stdin()
        .read_line(&mut leitura) //altera o valor de palavra com os dados recebidos na entrada
        .expect("fail to read"); //caso read_line devolva um erro, então expect termina a execução e printa o aviso
    print!("Aqui está sua frase em upper case: {}", leitura.to_uppercase());
    //tomar cuidado com read_line, pois ele insere oq foi lido ao final da string (append), logo se formos reutilizar leitura para
    //uma nova entrada de dados devemos "limpar" ela antes.
    leitura = "".to_string();
    println!("Digite um número: ");
    std::io::stdin().read_line(&mut leitura).expect("fail to read");
    let num: i32 = leitura
                        .trim() //remove o carácter /n do final da string leitura
                        .parse() //tenta converter a string para o tipo da variável a qual estamos atribuindo, nesse caso i32
                        .unwrap(); //unwrap lembra ao expect, ele lida com o caso de que não seja possível uma conversão
    println!("{} é seu antecessor!", num-1);

    leitura = String::new();
    println!("Digite os elementos de um array de inteiros: ");
    use std::io;
    io::stdin().read_line(&mut leitura).expect("fail to read");
    let entry: Vec<_> = leitura.trim()
                               .split_whitespace() //split_whitespace devolve um iterador das substrings separadas por espaços
                               .collect(); //transforma um iterador em uma coleção, nesse caso em um Vec, como especificado no tipo de entry
                                           //como split_whitespace devolve um iterador de &str teremos um Vec de &str
    let mut v: Vec<i32> = Vec::new();
    for i in entry{
        v.push(i.parse().unwrap()); //iterando sobre o vetor de &str e tentando converter seus elementos e inserir eles no Vec v, do tipo i32
    }
    v.sort_unstable(); //faz a ordenação sobre os elementos do vetor
    println!("Essa é a ordem crescente dos valores dados: {:?}", v);

    //se adicionamos a crate text_io às nossas dependências do projeto, podemos utilizar macros para a leitura de dados
    //para utilizar as macros da text_io, sem mencioná-la com o path (text_io::) podemos utilizar a linha de cod acima de fn main
    print!("Digite um número: ");
    std::io::Write::flush(&mut std::io::stdout()).unwrap(); //flush
    let mut num: u32 = read!(); //read! faz um leitura para uma varíavel a qual especificamos o tipo previamente
    println!("{}", num);

    println!("Digite seguindo o formato: num eh (número)");
    num = read!("num eh {}"); //nesse caso a leitura deve ser exatamente a descrita, caso contrário temos panic
    println!("o novo valor de num é: {}", num);

    let (a, b, c): (i32, i32, i32);
    print!("Digite 3 números separados por espaço: ");
    std::io::Write::flush(&mut std::io::stdout()).unwrap(); //flush
    scan!("{} {} {}", a, b, c); //diferente de read! podemos ler vários valores ao mesmo tempo com scan!
    println!("a: {}, b: {}, c: {}", a, b, c);
}*/

//ENTRADA DE DADOS DO USUÁRIO COMO ARGUMENTO EM LINHA DE COMANDO
/*fn main()
{
    let args = std::env::args().skip(1); //recebe a entrada de argumentos
    //para enviar argumentos devemos escrever cargo run -- (arg1) (arg2) ... (arg n)
    //o primeiro argumento recebido é sempre a path da aplicação, por isso usamos o skip(1)
    //pulando essa primeira informação que não é tão importante assim
    let mut resul: i32 = 0;
    for i in args{
        resul += i.trim().parse::<i32>().unwrap();
    }
    println!("A soma dos valores é: {}", resul);
    //compile o código com essa linha, por exemplo: cargo run -- 89 10 0 1
}*/

//STRUCTS
/*fn main(){
    struct Estru{ //criação de uma estrutura
        nome : String,
        senha : String, 
        idade : u8, 
        adulto : bool
    }
    //criação de um objeto da estrutura
    let mut pessoa1: Estru = Estru { 
      nome: String::from("Luan"),
      senha: String::from("123456"), 
      idade : 69, 
      adulto : false
    };
    pessoa1.adulto = true;
    println!("{}\t{}\t{}\t{}\t", pessoa1.adulto, pessoa1.idade, pessoa1.nome, pessoa1.senha);

    let pessoa2 = Estru {
        nome : String::from("Julin"),
        senha : String::from("22_22"),
        ..pessoa1 //criando pessoa2 e pegando emprestado o resto dos valores de pessoa1
    };
    println!("{}\t{}\t{}\t{}\t", pessoa2.adulto, pessoa2.idade, pessoa2.nome, pessoa2.senha);

    fn criando_ob(nome : String, senha : String) -> Estru{ //criando uma função que devolve uma estrutura criada
       Estru {
           nome,
           senha,
           adulto : false,
           idade : 9
       }
    }
    let pessoa3: Estru = criando_ob(String::from("Gameprei"), String::from("kk slk"));
    println!("{}\t{}\t{}\t{}\t", pessoa3.adulto, pessoa3.idade, pessoa3.nome, pessoa3.senha);

    //tuple structs
    struct Tst(u8, u8, u8); //é uma tupple que pode gerar objetos semelhantes, sem perder a facilidade de trabalhar com tupples
    let tup1: Tst = Tst(0, 90, 0);
    println!("{}, {}, {}", tup1.0, tup1.1, tup1.2);

    //devemos ter cuidado quando formos passar structs para dentro de funções, pois elas não fazem copy, mas sim borrowing
    //ou seja, podemos acabar perdendo a ownership durante a passagem
    #[derive(Debug)] //permite o print da estrutura Retang
    struct Retang{
        h : u16,
        l : u16
    }
    fn area(q : &Retang) -> u16{
        q.h*q.l
    }
    let r1 = Retang { h : 16, l : 8 };
    let a = area(&r1); //continuamos com a ownership
    println!("{:?}, {}", r1, a);

    //em vez de utilizar uma função separada (area) podemos definir um método(como em OO) para a struct Retang
    impl Retang {   //impl (implementation) liga as funções abaixo como métodos de Retang
        fn area(&self) -> u16{ //devemos continuar a utilizar & antes de self, pois os métodos ainda podem roubar ownership
            self.h * self.l
        }
        fn can_hold(&self, r2 : &Retang) -> bool{ //vê se o segundo retângulo cabe dentro do primeiro
            self.h >= r2.h && self.l >= r2.l
        }
        fn square(lado : u16) -> Retang{ //função para criar um quadrado facilmente, utilizada como um construtor
            Retang {                    //não conseguimos acessá-la com o ponto depois de r1, visto que &self não é argumento
                h : lado,
                l : lado
            }
        }
    }
    let r2 = Retang::square(9); //acessando os métodos da struct Retang através de ::, assim como String::from
    println!("calculando a área através de um método: {}", r1.area());
    println!("r2 cabe em r1: {}", r1.can_hold(&r2));
    println!("{:#?}", r2); //{:#?} uma forma mais elegante de printar structs
}*/

/* fn main(){
    #[derive(Debug)]
    enum Conj{
        Par{ value : i32},
        Impar{ value : i32}
    }

    let a: Conj = Conj::Par { value : 22 };
    let b = Conj::Impar { value : 21 };
    println!("{:?} {:?}", a, b);
}*/

//UTILIZAÇÃO DO MATCH
/*fn main(){
    let t: i32 = 1;
    //match funciona como um switch case, onde _ seria o caso default, o escopo de match tbm pode retornar valores
    let n = match t {
        z if z+1 == 4 => z*3, //z recebe o valor de t e, se a condição for satisfeita, a expressão depois da seta é devolvida
        z if (z*2)%4 == 0 => z/2,
        z if (z/3) == 3 => z+100,
        _ => -77, //default case
    };
    println!("{}", n);

    match t {//match não permite ranges exclusivos (0..9)
        0..=9 => println!("{}", t+12), //qualquer valor dentro do range satisfaz a condição
        10 | 12 | 15 | 17 | 19 => println!("{}", t*4), //se for qualquer um dos valores a condição é atendida
        _ => print!("fora do esperado!")
    }

    let t: (i32, &str) = (32, "Hello World");
    match t {
        (32, y) => println!("{}", &y[0..5]),
        (x, "Hello") => println!("{}", x+8),
        _ => println!("fora de range!")
    } //nesse caso as variáveis x e y recebem os valores as quais correspondem e o outro termo garante se a condição é válida ou n

    let t: i32 = 80;
    match t {
        x @ 0..=20 => println!("o valor de x é: {}", x),
        y @ (25 | 30 | 50 | 60) => println!("o valor de y é: {}", y),
        z @ w if (w/3)%3 == 0 => println!("o valor de z é: {}", z),
        _ => println!("nenhuma condição atendida!")
    }
    //se alguma condição for atendida, à direita de @, a variável à esquerda recebe o valor de t

    let (x, y) = (false, 90);
    match (x, y){
         t @ (x2, _) if !x2 => println!("é {t:?}"),
         t @ (_, y2) if !((y2 % 9) == 0) => println!("kkkkk {t:?}"),
         (_, _) => println!("F")
    }
    //duas variáveis estão sendo avaliadas no match
}*/

//ENUMS
/*#[allow(unused)]
fn main(){
    enum Exem{ //enums são conjuntos de tipos compostos, structs, que estão relacionadas de alguma maneira
        Ex1(u32), //tupple struct
        Ex2,    //struct sem dado associado
        Ex3{ nome: String }  //struct com uma string associada
    }
    let z = Exem::Ex3{ nome: String::from("Luan") };
    match z { //match faz uma associação de z com o tipo da sua variante e executa a linha match que a corresponde!
        Exem::Ex1(_) => println!("É uma tupple struct!"),
        Exem::Ex2 => println!("É uma struct sem dado associado!"),
        Exem::Ex3{ nome: s } => println!("É uma struct com uma string associada! Que tem: {s}")
    } 

    enum FormasGeo{ //enum de formas geométricas
        Circ{ raio: f64 },
        Retang{ base: u32, altura: u32 },
        Quadrado{ lado: u64 }
    }
    let a = FormasGeo::Quadrado{
        lado : 50
    };
    let b = FormasGeo::Circ{
        raio : 5.5
    };
    let c = FormasGeo::Retang{
        base: 20,
        altura: 12
    };
    impl FormasGeo{ //implementação de métodos próprios às variantes do enum FormasGeo
        fn area(&self) -> f64{ 
            match self { //calcula a area de self a partir de qual variante de FormasGeo ela é
                FormasGeo::Circ {raio} => 3.14 * (raio*raio),
                FormasGeo::Quadrado {lado} => (lado*lado) as f64,
                FormasGeo::Retang {base, altura} => (base*altura) as f64
            }
        }
    }
    println!("{} {} {}", a.area(), b.area(), c.area());

    //existe um enum muito usado em rust, o Option, pois em rust não existe o conceito de NULL, que representaria algo que não existe
    //para representar a não existência Option é utilizado:
    fn divisao(x: f64, y: f64) -> Option<f64>{ //devolve um enum, que pode ser qualquer uma de suas variantes
        if y != 0.0 {
            Some(x/y) //a divisão pode ser realizada
        }
        else {
            None //y == 0.0, a divisão não pode ser realizada (NÃO EXISTE)
        }
    }

    let quociente = divisao(9.1, 1.2);
    match quociente {
        Some(d) => println!("A divisão resultou em: {:.5}", d), //:.5 limita as casas decimais a 5
        None => println!("Não existe!")
    }

    //formas de utilizar o if let com enums, para retirar os valores de dentro das structs variantes sem o uso de match
    #[derive(Debug)]
    enum Comida{
        Pizza(String),
        Torta{ nome: String, valor: u32},
        Agua
    }
    let pizza = Comida::Pizza(String::from("Calabresa"));
    if let Comida::Pizza(_) = &pizza{ //só entra na condição se for uma variante pizza
        println!("{:?}", pizza);
    }
    if let Comida::Agua = &pizza{ //só entra na condição se for uma variante Agua
        println!("Água faz bem pra saúde!");
    }
    else{
        println!("Não é H20!");
    }

    let torta = Comida::Torta {
        nome : String::from("Frango"),
        valor : 25
    };                                   //torta deve ser uma referência para usarmos nos futuros if let
    if let Comida::Torta{ nome, valor } = &torta{ //por ser uma torta passa na condição, além disso atribui valores  a nome e valor
        println!("{} {}", nome, valor);
    }

    if let Comida::Torta{ nome, valor : 25 } = &torta{ //nesse caso a condição só é aceita se torta tiver valor 25
        println!("{}; {:?}", nome, &torta);
    }
    if let Comida::Torta{ nome, valor : 30 } = &torta{
        println!("{}; {:?}", nome, &torta);
    }
    else{
        println!("Pizzarias diferentes!");
    }
    //existe também while let que tem a mesma função que o if let, mas se repetindo caso a condição continue verdadeira
    //tanto o if let quando o while let fazem, em suas condições, comparações e atribuições, comparações para ver se a variante do enum
    //corresponde, e os valores se predefinidos, e atribuições ao desconstruir o tipo enum e conseguir o conteúdo específico das variantes
}*/

//VEC E SEUS MÉTODOS
/*fn main(){
    let mut v: Vec<u8> = vec![2, 3, 4, 5]; 
    //vec! é uma macro que nos permite criar um Vec e escrever os seus primeiros elementos, como em um array estático
    println!("{:?}", v);
    v.push(10);
    println!("{:?}", v);
    println!("{:?}, {:?}", v.pop(), v); //v.pop() devolve o enum Option, pois caso tentemos retirar algo que não existe ele retorna None
    v.reverse(); //reverte a ordem do vec
    println!("{:?}", v);
    v.sort_unstable(); //ordena o vec
    println!("{:?}", v);
    let mut vec:Vec<i32> = vec![-69; 10]; //inicializa um vetor com 10 posições todas com o valor -69
    for i in &vec {
        print!("{} ", i);
    }
    println!("\ntamanho de vec: {}, capacidade alocada: {}", vec.len(), vec.capacity());
    vec.push(0);
    println!("tamanho de vec: {}, capacidade alocada: {}, vetor: {:?}", vec.len(), vec.capacity(), vec); //a capacidade dobra sempre que precisa de mais memória
    vec.resize(15, 9); //alterando a capacidade anterior e os valores que não estavam antes são inicializados com 9
    println!("tamanho de vec: {}, capacidade alocada: {}, vetor: {:?}", vec.len(), vec.capacity(), vec);
    vec.resize(21, 0);
    println!("tamanho de vec: {}, capacidade alocada: {}", vec.len(), vec.capacity());//o resize ainda faz com que a alocação seja o dobro da anterior

    let mut ar: Vec<u8> = Vec::new(); //criando um vetor vazio
    println!("{} {} {}", ar.is_empty(), ar.capacity(), ar.len());
    ar.push(3);
    println!("{} {} {}", ar.is_empty(), ar.capacity(), ar.len()); //a capacidade aparenta iniciar com 8 lugares

    //como visto antes com os vetores estáticos, só podíamos utilizá-los com um tipo apenas, mas usando enum:
    #[derive(Debug)]
    enum Tipos{
        Tipo1(u32),
        Tipo2(f64),
        Tipo3(String)
    }
    //a realidade é que o vetor continua tendo um tipo apenas, que é Tipos, mas pode apresentar suas variações diferentes
    let ar_tipos_dif: Vec<Tipos> = vec![Tipos::Tipo1(55), Tipos::Tipo2(5.5), Tipos::Tipo3(String::from("Hello World!"))];
    println!("{:?}", ar_tipos_dif);
    for h in &ar_tipos_dif{ //desmembrando os valores dentro dos tipos
        match h {
            Tipos::Tipo1(valor) => print!("{} ", valor),
            Tipos::Tipo2(valor) => print!("{} ", valor),
            Tipos::Tipo3(s) => print!("{} ", s)
        }
    }
    println!("");

    //tirando um a um os elementos de v
    let mut v = vec![1, 2, 3, 4]; 
    while let Some(x) = v.pop(){ print!("{:?} ", x); } 
    println!("{:?}", v.pop());

    let v: Vec<(String, i32)> = vec![(String::from("alo"), -69); 5]; //criando um vetor de tupples com a macro vec!
    println!("{:?}", v);
}*/

//HASHMAPS E SEUS MÉTODOS
/*use std::collections::HashMap; //precisamos importar collections de std
fn main(){
    let mut hm: HashMap<String, i32> = HashMap::new(); //hashmap de strings para inteiros
    hm.insert(String::from("Hello World!"), 55);
    hm.insert(String::from("Hello Luan!"), 100);
    hm.insert(String::from("vida boa ein"), 8800);

    for (key, value) in &hm{
        println!("Key: {} and Value: {}", key, value);
    }

    if let Some(a) = hm.get(&String::from("vida boa ein")){ //hm.get retorna Option<t>
        println!("{}", a);
    }
    if let None = hm.get(&String::from("opa fi")){
        println!("não está na map!");
    }

    hm.remove(&String::from("vida boa ein")); //removido da map
    if let Some(a) = hm.get(&String::from("vida boa ein")){
        println!("{}", a);
    }
    else{
        println!("não está na map!");
    }

    if let Some((a, b)) = hm.get_key_value(&String::from("Hello World!")){ //manda a tupla (key, value)
        println!("({a}, {b})"); //a é a chave, b é o valor
    }

    println!("pares em hm: {}", hm.len());

    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];

    let scores: HashMap<_, _> = teams.into_iter().zip(initial_scores.into_iter()).collect();
    //consiste em transformar ambos vetores em iterators e depois juntá-los através do método zip, fazendo com que cada elemento dos Vec se correspondam
    //após isso é utilizado o método collect que transforma esse iterator em par numa coleção, nesse caso especificamos uma HashMap
    for (x, y) in &scores{
        println!("{} {}", x, y);
    }
}*/

//LIDANDO COM ERROS, TRABALHANDO COM ARQUIVOS
/*fn main(){
    //podemos utilizar a macro panic! quando queremos que o programa encerre totalmente como um erro
    if false { panic!("pane no sistema"); } //troque false por true

    //existem em rust alguns metódos/funções que devolvem o enum Result, com ele podemos lidar com erros que recuperáveis, por exemplo ao abrirmos um arquivo
    //let file = std::fs::File::open("text.txt").expect("n consegui fi, aí é F");
    //open devolve Result, caso seja possível abrir devolve um Ok("pasta"), caso não devolve Err(ERRO)
    //por sinal os Erros em Rust também são enums, e os tipos de erros são variantes da mesma

    use std::{io::{self, Read, Write, ErrorKind}, fs::File};
//    let f = match File::open("text.txt"){ //tenta abrir o arquivo
//        Ok(file) => file, //retornando o arquivo para f
//        Err(error) => panic!("F total, erro: {}", error) //caso retorne um erro, panic!
//    };
//outra forma de lidar com o erro acima sem o uso do match é utilizar unwrap() ou expect(), que geram panic quando um erro é retornado
//    let f = File::open("text.txt").unwrap();

    let s: String = String::from("text.txt");
    //outra coisa que podemos fazer é criar um arquivo caso ele não exista, tratando o erro retornado quando o arquivo não existe
    {
       let _f = match File::open(&s){
          Ok(file) => file, //arquivo existia
          Err(error) => match error.kind(){ //busca saber qual foi o erro
                          ErrorKind::NotFound => match File::create(&s){ //caso erro seja NotFound tentamos criar um arquivo
                              //a função create também retorna entretanto um Result, que devemos tratar com um match
                                                      Ok(arquivo_criado) => arquivo_criado, //arquivo novo criado e retornado para f
                                                      Err(create_error) => panic!("F total: {:?}", create_error) //erro de criação de arquivo
                                                  },
                          other_error => panic!("deu pane no sistema: {:?}", other_error)
                          //qualquer erro diferente do NotFound vira panic!
                      }
      };
    }//quando sair desse escopo o arquivo será fechado!!
    
    {    //considerando que chegamos até aqui, podemos garantir que o arquivo text.txt existe!

        //depois de alguns teste, eu recomendaria que fosse usado sempre o File::options para qualquer operação com arquivos
        //isto porque arquivos que são apenas abertos não podem ser escritos, mas com o options isso é facilmente contornado
        //além de que podemos usar os métodos create, open, read, write e append com ele
        let mut f = File::options().append(true).open("text.txt").expect("falha ao abrir o arquivo");
        //podemos habilitar mais de uma opção ao mesmo tempo para o tipo de operação que vamos fazer com o arquivo
        //ou seja ler, escrever e append ao mesmo tempo, true. OBS: append habilita a escrita automaticamente
        //caso coloquemos apenas write no arquivo a escrita começa do início, diferente do append que começa do final
        f.write(b"just a text\n").expect("naum cunsigo escrever :O");
    }
    let uepa = leitura_file(&s).unwrap();
    println!("{uepa}");
    fn leitura_file(file: &str) -> Result<String, io::Error> //lendo o arquivo que criamos
    {
        let mut f = File::options().read(true).open(file)?; //se não conseguir abrir retorna o erro
        let mut s = String::new();
        f.read_to_string(&mut s)?; // se não conseguir ler retorna o erro
        Ok(s)
        //o operador ? funciona quando queremos fazer uma função que retorna o enum Result ou Option
        //ele funciona como um match que retorna os casos de erro, ou none, sem precisarmos tratá-los com um match
        //e que continua a execução da função caso seja um sucesso

        /*
        let mut s = String::new();
        File::open("text.txt")?.read_to_string(&mut s)?;
        Ok(s)

        //o trecho acima se comporta da mesma forma que o anterior, apenas mais compactado
        */
    }
}*/

//MODULARIZAÇÃO DE CÓDIGO, ESCREVENDO CÓDIGO EM ARQUIVOS SEPARADOS
/*fn main(){
    //ver o package teste_modu, contém exemplos de modularização em módulos e arquivos diferentes
}*/


//UTILIZAÇÃO DE TIPOS GENÉRICOS
/*#![allow(unused)] // faz com que os warnings de não uso desapareçam
use basics::*;
//os arquivos main.rs e lib.rs sçao definidos por padrão em rust com o nome da crate, projeto em si,
//então com a linha acima estamos adicionando todos os módulos, funções, métodos, structs, enums, traits no arquivo lib.rs
//perceba que isto apenas traz para o escopo de main aquilo que está fora de um mod, visto que para estes teremos que acessar pelos módulos
fn main()
{
    sla::sla2(); //acessando uma função dentro de um mod
    sla_man::sla_man_2(); //acessando uma função dentro de um mod em lib
    let a: Teste<i32> = Teste{ nome: String::from("Luan"), value: -90};
    println!("{}, {}, fn testando: {}", a.nome, a.value, a.testando());
    a.func("só uma string que implementa Debug".to_owned());
    let b = Teste{ nome: "lenza".to_string(), value: "lenza".to_string()}; //b será do tipo Teste<String>
    println!("{}", b.sao_iguais());
    
    let tw = Tweet {
                username: String::from("teupai"),
                content: String::from("sou eu? ou o mundo está cada vez mais louco? rs"),
                reply: false,
                retweet: false
            };
    let nw = NewsArticle {
        headline: String::from("Penguins win the Stanley Cup Championship!"),
        location: String::from("Pittsburgh, PA, USA"),
        author: String::from("Iceburgh"),
        content: String::from("The Pittsburgh Penguins once again are the best \
             hockey team in the NHL.") //a barra invertida permite continuar escrevendo na linha abaixo
    };
    println!("1 new tweet: {}", tw.summarize());
    nw.func();
    println!("{}", nw.summarize());
    nw.default_func(); 
    tw.default_func();

    basics::notify(&nw);
    let asd: i32 = 90;
    let dsa: String = String::from("oi, meu bro");
    let aa = (0, 0, 0);
    prt(&asd); prt(&dsa);
    prt2(&asd); prt2(&aa);
    prt3(&dsa);

    let maior = cmp(("alo", 89), ("alo", 90));
    println!("{:?}", maior);

    let a = Pair::new(180, 90);
    let b = Pair::new(10, 90);
    let c = Pair::new(10, 90);
    a.cmp_and_display(); b.cmp_and_display();
    if a == b || b==c { println!("yes"); }
    else { println!("no"); }

    let vida = Teste::<i32>{
        nome: String::from("vida boa"), 
        value: 90
    };
    let morte: Teste<i32> = Teste {
        nome: String::from("vida boa"),
        value: 89
    };
    println!("{:?}\n{:?}", vida, morte); //podemos printar o tipo teste, pois derivamos o Debug trait
    println!("sao iguais? {}\nvida eh maior? {}", vida == morte, vida > morte);
    //podemos fazer as comparações, pois derivamos os traits PartialEq( == ), PartialOrd( > )
}
//agora que chegamos ao ponto de implementar traits mais específicos para os nossos tipos, o derive pode ser melhor explicado
//derive é uma forma de automaticamente implementar alguns traits básicos, sem precisar fazer impl Debug for (...)
//do nosso tipo, a implementação obviamente será básica e teremos de implementar manualmente caso algo mais elaborado seja necessário
//com o derive abaixo estamos implementando ao tipo Teste<T> os traits Debug, PartialEq e PartialOrd
#[derive(Debug, PartialEq, PartialOrd)] 
struct Teste<T> { //criando uma struct com um tipo genérico T
    nome: String,
    value: T
}
impl<T> Teste<T>{ //implementação para qualquer tipo
    fn testando(&self) -> &T{
        &self.value
    //recebe &self para não retirar a ownership do objeto e devolve um &T, pois se trata de um tipo genérico o qual ainda não implementamos
    //a cópia do seu valor, ou seja, sem & estamos movendo sua ownership, para que isso não ocorra passamos apenas a referência do valor
    }
    fn func<G>(&self, other: G) //apenas func possui dois tipos genéricos, visto que G foi criado nela
        where G: std::fmt::Debug //o tipo do argumento recebido por other deve implementar Debug
    {
        println!("{other:?}");
    } 
}
impl Teste<String> { //impl apenas para o caso do T ser uma String
    fn sao_iguais(&self) -> bool{
        if self.nome == self.value{
            return true
        }
        false
    }
}
mod sla{ //não precisamos usar pub aqui, pois sla está no mesmo path que main.rs, logo eles são públicos entre si
    //está dentro de um módulo, então devemos utilizar a keyword pub para torná-la visível para
    //todos que estão em um path(caminho desde o diretório base da crate) maior ou igual a sla
    pub fn sla2(){
        println!("fala, fi");
    }
}*/
//a implementação do trait das outras structs utilizadas na main estão no arquivo lib.rs

//LIFETIMES E LIFETIMES GENÉRICOS
/*#[allow(unused)]
fn main(){
    //lifetime é o tempo que leva para a variável sair de escopo e ter seu valor "dropado", free
    //se tentamos usar uma referência a um valor que saiu de escopo vamos ver que o referente 
    //n viveu o suficiente, isto evita dangling references, ponteiros que apontam para memória que foi liberada
    let s = String::from("opa fiote");
    let b;
    {
        let t = "opa fi".to_string();
        b = longest(&s, &t);
        println!("{}", b);
        println!("{}", one_parameter(b));
    }
    //println!("{}", b);
    //se o println de b estivesse fora do menor escopo teríamos um erro,
    //pois o lifetime genérico será com base no tamanho do menor lifetime entre os
    //dois argumentos, nesse caso o lifetime de t
    
    fn longest<'x>(s: &'x str, t: &'x str) -> &'x str{
        //'x é um lifetime genérico que devemos passar para o compilador do Rust
        //assim ele pode saber quando o valor retornado pela função vai sair de escopo
        //'x será igual ao menor lifetime dos argumentos recebidos
        
        if s.len() > t.len(){
            return s
        }
        t
    }
    //existem 3 regras para a inferência dos lifetimes pelo compilador do Rust
    //1: para cada referência que é argumento da função será inferido um lifetime diferente
    //2: se houver apenas um lifetime inferido então o lifetime do output será o mesmo que o da entrada
    //3: se for um método, com self nos argumentos, o lifetime da saída será o mesmo que o do objeto que chamou o método
    fn one_parameter(s: &str) -> &str{
    //esse tipo de função n precisaria do lifetime 'a, por causa da regra 2 
        s
    }
    struct Sla<'a>(&'a str);
    impl<'a> Sla<'a>{
        //fn func(&self, s: &str) -> &str { s }
        //segundo a regra 3 o lifetime de um método segue o lifetime de &self, mas estamos
        //retornando s, logo o lifetime do retorno n bate com o de &self, e, então, temos um erro
        //tire os comentários da função para ver o erro
    }
}*/

//MAIN COM RESULT COMO RETORNO
/*use std::io::{self, prelude::*};
fn main() -> io::Result<()>{
    //essa forma de escrever a função main é bem útil quando temos várias funções que devolvem
    //Results, pois conseguimos usar o operador ? e descartar os milhares de unwraps
    //erros vão ser devolvidos pelo ? e sucessos vão devolver o que estiver em Ok()
    let mut s = String::new();
    let bytes_r = io::stdin().read_line(&mut s)?;
    let bytes_w = io::stdout().write(s.as_bytes())?; //mesmo efeito que a macro println!
    println!("Quantidade de bytes lidos e escritos: {bytes_r} {bytes_w}");
    Ok(()) //Precisamos devolver um Ok(()) ao final da main para dizer que ela encerrou o processo corretamente
    //semelhante ao return 0; de C
}*/

//UTILIZAÇÃO DO DEREFERENCE OPERATOR (" * ")
/*fn main(){
    let mut a = vec![0; 5];
    let x = &mut a[0];
    *x+=9;
    for j in &mut a
    {
        *j+=3; //para realizar operções carcterísticas de um inteiro, ou seja, com o inteiro 3, devemos transformar o tipo de j 
               //que no moemento é &mut i32 para um i32, através do operador *
    }
    println!("{:?}", a);

    //o * pode ser utilzado também em tipos que implementam o trait Deref, como Box e Rc, que vão ser vistos no futuro 
}*/

//WORKING WITH CLOSURES
/*use std::thread;
fn main() {
    //closures are functions like, but they can infer types capturing the enviroment
    let x = |x, y| { x + y };
    println!("{}", x(1, 1));
    //once the compiler infers te types of a closure, they cannot change
    // println!("{}", x(1.0, 2.0)); //uncomment to see the error

    //by default, closures make references, imut or mut, like:
    let mut v = vec![1, 2, 3];
    let borrow_imut = || { println!("{v:?}"); };
    borrow_imut(); //borrow_imut only needs a immutable reference

    let mut borrow_mut = || {
        v.push(4);
        println!("{v:?}");
    };
    borrow_mut(); //here we need a v mutable reference, the closure has to be mut too 

    //we can pass the ownership to the closure using the "move" keyword
    let takes_owner_n_give_back = move | x | {
        v.push(x);
        println!("{v:?}");
        v
    };
    // println!("{v:?}"); //v lost his ownership
    let v2 = takes_owner_n_give_back(5); //v2 received it back
    println!("{v2:?}");

    //some functions/methods can receive closures as arguments, just like:
    thread::spawn(|| println!("Hi, i'm a thread")).join().expect("Fail to spawn");

    //this can be done implementing the traits Fn, FnOnce or FnMut
    let nome = String::from("Bob Dylan");
    let add = |x: i32, y: i32| { x+y };
    let sub = |x: i32, y:i32| { x-y };
    let kk = Sla{ nome: nome.clone(), sla_manin: add };
    println!("{} {}", kk.nome, (kk.sla_manin)(9, 9));
    //kk.sla_manin = sub;   //for this one, we can't change the field, see the next one

    //here we are receiving a fn, instead of a closure, but we can pass a closure too!
    let mut kk2 = Sla2 {
        nome, 
        sla_manin: add
    };
    println!("{} {}", kk2.nome,(kk2.sla_manin)(9, 9));
    kk2.sla_manin = sub;
    println!("{}", (kk2.sla_manin)(10, 9));
}
struct Sla<F: Fn(i32, i32) -> i32>{
    nome: String,
    sla_manin: F //field as a closure, can't change 
}
struct Sla2<T>
{
    nome: String,
    sla_manin: fn(T, T) -> T //field as a fn, can change, it accepts closures too
}*/

//WORKING WITH ITERATORS
/*fn main() -> std::io::Result<()>{
    let mut v = vec![1, 2, 3];
    let iterator = v.iter();
    for j in iterator{
        print!("{j} ");
        //j += 1; //using the iter() method the iterator returns a immutable reference, doesn't take ownership
    }
    println!("\n{v:?}");

    let iterator = v.iter_mut();
    for j in iterator{
        *j += 1; //the iter_mut() method returns a mutable reference, doesn't take ownership  
        print!("{j} ");
    }
    println!("\n{v:?}");

    let iterator = v.into_iter();
    for mut j in iterator{
        j += 1; //the into_iter() method takes the ownership of v and return it's elements 
        print!("{j} ");
    }
    println!("");

    let v: Vec<i32> = vec![1, 2, 3, 4, 5];
    let sum: i32 = v.iter().sum(); //sum consumes an iterator and iterate over it, giving back the total sum of it's elements
    println!("{sum}");
    
    //the map() method receive an iterator and returns another one
    //changing each element by action of a closure
    //and the collect() turns the iterator into a collection, in this case a Vec
    let new_v: Vec<_> = v.iter().map(| x | x*100 ).collect();
    println!("{new_v:?}");

    //the filter() method generates another iterator, selecting elements from the original one for the new one
    let iterator = new_v.into_iter().filter(| x | (*x % 200) == 0 );
    for i in iterator{
        print!("{i} ");
    }
    println!("");

    //iter::zip() turns two colections into a iterator of pairs
    let (ar1, ar2) = ([1, 2, 3], [4, 5, 6]);
    let zipado = std::iter::zip(ar1, ar2);
    let mut zipado_v2 = zipado.clone(); //zipado will be consumed by the for
    for (i, j) in zipado{
        println!("i: {i}, j: {j}");
    }

    println!("{:?}", zipado_v2.next()); //next is the main method of the iterators, walking through the iterator and returning it's items
    let mut zipado_v2 = zipado_v2.skip(2); //used to walk through the iterator a certain "distance", number of iterations
    println!("{:?}", zipado_v2.next());

    Ok(())
}*/

fn main() -> std::io::Result<()> {
    
    Ok(())
}