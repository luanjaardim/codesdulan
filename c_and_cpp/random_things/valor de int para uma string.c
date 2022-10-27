#include <stdio.h>

int main(){

long long int entrada;
int i, j;
char string[20]={};

scanf("%lld", &entrada);

while(entrada!=0){

i++;
for(j=i; j>0; j--)
    string[j]=string[j-1];

string[0]=(entrada%10+48);
entrada/=10;

}
printf("%s", string);

return 0;
}