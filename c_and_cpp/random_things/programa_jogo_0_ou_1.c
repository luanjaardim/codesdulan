#include <stdio.h>
#include <math.h>

int main(){

	int A, B, C;
	
	scanf("%i", &A);
	scanf("%i", &B);
	scanf("%i", &C);
	
	if(fabs(A)>1 || fabs(B)>1 || fabs(C)>1)	//alguma das variaveis n eh 0 ou 1
		printf("valores incompativeis.\n");
	else{
		if(A != B && A != C) //condição para A ganhar
			printf("A\n");
			
		if(B != C && B != A) //condição para B ganhar
			printf("B\n");
			
		if(C != A && C != B) //condição para C ganhar
			printf("C\n");
		
		if(A==B && A==C) //poderia ser B ou C no lugar de A
			printf("joguem novamente.\n");
		}
		
	return 0;
}
