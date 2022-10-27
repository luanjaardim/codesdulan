pub struct Cacher<T>
    where T: Fn(u32) -> u32
{
    calculation: T,
    value: Option<u32>
}
impl<T> Cacher<T>
    where T: Fn(u32) -> u32
{
    pub fn new(calculation: T) -> Cacher<T>{
        Cacher { calculation, value: None }
    }

    pub fn calculando(&mut self, arg: u32) -> u32{
        match self.value {
            Some(v) => v,
            None => {
                let x = (self.calculation)(arg);
                self.value = Some(x);
                x
            }
        }
    }
}

/*pub fn selection_sort<T: PartialOrd + Copy>(mut a: Vec<T>) -> Vec<T> {
    for i in 0..a.len()-1{
        let mut min = i;
        for j in i+1..a.len(){
            if a[min] > a[j] {
                min = j;
            }
        }
        let tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
    a
}

pub fn bubble_sort<T: PartialOrd + Copy>(mut a: Vec<T>) -> Vec<T>{
    for i in 0..a.len()-1{
        for j in 0..a.len()-i-1{
            if a[j] > a[j+1] {
                let tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    a
}*/