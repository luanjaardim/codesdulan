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

void func(auto &alo) //auto corresponde ao tipo vector<int> e está recebendo um argumento como referencia
{
    alo.push_back(2);
    alo.push_back(1);
    cout << alo.back() << ln;
    alo.pop_back();
    cout << alo.front() << ln;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    /* multiset<int> alo;
    alo.emplace(9); alo.emplace(8); alo.emplace(9); alo.emplace(1); alo.emplace(1);
    
    for(auto it = alo.begin(); it != alo.end(); it = next(it, 1))
        cout << *it << ln; */

    /* int a, b;
    cin >> a >> b;
    int man = (a > b) ? a : b;

    cout << man << ln; */

    /* vector<int> ksks;
    func(ksks); */

    /* vector<vector<int>> alo(5, vector<int>(5, 10));
    cout << alo.size() << " " << alo[0].size() << " " << alo[0][0] << ln;

    for(auto e : alo){
        for(auto e1 : e)
            cout << e1 << " ";
        cout << ln;
    } */

    /* vector<int> v = {11, 23, 24, 4, 65, 16, 0};
    sort(v.begin(), v.end());
    vector<int>::iterator x = lower_bound(v.begin(), v.end(), 0);
    cout << *x; */

    vvi alo mat(5, 5);

    for(auto x : alo){
        for(auto y : x)
            cout << y << " ";
        cout << ln; 
    }


    
    return 0;
}