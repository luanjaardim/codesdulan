//questão: Dias entre datas, thehuxley

#include <stdio.h>

int main(){
			
	long long int diferenca=0, ano1, ano2;
	int dia1, dia2, mes1, mes2, mes1x=0, mes2y=0;
	
	scanf("%d/%d/%lld", &dia1, &mes1, &ano1);
	scanf("%d/%d/%lld", &dia2, &mes2, &ano2);

	for(int cont=ano1; cont<ano2; cont++){
		if(cont%4==0 && cont%100!=0){
			diferenca++;
//			printf("%i %i\n", diferenca, cont);
		}
		if(cont%100==0 && cont%400==0){
			diferenca++;
//		printf("%i %i\n", diferenca, cont);
		}
	}
	
	for(int x=1; x<=mes1-1; x++){
		if(x==2){
			if(ano1%4 == 0 && ano1%100!=0)
				mes1x+=29;
			else if(ano1%100==0 && ano1%400==0)
				mes1x+=29;
			else if(ano1%100==0 && ano1%400!=0 || x==2)
				mes1x+=28;}
		if(x==1 || x==3 || x==5 || x==7 || x==8 || x==10)
			mes1x+=31;
		if(x==4 || x==6 || x==9 || x==11)		
			mes1x+=30;
	}
	for(int y=1; y<=mes2-1; y++){
		if(y==2){
			if(ano2%4 == 0 && ano2%100!=0)
				mes2y+=29;
			else if(ano2%100==0 && ano2%400==0)
				mes2y+=29;
			else if(ano2%100==0 && ano2%400!=0 || y==2)
				mes2y+=28;}
		if(y==1 || y==3 || y==5 || y==7 || y==8 || y==10)
			mes2y+=31;
		if(y==4 || y==6 || y==9 || y==11)		
			mes2y+=30;
		
	}	
//	printf("%i\n", diferenca);
	diferenca += (ano2-ano1)*365;
//	printf("%i\t %i\t %i\n", diferenca, mes2y, mes1x);
	diferenca += mes2y-mes1x;
//	printf("%i\n", diferenca);
//	printf("%i\t %i\t %i\n", diferenca, dia2, dia1);
	diferenca += dia2 - dia1;
	printf("%i\n", diferenca);
		
	return 0;
}
