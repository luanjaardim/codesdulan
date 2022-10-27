//questão: A Sequência de Josué, thehuxley

#include <stdio.h>

int main(){
	
	char e1, e2, e3;
	scanf("%c %c %c", &e1, &e2, &e3);
	
	if(e1>90 || e1<65 || e2>90 || e2<65 || e3>90 || e3<65 )
		printf("Etiquetas erradas!");
	else{
	
		if(e1==65|e1==69||e1==73||e1==79||e1==85||e2==65|e2==69||e2==73||e2==79||e2==85||e3==65|e3==69||e3==73||e3==79||e3==85){ //checa se h? vogais
		
			if(e2==e1+1 && e3==e2+1 || e3==e1+1 && e2==e3+1 ||e1==e2+1 && e3==e1+1 || e3==e2+1 && e1==e3+1 || e2==e3+1 && e1==e2+1 || e1==e3+1 && e2==e1+1){
			printf("Sequ?ncia quase perfeita.");
			return 0;}
			
			if(e2==e1+2 && e3==e2+2 || e3==e1+2 && e2==e3+2 ||e1==e2+2 && e3==e1+2 || e3==e2+2 && e1==e3+2 || e2==e3+2 && e1==e2+2 || e1==e3+2 && e2==e1+2){
			printf("Bissequ?ncia quase perfeita.");	
			return 0;}
			
			if(e2==e1+3 && e3==e2+3 || e3==e1+3 && e2==e3+3 ||e1==e2+3 && e3==e1+3 || e3==e2+3 && e1==e3+3 || e2==e3+3 && e1==e2+3 || e1==e3+3 && e2==e1+3){
			printf("Trissequ?ncia quase perfeita.");
			return 0;}
	}
		else{ 										//todas s?o consoantes		
			if(e2==e1+1 && e3==e2+1 || e3==e1+1 && e2==e3+1 ||e1==e2+1 && e3==e1+1 || e3==e2+1 && e1==e3+1 || e2==e3+1 && e1==e2+1 || e1==e3+1 && e2==e1+1){   
			printf("Sequ?ncia perfeita.");
			return 0;}
			
			if(e2==e1+2 && e3==e2+2 || e3==e1+2 && e2==e3+2 ||e1==e2+2 && e3==e1+2 || e3==e2+2 && e1==e3+2 || e2==e3+2 && e1==e2+2 || e1==e3+2 && e2==e1+2){
			printf("Bissequ?ncia perfeita.");
			return 0;}	
			
			if(e2==e1+3 && e3==e2+3 || e3==e1+3 && e2==e3+3 ||e1==e2+3 && e3==e1+3 || e3==e2+3 && e1==e3+3 || e2==e3+3 && e1==e2+3 || e1==e3+3 && e2==e1+3){
			printf("Trissequ?ncia perfeita.");
			return 0;}
			
	}
	printf("S? umas letras ai...");
}
	return 0;
}
