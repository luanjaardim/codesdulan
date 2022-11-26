#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem
{
    void *t1, *t2; //tipo coringa, podemos usar o casting para os mais diversos tipos de ponteiros
    int (* func)(int (* op)(void *arg1, void *arg2), void *a, void *b); 
    //recebe um endereço de função que devolve um int e recebe uma outra função e dois void * como argumentos
    //a ideia é usar uma função coringa que pode executar qualquer função que seja passada para ela como argumento
    //essa função vai retornar, como uma intermediária, o valores que a função que lhe foi passada retornou
}elem;

int operator(int (* op)(void *a, void *b), void *a, void *b), sub(void *a, void *b), add(void *a, void *b);

int main(int argc, char *argv[])
{
    if(argc <= 3) printf("Passe os argumentos corretamente!\n");
    // ./a 3 3 add   |  ./a 10 5 sub
    else
    {
        int a, b;
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        elem e = {(void *) &a, (void *) &b, &operator};
        if(!strcmp(argv[3], "add"))
            printf("%d\n", e.func(&add, e.t1, e.t2));
        else if(!strcmp(argv[3], "sub"))
            printf("%d\n", e.func(&sub, e.t1, e.t2));
        else  
            printf("não conheço essa operação\n");
    }
    getchar();
    return 0;
}

int add(void *a, void *b)
{
    return *(int *)a + *(int *)b;
}

int sub(void *a, void *b)
{
    return abs(*(int *)a - *(int *)b);
}

int operator(int (* op)(void *a, void *b), void *a, void *b)
{
    return op(a, b);
}
