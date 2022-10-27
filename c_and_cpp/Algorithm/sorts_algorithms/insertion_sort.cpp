#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int array[7] = {89, 45, 68, 90, 29, 34, 17};
    int v, i, j;

    //funciona vendo quais são os elementos anterios a v que são maiores que ele, quando achar um menor v é posto ao lado dele
    //caso v seja o menor, ele é posto na posição zero, pois j fica -1 e sai do while loop.
    for(i=1; i<7; i++)
    {
        v = array[i];
        j = i - 1;
        while(j>=0 && array[j] > v)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = v;
    }
    for(i=0; i<7; i++)
        cout << array[i] << " ";

    return 0;
}