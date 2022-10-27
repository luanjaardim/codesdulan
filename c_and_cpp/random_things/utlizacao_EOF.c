#include <stdio.h>

int main(){



  char frase[10000];      //escreva uma frase no terminal e veja a magica acontecer :)
  int count = 0; 


  while(scanf("%c", &frase[count]) != EOF){
    count++;
  }
  for(int i=0; i<count; i++){
  printf("%c\n", frase[i]);
  }

return 0;

}

