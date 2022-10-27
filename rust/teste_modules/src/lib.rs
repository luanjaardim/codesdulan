
mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}

        pub mod hosting_vips{
            pub fn add_to_viplist() {}
        }
    }
}

use self::front_of_house::hosting; 
//cria um atalho para hosting, traz hosting para o escopo de main
use self::front_of_house::hosting::hosting_vips::add_to_viplist as vip_list;
//com o use as podemos dar um novo nome para se referir ao path

pub fn eat_at_restaurant() {
    hosting::add_to_waitlist();
    vip_list();
}

//outros usos de " use "
pub use std::{ io, cmp::Ordering };
//trazendo para o escopo dois módulos que estavam em std, nesse caso poderíamos 
//substituir a linha acima por 2 uses: std::io e std::cmp::Ordering.

use std::cmp::{self, PartialEq};
//nesse caso é importado std::cmp e std::cmp::PartialEq

pub use std::collections::*; 
//neste todos os elementos de collections são importados

//o primeiro e último use acima estão com pub na frente, pois vamos usá-los na