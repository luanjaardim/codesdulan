//questão: Teclado com problema, thehuxley

#include <stdio.h>
#include <math.h>

int main(){
	
	int quantT, tamanho, cont, divisor, contx, checa, x, numeros=0, caracs=0;
	long long int resultadoP, resultadoNP;
	char t;
										//decimais = 48 a 57
										//maiusculas = 65 a 90
										//minusculas = 97 a 122
	scanf("%i", &quantT);
	
	for(int v=1; v<=quantT; v++){
		
	scanf("\n%c", &t);
	if(t>=48 && t<=57)
		numeros++;
	else
		caracs++;
	}
	
	scanf("\n%i", &tamanho);

	
	for(int cont=1; cont<=tamanho; cont++){
		x=0;
		checa=0;
		if(cont==1){
			x=1;
			checa=3;
		}
		for(divisor=1; divisor<=cont && x==0; divisor++){
			
			if(cont%divisor == 0){
			checa++;
			}
			if(checa>2)
				x=1;
		}
		if(checa==2){			//numeros primos de tamanho, mostram seqs de numeros
			resultadoP = pow(numeros, cont);
		
			printf("Tamanho %i:\n", cont);
			printf("Sequencias: 0, Numeros: %lli\n", resultadoP);
		}
		if(checa==3){			//numeros nao-primos de tamanho, mostram seqs de letras
			resultadoNP = pow(caracs, cont);
		
			printf("Tamanho %i:\n", cont);
			printf("Sequencias: %lli, Numeros: 0\n", resultadoNP);
		}
//	printf("Tamanho %i:", cont);
//	printf("Sequencias: %i, Numeros: %i",);
	}
	return 0;
}
