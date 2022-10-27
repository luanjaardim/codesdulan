//questão: L4Q2 - Soma Divina, thehuxley

#include <stdio.h>

int main(){

int tam, i, j;
scanf("%d", &tam);
if(tam==0){
    printf("Vazia\n");
    return 0;
}

int m1[tam][tam], m2[tam][tam], mSoma[tam][tam];

for(i=0; i<tam; i++){
    for(j=0; j<tam; j++){
        scanf(" %d", &m1[i][j]);
    }
}
for(i=0; i<tam; i++){
    for(j=0; j<tam; j++){
        scanf(" %d", &m2[i][j]);
    }
}

for(i=0; i<tam; i++){
    for(j=0; j<tam; j++){
        mSoma[i][j]=m1[i][j]+m2[i][j];
    }
}

for(i=0; i<tam; i++){
    for(j=0; j<tam; j++){
        printf("%i ", mSoma[i][j]);
    }
    printf("\n");
}

return 0;
}