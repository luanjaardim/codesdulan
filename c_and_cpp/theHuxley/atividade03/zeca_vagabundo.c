//questão: Zeca (não) quer trabalhar, thehuxley

#include <stdio.h>

int main(){

int valortv, amigos, i=0, j=0, t=0;
scanf("%d %d", &valortv, &amigos);

int grana[amigos];

for(i=0; i<amigos; i++){
scanf("%d", &grana[i]);
}

for(i=0; i<amigos; i++){
    for(j=1; j<amigos; j++){
        if(j==i)
            continue;
        for(t=2; t<amigos; t++){
            if(t==j || t==i)
                continue;
            
            if(grana[i]+grana[j]+grana[t] == valortv){
                printf("Zeca nao vai ter que trabalhar!");
                return 0;
            }
        }    
    }
}
printf("Zeca vai ter que trabalhar.");
return 0;
}