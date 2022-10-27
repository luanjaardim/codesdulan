//questão: Mensagem codificada, thehuxley

#include <stdio.h>
#include <string.h>

int main(){

char string[100000];
int i;

scanf("%99999[^\n]", string);

for(i=0; string[i]!='\0'; i++){
    if(string[i]=='4')
        string[i]='a';
    if(string[i]=='5')
        string[i]='e';
    if(string[i]=='1')
        string[i]='i';
    if(string[i]=='0')
        string[i]='o';
    if(string[i]=='2')
        string[i]='u';
    if(string[i-2]=='.' && string[i]>96 && string[i]<123)
        string[i]-=32;

}

if(string[0]>96 && string[0]<123)
    string[0]-=32;

printf("%s.", string, strlen(string));
if(string[strlen(string)-1]!='.')
    printf(".");


return 0;
}


///////// cod que deu certo no the huxley foi:

/* #include <stdio.h>
#include <string.h>

int main(){

char string[100000];
int i;

scanf("%99999[^\n]", string);

for(i=0; string[i]!='\0'; i++){
    if(string[i]=='4')
        string[i]='a';
    if(string[i]=='5')
        string[i]='e';
    if(string[i]=='1')
        string[i]='i';
    if(string[i]=='0')
        string[i]='o';
    if(string[i]=='2')
        string[i]='u';
    if(string[i-2]=='.' && string[i]>96 && string[i]<123)
        string[i]-=32;

}

if(string[0]>96 && string[0]<123)
    string[0]-=32;

printf("%s", string, strlen(string));
// if(string[strlen(string)-1]!='.')
//    printf("."); 


return 0;
} */