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

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        array[i] = tmp;
    }

    for(int i=0; i<n-1; i++){
        int menor = i;
        for(int j=i+1; j<n; j++){
            if(array[menor] > array[j])
                menor = j;
        }
        int tmp = array[i];
        array[i] = array[menor];
        array[menor] = tmp;
    }
    for(auto i : array)
        cout << i << ln;

    return 0;
}