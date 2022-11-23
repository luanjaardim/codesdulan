//programa criado para criptografar ou descriptografar uma mensagem através de uma cifra
//uma cifra será um inteiro q ao somar(cripto.) ou subtrair(descripto.) resultará no novo caractere

#include <stdio.h>

int main(){

char mensagem[1000], modoFunc, trad;
int cifra, i=0;


printf("Digite a cifra que sera utilizada: ");
scanf("%d", &cifra);
printf("Quer criptografar ou descriptografar (c/d)? ");
scanf(" %c", &modoFunc);
printf("Qual a mensagem?\n");
scanf(" %999[^\n]", mensagem);


if(modoFunc == 'c')
    while(mensagem[i]!='\0'){
        trad=mensagem[i];
        if(mensagem[i]>=97 && mensagem[i]<=122){ //muda apenas letras
        trad-=97;
        trad+=cifra;
        trad=trad%26;
        trad+=97;
        mensagem[i]=trad;
        //printf("%c ", trad);
        }
        if(mensagem[i]>=65 && mensagem[i]<=90){
        trad-=65;
        trad+=cifra;
        trad=trad%26;
        trad+=65;
        mensagem[i]=trad;
        }
        i++;
    }

if(modoFunc == 'd')
    while(mensagem[i]!='\0'){
        trad=mensagem[i];
        if(mensagem[i]>=97 && mensagem[i]<=122){ //muda apenas letras
        trad-=97;
        trad-=cifra;
        if(trad<0)
            trad+=26;
        trad+=97;
        mensagem[i]=trad;
        //printf("%c ", trad);
        }
        if(mensagem[i]>=65 && mensagem[i]<=90){
        trad-=65;
        trad-=cifra;
        if(trad<0)
            trad+=26;
        trad+=65;
        mensagem[i]=trad;
        }
        i++;
    }
printf("%s", mensagem);

return 0;
}