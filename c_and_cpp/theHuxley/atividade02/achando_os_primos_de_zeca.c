//questão: Os primos de Zeca, thehuxley

#include <stdio.h>

int main(){
	
	int a, b, inter, proc1, proc2, num, num1, num2, divisor, divisor1, divisor2, quantD, quantD1, quantD2, QuantPzeca=0, x, y, z, primoAnt=0, primoSuc=0, qfor1=0, qfor2=0;
	scanf("%i %i", &a, &b);
	
	for(inter = a; inter <= b; inter++){ 		// inter sao os valores no intervalo de a e b
		quantD=0;
		x=0;
		y=0;
		z=0;
		qfor1=0;
		qfor2=0;
		
		for(divisor=1; divisor<=inter && x==0 ; divisor++){ 		//gera todas as possibilidades de divisores para cada i
			num=inter;
			
			if(num%divisor == 0){
			num/=divisor;
			quantD++;
			}
			
			if(quantD>2)
				x=1;
		}
		
		if(quantD==2){
		
		//printf("%i",inter);
			
			for(proc1=inter-1; proc1>2 && qfor1==0; proc1--){
				quantD1=0;
				y=0;	
					
				for(divisor1=1; divisor1<=proc1 && y==0; divisor1++){ 	
				num1=proc1;

				if(num1%divisor1 == 0){
				num1/=divisor1;
				quantD1++;
				}
				if(quantD1>2)
				y=1;
				
			//	printf("%i %i %i %i %i\n", inter, proc1, divisor1, num1, quantD1 );
				}
				
			if(quantD1==2){
				primoAnt=proc1;
				qfor1=1;
				//printf("%i\n",primoAnt);
			}
		}
			
		
			for(proc2=inter+1; proc2<=2000 && qfor2==0; proc2++){
				quantD2=0;
				z=0;	
					
				for(divisor2=1; divisor2<=proc2 && z==0; divisor2++){ 	
				num2=proc2;

				if(num2%divisor2 == 0){
				num2/=divisor2;
				quantD2++;
				}
				if(quantD2>2)
				z=1;
				
			//	printf("%i %i %i\n", inter, proc2, quantD2 );
				}
				
			if(quantD2==2){
				primoSuc=proc2;
				qfor2=1;
			//	printf("%i\n",primoSuc);
			}
		
		}
	//	printf("%i %i %i\n", primoAnt, inter, primoSuc);
		
		if(inter == (primoAnt + primoSuc)/2){
		QuantPzeca++;	
		}
		
	}
		
		
		//printf("%i %i %i %i\n", inter, divisor, num, quantD);
	}
	printf("%i", QuantPzeca);
	
	return 0;
}
