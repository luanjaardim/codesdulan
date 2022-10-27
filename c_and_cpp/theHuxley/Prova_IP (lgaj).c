//Prova de IP, aluno: Luan Gabriel Araujo Jardim (lgaj).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM_TABULEIRO 8

//será uma matriz de caracteres, o caracter nulo indicará a não existência de peças no lugar, enquanto a letra o tipo dela
//letra minúsculas indicam a cor preta, enquanto a maiuscula a cor branca.

void iniciandoTabuleiro(char **mat){
    //como aloquei a matriz com o calloc as peças serão inicialmente todas '\0' = 0.
    //trocarei apenas as que possuem peças no início do jogo
    //a orientação das linhas começa de cima!!
    int i, j;
    for(i=0; i<DIM_TABULEIRO; i++){
        for(j=0; j<DIM_TABULEIRO; j++){
            if(i == 6) //linhas dos peões brancos
                mat[i][j] = 'P';
            if(i == 1)  //linhas dos peões pretos
                mat[i][j] = 'p';

            if(i == 7){ //linhas peças brancas, sem os peões
                if(j == 0 || j == 7) //posições das torres
                    mat[i][j] = 'T';
                if(j == 1 || j == 6) //posições dos cavalos
                    mat[i][j] = 'C';
                if(j == 2 || j == 5) //posições dos bispos
                    mat[i][j] = 'B';
                if(j == 3) //posição da rainha
                    mat[i][j] = 'D';
                if(j == 4) //posição do rei
                    mat[i][j] = 'R';
            }

            if(i == 0){ //linhas peças pretas, sem os peões
                if(j == 0 || j == 7) //posições das torres
                    mat[i][j] = 't';
                if(j == 1 || j == 6) //posições dos cavalos
                    mat[i][j] = 'c';
                if(j == 2 || j == 5) //posições dos bispos
                    mat[i][j] = 'b';
                if(j == 4) //posição da rainha
                    mat[i][j] = 'd';
                if(j == 3) //posição do rei
                    mat[i][j] = 'r';
            }       
        }
    }
}

void lendoJogoExistente(FILE *arquivoBin, char** matrizLida){ //caso exista um tabuleiro criado, as informações são lidas
    int i, j;
    for(i=0; i<DIM_TABULEIRO; i++){ 
        for(j=0; j<DIM_TABULEIRO; j++){     
            fread(&matrizLida[i][j], sizeof(char), 1, arquivoBin);
        }
    }
}
void mudancaNum(int num, char leitura[7]){
    if(leitura[num] == '1')
        leitura[num] = 7;
    if(leitura[num] == '2')
        leitura[num] = 6;
    if(leitura[num] == '3')
        leitura[num] = 5;
    if(leitura[num] == '4')
        leitura[num] = 4;
    if(leitura[num] == '5')
        leitura[num] = 3;
    if(leitura[num] == '6')
        leitura[num] = 2; 
    if(leitura[num] == '7')
        leitura[num] = 1;
    if(leitura[num] == '8')
        leitura[num] = 0;
}
void ajustaLeitura(char leitura[7]){
    leitura[1]-=97; //os alfanúmericos são subtraídos o valor de 'a', 97.
    leitura[4]-=97;

    mudancaNum(2, leitura); //os numericos passam por um processo mais chato de substituição
    mudancaNum(5, leitura);
}

