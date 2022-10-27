#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define tam 10

typedef struct{
    char remetente[50], assunto[50], mensagem[200];
} email;

typedef struct{
    char nome[50];
    char senha[50];
    int qtdRecebidos, qtdEnviados;
    email *recebidos;
    email *enviados;
} usuario;

void escrevendoBinarioMLQPIKA(FILE *arquivo, usuario *usuarios, int qtdUsuarios){
    int i, j;
    fwrite(&qtdUsuarios, sizeof(int), 1, arquivo);
        if(qtdUsuarios != 0){
            for(i=0; i<qtdUsuarios; i++){
                fwrite(usuarios[i].nome, sizeof(char), 50, arquivo);
                fwrite(usuarios[i].senha, sizeof(char), 50, arquivo);
                fwrite(&usuarios[i].qtdEnviados, sizeof(int), 1, arquivo);
                    if(usuarios[i].qtdEnviados != 0){
                        for(j=0; j<usuarios[i].qtdEnviados; j++){
                            /* usuarios[i].enviados = (email *) malloc((usuarios[i].qtdEnviados) 
                                                                    * sizeof(email));
                            if(usuarios[i].enviados == NULL) exit(1);
                            fwrite(usuarios[i].enviados[j].remetente, sizeof(char), 50, arquivo);
                            fwrite(usuarios[i].enviados[j].assunto, sizeof(char), 50, arquivo);
                            fwrite(usuarios[i].enviados[j].mensagem, sizeof(char), 200, arquivo); */
                        }
                    }
                fwrite(&usuarios[i].qtdRecebidos, sizeof(int), 1, arquivo);
                    if(usuarios[i].qtdRecebidos != 0){
                        for(j=0; j<usuarios[i].qtdRecebidos; j++){
                            /* usuarios[i].recebidos = (email *) malloc((usuarios[i].qtdRecebidos) 
                                                                    * sizeof(email));
                            if(usuarios[i].recebidos == NULL) exit(1);
                            fwrite(usuarios[i].recebidos[j].remetente, sizeof(char), 50, arquivo);
                            fwrite(usuarios[i].recebidos[j].remetente, sizeof(char), 50, arquivo);
                            fwrite(usuarios[i].recebidos[j].mensagem, sizeof(char), 200, arquivo); */
                        }
                    }
            }
        }
}

int main(){
/*
FILE *arq = NULL;

arq = fopen("teste.bin", "wb+");
if(arq == NULL){
    printf("Não consegui criar/abrir o arquivo!");
    exit(1);
}

int total_gravado, *escrita, *leitura;
escrita = (int *) malloc(tam * sizeof(int));
leitura = (int *) malloc(tam * sizeof(int));
if(escrita == NULL || leitura ==NULL)   exit(1);    //alocando os vetores

for(int i=0; i<tam; i++)
    scanf("%d", &escrita[i]); //lendo os valores a serem escritos

total_gravado = fwrite(escrita, sizeof(int), tam, arq); //escrevendo no arquivo
if(total_gravado != tam){ //o retorno das funções é a quantidade de "sizeof(int)" escritos
    printf("problema na escrita do arquivo!\n"); //se for diferente da colocada na função deu erro
    exit(1);
}
rewind(arq);
total_gravado = fread(leitura, sizeof(int), tam, arq);//mesma coisa q o fwrite, mas
if(total_gravado != tam){                             //colocando os valores lidos no arquivo 
    printf("problema na leiturax do arquivo!\n");     //em leitura.
    exit(1);
}

for(int i=0; i<tam; i++)
    printf("%d ", leitura[i]);

free(escrita);//freezinho da massa
free(leitura);
fclose(arq); */
int qtdUsuarios = 0, i, j, qtdPraAdicionar;
long tamanho;
    usuario *usuarios = NULL;

    FILE *arquivo;
    arquivo = fopen("users.bin", "ab+");
    rewind(arquivo);
        fread(&qtdUsuarios, sizeof(int), 1, arquivo);
        if(qtdUsuarios != 0){
            usuarios = (usuario *) malloc(qtdUsuarios * sizeof(usuario));
            if(usuarios == NULL) exit(1);

            for(i=0; i<qtdUsuarios; i++){
                fread(usuarios[i].nome, sizeof(char), 50, arquivo);
                fread(usuarios[i].senha, sizeof(char), 50, arquivo);
                fread(&usuarios[i].qtdEnviados, sizeof(int), 1, arquivo);
                    if(usuarios[i].qtdEnviados != 0){
                        for(j=0; j<usuarios[i].qtdEnviados; j++){
                           /*  usuarios[i].enviados = (email *) malloc((usuarios[i].qtdEnviados) 
                                                                    * sizeof(email));
                            if(usuarios[i].enviados == NULL) exit(1);
                            fread(usuarios[i].enviados[j].remetente, sizeof(char), 50, arquivo);
                            fread(usuarios[i].enviados[j].assunto, sizeof(char), 50, arquivo);
                            fread(usuarios[i].enviados[j].mensagem, sizeof(char), 200, arquivo); */
                        }
                    }
                fread(&usuarios[i].qtdRecebidos, sizeof(int), 1, arquivo);
                    if(usuarios[i].qtdRecebidos != 0){
                        for(j=0; j<usuarios[i].qtdRecebidos; j++){
                           /*  usuarios[i].recebidos = (email *) malloc((usuarios[i].qtdRecebidos) 
                                                                    * sizeof(email));
                            if(usuarios[i].recebidos == NULL) exit(1);
                            fread(usuarios[i].recebidos[j].remetente, sizeof(char), 50, arquivo);
                            fread(usuarios[i].recebidos[j].remetente, sizeof(char), 50, arquivo);
                            fread(usuarios[i].recebidos[j].mensagem, sizeof(char), 200, arquivo); */
                        }
                    }
            }
        }
    fclose(arquivo);
    scanf("%d", &qtdPraAdicionar);        
    usuarios = (usuario *) realloc(usuarios, (qtdUsuarios + qtdPraAdicionar) * sizeof(usuario));
    if(usuarios == NULL) exit(1);

    for(i=qtdUsuarios; i<(qtdUsuarios + qtdPraAdicionar); i++){
        scanf(" %49[^\n]", usuarios[i].nome);
        scanf(" %49[^\n]", usuarios[i].senha);
        usuarios[i].qtdEnviados = 0;
        usuarios[i].qtdRecebidos = 0;
    }
    qtdUsuarios+=qtdPraAdicionar;

    for(i=0;  i<qtdUsuarios; i++){
        printf("%s ", usuarios[i].nome);
        printf("%s ", usuarios[i].senha);
        printf("%d %d\n", usuarios[i].qtdRecebidos, usuarios[i].qtdEnviados);
    }
    
    arquivo = fopen("users.bin", "wb+");
    escrevendoBinarioMLQPIKA(arquivo, usuarios, qtdUsuarios);
    free(usuarios);
    fclose(arquivo);
return 0;
}