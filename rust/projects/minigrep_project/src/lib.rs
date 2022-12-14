pub use std::env; //leitura de argumentos por linha de comando 
pub use std::fs; //operações em arquivos
pub use std::process; //para encerrar o processo com exit(1)
pub use std::error::Error; //para retornar erros na função run

#[derive(Debug)]
pub struct Config{ pub filename: String, pub word: String, pub case: bool }
//filename: path do arquivo de busca
//word: palavra em busca
//case: busca sensitiva ao CAPS_LOCK(maiúsculas != minúsculas) ou não

impl Config{
    //recebe os argumentos da linha de comando e retorna um objeto Config

    pub fn new(args: &[String]) -> Result<Config, &'static str> {
        if args.len() < 3 {
            return Err("Argumentos insuficientes")
        }                                 //clone cria uma nova string, idêntica
        let c: Config = Config {filename: args[1].clone(), //usa clone para n pegar a ownership
                                word: args[2].clone(),  //usa clone para n pegar a ownership
                                case: env::var("CASE").is_err() //se for um erro retorna true, ou seja n passou CASE
                                };
        Ok(c)
    }

    pub fn build(mut args: impl Iterator<Item = String>) -> Result<Config, &'static str>{
        //using iterators to get the args from command line
        let (filename, word): (String, String);
        args.next();    
        filename = match args.next() {
            Some(filename) => filename,
            None => return Err("Argumentos insuficientes")  
        };
        word = match args.next() {
            Some(word) => word,
            None => return Err("Argumentos insuficientes")  
        };
        let case = env::var("CASE").is_ok();
        let c = Config{
            filename,
            word,
            case
        };
        Ok(c)
    }
}

//onde corre toda a lógica do cod
pub fn run(config: Config) -> Result<(), Box<dyn Error>>{ 
    let mut cnt = 1;
    let file = fs::read_to_string(config.filename)?; //lendo o arquivo passado como argumento, retorna erro com '?'
    let encountered;
    if config.case {
        encountered = search(&config.word, &file); 
    }
    else{
        encountered = search_case_insensitive(&config.word, &file);
    }

    for &linhas in &encountered{ //printando a linhas encontradas
        println!("{}: {}", cnt, linhas);
        cnt+=1;
    }
    Ok(()) //execução ocorreu bem
}

fn search<'a>(word: &str, contents: &'a str) -> Vec<&'a str>{
    let mut result: Vec<&str> = Vec::new(); 

    //transforma em um iterador de linhas, como &str, do arquivo, por isso a saída tem o lifetime dele
    for i in contents.lines(){ //itera sobre as linhas
        if i.contains(word) { //vê se possui ou não a palavra
            result.push(i); //adiciona a linha ao vetor de saída
        }
    }
    result
}

fn search_case_insensitive<'a>(word: &str, contents: &'a str) -> Vec<&'a str>{
    //para realizar não distinção de minúsculas para maiúsculas transformamos word e as linhas em lower_case(minúsculas)

    let mut result: Vec<&str> = Vec::new(); 
    let word = word.to_lowercase(); 

    for i in contents.lines(){
        if i.to_lowercase().contains(&word){ //checa se a palavra está linha, em lower_case
            result.push(i); //não devemos modificar i, as linhas, apenas usamos elas em lower_case para a checagem
        }
    }
    result
}

//run2 and search2 were implemented after the another ones, the build in impl Config too
//using them at the first implmentation of the code in main
pub fn run2(config: Config) -> Result<(), Box<dyn Error>>{
    let mut cnt = 1;
    let content = fs::read_to_string(config.filename)?;
    let encountered = search2(&config.word, &content, config.case);
    for line in encountered{
        println!("{cnt}: {line}");
        cnt += 1;
    }
    Ok(())
}
fn search2<'a>(word: &str, content: &'a str, case: bool) -> Vec<&'a str>{
    if case {
        let word = word.to_lowercase();
        return content.lines()
                      .filter(|line| line.to_lowercase().contains(&word))
                      .collect()
    }
    else {
        content.lines()
               .filter(|line| line.contains(word))
               .collect()
    }
}

//TESTES//
#[cfg(test)]
mod tests{
    use super::*;

    #[test]
    fn testando(){
        let content = fs::read_to_string("file.txt").unwrap();
        let a = "To";
        assert_eq!(vec!["Are you nobody, too?",
                        "How dreary to be somebody!",
                        "To tell your name the livelong day",
                        "To an admiring bog!"], search_case_insensitive(a, &content));
    }
}