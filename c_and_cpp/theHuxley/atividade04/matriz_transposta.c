////questão: Matriz transposta, thehuxley

#include <stdio.h>

int main(){

int tami, tamj, i, j;
scanf("%d %d", &tami, &tamj);
int M[tami][tamj];
for(i=0; i<tami; i++){
    for(j=0; j<tamj; j++){
        scanf("%d", &M[i][j]);
    }
}

int Mt[tamj][tami];
for(i=0; i<tamj; i++){
    for(j=0; j<tami; j++){
        Mt[i][j]=M[j][i];
    }
}

for(i=0; i<tamj; i++){
    for(j=0; j<tami; j++){
        printf("%i ", Mt[i][j]);
    }
    printf("\n");
}

return 0;
}