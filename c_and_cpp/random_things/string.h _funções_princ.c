#include <stdio.h>
#include <string.h>

int main(){

char palavra[100]="bolo", palavra2[100]="cenoura";

//scanf("%25s %25s", palavra, palavra2);

strcat(palavra, " de ");        //strcat junta duas strings, a segunda entra na primeira
strcat(palavra, palavra2);
printf("%s\n", palavra);
printf("o tamanho da *palavra* eh: %d\n", strlen(palavra));    //strlen mostra o tamanho da string

if(strcmp(palavra, palavra2)>=0)    //checa se as strings são iguais, compara elas, o resultado dessa função é subtração da
strcpy(palavra, palavra2);          //primeira letra diferente entre as strings(<1 ou >1), caso iguais é 0.
else
strcpy(palavra2, palavra);

printf("a palava 1 ficou como: %s, e a 2 ficou:%s", palavra, palavra2);



return 0;
}