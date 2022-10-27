//questão: os diamantes são para sempre, thehuxley

#include <stdio.h>

int main(){

int pontos, aster, i, j, Tp, Ta, tamanho;

scanf("%d", &tamanho);
pontos=tamanho;
aster=1;

for (i = 0; i < tamanho; i++)
{
    Ta=aster+2*i;
    Tp=pontos-i;

    while(Tp!=0){
        printf(".");
        Tp--;
    }
    while(Ta!=0){
        printf("*");
        Ta--;
    }
    printf("\n");
/*     printf("%i %i\n", Ta, Tp); */

}

pontos=1;
aster=2*(tamanho-1)+1;
for (i = 0; i < tamanho; i++)
{
    Ta=aster-2*i;
    Tp=pontos+i;

    while(Tp!=0){
        printf(".");
        Tp--;
    }
    while(Ta!=0){
        printf("*");
        Ta--;
    }
    printf("\n");
}


return 0;
}