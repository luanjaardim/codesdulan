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
    
    //podemos também fazer a desestruturação de uma struct em partes:
    struct Opa{x: f64, y: i32 }
    let opa = Opa{x: 2.0 , y: 5};

    let Opa{ x: a, y: b } = opa;
    let Opa{ x, y } = opa;
    println!("{a} {b} {x} {y}");
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
    sla_manin: fn(T, T) -> T //field as a function pointer, can change, it accepts closures too
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

//WORKING WITH SMART POINTERS
/*use std::rc::{Rc, Weak};
use std::cell::RefCell;
fn main(){
    let x = Box::<i32>::new(5); //the smart pointer Box allocates space in the heap
    let y = &5;
    println!("{} {}", x, *x); 
    println!("{} {}", y, *y);
    //Box implements the Deref trait, so it acts just like a reference further Box implements Drop trait
    //that deallocates the memory on heap when it goes out of the scope, and the memory on stack(the address itself)

    //we can use Box to implement recursive data types:
    enum List<T>{
        Node(T, Box< List<T> >), //whitout Box won't compile
        Null
    }
    let list = List::Node(10, Box::new(List::Node(20, Box::new(List::Null))));
    //the data above is a Node inside another Node until reach a Null, using Box for each heap alocation

    //walking on the list using if let
    if let List::Node(num, list2) = list{
        println!("{num}");
        if let List::Node(num2, list3) = *list2{
            println!("{num2}");
            if let List::Null = *list3{
                println!("the end of the list");
            }
        }
    }
    let mut n_list = List::Node(10, Box::new(List::Node(20, Box::new(List::Node(30, Box::new(List::Null))))));
    //walking on the list using while let
    while let List::Node(n_num, n_list2) = n_list{
        println!("{n_num}");
        n_list = *n_list2; //acessing the element in Box
    }
    println!("end of the list");

    //Box still can't handle with the next problem, we want to acess 'a' with 'b' and 'c'
    //but Box own the address it's pointing to, so to do that we have Rc<T> smart pointer...
    // let a = List::Node(1, Box::new(List::Null));
    // let b = List::Node(2, Box::new(a));
    // let c = List::Node(3, Box::new(a));

    use List_Rc::{Node, Null};
    enum List_Rc<T>{
        Node(T, Rc<List_Rc<T>>),
        Null
    }
    let a = Rc::new(Node(1, Rc::new(Node(2, Rc::new(Null)))));
    let b = Rc::new(Node(10, Rc::clone(&a)));
    let mut c = Rc::new(Node(20, Rc::clone(&a)));
    
    //walking through the c list
    while let Node(val, list) = &(*c){ //we are catching the reference of what is inside Rc with the while let
        println!("{val}");
        c = Rc::clone(list); //getting the reference of inner lists
    }
    println!("end of the list");

    //the problem with the Rc smart pointer is that we can't change the values it's apointing to
    let a = Rc::<f64>::new(1.0);
    // *a += 2.0;
    println!("{a}");

    //a way to have multiple owners and possible change the values on heap is using RefCell     
    //the RefCell smart pointer can borrow some value as mutable, or immutable, even if it's immutable
    let var = RefCell::new(2); //var is immutable
    {
    let mut refe = var.borrow_mut(); //refe needs to be mut to receive a mutable reference
    *refe += 2;
    }
    let refe_immut = var.borrow(); //creating a immutable reference
    println!("{}", *refe_immut);
    //RefCell has a particularity to "break" the borrowing rules of rust at the compile time,
    //instead it should respect them at the runtime...
    //at any given time, you can have either (but not both) one mutable reference or any number of immutable references
    //if, at runtime, we break this rule so the program panic, this is the reason that refe is inside an inner scope
    //when it goes out refe is deallocated, then we can immut borrow to refe_immut

    //another way to use RefCell is along with Rc:
    use List_RefRc::{Dot, Nil};
    #[derive(Debug)]
    enum List_RefRc<T>{
        Dot(T, Rc< RefCell< List_RefRc< T > > >),
        Nil
    }
    let list = Dot(10, Rc::new(RefCell::new(Dot(20, Rc::new(RefCell::new(Nil))))));
    let list_end = Dot(30, Rc::new(RefCell::new(Nil)));
    if let Dot(_, n) = &list{
        //n -> &Rc<RefCell<Dot>>
        //(*n) -> Rc<RefCell<Dot>>
        //(*(*n)) -> RefCell<Dot>
        //((*(*n)).borrow()) -> Ref<Dot> //Ref<> acts like an immut reference
        //(*((*(*n)).borrow())) -> Dot
        //&((*(*n)).borrow()) -> &Dot
        if let Dot(_, n2) = &(*((*(*n)).borrow())){
            //n2 -> &Rc<RefCell<Nil>>
            //(*n2) -> Rc<RefCell<Nil>>
            //(*(*n2)) -> RefCell<Nil>
            //(*(*n2)).borrow_mut() -> RefMut<Nil> //RefMut<> acts like a mut reference
            let mut tmp = (*(*n2)).borrow_mut();
            *tmp = list_end;
        }
    }
    println!("{list:?}");

    //but, now, using the RefCell with the Rc smart pointer we can create a cycle
    //that has, as consequence, a memory leak:
    use MemLeak::{Ta, Tb};
    #[derive(Debug)]
    enum MemLeak{
        Ta(RefCell< Rc< MemLeak > >),
        Tb
    }
    let m1 = Rc::new(Ta(RefCell::new(Rc::new(Tb))));
    let m2 = Rc::new(Ta(RefCell::new(Rc::clone(&m1))));    
    if let Ta(refe) = &*m1{
        *(*refe).borrow_mut() = Rc::clone(&m2);
    }
    //println!("{m1:?}");  //uncomment this to stackoverflow
    
    //now we have a cycle, a memory leak will occurs
    //a way to evade this is by the use of Weak<T>, a downgrade of Rc
    //Weak<T> does not own the data it apoints to, and will stay alive
    //while the strongers(Rc) are alive, so:

    //thinking like a tree:
    #[derive(Debug)]
    struct Noddle{
        parent: RefCell< Weak< Noddle > > ,//weak conection with it's parent
        child: RefCell< Vec< Rc< Noddle > > >    //strong conection with it's child
    }
    //if a child goes out of scope, the parent can remain
    //but if the parent goes out the child can't remain allocatedd

    let con1 = Rc::new(Noddle{ parent: RefCell::new(Weak::new()), child: RefCell::new(vec![]) });
    let con2 = Rc::new(Noddle{ parent: RefCell::new(Weak::new()), child: RefCell::new(vec![Rc::clone(&con1)])} );
    *((*con1).parent.borrow_mut()) = Rc::downgrade(&con2);
    println!("{con1:?}\n{con2:?}");

    //now we still have a cycle, but weak from one direction
    //when a cyle of Rc's occurs both strong_count will permanently be 1, because
    //they point each other, so the memory won't be deallocated
    //but working with Weak that can't happen, Weak doesn't guarantee that what he is 
    //pointing will continue allocated, as the Rc, but while there are Rc's pointing
    //to that place, Weak will exist.
    println!("{} {}", Rc::strong_count(&con2), Rc::weak_count(&con2)); 
    println!("{} {}", Rc::strong_count(&con1), Rc::weak_count(&con1));
    
    //how do we know that weak still points to a valid address?
    //the method upgrade:
    println!("{:?}\n{:?}", (*((*con1).parent.borrow())).upgrade(), (*((*con2).parent.borrow())).upgrade()) 
    //upgrade returns an option, if weak is a dangling pointer it returns None
}*/

