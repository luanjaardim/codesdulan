//questão: Espaços excedentes, thehuxley

#include <stdio.h>
#include <string.h>

int main(){

char string[300]={}, corrigida[300]={};
int i, j;

scanf("%299[^\n]", string);

j=0;
for(i=0; string[i]!='\0'; i++){
    if(string[i]==32 && string[i-1]==32)
        continue;
    corrigida[j]=string[i];
    j++;
}
printf("%s", corrigida);

return 0;
}