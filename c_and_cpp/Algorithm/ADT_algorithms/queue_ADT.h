#include <bits/stdc++.h>
#include "node_ADT.h"
using namespace std;

#define ln '\n'
#define ll long long

class Queue
{
private:
    int size;
    Node *front;
    Node *back;
    void removeall()
    {
        while(front != NULL)
        {
            Node *tmp = front;
            front = front->next;
            delete tmp;
        }
        back = NULL;
    }
public:
    Queue()
    {
        front = back = NULL;
        size = 0;
    }
    ~Queue(){ removeall(); }
  /*void push(int value)
    {
        if(back == NULL && front == NULL){
            back = new Node(value, back);
            front = back;
        }
        else{
            back = new Node(value, back);
        }
        size++;
    }
    int pop()
    {
        int value;
        Node *tmp = back;
        while(tmp->next != front)
        {
            tmp = tmp->next;
        }
        front = tmp;
        front->next = NULL;
        tmp = tmp->next;
        value = tmp->data;
        delete tmp;
        return value;
    } */
    void enqueue(int value)
    {
        if(back == NULL && front == NULL){
            back = new Node(value, NULL);
            front = back;
            size++;
        }
        else{
            back->next = new Node(value, NULL);
            back = back->next;
            size++;
        }
    }
    int dequeue()
    {
        if(size == 0){
            cout << "fila vazia" << ln;
            return 0;
        }
        int value = front->data;
        Node *tmp = front;
        front = front->next;
        size--;
        delete tmp;
        return value;
    }
};

Queue criar_queue()
{
    Queue st;
    return st;
}