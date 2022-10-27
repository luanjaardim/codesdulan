//questão: Insvestimentos N1, thehuxley

#include <stdio.h>

int main(){
	int dinheiro, divida, dividaF, diferenca, resto;
	scanf("%i %i", &dinheiro, &divida);
	
	if(divida%100!=0){
		resto=divida%100;
		dividaF = divida-resto+100;}
	if(divida%100==0){
	 	dividaF=divida;
	}
	
	if(dinheiro<divida){
		printf("Pedro vai ter que fugir\n");
		return 0;}
		
	if(dinheiro==divida && dinheiro<dividaF){
		printf("Pedro vai ter que fugir\n");
		return 0;}
	
	if(dividaF==0){
		diferenca = dinheiro-dividaF;
		printf("Esta pago\n");
		printf("Sobrou %i\n", diferenca);
		return 0;}
	
	if(dinheiro==divida && dinheiro==dividaF){
		diferenca = dinheiro-dividaF;
		printf("Esta pago\n");
		printf("Sobrou %i\n", diferenca);
		return 0;}
	
	if(dinheiro>divida && dinheiro<dividaF){
		printf("Pedro vai ter que fugir\n");
		return 0;}
	
	if(dinheiro>divida && dinheiro==dividaF){
		diferenca = dinheiro-dividaF;
		printf("Pegou mais\n");
		printf("Esta pago\n");
		printf("Sobrou %i\n", diferenca);
		return 0;}
		
	if(dinheiro>divida && dinheiro>dividaF){
		diferenca = dinheiro-dividaF;
		printf("Pegou mais\n");
		printf("Esta pago\n");
		printf("Sobrou %i\n", diferenca);
		return 0;}
	
	return 0;
}
