#include <bits/stdc++.h>
#include "node_ADT.h"
using namespace std;

#define ln '\n'
#define ll long long

class Stack
{
private:
    Node *top;
    int size;
    void removeall()
    {
        while(top != NULL)
        {
            Node *tmp = top;
            top = top->next;
            delete tmp;
        }
        size = 0;
    }
public:
    Stack()
    {
        top = NULL;
        size = 0;
    }
    ~Stack(){ removeall(); }
    void push(int num)
    {
        top = new Node(num, top);
        size++;
    }
    int pop()
    {
        if(top == NULL){
            cout << "stack is empty" << ln;
            return 0;
        }
        int value = top->data;
        Node *tmp = top;
        top = top->next;
        delete tmp;
        size--;
        return value;
    }
    int topValue() {
        if(top == NULL){
            cout << "stack is empty" << ln;
            return 0;
        }
        return top->data;
    }
    int length(){ return size; }
};

Stack criar_stack()
{
    Stack st;
    return st;
}