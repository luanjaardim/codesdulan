//questão: Teh Adventujrs of Meme Man: Cybermarket 2077, thehuxley

#include <stdio.h>

int main(){

char bombx;
int m, n, quant, i, j, bomby;
scanf("%dx%d", &m, &n);
scanf(" %d", &quant);

int mat[n][m];
for(i=0; i<n; i++){
    for(j=0; j<m; j++){
        mat[i][j]=0;
    }
}
if(quant>0)
for(i=0; i<quant; i++){
    scanf(" %c%d", &bombx, &bomby);
    mat[bombx-97][bomby-1]=9;
}

if(quant==m*n){
    printf("BANDECLAY OVERLOAD!");
    return 0;
}
for(i=0; i<n; i++){
    for(j=0; j<m; j++){
        if(mat[i][j]==9){
            if(i!=0 && mat[i-1][j]!=9)
                mat[i-1][j]++;

            if(j!=0 && mat[i][j-1]!=9)
                mat[i][j-1]++;

            if(j!=0 && i!=0 && mat[i-1][j-1]!=9)
                mat[i-1][j-1]++;

            if(i!=n-1 && mat[i+1][j]!=9)
                mat[i+1][j]++;

            if(j!=m-1 && mat[i][j+1]!=9)
                mat[i][j+1]++;

            if(j!=m-1 && i!=n-1 && mat[i+1][j+1]!=9)
                mat[i+1][j+1]++;
            
            if(j!=0 && i!=n-1 && mat[i+1][j-1]!=9)
                mat[i+1][j-1]++;
            
            if(j!=m-1 && i!=0 && mat[i-1][j+1]!=9)
                mat[i-1][j+1]++;
        }
    }
}

for(i=0; i<n; i++){
    for(j=0; j<m; j++){
        printf("%i ", mat[i][j]);
    }
    printf("\n");
}
    



return 0;
}