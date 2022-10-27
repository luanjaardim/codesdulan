#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void preencheConjuntos(int **A, int *quant){
    int i =0, j;
    char opcao = 's';

do {
scanf("%d %d", &A[0][i], &A[1][i]);
i++;
printf("ha mais algum par, sim ou nao? (s/n) ");
scanf(" %c", &opcao);

if(opcao == 's'){
    A[0] = (int *) realloc(A[0], (i+1) * sizeof(int));
    if(A[0]==NULL) exit(1);

    A[1] = (int *) realloc(A[1], (i+1) * sizeof(int));
    if(A[1]==NULL) exit(1);
}

} while(opcao == 's');

*quant = i;
}

int *preencheDominio(int *quantD){
    int i, *dominio;

    printf("Quantos elementos possui o conjunto? ");
    scanf("%d", quantD);
    printf("Digite-os:\n");
    dominio = (int *) malloc(*quantD * sizeof(int));
    if(dominio == NULL) exit(1);

    for(i=0; i<*quantD; i++)
        scanf("%d", &dominio[i]);

    return dominio;
}

int checaComposicao(int *CA, int *domB, int quantCA, int quantDB){
    int i, j, k=0, iguais = 0;
    if(quantCA != quantDB){
        printf("Nao pode fazer composicao.");
        iguais = 1;
    }
    for(i=0; i<quantCA && iguais == 0; i++){
        k=0;
        for(j=0; j<quantDB && k==0; j++){
            if(CA[i] == domB[j]){
                k=1;
            }      
        }
        if(k==0){
            printf("Nao pode fazer composicao.");
            iguais = 1;
        }
    }
    return iguais;
}

void ordenElementos(int *dominio, int quant){
int i, j, tmp, minimo;
for(i = 0; i < quant-1 ; i++)  {
  minimo = i ;

  for(j = i+1; j < quant ; j++ ) {
    if(dominio[ j ] < dominio[ minimo ])  {                
      minimo = j ;
 }
}
    tmp = dominio[i];
    dominio[i] = dominio[minimo];
    dominio[minimo] = tmp;
}
}

int **matrizLogica(int quantD, int quantC, int quantF, int *dominio, int *contra, int **funcao){
    int i, j, k;
    int **Mat = (int **) calloc(quantD, sizeof(int *));
        if(Mat == NULL) exit(1);
        for(i=0; i<quantD; i++){
            Mat[i] = (int *) calloc(quantC, sizeof(int));
                if(Mat[i]==NULL) exit(1);
        }
    for(i=0; i<quantF; i++)
        for(j=0; j<quantD; j++)
            for(k=0; k<quantC; k++){
                if(funcao[0][i] == dominio[j] && funcao[1][i] == contra[k])
                    Mat[j][k] = 1;
            }
    return Mat;
}

int **composicaoDeMatrizes(int **MatA, int **MatB, int quantDA, int quantCA, int quantDB, int quantCB){
    int i, j, t, achei;
    int **MatComposta = (int **) calloc(quantDA, sizeof(int *));
        if(MatComposta == NULL) exit(1);
        for(i=0; i<quantDA; i++){
            MatComposta[i] = (int *) calloc(quantCB, sizeof(int));
                if(MatComposta[i] == NULL) exit(1);
        }
    for(i=0; i<quantDA; i++)
        for(j=0; j<quantCB; j++){
            achei=0;
            for(t=0; t<quantCA && achei==0; t++){
                if(MatA[i][t] == 1 && MatA[i][t] == MatB[t][j]){
                        achei=1;
                }
            }  
            if(achei == 1)
                MatComposta[i][j]=1;
        }
        
    return MatComposta;
}

int main(){
    int *domA = NULL, *domB = NULL, *CA = NULL, *CB = NULL, **A = NULL, **B = NULL, **MatA = NULL, **MatB = NULL, **MatComposta = NULL;

A = (int **) malloc(2 * sizeof(int *));
    if(A == NULL) exit(1);
A[0] = (int *) malloc(sizeof(int));
    if(A[0] == NULL)    exit(1);
A[1] = (int *) malloc(sizeof(int));
    if(A[1] == NULL)    exit(1);

B = (int **) malloc(2 * sizeof(int *));
    if(B == NULL) exit(1);
B[0] = (int *) malloc(sizeof(int));
    if(B[0] == NULL)    exit(1);
B[1] = (int *) malloc(sizeof(int));
    if(B[1] == NULL)    exit(1);
 

    int i = 0, j, quantA, quantDA, quantCA, quantB, quantDB, quantCB, iguais;
    char opcao = 's';
printf("Digite os elementos do dominio A:\n");   
domA = preencheDominio(&quantDA);
printf("Digite os elementos do contradominio A:\n"); 
CA = preencheDominio(&quantCA);
printf("Digite os elementos do dominio B:\n"); 
domB = preencheDominio(&quantDB);

iguais = checaComposicao(CA, domB, quantCA, quantDB);
    if(iguais == 0){    //existe composição
    
printf("Digite os elementos do contradominio B:\n"); 
CB = preencheDominio(&quantCB);

    printf("Digite os pares do conjunto 1:\n");
    preencheConjuntos(A, &quantA);
    printf("Digite os pares do conjunto 2:\n"); 
    preencheConjuntos(B, &quantB);  

    ordenElementos(domA, quantDA); 
    ordenElementos(domB, quantDB);  
    ordenElementos(CA, quantCA);
    ordenElementos(CB, quantCB);
    //printf("Ha composicao.");

    MatA = matrizLogica(quantDA, quantCA, quantA, domA, CA, A);
    MatB = matrizLogica(quantDB, quantCB, quantB, domB, CB, B);

    MatComposta = composicaoDeMatrizes(MatA, MatB, quantDA, quantCA, quantDB, quantCB);
    }

    /* for(i=0; i<quantDA; i++){
        for(j=0; j<quantCA; j++)
            printf("%d ", MatA[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=0; i<quantDB; i++){
        for(j=0; j<quantCB; j++)
            printf("%d ", MatB[i][j]);
        printf("\n");
    } */
    printf("\n");
    for(i=0; i<quantDA; i++){
        for(j=0; j<quantCB; j++)
            printf("%d ", MatComposta[i][j]);
        printf("\n");
    }
        
    for(i=0; i<quantDA; i++){
        free(MatComposta[i]);
        }
    for(i=0; i<quantDA; i++){
        free(MatA[i]);
        }
    for(i=0; i<quantDB; i++){
        free(MatB[i]);
        }
    free(MatComposta);
    free(MatA);
    free(MatB);
    free(CA);
    free(CB);
    free(domA);
    free(domB);
    free(A[0]);
    free(A[1]);
    free(A);
    free(B[0]);
    free(B[1]);
    free(B);

return 0;
}