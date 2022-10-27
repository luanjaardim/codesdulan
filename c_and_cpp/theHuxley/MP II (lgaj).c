//MP2 - Luan Gabriel Araujo Jardim (lgaj)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    char nome[30];
    int tentativas, pontuacao;
} Competidor;

int **colocarTesouros(int **mat, int ordem, int *qtdTesouros){
    *qtdTesouros = 0;           //onde tiver ovos sera 1, caso nao 0
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            if((4*i*i + 3*j)%11 == 0){  //se a posicao satisfaz a expressao
                mat[i][j] = 1;
                (*qtdTesouros)++;
            }
            else    //nao satisfez '-'
                mat[i][j] = 0;
        }
    }
    return mat;
}

Competidor *leCompetidores(Competidor *competidores, int quantAt, int quantT){
    for(int i=(quantT-quantAt); i<quantT; i++){
        printf("Digite o nome do %d participante do dia: ", i+1);
        scanf(" %29[^\n]", competidores[i].nome);
        printf("Digite o numero de tentivas do %d participante do dia: ", i+1);
        scanf("%d", &competidores[i].tentativas);
        competidores[i].pontuacao = 0; //garantindo pontuação zerada no início.
    }   
    return competidores;
}

void ProcurandoEggs(Competidor *competidores, int *quantTesouros, int quantT, int quantAt, int **mat){
    int i, j, linha, coluna, acabou = 0;

    for(i=(quantT-quantAt); i<quantT && acabou ==0; i++){  
        printf("Digite os pares do %d participante da rodada(comeca do 0):\n", i+1);
        for(j=0; j<competidores[i].tentativas && acabou == 0; j++){
            if(*quantTesouros != 0){        //checa se os pares de entrada correspondem a um ovo
            scanf("%d %d", &linha, &coluna);// enquanto ainda existirem tesouros, claro '-'

            if(mat[linha][coluna] == 1){    //achou um ovo
                competidores[i].pontuacao++;
                (*quantTesouros)--;
                mat[linha][coluna] = 0;
            }  
            }
            else{   //caso ainda tenha tentivas e os ovos acabem a rodada acaba e a frase é emitida
                printf("Acabaram os ovos!!\n");
                acabou = 1;
            }  
    //    printf("%d\n", competidores[i].pontuacao);
        }
    }
}

void acharVencedor(Competidor *competidores, int quantCompetidores){
    Competidor vencedor;
    vencedor.pontuacao = 0;
    for(int i=0; i<quantCompetidores; i++){
        if(competidores[i].pontuacao > vencedor.pontuacao){
            vencedor = competidores[i]; //se a pontuação for maior do que a maior lida anteriormente 
        }                               // há uma substituição, caso iguais o anterior prevalecera!
    }
    printf("O vencedor foi %s com a pontuacao de %d\n", vencedor.nome, vencedor.pontuacao);
}

int main(){

    int **mat = NULL, n, j, i, qtdRodadas, qtdParticipantesT = 0, qtdParticipantesAt, tesouros;
    Competidor *competidores = NULL;

    printf("Quantas rodadas tera o jogo: ");
    scanf("%d", &qtdRodadas);

    j=0; //indice da rodada
    do{
        printf("Rodada %d\n", j+1);
        printf("Digite o n da matriz quadrada nxn: ");
        scanf("%d", &n);

        mat = (int **) realloc(mat, n * sizeof(int *));
            if(mat == NULL){    //procedimentos naturais de natureza natural em C
                printf("Prob. na alocacao!!\n");
                exit(1);
            }
            for(i=0; i<n; i++){
                mat[i] = NULL;  //jogando para nulo pra poder usar o realloc
                mat[i] = (int *) realloc(mat[i], n * sizeof(int));
                    if(mat[i] == NULL){     //procedimentos naturais de natureza natural em C
                    printf("Prob. na alocacao!!\n");
                    exit(1);
                    }
            }
                
        mat = colocarTesouros(mat, n, &tesouros);   //função q acha as poiscoes com ovos

        printf("Quantos participantes participarao desta rodada: ");
        scanf("%d", &qtdParticipantesAt);
        qtdParticipantesT += qtdParticipantesAt;    //acrescenta a cada rodada a quant de participantes novos ao total

        competidores = (Competidor *) realloc(competidores, qtdParticipantesT * sizeof(Competidor));
            if(competidores == NULL){   //procedimentos naturais de natureza natural em C
                printf("Prob. na alocacao!!\n");
                exit(1);
            }

        competidores = leCompetidores(competidores, qtdParticipantesAt, qtdParticipantesT);

        ProcurandoEggs(competidores, &tesouros, qtdParticipantesT, qtdParticipantesAt, mat);

        j++;
        qtdRodadas--;
    }while(qtdRodadas != 0);    //acabaram os jogos!!!!!

    acharVencedor(competidores, qtdParticipantesT); //vencedor decretado


    free(competidores);
    for(i=0; i<n; i++)  //n da matriz da ultima rodada.
        free(mat[i]);
    free(mat);

return 0;
}

//codguinho de luan gabriel araujo jardim de EC (lgaj)