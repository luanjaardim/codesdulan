#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data, key;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int value_key, int value, Node *next_value)
    {
        data = value;
        key = value_key;
        next = next_value;
    }
};

class Lista
{
public:
    Node *head;
    Node *tail;
    Node *curr;
    int qtd;
    Lista(int chave = -69, int valor = -69)
    { 
        //head é o primeiro node da lista, apontando para NULL
        //curr e tail são iguais a ele, pois só há 1 node
        head = tail = curr = new Node(chave, valor, NULL); 
        qtd = 0;
    }
    ~Lista()
    {
        while(head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    void append(int chave, int valor) //adicionar elementos ao final da lista
    {      
        tail->next = new Node(chave, valor, NULL); //tail->next poderia estar no lugar de NULL
        tail = tail->next;                         //já que tail sempre aponta pra NULL
        if(head->next == NULL)
            head->next = tail;
        qtd++;
    }
};

class Hash_Table
{
private:
    int m;
    int cnt;
    Lista *table;
    int hash_func(int k)
    {
        return abs(k%(m-1));
    }
public:
    Hash_Table(int tamanho)
    {
        m = tamanho; cnt = 0;
        table = new Lista[tamanho];
    }
    ~Hash_Table()
    {
        delete[] table;
    }
    void insert(int chave, int valor)
    {
        int index = hash_func(chave);
        table[index].append(chave, valor);
        cnt++;
    }
    void print_lista_interna(int chave)
    {
        int index = hash_func(chave);
        table[index].curr = table[index].head->next;
        while(table[index].curr != NULL){
            cout<<table[index].curr->data<<" ";
            table[index].curr = table[index].curr->next;
        }
        cout<<'\n';
    }
};