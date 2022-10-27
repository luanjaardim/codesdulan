//questão: A disputa final, thehuxley

#include <stdio.h>

int main(){
	
	int i;
	scanf("%i", &i);
	
	if(i>=0 && i<=11){
	
	switch(i){
		case 0:
			printf("rosa rosa verde rosa\n"); break;
		case 1:
			printf("verde rosa verde rosa\n"); break;
		case 2:
			printf("verde verde verde rosa\n"); break;
		case 3:
			printf("rosa verde verde rosa\n"); break;
		case 4:
			printf("rosa rosa rosa verde\n"); break;
		case 5:
			printf("verde rosa rosa verde\n"); break;
		case 6:
			printf("verde verde rosa verde\n"); break;
		case 7:
			printf("rosa verde rosa verde\n"); break;
		case 8:
			printf("verde verde verde verde\n"); break;
		case 9:
			printf("rosa rosa rosa rosa\n"); break;
		case 10:
			printf("rosa rosa verde verde\n"); break;
		case 11:
			printf("verde verde rosa rosa\n"); break;
		
	}
	
	}
	else
		printf("id nao existente");
		
		
	return 0;
}
