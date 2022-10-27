#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

usuario *FazerLogin(usuario *usuarios, int *qtdUsers, FILE *arquivo){
    (*qtdUsers)++;
    usuarios = (usuario *) realloc(usuarios, (*qtdUsers) * sizeof(usuario));
    if(usuarios == NULL) exit(1);
    printf("Digite o seu usuário: ");
    scanf(" %49[^\n]", usuarios[(*qtdUsers)-1].nome);
    printf("Digite sua senha: ");
    scanf(" %49[^\n]", usuarios[(*qtdUsers)-1].senha);
    usuarios[(*qtdUsers)-1].qtdEnviados = 0;
    // ........ continuar daqui
    FILE *arquivo = fopen("users.bin", "rb");

    fclose(arquivo);
    return usuarios;
}

int main(){
    int opcao, qtdUsuarios = 0, i, j;
    usuario *usuarios = NULL, *leituraUsers = NULL;
    FILE *arquivo = fopen("users.bin", "ab+");
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
                            usuarios[i].enviados = (email *) malloc((usuarios[i].qtdEnviados) 
                                                                    * sizeof(email));
                            if(usuarios[i].enviados == NULL) exit(1);
                            fread(usuarios[i].enviados[j].remetente, sizeof(char), 50, arquivo);
                            fread(usuarios[i].enviados[j].assunto, sizeof(char), 50, arquivo);
                            fread(usuarios[i].enviados[j].mensagem, sizeof(char), 200, arquivo);
                        }
                    }
                fread(&usuarios[i].qtdRecebidos, sizeof(int), 1, arquivo);
                    if(usuarios[i].qtdRecebidos != 0){
                        for(j=0; j<usuarios[i].qtdRecebidos; j++){
                            usuarios[i].recebidos = (email *) malloc((usuarios[i].qtdRecebidos) 
                                                                    * sizeof(email));
                            if(usuarios[i].recebidos == NULL) exit(1);
                            fread(usuarios[i].recebidos[j].remetente, sizeof(char), 50, arquivo);
                            fread(usuarios[i].recebidos[j].remetente, sizeof(char), 50, arquivo);
                            fread(usuarios[i].recebidos[j].mensagem, sizeof(char), 200, arquivo);
                        }
                    }
            }
        }
            
    fclose(arquivo);

do{
    printf("Digite a opcao que deseja\n");
    printf("1.....Cadastrar-se\n");
    printf("2.....Fazer login\n");
    printf("0.....Sair do e-mail\n");
    printf("Sua opcao: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1: usuarios = FazerLogin(usuarios, &qtdUsuarios, arquivo); break;
        case 2: //SistemaLogado(); break;
        case 0: break;
        default: printf("Opcao inválida\n"); break;
    }
}   while(opcao);

    free(usuarios);

return 0;
}