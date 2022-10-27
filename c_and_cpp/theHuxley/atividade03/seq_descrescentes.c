//questão: Maior sequência decrescente, thehuxley

#include <stdio.h>

int main(){

int casosT, tam, i=0, j=0, t=0, val, maior=0, tmp=0, checa=0, Jinicio=0, Jfinal=0, cap;
scanf("%d", &casosT);

int Matriz[101][101]={};

for(i=0; i<2*casosT; i++){
    j=0;
    if(i%2==0){
    scanf("%d", &tam);
    Matriz[i][j]=tam;
    }
    if(i%2==1){
    for(j=0; j<tam; j++){
    scanf("%d", &val);
    Matriz[i][j]=val;
    }
    }
}
j=0;
maior=0;
for(i=1; i<casosT*2; i+=2){
    cap=Matriz[i-1][0];
    tmp=0;
    maior=0;
    for(j=0; j<cap; j++){
        if(j!=0)
        if(Matriz[i][j] == Matriz[i][j-1] || Matriz[i][j] > Matriz[i][j-1]){
        tmp=0;
        }
        tmp++;
        if(tmp>maior){
            maior=tmp;
        }
    }
    if(maior==1)
        maior=0;
    Matriz[i-1][0]=maior;
    printf("%i\n", Matriz[i-1][0]);
    if(maior>=2){
        checa=0;
    for(j=0; j<cap; j++){
        if(j!=0)
        if(Matriz[i][j]>Matriz[i][j-1] || Matriz[i][j] == Matriz[i][j-1])
        checa=0;

        checa++;
        if(checa==maior){
            Jfinal=j;
            break;
        }
    }
    Jinicio = Jfinal-maior+1;
    for(j=Jinicio; j<maior+Jinicio; j++)
        printf("%i ", Matriz[i][j]);
        printf("\n");
    Jfinal=0;
    Jinicio=0;
    }

}

return 0;
}