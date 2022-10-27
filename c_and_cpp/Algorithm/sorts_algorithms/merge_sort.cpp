#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define mat(x, y) (x, vi(y))
#define pii pair<int, int>
#define qi queue<int>
#define si stack<int>
#define pri priority_queue<int>
#define all(x)  x.begin(), x.end()

void merge(int array[], int l, int r)
{
    vi tmp(r+1); //deve ser criado com o tamannho até o indice maximo utilizado, pois os indices sao referentes ao array original
    for(int i=l; i<=r; i++) //se atentar para o <=, pois como passamos n-1 devemos colocar a igualdade
        tmp[i] = array[i];

    int m = (l+r)/2;
    int i1 = l, i2 = m+1;

    for(int curr = l; curr<=r; curr++)
    {
    //as duas primeiras condições só ocorrem quando uma das metades foi totalmente transferida e a outra ainda não
    //as duas ultimas comparam os menores entre as duas listas
        if(i1 == m+1)
            array[curr] = tmp[i2++];
        else if(i2 > r)
            array[curr] = tmp[i1++];
        else if(tmp[i1] <= tmp[i2])
            array[curr] = tmp[i1++];
        else
            array[curr] = tmp[i2++];
    }
}

void mergeSort(int array[], int l, int r)
{
    if(l < r) //só será falsa para arrays unitários, que possuem mesmo l e r, os limites direito e esquerdo
    {
    //cria funcoes recursivas que se dividem até alcancar arrays simples, naturalmente, ordenados e a partir destes
    //cria arrays cada vez maiores, ordenadamente, até ordenar o inicial
        int m = (l+r)/2;
        mergeSort(array, l, m);
        mergeSort(array, m+1, r);

        merge(array, l, r); //ordena os subarrays
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tam;
    cin>>tam;
    int *array = new int[tam];
    for(int i=0; i<tam; i++)
        cin>>array[i];

    mergeSort(array, 0, tam-1);

    for(int i=0; i<tam; i++)
        cout << array[i] << ln;
    
    delete[] array;

    return 0;
}