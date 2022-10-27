//questão: Sherliro impede The Wrath of Khanmerer, thehuxley

#include <stdio.h>

/*
4522(divisivel por 7 e 17) 10(vai pra 20)
133 1 (produto impar divisivel por 19 -> 133/2 = 66)
266(divisivel por 7) 2(vai pra 4)
1726  6 (ambos se mant�m)
34 101	(vai a 0)
101926
*/

int main(){
	 int ID1, ID2, ID3, ID4, ID5, P1, P2, P3, P4, P5, totalFinal, tot1, tot2, tot3, tot4, tot5;
	 scanf("%i %i", &ID1, &P1);
	 scanf("%i %i", &ID2, &P2);
	 scanf("%i %i", &ID3, &P3);
	 scanf("%i %i", &ID4, &P4);
	 scanf("%i %i", &ID5, &P5);
	 scanf("%i", &totalFinal);
	 
	if(ID1==ID2 || ID1==ID3 || ID1==ID4 || ID1==ID5 || ID2==ID3 || ID2==ID4 || ID2==ID5 || ID3==ID4 || ID3==ID5 || ID4==ID5){ 		//IDS IGUAIS
	 	printf("UEPAAA TEMOS UM RATINHO");
	 	return 0;}	
	 	
	if(ID1<0 || ID2<0 || ID3<0 || ID4<0 || ID5<0 || P1<0 || P2<0 || P3<0 || P4<0 || P5<0) 	
		return 0;
										
	if(ID1%3==0 || ID1%5==0 || ID1%7==0){
		if(ID1%2==0)		//CHECA A REGRA 1 PARA O ID1
			P1 = P1*2;}
	else{
		if(ID1%17==0 && ID1%2==0)	//CHECA O ID PARA A REGRA 3
			ID1=0;}
		
	if(ID2%3==0 || ID2%5==0 || ID2%7==0){
		if(ID2%2==0)		//CHECA A REGRA 1 PARA O ID2
			P2 = P2*2;}
	else{
		if(ID2%17==0 && ID2%2==0)	//CHECA O ID PARA A REGRA 3
			ID2=0;}
								
	if(ID3%3==0 || ID3%5==0 || ID3%7==0){
		if(ID3%2==0)		//CHECA A REGRA 1 PARA O ID3
			P3 = P3*2;}
	else{
		if(ID3%17==0 && ID3%2==0)	//CHECA O ID PARA A REGRA 3
			ID3=0;}
							
	if(ID4%3==0 || ID4%5==0 || ID4%7==0){
		if(ID4%2==0)		//CHECA A REGRA 1 PARA O ID4
			P4 = P4*2;}
	else{
		if(ID4%17==0 && ID4%2==0)	//CHECA O ID PARA A REGRA 3
			ID4=0;}
								
	if(ID5%3==0 || ID5%5==0 || ID5%7==0){
		if(ID5%2==0)		//CHECA A REGRA 1 PARA O ID5
			P5 = P5*2;}
	else{
		if(ID5%17==0 && ID5%2==0)	//CHECA O ID PARA A REGRA 3
			ID5=0;}
				
		
								
		tot1 = ID1*P1;
		tot2 = ID2*P2;
		tot3 = ID3*P3; 			//CALCULA OS TOTAIS
		tot4 = ID4*P4;
		tot5 = ID5*P5;			
				
		
							
		if(tot1%2!=0)													//CHECA A REGRA 2 PARA O ID1
			if(tot1%11==0 || tot1%13==0 || tot1%17==0 || tot1%19==0)
				tot1 = tot1/2;
				
		if(tot2%2!=0)													//CHECA A REGRA 2 PARA O ID2
			if(tot2%11==0 || tot2%13==0 || tot2%17==0 || tot2%19==0)
				tot2 = tot2/2;
				
		if(tot3%2!=0)													//CHECA A REGRA 2 PARA O ID3
			if(tot3%11==0 || tot3%13==0 || tot3%17==0 || tot3%19==0)
				tot3 = tot3/2;
				
		if(tot4%2!=0)													//CHECA A REGRA 2 PARA O ID4
			if(tot4%11==0 || tot4%13==0 || tot4%17==0 || tot4%19==0)
				tot4 = tot4/2;
				
		if(tot5%2!=0)													//CHECA A REGRA 2 PARA O ID5
			if(tot5%11==0 || tot5%13==0 || tot5%17==0 || tot5%19==0)
				tot5 = tot5/2;
						
/*	
		printf("%i\n", tot1);
		printf("%i\n", tot2);
		printf("%i\n", tot3);
		printf("%i\n", tot4);
		printf("%i\n", tot5);
*/
			
		if(totalFinal != tot1+tot2+tot3+tot4+tot5){
			printf("UEPAAA TEMOS UM RATINHO");
	 		return 0;
		}	
		else{
			printf("barra limpa, khan");
			return 0;
		}	
		
	return 0;
}
