//programa de Luan Gabriel Araujo Jardim para a MP 1 de IP, UFPE.

#include <stdio.h>
#include <string.h>

int main(){

int tamM, i, j, x, tamMaxC, soma, m=0, n=0; 
printf("Digite a dimensao da matriz: ");
scanf("%d", &tamM);
if(tamM==0 || tamM<0){        // checa se o engracadinho do usuario colocou algo diferente de um numero natural positivo
    printf("Dimensao top dms, n entendi nada, encerrando o programa...");
    return 0;
}
printf("Digite agora as %d strings que comporao a matriz %d x %d:\n", tamM*tamM, tamM, tamM);

char matrizS[tamM][tamM][31];
tamMaxC=tamM*tamM*31;                    // o maximo de carcateres q a senha pode receber é quando todos
char senha[tamMaxC], somaVet[31]={};     //os caracteres(31 com o \0) das tamM*tamM strings sao preenchidos

for(i=0; i<tamM; i++)               //Le a matriz de strings
    for(j=0; j<tamM; j++)
        scanf(" %30s", matrizS[i][j]);


for(i=0; i<tamM; i++)              
    for(j=0; j<tamM; j++){
    
        if(i==j){
            x=0;       // x é a variavel q viaja na dimensão dos carcateres que compoem as strings

            if(strlen(matrizS[i][j])!=i+j+1){     //checa o tamanho
                printf("A matriz nao satisfaz a propriedade!\n");
                return 0;
            }
            while(matrizS[i][j][x]!='\0'){      //checa se há caracteres diferentes das vogais minusculas
    if(matrizS[i][j][x]!='a' && matrizS[i][j][x]!='e' && matrizS[i][j][x]!='i' && matrizS[i][j][x]!='o' && matrizS[i][j][x]!='u'){
                    printf("A matriz nao satisfaz a propriedade!\n");
                    return 0;
                }
                x++;
            }

        }
        if(i!=j){
            x=0;

            while(matrizS[i][j][x]!='\0'){  //checa se há vogais maiusculas
            if(matrizS[i][j][x]=='A' || matrizS[i][j][x]=='E' || matrizS[i][j][x]=='I' || matrizS[i][j][x]=='O' || matrizS[i][j][x]=='U'){
                printf("A matriz nao satisfaz a propriedade!\n");
                return 0;
            }
            if(matrizS[i][j][x]>90 || matrizS[i][j][x]<65){     //checa se são consoantes maiusculas
                printf("A matriz nao satisfaz a propriedade!\n");
                return 0;
            }
            x++;
            }
        }   
    }  
        //caso saia desses for's a matriz está qualificada a gerar uma senha!

for(i=0; i<tamM; i++)             //formação da senha 
    for(j=0; j<tamM; j++){
        if(i==j){
            if(i==0 && j==0)
            strcpy(senha, matrizS[i][j]);   //como n há nada de interessante em senha, ainda, e (0,0) é 
            else{                           //a primeira posição possível copiei seu conteúdo para senha
            strcat(senha, matrizS[i][j]);
            }
        }
        if(i!=j){
            x=0;
            soma=0;
            m=0;
            n=0;

            while(matrizS[i][j][x]!='\0'){  //realizando a soma dos valores ascii
            soma +=  (int)matrizS[i][j][x];
            x++;
            }

            while(soma!=0){
            
            m++;
            for(n=m; n>0; n--)              //m e n sao variaveis auxiliares na transformação de um inteiro para uma string
                somaVet[n]=somaVet[n-1];
            
            somaVet[0]=(soma%10+48);
            soma/=10;
            }
            strcat(senha, somaVet);

            for(m=0; m<31; m++)
                somaVet[m]='\0';    //limpando os restos mortais
        }
    }

printf("Sua senha eh: %s", senha);



return 0;
}