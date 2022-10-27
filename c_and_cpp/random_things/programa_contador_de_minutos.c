//programa contador de minutos
#include <stdio.h>

int main(){
	
	int horas, minutos, totalmin;
	
	printf("Digite um horário respectivamente em horas e minutos.\n");
	
	printf("horas: ");
	scanf("%i", &horas); 
	printf("minutos: ");
	scanf("%i", &minutos);
	
	totalmin = horas*60 + minutos;
	
	printf("O total em minutos eh: %i.", totalmin);
	
	return 0;
}
