//questão: Investimentos N3, thehuxley

#include <stdio.h>

int main(){

int bairro[4][4]={}, i, j, x, maiorI=0, maiorJ=0;
char pos[20]={};

for(i=0; i<20; i++){
    scanf(" %c", &pos[i]);
}

i=0;
j=0;
x=0;
while(x<20){

if(pos[x]=='d' && j!=3){
j++;
bairro[i][j]++;
}
if(pos[x]=='b' && i!=3){
i++;
bairro[i][j]++;
}
if(pos[x]=='c' && i!=0){
i--;
bairro[i][j]++;   
}
if(pos[x]=='e' && j!=0){
j--;
bairro[i][j]++;
}

x++;
if(x==20){
    for(i=0; i<4; i++)
        for(j=0; j<4; j++){
            if(bairro[i][j]>bairro[maiorI][maiorJ]){
                maiorI=i;
                maiorJ=j;
        }
}
}
}
printf("Coordenada X:%i, Y:%i\n", maiorJ, maiorI );

/* for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            printf("%i ", bairro[i][j]);
        }
        printf("\n");
} */

return 0;
}