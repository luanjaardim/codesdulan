//questão: Ajude a dudinha!, thehuxley

#include <stdio.h>
#include <math.h>

int main(){
	
	long long int inicio, final, fatPdist;
	int primeiro=0, primos, divisor, x, y, quantD, num, checa=0, Q;
	
	scanf("%lli %lli %lli", &inicio, &final, &fatPdist);
	
	num=inicio;
	
while(num<final){	
	y=0;
	
	for(primos=1; primos<=final && y==0; primos+=2){
		quantD=0;
		x=0;
		
		for(divisor=1; divisor<=primos && x==0; divisor++){
			if(primos%divisor == 0)
				quantD++;
			if(quantD>2)
				x=1;	
		}
		if(quantD==2){
			if(num%primos == 0)	{		
				checa++;
			if(num%(primos*primos)==0)
				checa+=fatPdist;	
			}
			if(checa>fatPdist || primos>num)
			y=1;
		}
	}		
if(checa==fatPdist){
	if(primeiro==0)
		primeiro=num;
	else
		Q++;
}

checa=0;
num++;
}

if(primeiro!=0)
printf("%i %i", primeiro, Q);

else
printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.");

	return 0;
}
