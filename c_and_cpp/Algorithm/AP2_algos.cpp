#include <bits/stdc++.h>
#include "linked_list_ADT.h"
using namespace std;

#define ln '\n'
#define ll long long

int count(Lista_ligada& listinha, int value)
{
    listinha.remove();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int casos;
    cin >> casos;
    while(casos--)
    {
        Lista_ligada listinha = criar_lista_ligada();
        int ops;
        cin >> ops;
        while(ops--)
        {
            string palavra_lida;
            cin >> palavra_lida;
            if(palavra_lida == "insert"){
                int value;
                cin >> value;
                listinha.insert(value);
            }
            else if(palavra_lida == "remove"){
                listinha.remove();
            }
            else if(palavra_lida == "count"){
                int value;
                cin >> value;
                count(listinha, value);
            }
            else if(palavra_lida == "next"){
                listinha.next();
            }
            else if(palavra_lida == "prev"){
                listinha.prev();
            }
            else{
                cout << "error, operacao inexistente, tente novamente" << ln;
                ops++;
            }
        }
        cout << listinha.getValue() << ln;
        listinha.next();
        cout << listinha.getValue() << ln;
    }

    return 0;
}