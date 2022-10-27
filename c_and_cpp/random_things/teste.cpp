#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long

void sap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

 //testes com a função new e delete
/*     int *num;
    num = new int(10); //alocando um inteiro e devolvendo seu endereco ao ponteiro num, o valor entre () atribui valor no endereco alocado, por default = 0
        if(num == nullptr) exit(1);  

    cout << *num << ln;

    delete num; //dando "free" no endereco alocado  */

/*     int linhas, colunas;     //alocando dinamicamente uma matriz com os operadores new e delete
    cin >> linhas >> colunas;
    int **pt_duplo = new int *[linhas];
        if(pt_duplo == NULL) exit(1);
    for(int i=0; i<linhas; i++)
    {
        pt_duplo[i] = new int[colunas]; //alocando os ponteiros simples
            if(pt_duplo[i] == NULL) exit(1);
        for(int j=0; j<colunas; j++)
            pt_duplo[i][j] = i+j;
    }

    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++)
            cout << pt_duplo[i][j] << " ";
        cout << ln;
    }

    for(int i=0; i<linhas; i++)
        delete[] pt_duplo[i]; //por se tratarem de arrays usamos o []
    delete[] pt_duplo; */

/*
//passa parametros por referencia sem precisar colocar & antes, so depois
int a=5, b=6;
sap(a, b);
cout << a << " " << b << ln; */
    
    /* int alo = 10;
    alo = 1<<alo;
    cout << alo; */

    /* int alo = -1;

    assert(alo>0); //avisa ao usuário que houve um erro inesperado. */

    return 0;
}


//priority_queue para structs
/* struct elem
{
    int g, r, s;
};

struct cmp{
    bool operator()(elem const& a, elem const& b)
    {
        return a.g > b.g;
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    priority_queue<elem, vec(elem), cmp> gg; elem teste;
    while(cin>>teste.g>>teste.r>>teste.s)
        gg.push({teste.g, teste.r, teste.s});
    
    while(!gg.empty()){
        teste = gg.top();
        cout<<teste.g<<" "<<teste.r<<" "<<teste.s<<ln;
        gg.pop();
    }

    return 0;
} */