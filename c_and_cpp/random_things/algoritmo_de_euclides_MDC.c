//Utilizando do Algoritmo de Euclides para o cálculo do MDC de dois números

#include <stdio.h>

long Euclides(long a, long b);
void Euclides_recursivo(long a, long b, long *mdc);

int main()
{

long num1=0, num2=0, mdc=1;

printf("Digite dois numeros para que eu encontre O MDC deles!\n");
scanf("%ld %ld", &num1, &num2);

mdc = Euclides(num1, num2);
//Euclides_recursivo(num1, num2, &mdc);

printf("O MDC eh: %ld", mdc);
        
return 0;
}

long Euclides(long a, long b)
{
//Solução através de while loop's
    long tmp;
        while(b!=0)
        {
        tmp=b;
        b=a%b;
        a=tmp;
        }
    return a;
}

void Euclides_recursivo(long a, long b, long *mdc)
{
//Utilizando da recursividade para encontrar o resto entre "a" e "b" até que "b" seja 0
    if(b==0)
        *mdc = a;
    else
        Euclides_recursivo(b, a%b, mdc);
}