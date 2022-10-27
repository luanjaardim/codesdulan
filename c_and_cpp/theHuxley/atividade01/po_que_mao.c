//questão: Pô, que mao, thehuxley

#include <stdio.h>

int main(){
	int N, p1, p2, p3;
	scanf("%i", &N);
	scanf("%i", &p1);
	scanf("%i", &p2);
	scanf("%i", &p3);
	
	if(N>=0 && p1>0 && p2>0 && p3>0 && N<=1000 && p1<=1000 && p2<=1000 && p3<=1000){
		
		if(N>=p1+p2+p3){
			printf("3");
			return 0;}
		
		if(N>=p1+p2 || N>=p3+p2 || N>=p1+p3){
			printf("2");
			return 0;}
		
		if(N>=p1 || N>=p3 || N>=p2){
			printf("1");
			return 0;}
			
		if(N<p1 && N<p3 && N<p2){
			printf("0");
			return 0;}
		
	}
	else
		printf("**");
		
	return 0;
}
