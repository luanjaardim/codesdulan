//questão: Ambrosio's Bus Company, thehuxley

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{

int numPassagem, idade, numPoltrona;
char nome[100], data[11], destino[30], origem[30], hora[6];

}Passageiro;

int main(){

    int i=0, media=0, checa=0, par=0, idade=0;

    Passageiro passageiros[45];

scanf("%d", &passageiros[0].numPassagem);
while(i<44 && checa != -1){  
    scanf(" %10s", passageiros[i].data);
    scanf(" %29[^\n]", passageiros[i].origem);
    scanf(" %29[^\n]", passageiros[i].destino);
    scanf(" %5s", passageiros[i].hora);
    scanf("%d", &passageiros[i].numPoltrona);
    scanf("%d", &passageiros[i].idade);
    scanf(" %99[^\n]", passageiros[i].nome);
    media+=passageiros[i].idade;
    i++;
    scanf("%d", &checa);
    passageiros[i].numPassagem = checa;    
}
media/=i;

    for(i=0; passageiros[i].numPassagem != -1; i++){
        idade = passageiros[i].idade;
        par = passageiros[i].numPoltrona%2;
        if(idade > media && par==0)
            printf("%s\n", passageiros[i].nome);
    }



return 0;
}