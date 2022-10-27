//questão: Frequência de um texto em uma Lista Encadeada, thehuxley

#include <stdio.h>

int main(){



  char frase[10000], letras[256]={};
  int repets[256];
  int count = 0, i, j, primeiro, tmp, x;


  while(scanf("%c", &frase[count]) != EOF){
    count++;
  }

for(i = 0; i < count-1 ; i++)  {
  primeiro = i ;

  for(j = i+1; j < count ; j++ ) {
    if(frase[ j ] > frase[ primeiro ])  {                
      primeiro = j ;
 }
}
    tmp = frase[i];
    frase[i] = frase[primeiro];
    frase[primeiro] = tmp;
}

letras[0]=frase[0];
x=0;
for(i=1; i<count; i++){
    if(frase[i]!=letras[x]){
    x++;
    letras[x]=frase[i];
    }
}
x=0;
for(i=0; i<256 && x==0; i++){
  for(j=0; j<count; j++){
      if(letras[i]==0){
        x=1;
        break;
      }
      if(letras[i]==frase[j])
        repets[i]++;
  }//
}

for(i=0; i<256; i++){
    if(letras[i]==0)
        break;
    printf("%c %i\n", letras[i], repets[i]);
}

return 0;

}

