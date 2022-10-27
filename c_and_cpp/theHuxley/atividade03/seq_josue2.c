//questão: Os Ímpares de Josué, thehuxley

#include <stdio.h>

int main(){
    int nums[10000]={}, i=0, j, tmp, min, x, tam, tamR;
    while(scanf("%d", &nums[tam])!=EOF){ //valores lidos e tam do vetor
        tam++;
    }

    for(i = 0; i < tam-1 ; i++)  { //sorting
    min = i ;

    for(j = i+1; j < tam ; j++ ) {
    if(nums[ j ] < nums[ min ])  {                
    min = j ;
 }
}
    tmp = nums[i];
    nums[i] = nums[min];
    nums[min] = tmp;
}
    tamR = nums[tam-1]+1;
    int repets[tamR];
    for(i=0; i<tamR; i++){
        repets[i] = 0;
    }

x=1;
    for(i=0; i<tamR; i++){
    for(j=0; j<tam; j++){
        if(x==nums[j])
            repets[x]++;
    }
x++;
}

for(i=0; i<tam; i++){
    printf("%i ", nums[i]);
} 

for(i=1; i<tamR; i++){
    if(repets[i==0])
        continue;
    if(repets[i]%2==1){
        printf("\n%i", i);
        return 0;
    }
}
printf("\n0");

    return 0;
}