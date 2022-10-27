//questão: Investimentos N2, thehuxley

#include <stdio.h>

int main(){
	
	int ac, velo, curvas, x =0;
	scanf("%i %i", &ac, &curvas);
	
	while(x==0){
		if(curvas>=0)
			curvas--;
		
		if(curvas<=0)
			x=1;
			
		velo=30;
		ac++;
		
		if(velo%ac == 0)
			printf("Curvou\n");
		else{
			printf("Pedro se cagou todo e foi pego.\n");
			return 0;
		}
}
	
	return 0;
}
