//questão: Datas entre dias: o retorno, thehuxley

#include <stdio.h>

int main(){

    int tam, i, j, indMenor, rep=0, tmp;
    scanf("%d", &tam);

    int vet[tam], ordem[tam];
    int registroV[tam], registroId[tam];

    for(i=0; i<tam; i++){
    scanf("%d", &ordem[i]);
    vet[i]=ordem[i];
    }
    for(i=0; i<tam; i++){
    registroV[i]=0;
    registroId[i]=0;
    }

    for(i = 0; i < tam-1 ; i++)  {
    indMenor = i ;

    for(j = i+1; j < tam ; j++ ) {
        if(ordem[j] < ordem[indMenor])  {                
        indMenor = j ;
    }
    }
        tmp = ordem[i];
        ordem[i] = ordem[indMenor];
        ordem[indMenor] = tmp;
    }

    for(i=0; i<tam; i++){
        if(vet[i]==ordem[i]){
            rep++;
            registroV[i] = vet[i];
            registroId[i] = i;
        }
    }
    printf("%i\n", rep);
    for(i=0; i<tam; i++){
        if(registroV[i]!=0)
         printf("%i %i\n", registroV[i], registroId[i]+1);
    } 
return 0;

}