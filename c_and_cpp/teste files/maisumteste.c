#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    float num;
    int numMat;
    char nome[30];
} Aluno;

int main(){
/* 
FILE *arquivo = NULL;

int i, opcao, quantAlunos = 0;
Aluno *alunos = NULL, *leitura = NULL;
arquivo = fopen("arquivo.bin", "rb");
if(arquivo != NULL){
    fread(&quantAlunos, sizeof(int), 1, arquivo);
    if(quantAlunos != 0)
        opcao = 2;
    else
        opcao = 1;
fclose(arquivo);
}
    

do{
    if(opcao == 1){
        arquivo = fopen("arquivo.bin", "wb");
        alunos = (Aluno *) realloc(alunos, (quantAlunos+1) * sizeof(Aluno));
        if(alunos == NULL) exit(1);
        if(quantAlunos != 0)
        for(i=0; i<quantAlunos; i++)
            alunos[i] = leitura[i];

        scanf("%f", &alunos[quantAlunos].num);
        scanf("%d", &alunos[quantAlunos].numMat);
        scanf(" %29[^\n]", alunos[quantAlunos].nome);    
        quantAlunos++;

        fwrite(&quantAlunos, sizeof(int), 1, arquivo);
        for(i=0; i<quantAlunos; i++){   
            fwrite(&alunos[i].num, sizeof(float), 1, arquivo);
            fwrite(&alunos[i].numMat, sizeof(int), 1, arquivo);
            fwrite(alunos[i].nome, sizeof(char), 30, arquivo);
        }

        fclose(arquivo);
    }
        arquivo = fopen("arquivo.bin", "rb");

        fread(&quantAlunos, sizeof(int), 1, arquivo);
        if(quantAlunos != 0){
            leitura = (Aluno *) realloc(leitura, quantAlunos * sizeof(Aluno));
            if(leitura == NULL) exit(1);

            for(i=0; i<quantAlunos; i++){
                fread(&leitura[i].num, sizeof(float), 1, arquivo);
                fread(&leitura[i].numMat, sizeof(int), 1, arquivo);
                fread(leitura[i].nome, sizeof(char), 30, arquivo);
                printf("%.2f ", leitura[i].num);
                printf("%d ", leitura[i].numMat);
                printf("%s\n", leitura[i].nome);
            }
        }    
        fclose(arquivo);

    scanf("%d", &opcao);
}   while(opcao != 0);

free(alunos);
free(leitura); */

//fazer um cod q atualiza um arquivo binário e pode modificar ele acrescentando mais elementos (com rb+)

return 0;
}