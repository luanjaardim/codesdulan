//questão: Teh Adventujrs of Meme Man: Loop do Mercado, thehuxley

#include <stdio.h>

int main(){
	
	 int temp, saida, seg, i;
	 
	 scanf("%i %i", &seg, &saida);
	 
	 saida*=60;
	 
 	for(int i=0; i<saida; i++){
 		if(seg!=0){
 		if(seg%13 == 0){
 			seg-=60;
 			if(seg%60 == 0)
 			 seg+=90;
		 }
		}
		else{
			printf("%i", i-seg);
			return 0;
		}
 		seg++;
	 }

	printf("fui pedir comida mesmo");
	return 0;

}
