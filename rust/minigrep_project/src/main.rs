use minigrep_project::*; //importando as funções de lib.rs

fn main() {
    let config = Config::build(env::args())
                                .unwrap_or_else(
                                    | err | { 
                                        eprintln!("Error: {err}");
                                        process::exit(1); 
                                    }
                                );
    if let Err(err) = run2(config){
        eprintln!("Error: {err}");
        process::exit(1);
    }
}

/* SEGUNDA IMPLEMENTAÇÃO
//a função main ficou encarregada apenas de lidar com os erros vindo das outras funções, 
// printando em stderr caso ocorram, e receber os argumentos com args
fn main() {
    //este projeto busca as linhas de um texto que contém uma determinada palavra
    //para rodar este programa devemos usar argumentos na linha de comando
    //(var especial) cargo run (nome do arquivo de leitura) (palavra buscada) > (arquivo para a saída padrão / standard output)
    /*
    Exs.: cargo run > output.txt //erro por falta de argumentos
          cargo run file.txt to > output.txt //sucesso, saída encontrada output.txt
          CASE=1 cargo run file.txt to //sucesso, saída encontrada no terminal 
          (CASE=1 indica que a leitura não vai considerar a diferença entre T e t, por exemplo)
    */
    let args: Vec<String> = env::args().collect();
    let config = Config::new(&args)
                                .unwrap_or_else(|err|{eprintln!("Error: {}", err); process::exit(1); });
                                //lidando com o Err()          //eprintln! é uma macro que printa na saída padrão de erros(standard error)
                                //dentro de unwrap_or_else podemos colocar um código que será realizado quando ocorrer um erro,
                                //nesse caso temos uma closure que recebe o erro e printa ele na saída de erros e termina o programa com o exit(1)
    if let Err(err) = run(config) {
        eprintln!("Error: {}", err);
        process::exit(1); //terminando a execução do programa, com erro
    }
}*/
