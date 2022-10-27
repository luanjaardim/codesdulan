//questão: A Linha de montagem do Dr. Zululu, thehuxley

#include <stdio.h>
#include <stdlib.h>

int main(){

int numLant, numLnova, i, j, x=0, y=0, checa=0, min, tmp;
scanf("%d %d", &numLant, &numLnova);

int Lant[numLant];
for(i=0; i<numLant; i++){   //encontra os elementos da lista antiga
    scanf("%d", &Lant[i]);
}

int Lnova[100];
for(i=0; i<100; i++) Lnova[i] = 0;  //zera os elementos de uma lista nova q pode comportar quais quer valores até 100 deles

/* for(i=0; i<100 && checa<numLnova; i++){     //pega os valores recebidos até q tenha pego "numLnova" valores diferentes
    x=0;
    scanf("%d", &Lnova[i]);
    for(j=0; j<numLant; j++){
        if(Lnova[i]==Lant[j]){
            x=1;
            break;
        }
    }
    if(x==0)
        checa++;
} */
while(scanf("%d", &Lnova[checa]) != EOF){
    checa++; //tamanho de memória utilizado
  }
//printf("%i", checa);

int Lproc[checa];       //vetor com os valores recebidos e com um tamanho já definido, será modificado ao longo do cod
for(i=0; i<checa; i++){
    Lproc[i]=Lnova[i];
}

for(i=1; i<checa-1; i++){   //processando os valores da lista
    Lproc[i] = abs((Lnova[i-1]*Lnova[i])-Lnova[i+1]);
}
Lproc[checa-1]= Lnova[checa-1]*Lnova[checa-2];


for(i = 0; i < checa-1 ; i++)  {        //ordenando eles
  min = i ;

  for(j = i+1; j < checa ; j++ ) {
    if(Lproc[ j ] < Lproc[ min ])  {                
      min = j ;
 }
}
    tmp = Lproc[i];
    Lproc[i] = Lproc[min];
    Lproc[min] = tmp;
}

for(i=0; i<checa; i++){     //printando os valores
    y=0;
    for(j=0; j<numLant; j++){
        if(Lproc[i]==Lant[j]){
            y=1;
            break;
        }
    }
    if(y==1)
        printf("DELETADO ");
    else
        printf("%i ", Lproc[i]);
}

return 0;
}