#include <bits/stdc++.h>
#include "node_ADT.h"
using namespace std;

#define ln '\n'
#define ll long long

class Lista_ligada
{
    Node *head;
    Node *tail;
    Node *curr;
    int qtd;
    void removeAll()
    {
        while(head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
public:
    Lista_ligada(int head_value = 0)
    { 
        //head é o primeiro node da lista, apontando para NULL
        //curr e tail são iguais a ele, pois só há 1 node
        head = tail = curr = new Node(head_value, NULL); 
        qtd = 0;
    }
    ~Lista_ligada()
    { removeAll(); }
    void insert(int data)
    {
        curr->next = new Node(data, curr->next);
        if(tail == curr) tail = curr->next; //tail agora está na ponta
        qtd++;
    }
    int remove()
    {
        if(curr->next == NULL){ //o curr está na última posição
            cout << "no element" << ln;
            return 0;
        }
        if(curr->next == tail) //o curr é o penultimo
            tail = curr;
        int value = curr->next->data; //valor do node a ser descartado
        Node *n = curr->next; //guardando o endereço para dar free
        curr->next = curr->next->next;
        qtd--;
        delete n;
        return value;
    }
    void append(int value) //adicionar elementos ao final da lista
    {
        tail->next = new Node(value, NULL); //tail->next poderia estar no lugar de NULL
        tail = tail->next;                  //já que tail sempre aponta pra NULL
        qtd++;
    }
    void moveToStart()
    { curr = head; }
    void moveToEnd()
    { curr = tail; }
    void prev()
    {
        if(curr == head){cout << "no previous element" << ln; return;}
        
        //para achar o anterior devemos fazer um search pela lista desde a head
        Node *tmp = head;
        while(tmp->next != curr) tmp = tmp->next;
        curr = tmp;
    }
    void next(){
        if(curr == tail)
            cout << "no next element" << ln;
        else
            curr = curr->next;
    }
    int lenght()
    {return qtd;}
    int getValue()
    {
        if(curr->next != NULL)
            return curr->next->data;
        cout << "operacao invalida" << ln;
        return 0;
    }
};

Lista_ligada criar_lista_ligada()
{
    Lista_ligada listinha;
    return listinha;
}