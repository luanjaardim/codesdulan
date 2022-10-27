#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// - modos de abertura de arquivo (w, r, wb, rb, a+)
// - abrir arquivo txt
// - escrita e leitura em arquivo normal (fprintf e fscanf)
// - abrir arquivo binario
// - escrita e leitura em arquivo normal (fwrite, fread)
// - funcoes auxiliares com arquivos binarios [brincando com cursores] (fseek, ftell, rewind)


typedef struct{
        int x, y;
        float value;
} cell;


int main(){
        // Declarando variaveis 
        int i, size;
        char buff[255]; char buffer[100];
          char str[] = "zildao eh lindo com fwrite\n";
        FILE *fp = NULL; // boas praticas [acm gosta]


        /// Abrindo arquivos não binários
        // Abrir com "w" => apaga TUDO que tinha no arquivo anterior, permite fazer apenas escrita
        // fp = fopen("arquivo.txt", "w"); 
  // if(fp == NULL) {
  //   printf("arquivo not found");
  //   exit(-1);
  //   }
        // fprintf(fp, "zildao eh lindo com fprintf...\n");
  // fprintf(fp, "%s", str);
  
        // fclose(fp);


  


        // Abrir com "r" => mantém os dados do arquivo, permite fazer apenas leitura
        // fp = fopen("arquivo.txt", "r"); 
        // fscanf(fp, " %[^\n]", buff);
        // printf("1: %s\n", buff );
        // fclose(fp);


        // // Abrir com "a+" => mantem tudo que tava no arquivo anterior, permite fazer leitura e escrita =)
  // fp = fopen("arquivo.txt", "a+");
  // fprintf(fp, "pijey gatao agora printado no arquivo...\n");
  //   fclose(fp);
 
        
          // fp = fopen("arquivo.txt", "r"); 


        // fscanf(fp, " %[^\n]", buff);
        // printf("2: %s\n", buff);


        // fscanf(fp, " %[^\n]", buff);
        // printf("3: %s\n", buff);


  //         fscanf(fp, " %[^\n]", buff);
        // printf("4: %s\n", buff);


        // fclose(fp);


        // Nota: abrir arquivos com "r" necessitam que ele exista, abrir com "w" ou "a+" cria ele automaticamente caso não exista.


        /// AQUI A MÁGICA COMEÇA MEUS AMIGOS
        printf("\n----------------------\n");
        printf("Mágica com binários agora meus amigos\n");
        printf("----------------------\n");
        /// Abrindo arquivos binarios
        // Aqui as aberturas são bem parecidas, mas elas se diferem com um 'b' no final do tipo de abertura. [Ex.: "wb", "rb"], esse modo tem "a+b"
        
        /// Usando "wb" [escrita binária]
        // Geralmente com arquivos binários nas provas de ACM são usadas structs pré-definidas por ele na prova, mas ele também pode pedir pra vocês escreverem vetores de qualquer tipo da linguagem.
/*
        // Preparando um vetor com o tipo de dado de uma struct pré-declarada
        cell celulas[5];
        for(i = 0; i < 5; i++) {
                celulas[i].x = i;
                celulas[i].y = 5-i;
                celulas[i].value = (celulas[i].x * celulas[i].y);
        }


        printf("\n----------------------\n");
        printf("Escrita, debugando o que vai ser escrito:\n");
        printf("----------------------\n");
        for(i = 0; i < 5; i++) {
                printf("Cell %d\n", i);
                printf("Cell x: %d\n", celulas[i].x);
                printf("Cell y: %d\n", celulas[i].y);
                printf("Cell value: %f\n\n", celulas[i].value);
        }


        // Fazendo a escrita
        fp = fopen("arquivo.bin", "wb");
        fwrite(celulas, sizeof(cell), 5, fp);
        fclose(fp);
*/
        /// Usando "rb" [leitura binaria]
/*
        fp = fopen("arquivo.bin", "rb");


        // hack for the life:
        // fseek, ftell e rewind, trio da massa 😎


        // Como estamos trabalhando com arquivos binários, podemos, em vez de fazer uma leitura sequencial dos dados, fazer uma leitura [COMPLETA] deles. Como assim?


        // Se soubermos a quantidade de bytes total do nosso conjunto de dados, podemos também saber quantos elementos aquele arquivo possui e, consequentemente, podemos ler todos os dados de uma vez só!!!! [parece mágica, mas C eh um bom mágico].


        fseek(fp, 0, SEEK_END); // Movendo o cursor para o fim do arquivo https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm


        size = ftell(fp); // Obtendo a quantidade de bytes (começo do arquivo até o cursor)
        size = size / sizeof(cell); // Pegando a quantidade de elementos no arquivo (tamanho em bytes / tamanho de cada elemento)
        rewind(fp); // Movendo o cursor de volta para o começo do arquivo [importante para poder fazer fread depois] pode usar fseek(fp, 0, SEEK_SET) tbm;


   


        // Alocado memória no nosso vetor que irá armazenar os dados
        cell *celulasRecebidas = NULL; // boa pratica
        celulasRecebidas = (cell *) malloc(size * sizeof(cell));


  if(celulasRecebidas==NULL){
    printf("deu ruim no vetor de celulas");
    exit(-1);
  }


        // Chamando o brabissimo fread
        fread(celulasRecebidas, sizeof(cell), size, fp);


        printf("\n----------------------\n");
        printf("Leitura, debugando o que foi lido:\n");
        printf("----------------------\n");


        // Debugando pra provar a mágica 😎
        for(i = 0; i < size; i++) {
                printf("Cell %d\n", i);
                printf("Cell x: %d\n", celulasRecebidas[i].x);
                printf("Cell y: %d\n", celulasRecebidas[i].y);
                printf("Cell value: %f\n\n", celulasRecebidas[i].value);
        }
*/


        /// Método alternativo de leitura (diga-se de passagem, feio pa caraio)
        printf("----------------------\n");
        printf("Método alternativo de leitura\n");
        printf("----------------------\n");


        fp = fopen("arquivo.bin", "rb");
        rewind(fp); // Voltando o ponteiro para o começo do arquivo (só to fazendo isso pq a gente tava lendo nele antes, mas quando o arquivo eh aberto o ponteiro já ta no começo!)


        // fread retorna a quantidade de bytes lidos... então enquanto tentarmos ler e ele retornar valors diferentes de 0 (leu com sucesso), tamo safe!
        cell celulazinha;
        cell *celulasRecebidas2 = NULL; // boa pratica
        int quantidade = 0;
        while(fread(&celulazinha, sizeof(cell), 1, fp) != 0) {
                // O bom e velho realloc
                celulasRecebidas2 = (cell *) realloc(celulasRecebidas2, (quantidade + 1) * sizeof(cell));


    if(celulasRecebidas2 == NULL){
      printf("deu ruim celulasRecebidas2 na alloc %d", (quantidade + 1));
      exit(-1);
    }
                
                // Atribui a celula lida
                celulasRecebidas2[quantidade] = celulazinha;


                // Incrementa quantidade
                quantidade++;
        }


        // Boh debugar, esse jeito é mto feio
        for(i = 0; i < quantidade; i++) {
                printf("Cell %d\n", i);
                printf("Cell x: %d\n", celulasRecebidas2[i].x);
                printf("Cell y: %d\n", celulasRecebidas2[i].y);
                printf("Cell value: %f\n\n", celulasRecebidas2[i].value);
        }


        printf("----------------------\n");


        // Fecha o arquivaum
        fclose(fp); 
        
        return 0;
}