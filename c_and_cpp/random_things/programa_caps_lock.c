//programa simulador de capslock
#include <stdio.h>

int main(){
	
	char caractere;
	
	printf("Digite um letra maiuscula ou minuscula: ");
	scanf("%c", &caractere);
	
	if(caractere>=65 and caractere<=90){
		caractere+=32;
		printf("Este eh seu numero minusculo: %c.", caractere);
	}
	else if(caractere>=97 and caractere<=122){
		caractere-=32;
		printf("Este eh seu numero maiusculo: %c.", caractere);
	}
	return 0;
}
