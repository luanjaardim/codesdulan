//questão: Bruna e os quadrados, thehuxley

//versão nova:
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define f(a, b) for(int a=0; a<b; a++)
int size = 0;

bool searchSub(int m[][size], int max, int x, int y)
{
    for(int i=x; i <= max + x; i++)
        for(int j=y; j <= max + y; j++)
        {
            if(!(m[i][j]))
                return false;
        }
    return true;
}

int searchOne(int m[][size]) {
  int max_size = -1;
  f(i, size)
      f(j, size)
      {
        if(m[i][j])
        {
            int max_tam  = (size - 1) - j; //tamanho máximo para o quadrado de 1's
            while(max_tam > max_size){
                if(max_tam > (size - 1) - i) {
                    max_tam--; 
                    continue;
                }
                if(m[i+max_tam][j] && m[i][j+max_tam] && m[i+max_tam][j+max_tam])
                {
                    if(searchSub(m, max_tam, i, j))
                        max_size = max_tam;
                }
                max_tam--;
            }
          }
        }

  return (max_size+1);
}

int main(int argc, char **argv) {
  
  scanf("%d", &size);
  int mat[size][size];
  f(i, size)
    f(j, size)
      scanf("%d", &mat[i][j]);
  
  int max_size = searchOne(mat);
  printf("%d\n", max_size * max_size);

  return 0;
}

//versão antiga:
/*#include <stdio.h>

int main(){

int tam, i, j, x, y, cont=0, areaNova=0, area=0, quantTeste, checa=1;
scanf("%d", &tam);
int mat[tam][tam];

for(j=0; j<tam; j++)
    for(i=0; i<tam; i++){
        scanf(" %d", &mat[i][j]);
    }

for(j=0; j<tam; j++){
    for(i=0; i<tam; i++){
        if(mat[i][j]==1){
            cont=0;
            x=i;
            y=j;
            while(mat[x][y]==1 && x<tam){
                cont++;
                x++;
            }
            checa=1;
            do{
            for(x=i; x<cont+i; x++){
                for(y=j; y<j+cont; y++){
                    if(mat[x][y]==0){
                        cont--;
                        checa++;
                    }   
                }
            }
            checa--;
            }while(checa!=0);
            
            mat[i][j]=0;
            areaNova=cont*cont;

            if(areaNova>area){
                area=areaNova;
            }
        }
    }
}

printf("%i", area);

return 0;
}*/
