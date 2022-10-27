//questão: Ajude o Mateus, thehuxley

#include <stdio.h>

int main(){
	
	int reais, pamin, pamax, comin, comax, pemin, pemax, resulpa, resulco, resulpe; 
	scanf("%i", &reais);
	scanf("%i %i %i %i %i %i", &pamin, &pamax, &comin, &comax, &pemin, &pemax);
	
	resulpa=pamax;
	resulpe=pemax;
	resulco=comax;
	
	for(int pax=pamin; pax<=pamax; pax++){
		
		for(int cox=comin; cox<=comax; cox++){
			
			for(int pex=pemin; pex<=pemax; pex++){
				if(pax+cox+pex == reais){
					
					if(pax<resulpa){
					resulpa=pax;
					resulpe=pex;
					resulco=cox;}
					
					if(pax==resulpa){
						if(pex<resulpe){
						resulpa=pax;
						resulpe=pex;
						resulco=cox;}
					}
				}		
			}
		}
	}
	//printf("%i %i %i", resulpa, resulco, resulpe);
	
	if(resulpa+resulco+resulpe == reais){
	printf("S\n");
	printf("%i %i %i", resulpa, resulco, resulpe);}
	
	else
	printf("N");
	
	return 0;
}
