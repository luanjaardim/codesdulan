#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long

class Lista_array
{
private:
    int maxSize, size, curr;
    int *array;
    void removeall()
    {
        delete[] array;
    }

public:
    Lista_array(int Msize)
    {
        array = new int[Msize];
        maxSize = Msize;
        size = curr = 0;
    }
    ~Lista_array()
    { removeall(); }
    void insert(int num_add) //insere um elemento na direita do cursor, se houver espaço
    { 
        if(size >= maxSize)
            printf("Nao ha mais espaco no array!");
        else
        {
            for(int i = size; i > curr; i--)
            {
                array[i] = array[i-1];
            }
            array[curr] = num_add;
            size++;
        }
    }
    int remove() //remove o elemento na direita do cursor, se houver
    {
        int value = array[curr];
        if(curr < 0 || curr >= size)
            printf("Operação inválida");
        else
        {
            for(int i = curr; i < size; i++)
            {
                array[i] = array[i+1];
            }
            size--;
        }
        return value;
    }
    int count(int procurar) //conta as repetições de um valor
    {
        int cont = 0;

        for(int i=0; i<size; i++)
        {
            if(array[i] == procurar)
                cont++;
        }
        return cont;
    }
    void prev() //move o cursor para a esquerda
    {
        if(curr == 0)
            printf("O cursor ja esta no limite minimo");
        else
            curr--;
    }

    void next() //move o cursor para a direita
    {
        if(curr == size)
            printf("O cursor ja esta no limite maximo");
        else
            curr++;
    }

    void clear() //"limpa" a lista
    {
        size = 0;
        curr = 0;
    }
    void getInfo() //mostra infos
    {
        cout << "Tamanho atual da lista: " << size << ln;
        cout << "Posicao atual do cursor: " << curr << ln;
    }
    int getValue() //mostra o valor no cursor
    {
        if(curr < size && curr >= 0 && size > 0)
            return array[curr];
        cout << "operacao invalida" << ln;
        return 0;
    }

    void deletar_lista_array()
    {
        delete[] array;
        array = NULL;
    }
};

Lista_array criar_lista_array(int Msize)
{
    Lista_array listinha(Msize);
    return listinha;
}