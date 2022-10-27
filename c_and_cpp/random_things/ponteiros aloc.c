#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Aluno;

int main() {

    //exemplo: turma com alocação dinamica de um vetor de alunos

 Aluno *turma=NULL; // Ponteiro para Aluno
    int i=0;
    char prox='s'; // prox = 's' => sim; 'n' => para
    while(prox == 's') {
        turma = (Aluno *) realloc(turma, (i+1) * sizeof(Aluno));
        if(turma==NULL) exit(1);
        printf("Digite nome do %do aluno: ", i+1);
        scanf(" %49[^\n]", turma[i].nome);
        printf("Digita sua idade: ");
        scanf("%d", &turma[i].idade);
        i++;
        printf("Tem proximo (s/n)? ");
        scanf(" %c", &prox);
    }
    free(turma); 


    //////////
/* 
    //fORMA MAIS SEGURA DE REALIZAR UMA ALOCACAO DINAMICA

    //utiliza de dois vetores para garantir que, caso realloc n tenha sucesso,
    //os enderecos de vet sejam guardados, pois, quando realloc falha, o retorno da 
    //funcao é NULL, no caso de usar apenas vet perderiamos seus valores, pois o endereco
    //armazenado se transformaria em NULL, além de n liberar a memória utilizada(free), já quando 
    //utilizado vetAt garantimos os valores de vet e apenas vetAt vira NULL e então podemos
    //liberar a memória de vet.

     int n = 0, *vet = NULL, *vetAt = NULL, tmp;
    // Ler inteiros do teclado enquanto > 0
    printf("Digite um valor (<= 0 para): ");
    scanf("%d", &tmp);
    while(tmp > 0) {
        vetAt = (int *) realloc(vet, (n+1)*sizeof(int));
        if(vetAt==NULL) { free(vet); exit(1); }
        vet = vetAt;
        vetAt[n] = tmp;
        n++;
        printf("Digite um valor (<= 0 para): ");
        scanf("%d", &tmp);
    }
    for(tmp=0; tmp<n; tmp++)
        printf("vet[%d]=%d\n", tmp+1, vetAt[tmp]);
    free(vetAt); 
*/

    // PONTEIROS DUPLOS (PONTEIROS DE PONTEIROS = AGINDO COMO VETORES DE VETORES OU MATRIZES)
/* 
    int **mat;  //será uma matriz 2x2

    mat = (int **) malloc(2*sizeof(int *));
    if(mat == NULL) exit(1);

    for(int i=0; i<2; i++){
        mat[i] = (int *) malloc(2*sizeof(int));
        if(mat[i] == NULL) exit(1);
    }
    
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    printf("%i ", mat[i][j]);

    for(int i=0; i<2; i++)
        free(mat[i]);
    free(mat);
 */

    return 0;
}