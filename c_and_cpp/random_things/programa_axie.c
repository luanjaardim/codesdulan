#include "auxiliar.h"

void sisteminha(int *opcao){

    printf("\n------------------------\n");
    printf("1.... Qtd. SLPS\n");
    printf("2.... Deposito SLPS\n");
    printf("3.... Fim de temp.\n");
    printf("0.... Sair\n");
    printf("Digite sua opcao: ");
    scanf("%d", opcao);
    printf("\n");
}

void DepSLPS(int *total){
    int temp;
    printf("Digite o novo valor: ");
    scanf("%d", &temp);
        FILE *arq = fopen("axie.bin", "wb");
            if (arq == NULL){
                printf("Ocorreu um ERRO!");
                exit(1);
            }
            fwrite(&temp, sizeof(int), 1, arq);
        fclose(arq);
    printf("O ganho diario foi de %d SLPS\n", temp - (*total));
    *total = temp;
    printf("Depositado com sucesso!\n");
}

int fimTemp(int total){
    printf("O ganho da quinzena foi: %.2f\n", total*0.4);
    FILE *arq = fopen("axie.bin", "wb");
        if(arq == NULL){
            printf("Ocorreu um ERRO!");
            exit(1);
        }
    fclose(arq);
    printf("A quantidade de SLPS foi resetada!\n");
    return 0;
}

int main(){

    int opcao, total = 0;
    FILE *arquivo = fopen("axie.bin", "rb");
        if(arquivo == NULL){
            printf("O arquivo n existia, para utilizar o novo reinicie o programa.");
                arquivo = fopen("axie.bin", "wb");
                fclose(arquivo);
            exit(1);
        }
    fread(&total, sizeof(int), 1, arquivo);
    fclose(arquivo);

    do{
        sisteminha(&opcao);
        switch (opcao){
            case 1: printf("Qtd Atual de SLPS: %d\n", total); break;
            case 2: DepSLPS(&total); break;
            case 3: total = fimTemp(total); break;
            case 0: break;
            default: printf("Tente novamente!\n");
        }
    }   while(opcao != 0);

    return 0; 
}