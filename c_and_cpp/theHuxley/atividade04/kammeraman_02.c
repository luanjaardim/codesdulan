//questão: Kammera Man Corrompeu suas Matrizes, thehuxley

#include <stdio.h>
#include <math.h>

int main(){

int linhas, colunas, i, j, x;
scanf("%d %d", &linhas, &colunas);
double matriz[linhas][colunas], suc, ant;

for(i=0; i<linhas; i++){
    for(j=0; j<colunas; j++){
        scanf(" %lf", &matriz[i][j]);
    }
}

for(i=0; i<linhas; i++){
    for(j=0; j<colunas; j++){
        if(matriz[i][0]==-1)
            matriz[i][0]=1;

        if(matriz[i][1]==-1){
            if(matriz[i][j]!=-1 && j>1){
            matriz[i][1]=pow(matriz[i][j], 1.0/j);
            j=2;
            x=1; 
            }
        }
        else{
            x=1;
        }
        if(matriz[i][j]==-1 && x==1){
            matriz[i][j]=pow(matriz[i][1], (double)j);
        }
    }
    x=0;
}

for (i = 0; i < linhas; i++){
    for(j=0; j<colunas-1; j++){
        printf("%.0f ", matriz[i][j]);
    }
    printf("%.0f", matriz[i][j]);
    printf("\n");
}


return 0;
}