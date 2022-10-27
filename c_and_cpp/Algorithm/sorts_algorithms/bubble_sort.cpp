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

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++)
            if(array[j] > array[j+1]){
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
    }

    for(int x : array)
        cout << x << ln;

    return 0;
}