//WORKING WITH THREADS
/*use std::{io, thread, time::Duration, sync::{mpsc, Mutex, Arc}};
fn main() -> io::Result<()>{
    //THIS TOPIC HAS SUBTOPICS, COMMENT THE OTHERS TO RUN BEFORE RUN    
    /*//TOPIC 1:
    thread::spawn(|| {
        for i in 1..=9{
            println!("printing from new thread the number: {i}");
            thread::sleep(Duration::from_millis(1));
        }
    });
    for i in 1..=5{
        println!("printing from main thread the number: {i}");
        thread::sleep(Duration::from_millis(1));
    }
    //here we can see that depending how the scheduler from OS
    //alternates the thread executing we have a different result
    //but, in major, the spawned thread doesn't complete all it's iterations
    //that's because main ended first and everything inside got deallocated
    */
    /* //TOPIC 2:
    let ret = thread::spawn( || {
        for i in 1..=9{
            println!("printing from new thread the number: {i}");
            thread::sleep(Duration::from_millis(1));
        }
    });
    for i in 1..=5{
        println!("printing from new thread the number: {i}");
        thread::sleep(Duration::from_millis(1));
    }
    ret.join().unwrap(); 
    //when called .join() the main cannot continue it's execution
    //main is waiting for the end of spawned
    println!("end of the thread spawned execution, main continues");
    */
    /*//TOPIC 3:
    thread::spawn( || {
        for i in 1..=9{
            println!("printing from new thread the number: {i}");
            thread::sleep(Duration::from_millis(1));
        }
    }).join().unwrap(); 
    //this code diferently from the above has the join before the for
    //loop in main, this loop only executes at the end of thread execution
    for i in 1..=5{
        println!("printing from new thread the number: {i}");
        thread::sleep(Duration::from_millis(1));
    }*/
    /*//TOPIC 4:
    //now we are working on a way of communication between threads
    let v = vec![1, 2, 3];

    let ret = thread::spawn(move || { println!("{v:?}"); v });
    //here we use the move keyword to transfer the ownership of v to the thread
    //println!("{v:?}"); //v was moved

    let v = ret.join().unwrap(); //but we can bring v back to main
    println!("{v:?}"); //and then get it's onwership in main again
    */
    /*//TOPIC 5:
    let (tx, rx) = mpsc::channel(); //mpsc -> multiple producers, single consumer
    //creating a channel of comunication between threads
    //it returns a tupple, the first is a producer and the second a consumer
    let mut v = vec![1, 2, 3];
    thread::spawn(move || { //moving v and tx
        v.push(4);  
        tx.send(v).unwrap();//waiting for someone to receive the message
        //println!("{v:?}"); //v was moved at send
    });
    let v_recv = rx.recv().unwrap();//waiting for someone to send the message

    //send() will return a Err if the receiver was dealocated.
    //recv() will return a Err if the sender was dealocated.
    //note that if none sender send a message recv() won't stop waiting,
    //we can use try_recv() for just attempt to receive the message,
    //if there wasn't any message on the channel the thread continues it's execution
    
    println!("{:?}", v_recv);

    let (tx, rx) = mpsc::channel();
    thread::spawn(move || {
        for val in v_recv{  //iterating over the elements in v_recv and sending them
            thread::sleep(Duration::from_secs(1));
            tx.send(val).unwrap();
        }
    });
    for receive in rx{ //using rx as a iterator, it will wait for messages just like .recv()
        println!("Received: {receive}");
    }
    */
    /*//TOPIC 6:
    let (tx, rx) = mpsc::channel();
    let tx2 = tx.clone(); 
    //as mentioned above, mpsc -> multiple producers so we can clone tx
    
    thread::spawn(move || { //thread using tx
        for i in 1..=5{
        let s = format!("from tx:  {i}");
        tx.send(s).unwrap();
        thread::sleep(Duration::from_millis(1));        
        }
    });
    thread::spawn(move || { //thread using tx2
        for i in 1..=5{
        let s = format!("from tx2: {i}");
        tx2.send(s).unwrap();
        thread::sleep(Duration::from_millis(1));        
        }
    });
    for received in rx{ //receiving messages from both threads
        println!("{received}");
    }*/
    /*//TOPIC 7:
    //another way of communication between threads, without sending or receiving messages,
    //is through shared memory and manipulating it, one at time.
    let m = Mutex::new(0); 
    //mutex protects a shared memory from being accessed by multiple threads
    {
        *m.lock().unwrap() += 10; 
        //when we want to access that region we need to lock() the mutex,
        //if someone is already inside the shared region the thread wait for it's turn
        //a good pratice is unlock() the mutex, but in rust when the variable that
        //locked the mutex goes out of scope the mutex is unlocked
    }
    println!("{}", *m.lock().unwrap());

    //when working with threads, it's required that any thread can access that shared memory,
    //one at time, so every thread must have the ownership of the mutex, but Rc smart pointer
    //does not the job with multithreading, for that we have Arc, the version of Rc that works with threads:
    let m = Arc::new(Mutex::new(0));
    //now we can share the address of the shared memory
    let mut v_handle = vec![];
    for id in 0..10{
        let shared_add = Arc::clone(&m);
        let handle = thread::spawn(move || {
            println!("thread {id} in execution...");
            let mut num = (*shared_add).lock().unwrap(); //adds the id to the shared memory 
            *num += id;
            drop(num); //dropping num and unlocking the mutex, we could just let it goes out of scope too
            //another option is: Mutex::unlock(num), does the same of dropping the guard(num) and unlock it
            id
        });
        v_handle.push(handle);
    }
    for handle in v_handle{
        println!("thread {} finished it's execution!", handle.join().unwrap());
    }
    println!("at the end we have the sum: {}", (*m).lock().unwrap());
    //a important thing to see is that Mutex, juts like the Arc and Rc, is similar to RefCell,
    //guaranteeing interior mutability, so we have to be cautious when using them together
    //because there are chances of deadlock, two threads that wait for each other permanently
    */
    /*//TOPIC 8:
    //we can use both given ways of communicating between threads
    //a simple fatorial with threads:
    let mutex = Arc::new(Mutex::<u128>::new(1)); //updating the final result at each thread
    let (tx, rx) = mpsc::channel(); //communicating the end of each threads execution

    println!("Please enter a number: ");

    let mut s = String::new();
    std::io::stdin().read_line(&mut s).expect("read error");
    let fact: u8 = match s.trim().parse() {
        Ok(num) => num,
        Err(_) => { println!("Not a u8!"); std::process::exit(1); }
    };
    
    if fact < 2 { *((*mutex).lock().unwrap()) = 1; }
    else if fact > 20 { println!("too large."); std::process::exit(0); }
    else { 
        for id in 2..=fact{
            let mutex_thread = Arc::clone(&mutex);
            let tx_thread = tx.clone(); 
            thread::spawn(move || {
                *((*mutex_thread).lock().unwrap()) *= id as u128;
                tx_thread.send(id).unwrap();
            });
        } 
    }
    drop(tx); //dropping tx because rx will continue to wait for a message from him
    for received in rx{
        println!("thread {received} finished.");
    }
    println!("{fact}! = {}", (*mutex).lock().unwrap());
    //without the join() we can make the execution order more random,
    //that's because the main thread won't wait for the end of each thread execution,
    //and will start to create all the threads, just then wait till all threads are finished
    */
    Ok(())
}*/

