//questão: O Campeonato de Vôlei do CIn, thehuxley

#include <stdio.h>

int main(){
	
	int A, B, C, D, E, F, G, H;
	scanf("%i",&A);
	scanf("%i",&B);
	scanf("%i",&C);
	scanf("%i",&D);
	scanf("%i",&E);
	scanf("%i",&F);
	scanf("%i",&G);
	scanf("%i",&H);
	
	if( A<1 || A>4 || B<1 || B>4 || C<1 || C>4 || D<1 || D>4 || E<1 || E>4 || G<1 || G>4 || H<1 || H>4)
		printf("****");
		
	else{
		
	if(G==H && D!=C){
		printf("Alguem nao esta satisfeito...");
		return 0;
	}
	if(C==E && F!=A){
		printf("Alguem nao esta satisfeito...");
		return 0;
	}
	if(C!=E && F==A){
		printf("Alguem nao esta satisfeito...");
		return 0;
	}
	if(A==C || A==E || A==G){
		printf("Alguem nao esta satisfeito...");
		return 0;
	}
	if(B==A || B==D){
		printf("Alguem nao esta satisfeito...");
		return 0;
	}
	if(H==G || H==F){
		printf("Conseguimos times suficientes!");	
	}
	else
		printf("Alguem nao esta satisfeito...");
		
	
}
	return 0;
}
