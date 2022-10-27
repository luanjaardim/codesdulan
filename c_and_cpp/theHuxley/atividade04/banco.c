//questão: Operação bancária, thehuxley

#include <stdio.h>

int main(){

int operacao[100][2], i, j, x=0;
double valores[100][2], creditos=0, debitos=0, saldo=0;

for(i=0; i<100 && x==0; i++){
    for(j=0; j<100 && x==0; j++){
        scanf("%d", &operacao[i][j]);
        if(operacao[i][j]==-1){
            x=1;
        }
        else{
        scanf(" %lf", &valores[i][j]);
        if(operacao[i][j]==1){
            creditos+=valores[i][j];
        }
        else{
            debitos+=valores[i][j];
        }
        }
    }
}
saldo=creditos-debitos;

printf("Creditos: R$ %.2lf\n", creditos);
printf("Debitos: R$ %.2lf\n", debitos);
printf("Saldo: R$ %.2lf\n", saldo);

return 0;
}