//ADVANCED FEATURES IN RUST

//ADVANCED FEATURES IN RUST -> UNSAFE RUST:
/*//in Rust we have unsafe blocks to write codes that have at least:
//static mut operations
//raw pointers dereference operations
//calls to unsafe functions or methods
//implementations of unsafe traits
//acess to unions fields(i won't cover that)

extern "C"{ //a simple way to use C functions in Rust
    fn abs(x: i32) -> i32;
}
//a more sofisticated way to bring our own code from C
//on ctest project folder

static mut COUNTER: i64 = 0; 
//static variables are the global variables of Rust
//they can be mut, but mutate them is a unsafe operation
const CONST_VALUE: i64 = 10;
//they are different from const, everywhere that mentionates the const
//will be replaced with it's value at compile process, a static acts has it's own
//address like a true variable and can have it's value read and modified(unsafe),
//both needs a explict type definition at declaration.

fn main() -> std::io::Result<()> {
    let mut num: i64 = -5;
    unsafe { 
    unsafe_work(&mut num); 
    println!("{num} {}", abs(num as i32)); //extern C functions must be called inside unsafe blocks
    
    println!("COUNTER value: {}", COUNTER);
    mutate_static();
    println!("COUNTER value: {}", COUNTER);    
    } //unsafe

    //unsafe{ //working with raw pointers and it's methods
    
    //}
    Ok(())
}
unsafe fn unsafe_work(pnt: &mut i64){
//unsafe functions only can be called inside unsafe blocks
    let pnt1 = pnt as *const i64; //create raw pointers isn't a unsafe operation
    let pnt2 = pnt as *mut i64;
    unsafe {
        *pnt2 = -10; //dereference raw pointers is a unsafe operation
        println!("{:?} {:?} {}", pnt1, pnt1.offset(1), *pnt2); 
    }
} 
unsafe fn mutate_static(){
    unsafe { COUNTER += CONST_VALUE; }
}

//traits can be unsafe too:
pub unsafe trait Foo{
    fn bar(){ println!("unsafe code lays here"); }
}
pub struct Fuba<T>(T);
unsafe impl<T> Foo for Fuba<T> {} 
//so the implementation for the Foo trait must be unsafe too 
*/

