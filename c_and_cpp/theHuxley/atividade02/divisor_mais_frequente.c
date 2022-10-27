//questão: Divisor mais frequente, thehuxley

#include <stdio.h>

int main(){
	
	int numero, num, divisores, divisorF, freq = 0, checar = 0;
	scanf("%i", &numero);
	
	for(divisores = 2; divisores <= numero; divisores++){
		if(numero%divisores == 0){	
			
			num = numero;
			
			while(num%divisores == 0){
				
			num/=divisores;
			checar++;
			//printf("%d ", divisores);
			}
				
			if(checar>freq){
				freq = checar;
				divisorF = divisores;
			}
			checar=0;
		}
	}
	printf("mostFrequent: %i, frequency: %i", divisorF, freq);
	
	return 0;
}
