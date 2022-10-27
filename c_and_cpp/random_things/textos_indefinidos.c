#include <stdio.h>
#include <stdlib.h>

int main(){
    char *texto = NULL, carac;
    int qtd = 0;

    do {
        scanf("%c", &carac);
        texto = (char *) realloc(texto, (qtd+1) * sizeof(char));
            if(texto == NULL) exit(1);
        texto[qtd] = carac;
        qtd++;

    }   while(carac != '\n');

    if(texto[qtd-1] == '\n')
        texto[qtd-1] = '\0';

    printf("%s", texto);
    free(texto);

    return 0; 
}