//ADVANCED FEATURES IN RUST -> ADVANCED TRAITS:
/*//traits are very used in Rust to define properties that a certain
//group respect and implements, some advanced topics about traits 
//will be covered here:

trait AssociatedTrait{
    type AssType;
    //this trait has a associated type, some trait of std has it
    //inside it's definition, that type is connected with
    fn greatest_of_greatests(&mut self, vector: Self::AssType) -> i32;
    fn new(first: i32);
}
struct MyStruct{
    v: Vec<i32>, 
    greater: i32 
}
impl MyStruct{
    fn new(first: i32) -> MyStruct{
        MyStruct{
            v: vec![first], greater: first
        }
    }
    fn update_greatest(&mut self){
        let mut max = (*self).v[0];
        for i in &(*self).v{
            if max < *i {
                max = *i; 
            }
        }
        (*self).greater = max;
    }
}
impl AssociatedTrait for MyStruct{
    //don't matter the type of T, AssType must be a Vec<T>
    type AssType = Vec<i32>;
    fn new(first: i32){
        println!("this function exists just for explanation about syntax to disambiguation! {first}");
    }
    fn greatest_of_greatests(&mut self, mut vector: Self::AssType) -> i32 {
        (*self).update_greatest();
        vector.sort_unstable();
        if self.greater > vector[vector.len() - 1]{
            return self.greater
        }
        vector[vector.len() - 1]
    }
}

struct Point(i32, i32);
impl std::fmt::Display for Point{ //implementing the way to transform Point in String to be Displayed
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "({}, {})", self.0, self.1)
    }
}
//CustomPrint is a super trait, only types that implements Display can implement CustomPrint
trait CustomPrint: std::fmt::Display {
    fn custom_print(&self);
}
impl CustomPrint for Point{
    fn custom_print(&self) {
        let s = self.to_string(); //a type that implements display, has .to_string() method
        println!("*{}*", "*".repeat(s.len() + 2)); //************                  */
        println!("*{}*", " ".repeat(s.len() + 2)); //*          *                  */
        println!("* {s} *");                       //* a string *                  */
        println!("*{}*", " ".repeat(s.len() + 2)); //*          *                  */
        println!("*{}*", "*".repeat(s.len() + 2)); //************                  */
    }
}

