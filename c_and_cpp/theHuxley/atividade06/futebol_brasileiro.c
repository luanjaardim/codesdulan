//questão: Por favor, salvem o futebol brasileiro, thehuxley

#include <stdio.h>
#include <string.h>

typedef struct{

char nomeClube[100], foco;
int dinheiro, contratados;

} Time;

typedef struct{

char nome[100], paisOrigem[100];
int custo, ataque, defesa;

} Jogador;


int main(){

    int qtdTimes, qtdJogadores, i, j, timeComprador=0, vasco=0;
    
    scanf("%d", &qtdTimes);
    Time times[qtdTimes];

    for(i=0; i<qtdTimes; i++)
        times[i].contratados=0;

    for(i=0; i<qtdTimes; i++){
        scanf(" %99s", times[i].nomeClube);
        if(!(strcmp(times[i].nomeClube, "Vasco"))){ 
            vasco++;
            times[i].dinheiro=0, times[i].foco=0;
            continue; }                         
        scanf("%d %c", &times[i].dinheiro, &times[i].foco);

    }

    scanf("%d", &qtdJogadores);
    Jogador jogadores[qtdJogadores];
    int comprados[qtdJogadores];

    for(i=0; i<qtdJogadores; i++)
        comprados[i]=-1;

    for(i=0; i<qtdJogadores; i++){
        scanf(" %99s %99s", jogadores[i].nome, jogadores[i].paisOrigem);
        scanf("%d %d", &jogadores[i].ataque, &jogadores[i].defesa);
        scanf("%d", &jogadores[i].custo);
    }
    while(vasco>0){
        printf("Vasco nao tem salvacao, tomou 3 pro vitoria em casa\n");
        vasco--;
    }

    for(i=0; i<qtdJogadores; i++){
        timeComprador=0;

        for(j=0; j<qtdTimes; j++){
           
           if(times[j].dinheiro >= jogadores[i].custo && times[timeComprador].dinheiro < jogadores[i].custo){
               timeComprador=j;
               continue;
           }

           if(jogadores[i].custo > times[j].dinheiro){  //checa se o time n pode comprar o jogador
            continue;   
           }
           else{
               if(times[j].foco == times[timeComprador].foco){
                   if(times[j].dinheiro <= times[timeComprador].dinheiro)
                    continue;
                   else
                    timeComprador=j;
               }
               else{
               if(times[j].foco == 'A' && jogadores[i].ataque >= jogadores[i].defesa)
                timeComprador=j;
               if(times[j].foco == 'D' && jogadores[i].ataque < jogadores[i].defesa)
                timeComprador=j;
               }
           }

        
        }
    if(times[timeComprador].dinheiro < jogadores[i].custo)
    printf("%s ta muito caro\n", jogadores[i].nome);
    else{      
    printf("%s eh do %s\n", jogadores[i].nome, times[timeComprador].nomeClube);
    times[timeComprador].dinheiro-=jogadores[i].custo;
    times[timeComprador].contratados++;
    comprados[i]=timeComprador;
    }
               
}
printf("\n");

for(i=0; i<qtdTimes; i++){
    if(!(strcmp(times[i].nomeClube, "Vasco")))
    continue;
    printf("Situacao %s\n", times[i].nomeClube);
    printf("Dinheiro restante = %d\n", times[i].dinheiro);
    printf("Num de Jogadores = %d\n", times[i].contratados);
    for(j=0; j<qtdJogadores; j++){
        if(comprados[j]==i)
        printf("%s %s\n", jogadores[j].nome, jogadores[j].paisOrigem);
    }
    printf("\n");
        
}

return 0;
}