//todas as funções de movimentos apenas checam se podem mover as peças
// e comem os inimigos que estiverem lá, as pecas que se moveram só mudam 
// de lugar quando o tabuleiro atualiza             
int movimentoPeao(char leitura[7], char **mat){
    if(mat[leitura[5]][leitura[4]] == 0 && (leitura[5] == (leitura[2]+1) && leitura[4] == leitura[1])){
       //checa se a posição à frente está vazia e se eh uma casa à frente
       return 1; 
    }
    else if(mat[leitura[5]][leitura[4]] != 0){ //checa se há um oponente na posição e se é duas casas para uma das diagonais
        if((leitura[4] == (leitura[1]+2) && leitura[5] == (leitura[2]+2))){
            if((mat[leitura[2]][leitura[1]] > 90 && mat[leitura[5]][leitura[4]] < 90) || 
               (mat[leitura[2]][leitura[1]] < 90 && mat[leitura[5]][leitura[4]] > 90)){
            //checa se são inimigos
            mat[leitura[2]+1][leitura[1]+1] = 0; //quem estava à diagonal foi comido 
            return 1;}
            else    return 0; //não são inimigos, movimento invalido
            }
        if((leitura[4] == (leitura[1]-2) && leitura[5] == (leitura[2]+2))){
            if((mat[leitura[2]][leitura[1]] > 90 && mat[leitura[5]][leitura[4]] < 90) || 
               (mat[leitura[2]][leitura[1]] < 90 && mat[leitura[5]][leitura[4]] > 90)){ //checa se são inimigos, por letra maiusculas e minusculas
                   mat[leitura[2]+1][leitura[1]-1] = 0; //quem estava à diagonal foi comido 
                    return 1;
               }
            else return 0; //nao sao inimigos
            }
    }
    else return 0;
}
int movimentoCavalo(char leitura[7], char **mat){
    if(leitura[4] == (leitura[1]+1) && leitura[5] == (leitura[2]+2)){
        //andou para o L direito
        if((mat[leitura[2]][leitura[1]] > 90 && mat[leitura[5]][leitura[4]] < 90) || 
            (mat[leitura[2]][leitura[1]] < 90 && mat[leitura[5]][leitura[4]] > 90)){
              mat[leitura[2]+2][leitura[1]+1] = 0; //comeu
            return 1;  
            }
        else return 0;
    }
    if(leitura[4] == (leitura[1]-1) && leitura[5] == (leitura[2]+2)){
        //andou para o L esquerdo
        if((mat[leitura[2]][leitura[1]] > 90 && mat[leitura[5]][leitura[4]] < 90) || 
            (mat[leitura[2]][leitura[1]] < 90 && mat[leitura[5]][leitura[4]] > 90)){
                mat[leitura[2]+2][leitura[1]+1] = 0; //comeu
            return 1;
            }
        else return 0;
        
    }
    return 0;
}
int movimentoTorre(char leitura[7], char **mat){
    //não tive tempo para implementar os movimentos

    if((mat[leitura[2]][leitura[1]] > 90 && mat[leitura[5]][leitura[4]] < 90) || 
        (mat[leitura[2]][leitura[1]] < 90 && mat[leitura[5]][leitura[4]] > 90)){

        }
    else return 0;
}
int movimentoBispo(char leitura[7], char **mat){


    //não tive tempo para implementar os movimentos

    if((mat[leitura[2]][leitura[1]] > 90 && mat[leitura[5]][leitura[4]] < 90) || 
        (mat[leitura[2]][leitura[1]] < 90 && mat[leitura[5]][leitura[4]] > 90)){

        }
    else return 0;
}
int movimentoDama(char leitura[7], char **mat){

    //não tive tempo para implementar os movimentos
    
    if((mat[leitura[2]][leitura[1]] > 90 && mat[leitura[5]][leitura[4]] < 90) || 
        (mat[leitura[2]][leitura[1]] < 90 && mat[leitura[5]][leitura[4]] > 90)){

        }
    else return 0;
}
int movimentoRei(char leitura[7], char **mat){
    if(leitura[5] > (leitura[2]+1) || leitura[5] < (leitura[2]-1)) //vê se a distância é maior q as casas vizinhas 
        return 0;
    if(leitura[4] > (leitura[1]+1) || leitura[4] < (leitura[1]-1)) //vê se a distância é maior q as casas vizinhas 
        return 0;
    if((mat[leitura[2]][leitura[1]] > 90 && mat[leitura[5]][leitura[4]] < 90) || 
        (mat[leitura[2]][leitura[1]] < 90 && mat[leitura[5]][leitura[4]] > 90)){
            mat[leitura[5]][leitura[4]] = 0; //come as pecas q estiverem no lugar
            return 1;
        }
    else return 0;
}

// vai descobrir qual funcao de movimento utilizar
int movimentoPeca(char leitura[7], char **mat){ //retorna 1 ou 0 
    if(leitura[0] == 'P' || leitura[0] == 'p')  //caso o movimento seja valido 1
        return movimentoPeao(leitura, mat);     //caso nao 0
    if(leitura[0] == 'T' || leitura[0] == 't')
        return movimentoTorre(leitura, mat);
    if(leitura[0] == 'C' || leitura[0] == 'c')
        return movimentoCavalo(leitura, mat);
    if(leitura[0] == 'B' || leitura[0] == 'b')
        return movimentoBispo(leitura, mat);
    if(leitura[0] == 'D' || leitura[0] == 'd')
        return movimentoDama(leitura, mat);
    if(leitura[0] == 'R' || leitura[0] == 'r')
        return movimentoRei(leitura, mat);
}