//a important thing to know about traits is that we cannot implement a std trait
//to an std type, but we can implement our trait for std types or std traits for our types, so:
//impl std::fmt::Display for Vec<String> //won't work

//a solution is to use a struct as a Wrapper:
struct Wrapper(Vec<String>);
impl std::fmt::Display for Wrapper{
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "[{}]", self.0.join(", "))
    }
}
//unfortunately, with this we can't use Vec<> methods directly
//a solution could be implement the Deref trait:
impl std::ops::Deref for Wrapper{
    type Target = Vec<String>;
    fn deref(&self) -> &Self::Target {
        &(*self).0
    }
}
impl std::ops::DerefMut for Wrapper{
    fn deref_mut(&mut self) -> &mut Self::Target { //Target from the Deref trait
        &mut (*self).0
    }
}
fn main(){
    let mut st1 = MyStruct::new(1);
    st1.v.push(2);
    st1.v.push(5);
    st1.v.push(6);
    st1.v.push(8);
    let v = vec![5, 6, 2, 9];
    let greater = st1.greatest_of_greatests(v);
    println!("{greater}");
    // AssociatedTrait::new(5); //how to distinguish new from impl Mystruct and impl AssociedTrait for MyStruct?
    //calls the function AssociatedTrait implemented for MyStruct 
    <MyStruct as AssociatedTrait>::new(5);

    let point = Point(89, 68);
    point.custom_print();

    let mut wrap = Wrapper(vec!["hello".to_owned(), "world!".to_owned()]);
    println!("{}", wrap);
    (*wrap).push("another".to_owned());
    (*wrap).push("hello!".to_owned());
    (*wrap).sort_unstable();
    println!("{}", wrap);
}*/

