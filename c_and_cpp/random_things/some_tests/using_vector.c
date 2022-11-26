#include "vector.h"

INITIATE_VEC(int, sla2) //cada elemento será um int 
INITIATE_VEC(vec_sla2 *, sla)   //cada elemento será um ponteiro para um vec de int

int main(int argc, char *argv[])
{  
    vec_sla *mat = vec_init_sla(8); //iniciando uma matriz com inicialmente 8 espaços
    f(i, 10) {
        push_back_sla(mat, vec_init_sla2(1)); //dá pushback de vetores com capacidade 1
        f(j, 5) push_back_sla2(read_sla(mat, i), j); //dá pushback nos vetores recém-criados, eles se realocam com o tempo
    }
    f(i, mat->size){
        f(j, read_sla(mat, i)->size)
            printf("%d ", read_sla2(read_sla(mat, i), j)); //printando os elementos
        printf("\n");
    }

    f(i, mat->size)
        vec_destroy(read_sla(mat, i)); //desalocando primeiro os vetores
    vec_destroy(mat);   //desalocando mat 

    vec_sla2 *v = vec_init_sla2(4);
    push_back_sla2(v, 1); // 1
    push_back_sla2(v, 3); // 1 3
    push_back_sla2(v, 2); // 1 3 2
    push_back_sla2(v, 1); // 1 3 2 1
    rem_sla2(v, 1); // 1 1 2, the last element is copied to the position removed
    f(i, v->size)
        printf("%d\n", read_sla2(v, i));
    return 0;
}