int checaJogada(char leitura[7], char **mat){
    int movInvalido = 0, i, j;

    for(i=0; i<DIM_TABULEIRO && movInvalido == 0; i++){
        for(j=0; j<DIM_TABULEIRO && movInvalido == 0; j++){
            ajustaLeitura(leitura); //ajusta leitura para uma forma legível
            if(leitura[0] != mat[leitura[2]][leitura[1]]){
                movInvalido = 1; //checa se as letras das peças correspondem com a da jogada
            }
            movInvalido = movimentoPeca(leitura, mat); //checa se a peca pode chegar ao destino
        }
    }
    return movInvalido;
}

//**pecas comidas foram atualizadas nas funções de movimento**
void atualizaTabuleiro(char **mat, char leitura[7]){   //se a jogada for válida a peça muda de lugar e pecas inimigas comidas somem
    int i, j;
    mat[leitura[2]][leitura[1]] = 0; //posicao antiga
    mat[leitura[5]][leitura[4]] = leitura[0]; //posicao nova
}

void printaTabuleiroArmazenado(char **mat, FILE *arquivo){
    int i, j;
    for(i=0; i<DIM_TABULEIRO; i++){
        for(j=0; j<DIM_TABULEIRO; j++){
            fwrite(&mat[i][j], sizeof(char), 1, arquivo);//aramzena no arquivo
        }
    }
    for(i=0; i<DIM_TABULEIRO; i++){
        for(j=0; j<DIM_TABULEIRO; j++){
            printf("%c", mat[i][j]);//printa na tela como anda o jogo
        }
        printf("\n");
    }
}

int checaChequeMate(char **mat){   //procura pelo tabuleiro 'r' e 'R'
    int i, j, qtdReis = 0;  // se não chegar a 2 algum dos reis morreu
    for(i=0; i<DIM_TABULEIRO; i++){
        for(j=0; j<DIM_TABULEIRO; j++){
            if(mat[i][j] == 'R' || mat[i][j] == 'r'){
                qtdReis++;
            }
        }
    }
    if(qtdReis == 2){
    return 0;   //nao houve cheque
    }
    return 1;
}

int main(){
    FILE *arq;
    char **mat = NULL, leitura[7];
    int i, j, movInvalido = 0, chequeMate = 0;

        mat = (char **) calloc(DIM_TABULEIRO, sizeof(char *)); //alocacao das linhas
        if(mat == NULL){
            printf("Problema na alocacao da matriz!\n");
            exit(1);
        }
        for(i=0; i<DIM_TABULEIRO; i++){
            mat[i] = (char *) calloc(DIM_TABULEIRO, sizeof(char)); //das colunas
            if(mat[i] == NULL){
            printf("Problema na alocacao da matriz!\n");
            exit(1);
        }
        }

    arq = fopen("xadrez.bin", "rb");
    if(arq == NULL){    //não existia um arquivo criado
        arq = fopen("xadrez.bin", "ab+");
        iniciandoTabuleiro(mat); //colocando as peças nas posições iniciais da partida
        fclose(arq);
    }
    else{       //existia um arquivo criado
    lendoJogoExistente(arq, mat);
    fclose(arq);    
    }        

scanf(" %6s", leitura);
movInvalido = checaJogada(leitura, mat);

while(movInvalido != 1){

atualizaTabuleiro(mat, leitura);
arq = fopen("xadrez.bin", "wb"); //reescreve o tabuleiro antigo com o atualizado
printaTabuleiroArmazenado(mat, arq); //printa e atualiza o tabuleiro

scanf(" %6s", leitura);
movInvalido = checaJogada(leitura, mat);    //faz a nonva leitura e checagem da mesma

chequeMate = checaChequeMate(mat);  //checa algum dos reis morreu
if(checaChequeMate){ //se houve cheque o jogo acaba
    printf("FIM DE JOGO!!");
    return 0;
}
}
    printf("Movimento invalido!");
    for(i=0; i<DIM_TABULEIRO; i++){ //dando free nas alocações
        free(mat[i]);
    }
    free(mat);            
    fclose(arq); //fechando o arquivo aberto no ciclo while

return 0;
}