pub mod teste2;

pub fn teste1() 
{
    println!("função dentro de teste1 em teste");
}

pub struct TesteStruct{ //definindo um struct pública que tem apenas um elemento publico, num não poderá ser acessado em main
    pub nome : String,
    num : i32 //num é um elemento da struct que é privado
}

impl TesteStruct{ //a implementação não precisa ser pub, apenas as funções, visto que isso só será pub se TesteStruct for
    pub fn criar_teste_struct() -> TesteStruct { //constructor pub para colocar valores em num, já que não seria possível fazer isso fora desse escopo
        TesteStruct{
            nome : String::from("João"),
            num : 19
        }
    }
    pub fn qual_meu_num(&self){
        println!("{}", self.num);
    }
}

pub enum TesteEnum{ //definindo uma enum pública, na enum as variantes são públicas se a enum também for
    Caraio,
    Kkkk(i32, i32),
    Vsf { num : u32 }
}
