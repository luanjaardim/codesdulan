//questão: Teh Adventujrs of Meme Man: Volta do Mercado, thehuxley

#include <stdio.h>

int main(){
	
	int tempo;
	scanf("%i", &tempo);
	
	if(tempo<0)
		printf("Meme man quebrou o tempo! De volta ao transito :(\n");
	
	else{
	
	if(tempo<62)
		printf("...Ainda no transito...\n");
	
	else if(tempo>=31*24+28*24+31*24+30*24+31*24+4*24 && tempo<31*24+28*24+31*24+30*24+31*24+5*24){	//3720 e 3768
		printf("Stonks has been born!\n");
	}
	else{
		printf("Lar doce lar");
	}
}
	return 0;
}
