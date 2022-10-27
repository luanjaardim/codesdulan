//questão: Dudinha's password, thehuxley

#include <stdio.h>
#include <string.h>

int main(){

int Npalavra, i, j, w, x=0, repets=0, testeI, maiorI;
scanf("%d", &Npalavra);
char palavras[Npalavra][13], direcoes[Npalavra], senha[242]={}, senhaCheque[121]={}, Pchave[121]={};


j=0;
for(i=0; i<Npalavra*2; i++){
    if(i%2){
    scanf(" %12[^\n]", palavras[j]);
    j++;}
    else{
    scanf(" %c", &direcoes[j]);
}
}
scanf(" %s", Pchave);

for(i=0; i<Npalavra; i++){

if(direcoes[i]=='e'){
    if(x==0){
    w=0;
    for(j=11; j>5; j--){
        senha[w]=palavras[i][j];
        w++;
    }
    x=1;
    }
    else{
    w=0;
    for(j=11; j>5; j--){
        senhaCheque[w]=palavras[i][j];
        w++;
    }
    strcat(senha, senhaCheque);
    }
}
if(direcoes[i]=='d'){
    if(x==0){
    w=0;
    for(j=0; j<6; j++){
        senha[w]=palavras[i][j];
        w++;
    }
    x=1;
    }
    else{
    w=0;
    for(j=0; j<6; j++){
        senhaCheque[w]=palavras[i][j];
        w++;
    }
    strcat(senha, senhaCheque);
    }
}

}
/* strcpy(senhaCheque, senha);
strcat(senha, senhaCheque);
 */
//printf("%s", senha);

for(i=0; senha[i]!='\0'; i++){
    x=1;
    if(Pchave[0]==senha[i]){
        testeI=i;
        for(j=0; Pchave[j]!='\0'; j++){
            if(senha[testeI]=='\0')
                testeI=0;
            if(Pchave[j]!=senha[testeI]){
                x=0;
                continue;
            }
            testeI++;
        }
        if(x==1)
            repets++;
    }
}
i--;
maiorI=i;
while(i>=0){
    x=1;
    if(Pchave[0]==senha[i]){
        testeI=i;
        for(j=0; Pchave[j]!='\0'; j++){
            if(testeI<0)
                testeI=maiorI;
            if(Pchave[j]!=senha[testeI]){
                x=0;
                continue;
            }
            testeI--;
        }
        if(x==1)
            repets++;
    }
    i--;
}
printf("%s", Pchave);
printf("%i", repets);


return 0;
}