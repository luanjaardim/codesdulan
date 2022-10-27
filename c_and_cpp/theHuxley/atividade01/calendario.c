//questão: Data válida, thehuxley

#include <stdio.h>

int main(){
	
	int dias, meses, anos;
	scanf("%i %i %i", &dias, &meses, &anos);
	
	if(anos<1900 || anos>2100 || meses>12 || meses<1)
		printf("invalida");
	
	else{
		if(anos>1900 && anos<2100){
			
			if(anos%4==0){ //anos bissextos
			
				if(meses==2){
					if(dias<=29 && dias>0){
					printf("valida");
					return 0;	
					}
				}
				if(meses==1 || meses==3 || meses==5 || meses==7 || meses==8 || meses==10 || meses==12){
					if(dias<=31 && dias>0){
						printf("valida");
						return 0;
					}
				}
				if(meses==4 || meses==6 || meses==9 || meses==11){
					if(dias<=30 && dias>0){
						printf("valida");
						return 0;
				}
				
			}
    	}
			else{
				if(meses==2){
					if(dias<=28 && dias>0){
					printf("valida");
					return 0;	
					}
				}
				if(meses==1 || meses==3 || meses==5 || meses==7 || meses==8 || meses==10 || meses==12){
					if(dias<=31 && dias>0){
						printf("valida");
						return 0;
					}
				}
				if(meses==4 || meses==6 || meses==9 || meses==11){
					if(dias<=30 && dias>0){
						printf("valida");
						return 0;
				}
				
			}
		}
		
		
	}
	printf("invalida");
}
}
