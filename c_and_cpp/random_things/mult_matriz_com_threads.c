#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define f(a, b) for(int a=0; a<b; a++)
#define pt pthread_

int **mat, **mat2, *tam;

typedef struct elem{
    int x, y;
    long long val;
} elem;

void *mult_mat(void *arg)
{
    elem *e = (elem *) arg;
    e->val = 0;
    for(int i=0; i < *tam; i++)
        e->val += mat[e->x][i] * mat2[i][e->y];
    return (void *) e;
}

int main(int argc, char *argv[])
{
    int linhas, colunas;
    printf("Linhas e colunas da matriz 1:\n");
    scanf("%d %d", &linhas, &colunas);
    mat = (int **) malloc(sizeof(int *) * linhas);
        if(mat == NULL) return 1;
    f(i, linhas){
        mat[i] = (int *) malloc(sizeof(int) * colunas);
            if(mat[i] == NULL) return 1;
    }
    printf("Elementos da matriz 1:\n");
    f(i, linhas)
        f(j, colunas)
            scanf("%d", &mat[i][j]);

    printf("Linhas e colunas da matriz 2:\n");
    int linhas2, colunas2;
    scanf("%d %d", &linhas2, &colunas2);

    if(linhas2 == colunas){
        mat2 = (int **) malloc(sizeof(int *) * linhas2);
            if(mat2 == NULL) return 1;
        f(i, linhas2){
            mat2[i] = (int *) malloc(sizeof(int) * colunas2);
                if(mat2[i] == NULL) return 1;
        }
        long long resultado[linhas][colunas2];

        printf("Elementos da matriz 2:\n");
        f(i, linhas2)
            f(j, colunas2)
                scanf("%d", &mat2[i][j]);
        
        int cnt = 0;
        pthread_t th[linhas*colunas2];
        f(i, linhas)
            f(j, colunas2)
            {
                elem *e = (elem *) malloc(sizeof(elem));
                e->x = i; e->y = j; 
                tam = &colunas; //ou linhas2
                pthread_create(th + cnt, NULL, &mult_mat, (void *)e);
                cnt++;
            }
        f(i, linhas*colunas2)
        {
            elem *e;
            pthread_join(th[i], (void **) &e);
            resultado[e->x][e->y] = e->val;
            free(e);
        }

        printf("Resultado:\n");
        f(i, linhas){
            f(j, colunas2)
                printf("%lld ", resultado[i][j]);
            printf("\n");
        }

        f(i, linhas2)
            free(mat2[i]);
        free(mat2);   
    }
    else
        printf("Não é possível fazer a multiplicação!\n");
    f(i, linhas)
        free(mat[i]);
    free(mat);

    return 0;
}