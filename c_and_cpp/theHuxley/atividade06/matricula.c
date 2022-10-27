//questão: Sistema de matrícula, thehuxley

#include <stdio.h>
#include <string.h>

typedef struct{

char cod[31], nome[501], sexo;
float idade, nota;

} Aluno;

typedef struct{

char codDisciplina[26], nomeDisciplina[101];
int matriculados;  

} Disciplina;

typedef struct{

char codA[31], codD[26], NcodA[501];

} Cadastro;


int main(){

    int qtdAlunos, qtdDisciplinas, qtdCadastros, qtdM=0, qtdF=0, contagem=0, i, j, primeiro, tmpi;
    float mediaI=0.0, mediaN=0.0;           //contagem é a varíavel q vê quantos alunos tem nota acima de 7.5
    char tmp[101], tmps[26], tmpr[501];
    scanf("%d", &qtdAlunos);

    Aluno alunos[qtdAlunos];

    for(i=0; i<qtdAlunos; i++){
        scanf(" %30s", alunos[i].cod);
        scanf(" %500[^\n]", alunos[i].nome);
        scanf(" %f", &alunos[i].idade);
        scanf(" %d", &alunos[i].sexo);
        scanf(" %f", &alunos[i].nota);
    }

    scanf("%d", &qtdDisciplinas);

    Disciplina disciplinas[qtdDisciplinas];
    for(i=0; i<qtdDisciplinas; i++)
        disciplinas[i].matriculados=0;

    for(i=0; i<qtdDisciplinas; i++){
        scanf(" %25s", disciplinas[i].codDisciplina);
        scanf(" %100[^\n]", disciplinas[i].nomeDisciplina);
    }

    scanf("%d", &qtdCadastros);

    Cadastro cadastros[qtdCadastros];

    for(i=0; i<qtdCadastros; i++){
        scanf(" %30s", cadastros[i].codA);
        scanf(" %25s", cadastros[i].codD);
        for(j=0; j<qtdDisciplinas; j++){
            if((strcmp(cadastros[i].codD, disciplinas[j].codDisciplina)==0)){
                disciplinas[j].matriculados++;
            }
        }
        for(j=0; j<qtdAlunos; j++){
            if((strcmp(cadastros[i].codA, alunos[j].cod)==0))
                strcpy(cadastros[i].NcodA, alunos[j].nome);
        }
    }

    //ordenação alfabética de disciplinas e dos cadastros

    for(i = 0; i < qtdDisciplinas-1; i++)  {
    primeiro = i ;

    for(j = i+1; j < qtdDisciplinas; j++ ) {
        if((strcmp(disciplinas[primeiro].nomeDisciplina, disciplinas[j].nomeDisciplina))>0)  {                
        primeiro = j ;
    }
    }
        strcpy(tmp, disciplinas[i].nomeDisciplina);
        strcpy(tmps, disciplinas[i].codDisciplina);
        tmpi = disciplinas[i].matriculados;

        strcpy(disciplinas[i].nomeDisciplina, disciplinas[primeiro].nomeDisciplina);
        strcpy(disciplinas[i].codDisciplina, disciplinas[primeiro].codDisciplina);
        disciplinas[i].matriculados = disciplinas[primeiro].matriculados;

        strcpy(disciplinas[primeiro].nomeDisciplina, tmp);
        strcpy(disciplinas[primeiro].codDisciplina, tmps);
        disciplinas[primeiro].matriculados = tmpi;
    }

    for(i = 0; i < qtdCadastros-1; i++)  {
    primeiro = i ;

    for(j = i+1; j < qtdCadastros; j++ ) {
        if((strcmp(cadastros[primeiro].NcodA, cadastros[j].NcodA))>0)  {                
        primeiro = j ;
    }
    }
        strcpy(tmpr, cadastros[i].NcodA);
        strcpy(tmp, cadastros[i].codD);
        strcpy(tmps, cadastros[i].codA);
        
        strcpy(cadastros[i].NcodA, cadastros[primeiro].NcodA);
        strcpy(cadastros[i].codD, cadastros[primeiro].codD);
        strcpy(cadastros[i].codA, cadastros[primeiro].codA);
        
        strcpy(cadastros[primeiro].NcodA, tmpr);
        strcpy(cadastros[primeiro].codD, tmp);
        strcpy(cadastros[primeiro].codA, tmps);
    }

    //FIM DA ORDENAÇÃO

    for(i=0; i<qtdAlunos; i++){
        if(alunos[i].sexo==1)
            qtdM++;
        if(alunos[i].sexo==0)
            qtdF++;
        mediaI+=alunos[i].idade;
        if(alunos[i].nota>7.5){
        mediaN+=alunos[i].idade;
        contagem++;
        }
    }
    mediaI/=qtdAlunos;
    mediaN/=contagem;


    printf("%d\n", qtdM);
    printf("%d\n", qtdF);
    printf("%.2f\n", mediaI);
    printf("%.2f\n", mediaN);

    for(i=0; i<qtdDisciplinas; i++){
        printf("%s\n", disciplinas[i].nomeDisciplina);
        printf("%d\n", disciplinas[i].matriculados);

        if(disciplinas[i].matriculados!=0){
        for(j=0; j<qtdCadastros; j++){
            if( strcmp(cadastros[j].codD, disciplinas[i].codDisciplina) == 0)
                printf("%s\n", cadastros[j].NcodA);
        } 
        }
        
    }

return 0;
}