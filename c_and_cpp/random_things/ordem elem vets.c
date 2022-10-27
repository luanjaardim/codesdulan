#include <stdio.h>

void swap(int *elem1, int *elem2)
{
  int tmp = *elem1;
  *elem1 = *elem2;
  *elem2 = tmp;
}

void bubbleSort(int vet[], int n)
{
   int i, j;

   for (i = 0; i < n-1; i++)
   {  // esse sort trabalha colocando o maior para o final e então fazendo a procura do segundo maior e assim por diante
      // subtrai-se i para diminuir os números maiores q foram postos no final.
     for (j = 0; j < n-i-1; j++)
           if (vet[j] > vet[j+1])
              swap(&vet[j], &vet[j+1]);
   }      
}

void selectionSort(int vet[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {   // procura o menor elemento do vetor e coloca no início depois procura pelo menor depois dele
      min_idx = i;
      for (j = i+1; j < n; j++)
        if (vet[j] < vet[min_idx])
          min_idx = j;

      if(min_idx != i)
        swap(&vet[min_idx], &vet[i]);
    }
}


int main() 
{  

  int tam, i;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tam);

  int vetor[tam];
  for(i=0; i<tam; i++)
  {
    printf("Digite o %d elemento: ", i+1);
    scanf("%d", &vetor[i]);
  }

  //selectionSort(vetor, tam);

  bubbleSort(vetor, tam);


  for(int i=0; i<tam; i++)
    printf("%i\t", vetor[i]);

  //ORDENAÇÃO DE STRINGS
  //falta alguns ajustes

  /* for(i = 0; i < n-1; i++)  {
      primeiro = i ;

      for(j = i+1; j < n; j++ ) {
          if((strcmp(alunos[primeiro].nome, alunos[j].nome))>0)  {                
          primeiro = j ;
      }
      }
          strcpy(tmp, alunos[i].nome);
          strcpy(alunos[i].nome, alunos[primeiro].nome);
          strcpy(alunos[primeiro].nome, tmp);
      } */


  return 0;
}