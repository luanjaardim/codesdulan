#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}   Data;

int main(){

//UTILIZACAO BASICA DE PONTEIROS

/* char c = 'A';
char *p_c;  //ponteiro de char
printf("%c\n", c);

p_c = &c;   //p_c vai guardar o endereço de memoria(&) de c
*p_c = 'B'; //p_c vai acessar o endereço de c e alterar seu valor 'A' -> 'B'
printf("%c", c); */

// PONTEIROS TRABALHANDO EM CONJUNTO COM VETORES

/* int vet[5]= {1, 2 , 3, 4, 5};
int *pVet;
pVet = vet;     //pVet agr possui o endereco de vet, essa é a nomenclatura mais simples(sem o &)

pVet[0] = 500;  //alem de n precisar de * ao inicio
pVet[4] = 100;  //e trabalhar com os enderecos com uma nomenclatura semelhante a de vetores

for(int i=0; i<5; i++)
    printf("%i\n", vet[i]); */


// UM POUCO SOBRE O ARMAZENAMENTO DE ENDERECOS

/* int num = 50, i=0;
int *ponteiro = &num, *pontI = &i;

printf("endereco de num: %p\n", &num);
printf("endereco de num: %p\n", ponteiro);
printf("endereco de num: %p\n", &i);
printf("endereco de num: %p\n", pontI); */

// CASTING DE PONTEIROS

/* int num=15455, i;
char *pChar = (char *) &num;    //pChar terá o endereco de num, mas, como é um char, aponta para apenas um byte

for(i=0; i<sizeof(int); i++)  //este for analisa o valor que cada byte de num contém(sizeof(int) é 4, pois o tipo int é formado por 4 bytes)
    printf("%d\n", pChar[i]);   // 95, em binário, é a parte menos significativa de 15455
                                // 60 vem logo depois completando o número 15455
//outra forma de escrever pChar[i] é com *(pChar + i)

//15455 em binário é 11110001011111
//os 8 bits menos significativos são o 95: 01011111
//o restante se torna em 60: 00111100(os 0's na frente n tem valor significativo, são apenas para completar os 8 bits)

for(i=0; i<sizeof(int); i++){ //neste for será mostrado o endereco de memoria de casa byte de num
    printf("%p\n", pChar);
    pChar++;}//isso é uma soma de ponteiros, como pChar é do tipo char o endereco terá o acréscimo de 1
             //entretanto caso o tipo fosse int, por exemplo, a soma seria de 4, pois o tipo int tem 4 bytes
 */

// PONTEIROS QUE APONTAM PARA ESTRUTURAS

/* Data *pont;

pont = (Data *) malloc(sizeof(Data));
if(pont == NULL) exit(1);

pont -> dia = 12;   //quando um ponteiro aponta para um elemento de uma estrutura podemos usar
pont[0].mes = 11;   //essa setinha (->), ou usar o [i] antes do ponto, nesse caso o ponteiro está agindo
pont[0].ano = 2002; //como um ponteiro de elemento único do tipo Data.

printf("%i/", pont -> dia);
printf("%i/", pont -> mes);
printf("%i", pont[0].ano); 

free(pont);
*/


return 0;                     
}