//ADVANCED FEATURES IN RUST -> ADVANCED TYPES:
/*use std::rc::Rc;
use std::cell::RefCell;
type MyType<T> = Option<Rc<RefCell<T>>>;
//the type keyword can be used as a easily way to write a
//large type as we have above, for now on they mean the same thing,
//a example is the std::io::Result<T> that is an alias for:
//std::result::Result<T, std::io::Error>
fn main() -> std::io::Result<()> {
    /*let op = Some(5);
    let var = match op{
        Some(_) => 5,
        None => "hello"
    };*/
    //when using a match we aren't able to have different types for each
    //match arm, that's because rust must know at compile time the var's type, but:
    let mut cnt = 0;
    let res = loop{
        cnt += 1;
        //but here we have two arms with different types, continue isn't a i32,
        //he has the never type( ! ), ! can *never* have a value, that allows
        //rust infer that the only possible value for var is a i32, that will be it's type,
        //another example is the panic! macro that also has never type
        let var = match cnt {
            0..=10 => continue,
            x => x
        };
        break var
    };
    println!("{res}");

    //dynamically sized types are types that we don't know the size at compile time
    //we have the reserved keyword "dyn" to especify them, a example is the str type
    //"just a word" and "word" have different size, but for a &str they have the same
    //size = a pointer to the begin of the word and the len of the word
    //with this we can know the size, at compile time, for a &str, even if the 
    //amount of data that Rust will alocate to keep these bytes is unknown

    //*see the lib.rs at test_modules crate for another example*//
    Ok(())
}*/

//ADVANCED FEATURES IN RUST -> ADVANCED FUNCTIONS AND CLOSURES:
/*fn some_func<F: Fn(i32) -> i32 >(f: F, v: i32) -> i32 { f(v) }
fn another_func(f: fn(i32) -> i32, v: i32) -> i32 { f(v) }
fn doubler(x: i32) -> i32 { x*2 }

//when exploring for the first time closures, i wasn't able to modify a
//field of a struct that receives a closure, a way to do that is to use:
type Inner = Box<dyn Fn() -> i32>;
struct Teste(Inner);

//another funcionality is the capacity to return closures from a function/closure
type ClosRet<T> = Box<dyn Fn(T, T) -> T>;
fn return_clos<T>() -> ClosRet<T>
    where T: std::ops::Add<Output = T>
{
    Box::new(|x: T, y: T| x+y)    
}

fn main(){
    let mut ret = some_func(|x| x+1, 2);
    println!("receiving a closure with some_func: {ret}");
    ret = some_func(doubler, 4);
    println!("receiving a function pointer with some_func: {ret}");
    ret = another_func(doubler, 4);
    println!("receiving a function pointer with another_func: {ret}");
    ret = another_func(|x| x+1, 2);
    println!("receiving a closure with another_func: {ret}");
    
    let mut sla = Teste(Box::new(|| 5));
    println!("{}", (*sla.0)());
    sla.0 = Box::new(|| 4); //modifying the field that contains a closure
    println!("{}", (*sla.0)());    

    let sla = || { |x| x+1 }; //a closure that returns another closure
    let sla2 = sla();
    println!("{}", sla2(99));

    let clos = return_clos(); //a function that returns a add closure
    println!("{}", clos(20, 30));
    let clos = return_clos(); //the type of the closure is generic, until the first call
    println!("{}", clos(2.1, 3.98));
    //println!("{}", clos(2, 3)); //error
    
    let v: Vec<_> = (1..=10).into_iter().map(doubler).collect();
    //map can receive either a closure or a function
    println!("{v:?}");
}*/

