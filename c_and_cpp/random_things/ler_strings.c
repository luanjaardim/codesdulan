#include <stdio.h>

int main(){

char nome[50];

scanf("%49[^\n]", nome); //49 por causa do tamanho do vetor-1; ^\n inclui espaços na string
printf("%s", nome);

return 0;
}