//questão: Algoritmo do Cubo Mágico, thehuxley

#include <stdio.h>

int main(){

int i, j=0, count=0, maior=0;
char seq[25][4]={}, entrada[100]={};

scanf("%75[^\n]", entrada);

for(i=0; entrada[i]!='\0'; i++){
  if(entrada[i]!=32){
    seq[count][j]=entrada[i];
    j++;
  }
  else{
    count++;
    j=0;
    continue;
  }
}

for(i=0; seq[i][0]!='\0'; i++){
  if(seq[i][1]=='\'')
    seq[i][1]='\0';
  else if(seq[i][1]=='\0')
    seq[i][1]='\'';

  maior++;
}
maior--;
for(i=maior; i>=0; i--){
  printf("%s ", seq[i]);
}

return 0;
}