#include "auxiliar.h"
#include <time.h>

int main()
{

    /* int elementos[5] = {1, 2, 3, 4, 5};
    
    for(int i = 0; i < sizeof(elementos)/sizeof(int); i++)
        printf("%d ", elementos[i]); */

    /* int mat[][3] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9},
                    {0, 0, 0} };

    for(int i = 0; i < (int) sizeof(mat)/sizeof(mat[i]); i++)   //interessante para ter um limite sem saber a quantidade de itens
        for(int j = 0; j < (int) sizeof(mat[i])/sizeof(mat[i][j]); j++)
            printf("%d ", mat[i][j]); */

    //cod para o jogo de "adivinhe o número"

    srand(time(0)); //pegando uma seed para a geração de valores pseudo-aleatórios através do tempo

    int num = rand() % 10; //irá gerar valores de 0 a 9
    printf("%d", num);

    return 0;
}