//Lista 07 de ponteiros, Aluno: Luan Gabriel Araujo Jardim (lgaj)

#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int matricula;
    float nota;
    char curso[20];

} Aluno;


int main(){

    //1ª questão

/*
    char c = 'a', *pc = &c;

//a)
    printf("%p %c\n", &c, c);

//b)
    printf("%p %c\n", pc, *pc);

//c)
    printf("%p\n", &pc);

//d)
    printf("%p %p\n", &*pc, *&pc);
*/

//e) 
 /*   Um ponteiro armazena um endereco de memoria, ao utilizar a notacao "*pc" o valor guardado 
    no endereco para o qual o ponteiro está apontando é acessado, ao imprimir o endereco(&) do 
    valor acessado a saída será o próprio endereco guardado em "pc", isto é, o endereco de "c". 
      Já no segundo caso há o acesso do endereco de um ponteiro, um ponteiro duplo, logo, o acesso 
    deste ponteiro duplo tem como saída o conteudo guardado em "pc" que é o endereco de "c".
      Desta forma, é perceptivel o motivo da igualdade nas impressoes das duas formas apresentadas.
 */

    //2ª questão

/*
    int vet[5] = {1, 2, 3, 4, 5}, *p = vet, i;

//a)
    printf("%p %p\n", &vet, p);

//b)    
    for(i = 0; i < 5; i++)
        printf("%d ", p[i]);
    printf("\n");

//c)
    for(i = 0; i < 5; i++)
        printf("%d ", *(p + i));
    printf("\n");

//d)
    for(i = 0; i < 5; i++)
        printf("%d ", vet[i]);
    printf("\n");
    for(i = 0; i < 5; i++)
        printf("%d ", *(vet + i));
    printf("\n");
*/

    //3ª questão

/* 
Aluno aluno;

scanf("%d %f %19[^\n]", &aluno.matricula, &aluno.nota, aluno.curso);

Aluno *pAluno = &aluno;

printf("%d %.2f %s", pAluno -> matricula, pAluno -> nota, pAluno -> curso);
*/

    //4ª questão

/*
int n, *vet = NULL;

scanf("%d", &n);

while(n > 0){

     vet = (int *) realloc(vet, n * sizeof(int));
    if(vet == NULL){
        printf("PROBLEMA NA ALOCACAO!\n");
        exit(1);
    }
    else
    printf("A ALOCACAO FOI UM SUCESSO!\n");
 
    scanf("%d", &n);
    if(n <= 0)
    free(vet); //coloquei "free()" dentro de "while" para o caso do primeiro scanf ser <=0 e nao 
               //alocar nenhuma vez na memoria, dando free em um ponteiro que nao alocou memoria.
}
printf("VALOR INCOMPATIVEL, FIM DAS ALOCACOES!\n");
*/

return 0;
}