//ADVANCED FEATURES IN RUST -> MACROS:
/*//macros are funcionalities in Rust that can "expand" creating more code
//during compile time, at some point they are very similar to functions,
//but this atribute make them useful for a lot of other things that won't
//be possible with functions, however they are verboser and hard to write

//a simple macro inits with a macros_rule! and it's name, without the !:
#[macro_export] //exporting for use
macro_rules! first_macro {
    //inside a macro we have the rules of that macro that acts like a match arm,
    //when the condition for the rule is valid the invocation is replaced by the expansion
    ($e:expr) => {
        $e * 5
    };
    //a variable inside a rule has a $ and a specifier :(specifier) that determines the kind
    //of the capture: expr for expressions, item for items(functions, struct, mod, impl, ...), ...
    
    ($e:expr, $x:expr) => {
        $e + $x
    };
    //now we have a rule that receive 2 expressions, if we use more than one expression inside
    //our macro the first tule won't validate, then we go for the second rule, and then goes
    
    ($e:expr, $($x:expr),* ) => { 
        {
            let mut sla = $e; //the first expression 
            $(
                sla *= $x; //all other expressions
            )*
            sla //return value
        } //as we are using ';' at some lines we need to create a new scope
    };
    //at this rule we have a repetition, $( ... ),* represents that:
    //what's inside $( ... ) gonna repeat
    //  , -> with a ',' as a separator => 1, 2, 3, 4 ...
    //  * -> 0 or more times 
    //so this will repeat untill there isn't any expressions to put in $x
    //don't matter how many expressions we pass to our macro, this rule
    //will validate...

    //for the separator we could have ';' or none, and for '*' there is other options:
    //? -> indicating at most one repetition
    //+ -> indicating one or more repetitions
}

//attempt to make a "scanf" in Rust with macros
#[macro_export]
macro_rules! scanf{
    ( $( $x:ty ),* ) => {
    //receiving a serie of types
        {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).expect("Fail to read");
        //reading from stdin the string to parse, with ", " between the elements

        let mut iter = s.trim().split(", ").into_iter();
        ( //begin of the return tuple
            $(
            iter.next().expect("Fail at next").parse::<$x>().expect("Fail to parse") //parse matching the type received
            ),* //the ',' to separate the elements in the tuple
        ) //return tuple
        }
    };//end of the rule
}//end of the macro

fn main(){
    let mut sla = first_macro!{1};
    println!{"{sla}"};
    sla = first_macro!(5, 5);
    println!("{sla}");
    sla = first_macro![2, 2, 2, 2, 2, 2];
    println!["{sla}"];
    //macros accepst {}, () and [] to delimitate

    println!["Enter a f64, i32, String, char, bool. (with ' ,' between them)"];
    let output = scanf!(f64, i32, String, char, bool);
    //the input must respect the order of the types
    //and the input format: (f64), (i32), (String), (char), (bool)
    println!("{output:?}");
}*/

//BOXING STRUCTS IN ENUMS AND THEN UNBOXING
/*//putting that struct in a box to unbox it latter :0
trait Converter<T>{
    fn transmutate(&self) -> T;
//when implmenting Converter we must especifie the generic T
//as the same type of the struct we are implementing, being in a Converter method 
//we can acces it's fields and generate a new struct with the same fields(tricks)
}

#[derive(Debug)]
struct Tipo1(i32, i32);
impl Converter<Tipo1> for Tipo1{
    fn transmutate(&self) -> Tipo1{
        Tipo1(self.0, self.1)
    }
}
#[derive(Debug)]
struct Tipo2(f64);
impl Converter<Tipo2> for Tipo2{
    fn transmutate(&self) -> Tipo2{
        Tipo2(self.0)
    }
}

use Wrapper::Con;
enum Wrapper<T>{ 
//wrapper is a enum that can store any struct that implements Converter<T>
//with it we can get the struct back unboxing the Wrapper and then transmuting it's content
    Con(Box<dyn Converter<T>>)
}
impl<T> Wrapper<T>{
    fn new(stru: Box<dyn Converter<T>>) -> Wrapper<T>{
        Con(stru)
    }
    fn unboxing(self) -> Box<dyn Converter<T>>{
        let Con(inner) = self;
        inner
    }
}

fn main(){
    let wrap1 = Wrapper::new(Box::new(Tipo1(1, 2)));
    let type1 = wrap1.unboxing() //a Box to a struct that implements Convert<T>
                     .transmutate(); //acessing Convert<T> methods
    //don't matter what struct is unboxed, that must implement Convert<T>,
    //so we can call the transmutate method, and then access the impl
    //of the especifc type that the Box is referring to get a new struct
    
    let wrap2 = Wrapper::new(Box::new(Tipo2(1.2)));
    let type2 = wrap2.unboxing().transmutate(); 
    println!("{type1:?} {} {}", type1.0, type1.1);
    println!("{type2:?} {}", type2.0);

    //making a new type and then impl Convert<T>
    #[derive(Debug)]
    struct NewStruct{
        float: f64,
        int: i32,
    }
    impl NewStruct{
        fn sum(&self) -> f64{
            self.float + (self.int as f64)
        }
    }
    impl Converter<NewStruct> for NewStruct{
        fn transmutate(&self) -> NewStruct{
            NewStruct{
                float: self.float,
                int: self.int
            }
        }
    }
    let x = Wrapper::new(Box::new(NewStruct{ float: 5.5, int: 9 }));
    let y = x.unboxing().transmutate();
    println!("{} {} {}", y.float, y.int, y.sum())
}*/

fn main(){
    
}
