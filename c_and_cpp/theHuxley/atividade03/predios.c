//questão: Os novos prédios, thehuxley

#include <stdio.h>

int main(){

int tam, tmp, min, i, j, altos=0, medios=0, baixos=0, alturasDif=0, diferenca=0, x=0;

scanf("%d", &tam);
int predios[tam], prediosC[tam];

for(i=0; i<tam; i++){
 scanf("%d", &predios[i]);
 prediosC[i] = predios[i];
  }

alturasDif=tam;

for(i = 0; i < tam-1 ; i++)  {
  min = i ;
  x=0;
  for(j = i+1; j < tam ; j++ ) {
    if(prediosC[j]==prediosC[i] && x==0){
        alturasDif--;
        x=1;
    }
    if(predios[ j ] < predios[min])  {                
      min = j;
 }
}
    tmp = predios[i];
    predios[i] = predios[min];
    predios[min] = tmp;
}
for(i = 0; i < tam ; i++){
    if(predios[i]>0 && predios[i]<50)
        baixos++;
    if(predios[i]>=50 && predios[i]<100)
        medios++;
    if(predios[i]>=100)
        altos++;
}
diferenca = predios[tam-1] - predios[0];

printf("%i\n", alturasDif);
printf("%i\n", altos);
printf("%i\n", medios);
printf("%i\n", baixos);
printf("%i\n", diferenca);

return 0;

}