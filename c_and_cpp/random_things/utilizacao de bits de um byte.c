#include <stdio.h>

typedef struct{
    unsigned primeiro:1;
    unsigned bits10:10;
} Bools;

int main(){

    Bools bits;
    int x=0;
    scanf("%d", &x);
    bits.primeiro=x, bits.bits10=x;
    
    printf("%i %i", bits.primeiro, bits.bits10);

    //o programa cria um tipo de variável que armazena o primeir e os 10 primeiros bits de um valor.
    //para o primeiro == 0 temos um valor par, para primeiro == 1 um valor ímpar
    //já em bits10 serão mostrados apenas valores entre 0 e 1023(2^10)

    //essa forma de ler apenas uma parte de um tipo só pode ser feita ao criar um novo tipo de variável
    //com o typedef, até onde sei no momento.

    return 0;
}