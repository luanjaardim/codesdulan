//questão: A Guerra dos CinCabeças, thehuxley

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{

char nome[21];
int idade, pontos;
double id;

} Heroi;

int main(){

Heroi player1, player2;
player1.pontos=0, player2.pontos=0;

int retorno=0, i, x=0, raiz1, raiz2;

scanf("%d %lf", &player1.idade, &player1.id);
scanf("%20s", player1.nome);
scanf("%d %lf", &player2.idade, &player2.id);
scanf("%20s", player2.nome);

retorno = strcmp(player1.nome, player2.nome);
if(retorno != 0){
    if(retorno > 0)
        player1.pontos+=2;
    if(retorno < 0)
        player2.pontos+=2;
}

for(i=2; i<player1.idade && x==0; i++){
    if(player1.idade%i == 0)
        x=1;
}
if(x==0)
player1.pontos+=4;
x=0;
for(i=2; i<player2.idade && x==0; i++){
    if(player2.idade%i == 0)
        x=1;
}
if(x==0)
player2.pontos+=4;

raiz1 = (int) sqrt(player1.id);
raiz2 = (int) sqrt(player2.id);

if(raiz1*raiz1 == player1.id)
    player1.pontos+=3;
if(raiz2*raiz2 == player2.id)
    player2.pontos+=3;

if(player1.pontos == player2.pontos)
printf("CInCABECAS EMPATADOS");
else{
if(player2.pontos > player1.pontos)
printf("%s WINS", player2.nome);

else
printf("%s WINS", player1.nome);
}

// printf("%d %d", player1.pontos, player2.pontos);
 
return 0;
}