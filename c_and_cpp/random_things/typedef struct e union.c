#include <stdio.h>

typedef struct {    //ciração do tipo Reais
    float parteReal;
} Reais;

typedef struct{     //criação do tipo Complexos
    Reais real;//acessa a parte real a partir de um elementos do tipo Reais(real)
    float parteImaginaria;
    char sinal;
} Complexos;

typedef union{
    int inteiro;
    double flutuante;
} Uniao;


int main(){
/* 
    //UTILIZACAO TYPEDEF STRUCT
    //nela podemos usar diversos tipos de forma individual, um de cada vez ou ao mesmo tempo.
    Complexos num;
    //Complexos num = {3.5, 2, '-'};//Declaração escrita, deve seguir a ordem das variáveis na struct criada(parteReal, parteImaginaria e sinal)
    scanf("%f %c %f", &num.real.parteReal, &num.sinal, &num.parteImaginaria);
    printf("%.2f %c %.2fi", num.real.parteReal, num.sinal, num.parteImaginaria);
                        //num é um tipo Complexos e para acessar a "parteReal" deve acessar antes "real", que é uma vriável do tipo Reais
*/
/* 
    //UTILIZACAO TYPEDEF UNION
    //já na union uma mesma regiao de memoria é utilizada para mais de um tipo de variável
    //a região total ficará, portanto, com o tamanho do maior tipo que foi utilizado
    
    Uniao numero;
    numero.inteiro=10;
    printf("%i ", numero.inteiro);
    numero.flutuante=10.05;
    printf("%.2lf\n", numero.flutuante);
    numero.inteiro=200;
    numero.flutuante=566.0525;
    printf("%.4lf %i", numero.flutuante, numero.inteiro); //como último valor atribuído foi o de flutuante
                                                          //int n consegue lê=lo.

    //o benefício de union é utilizar uma região apenas para diversos tipos de variáveis
    //criando uma "variável variável", entretanto os valores podem ser confundidos entre os tipos
    //logo só podemos usar um dos tipos de cada vez.
*/


    return 0;
}