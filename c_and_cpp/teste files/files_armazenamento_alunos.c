#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define qtdNotas 4

typedef struct{
    char nome[30];
    float media, nota[qtdNotas];
    int numMat;
} Aluno;

typedef struct{
    Aluno *alunos;
    char codTurma[5];
    int quantAlunos;
    float mediaTot;
} Turma;

Turma *criarTurminha(Turma *turmas, int *qtdTurmas){
    (*qtdTurmas)++;
    turmas = (Turma *) realloc(turmas, *qtdTurmas * sizeof(Turma));
    if(turmas == NULL) exit(1);
    printf("Digite o cod da turma: ");
    scanf(" %4s", turmas[(*qtdTurmas)-1].codTurma);
    turmas[(*qtdTurmas)-1].quantAlunos = 0;
    turmas[(*qtdTurmas)-1].mediaTot = 0;
    turmas[(*qtdTurmas)-1].alunos = NULL;

    return turmas;
}

void adicionarAluninhos(Turma *turmas, int qtdTurmas){
    char codTmp[5];
    printf("Em qual turma quer adicionar(cod): ");
    scanf(" %4s", codTmp);
    for(int i=0; i<qtdTurmas; i++){
        if((strcmp(turmas[i].codTurma, codTmp)) == 0){
            turmas[i].quantAlunos++;
            turmas[i].alunos = (Aluno *) realloc(turmas[i].alunos, 
                                                turmas[i].quantAlunos * sizeof(Aluno));
                if(turmas[i].alunos == NULL) exit(1);
            printf("Digite o nome do aluno: ");
            scanf(" %29[^\n]", turmas[i].alunos[(turmas[i].quantAlunos)-1].nome);
            printf("Digite a matricula do aluno: ");
            scanf("%d", &turmas[i].alunos[(turmas[i].quantAlunos)-1].numMat);
            printf("Digite as notas do aluno: ");
            scanf("%d %d %d %d", &turmas[i].alunos[(turmas[i].quantAlunos)-1].nota[0],
                                 &turmas[i].alunos[(turmas[i].quantAlunos)-1].nota[1],
                                 &turmas[i].alunos[(turmas[i].quantAlunos)-1].nota[2],
                                 &turmas[i].alunos[(turmas[i].quantAlunos)-1].nota[3]);
            printf("Aluno cadastrado com sucesso!\n");
            break;
        }
    }
}

int main(){

int qtdTurmas = 0, opcao;
Turma *turmas = NULL;


printf("    Bem-vindo ao menu do SIGAzin!\n\n");
printf("        Menu do SIGAzin:\n");
do{
printf("1......Criar uma nova turma\n");
printf("2......Adcionar alunos\n");
printf("3......Exibir media de turma\n");
printf("4......Lista de turmas\n");
scanf("%d", &opcao);
    switch (opcao){
        case 1: turmas = criarTurminha(turmas, &qtdTurmas); break;
        case 2: adicionarAluninhos(turmas, qtdTurmas); break;
        case 3: mostraMedia(); break;
        case 4: listaTurma(); break;
        case 5: break;
        default:
            printf("Comando inexistente, tente novamente, por favor!\n");
            break;
    }
}while(opcao != 5);
printf("Obrigado pela preferencia!\n");

return 0;
}