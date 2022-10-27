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

int HoarePartition(int *array, int l, int r)
{
    //i vai ser o cara que vai procurar o primeiro elemento da esquerda para a direita
    //do subarray a ser maior q o p(pivot), e j vai procurar pelo primeiro menor
    //se repetindo até o ponto que esses dois se cruzem e seja garantido que 
    //à esquerda do pivot só existem elementos menores ou iguais a ele
    //e à direita apenas maiores ou iguais. o processo vai se repetir para os dois subarrays gerados.
    int p = array[l], i = l, j = r + 1;
    do
    {
        do{
            i++;
        } while(i < r && array[i] < p);
        do{
            j--;
        } while(array[j] > p);    

        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;

    }while(i<j);

    //essa última troca existe para desfazer a última troca(errada) do loop anterior
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    //novo local do pivot
    tmp = array[l]; 
    array[l] = array[j];
    array[j] = tmp;
    return j;
}

void quickSort(int *array, int l, int r)
{
    if(l < r)
    {
        int s = HoarePartition(array, l, r);
        quickSort(array, l, s-1);
        quickSort(array, s+1, r);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tam;
    cin>>tam;
    int array[tam];
    for(int i=0; i<tam; i++)
        cin>>array[i];
    
    quickSort(array, 0, tam-1);

    for(int i=0; i<tam; i++)
        cout<<array[i]<<ln;

    return 0;
}