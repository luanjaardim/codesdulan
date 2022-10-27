//questão: Sherlirow quer dormir, thehuxley

#include <stdio.h>

int main(){

int Ncoords, tamI, tamJ, i, j, x, checa1=0, checa2=0, checa3=0, checa4=0, maior=0;
scanf("%d %d %d", &Ncoords, &tamI, &tamJ);
int coords[Ncoords][2], matriz[tamI][tamJ];
for(i=0; i<Ncoords; i++){
    for(j=0; j<2; j++){
        scanf("%d", &coords[i][j]);
    }
}
for(i=0; i<tamI; i++){
    for(j=0; j<tamJ; j++){
        scanf("%d", &matriz[i][j]);
    }
}

for(x=0; x<Ncoords; x++){
    checa1=0,checa2=0,checa3=0,checa4=0;
    for(i=0; i<tamI; i++){
        for(j=0; j<tamJ; j++){
            if(matriz[i][j]==1 && (i==coords[x][0] || j==coords[x][1]))
                checa1++;
            if(matriz[i][j]==2 && (i==coords[x][0] || j==coords[x][1]))
                checa2++;
            if(matriz[i][j]==3 && (i==coords[x][0] || j==coords[x][1]))
                checa3++;
            if(matriz[i][j]==4 && (i==coords[x][0] || j==coords[x][1]))
                checa4++;
        }
        if(checa1>maior)
            maior=checa1;
        if(checa2>maior)
            maior=checa2;
        if(checa3>maior)
            maior=checa3;
        if(checa4>maior)
            maior=checa4;
    }
}
printf("A pontuacao da equipe vencedora sera %i ponto(s)!", maior);

/* printf("\n");
for(i=0; i<tamI; i++){
    for(j=0; j<tamJ; j++){
        printf("%i ", matriz[i][j]);
    }
    printf("\n");
} */

return 0;
}