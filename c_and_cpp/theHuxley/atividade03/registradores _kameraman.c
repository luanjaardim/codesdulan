//questão: Os registradores de Kammera Man, thehuxley

#include <stdio.h>

int main(){

int vetvalor[4]={}, vetinstru[4]={}, valor=0, instru=0, i, x=0;
for(i=0; i<4; i++){
scanf("%d", &vetinstru[i]);
}
for(i=0; i<4; i++){
scanf("%d", &vetvalor[i]);
}
for(i=0; i<4; i++){
if(vetvalor[i]==1 && i==3)
valor++;
if(vetvalor[i]==1 && i==2)
valor+=2;
if(vetvalor[i]==1 && i==1)
valor+=4;
if(vetvalor[i]==1 && i==0)
valor+=8;
}
/* printf("%i ", valor); */

for(i=0; i<4; i++){
if(vetinstru[i]==1 && i==3)
instru++;
if(vetinstru[i]==1 && i==2)
instru+=2;
if(vetinstru[i]==1 && i==1)
instru+=4;
if(vetinstru[i]==1 && i==0)
instru+=8;
}
/* printf("%i ", instru); */


while(instru!=15){


if(instru==0 && x==0){
    valor=0;
    for(i=0; i<4; i++){
    scanf("%d", &vetvalor[i]);
    }
    for(i=3; i>=0; i--){
    if(vetvalor[i]==1 && i==3)
    valor++;
    if(vetvalor[i]==1 && i==2)
    valor+=2;
    if(vetvalor[i]==1 && i==1)
    valor+=4;
    if(vetvalor[i]==1 && i==0)
    valor+=8;
}
x=1;
}
if(instru==2 && x==0){
    printf("O registrador tem os seguintes valores:\n");
    printf("High: %d\n", instru);
    printf("Low: %d\n", valor);
x=1;
}
if(instru==5 && x==0){
    printf("%i\n", valor*valor);
x=1;
}
if(instru==8 && x==0){
    printf("%X\n", valor);
x=1;
}
if(instru==12 && x==0){
    scanf("%d", &i);
    printf("%i\n", i*valor);
x=1;
}
if((instru!=12 || instru!=15 || instru!=0 || instru!=2 || instru!=5 || instru!=8) && x==0){
    printf("ERRO: A instrucao nao existe.\n");
x=1;
}

for(i=0; i<4; i++){
scanf("%d", &vetinstru[i]);
}
instru=0;
for(i=3; i>=0; i--){
if(vetinstru[i]==1 && i==3)
instru++;
if(vetinstru[i]==1 && i==2)
instru+=2;
if(vetinstru[i]==1 && i==1)
instru+=4;
if(vetinstru[i]==1 && i==0)
instru+=8;
}

if(instru==15){
  return 0;  
}
x=0;
}

return 0;
}