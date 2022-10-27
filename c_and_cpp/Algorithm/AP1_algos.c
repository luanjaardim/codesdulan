/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX 50

typedef struct
{
    int size, sizeMax, curr;
    int *array;
} lista;

void insert(lista *listinha)
{
    if(listinha->size >= listinha->sizeMax)
        printf("Nao ha mais espaco no array!");
    else
    {
        int num_add;
        scanf("%d", &num_add);
        for(int i = listinha->size; i > listinha->curr; i--)
        {
            listinha->array[i] = listinha->array[i-1];
        }
        listinha->array[listinha->curr] = num_add;
        listinha->size++;
    }
}

void remov(lista *listinha)
{
    if(listinha->curr < 0 || listinha->curr >= listinha->size)
        printf("Operação inválida");
    else
    {
        for(int i = listinha->curr; i < listinha->size; i++)
        {
            listinha->array[i] = listinha->array[i+1];
        }
        listinha->size--;
    }
}

int count(lista *listinha)
{
    int procurar, cont = 0;
    scanf("%d", &procurar);

    for(int i=0; i<listinha->size; i++)
    {
        if(listinha->array[i] == procurar)
            cont++;
    }
    return cont;
}

void prev(lista *listinha)
{
    if(listinha->curr == 0)
        printf("O cursor ja esta no limite minimo");
    else
        listinha->curr--;
}

void next(lista *listinha)
{
    if(listinha->curr == listinha->size)
        printf("O cursor ja esta no limite maximo");
    else
        listinha->curr++;
}

void clear(lista *listinha)
{
    listinha->size = 0;
    listinha->curr = 0;
}

int main()
{
    
    lista *listinha = (lista *) malloc(sizeof(lista));
    listinha->sizeMax = SIZE_MAX;
    listinha->size = listinha->curr = 0;
    listinha->array = (int *) malloc(listinha->sizeMax * sizeof(int));

    int num_casos, qtd_ops, i, j;
    char op_lida[16];
    
    scanf("%d", &num_casos);
    for(i=0; i<num_casos; i++)
    {
        printf("Caso %d:\n", (i+1));
        scanf("%d", &qtd_ops);       

            for(j=0; j<qtd_ops; j++)
            {
                scanf("%15s", op_lida);
                char casos = op_lida[0];

                switch (casos)
                {
                    case 'i': insert(listinha); break;
                    case 'r': remov(listinha); break;
                    case 'c': printf("%d\n", count(listinha)); break;
                    case 'p': prev(listinha); break;
                    case 'n': next(listinha); break; 
                    default: 
                    /* for(int k=0; k<listinha->size; k++)
                        printf("%d ", listinha->array[k]); */
                    break;
                }
            }

        clear(listinha);
    }

    free(listinha->array);
    free(listinha);

    return 0;
}
