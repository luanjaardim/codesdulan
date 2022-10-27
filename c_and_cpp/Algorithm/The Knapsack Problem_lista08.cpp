#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define lt '\t'
#define es " "
#define ll long long
#define ull unsigned long long
#define intmx INT_MAX
#define f(x, y) for(int x=0; x<y; x++)
#define vec(a) vector<a>
#define pair(a, b) pair<a, b>
#define unmap(a, b) unordered_map<a, b>
#define unset(a, b) unordered_set<a, b>
#define all(x) x.begin(), x.end()
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln
#define debug if(true)

struct elem{
    ll p, v;
};

ll knapsack(vec(vec(ll)) &m, vec(elem) &ar, int i, int j)
{
    if(m[i][j] < 0)
    {
        ll value;
        if(j < ar[i].p) value = knapsack(m, ar, i-1, j);
        else{
            value = max(knapsack(m, ar, i-1, j), ar[i].v + knapsack(m, ar, i-1, j-ar[i].p));
        }
        m[i][j] = value;
    }
    return m[i][j];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, s;
    cin>>s>>n;
    vec(elem) ar(n+1);
    vec(vec(ll)) mat(n+1, vec(ll)(s+1));
    f(x, n+1){
        f(y, s+1)
        {
            if(y == 0 or x == 0) mat[x][y] = 0;
            else mat[x][y] = -1;
            //debug cout<<mat[x][y]<<es;
        }
    //debug cout<<ln;
    }

    for(int i=1; i<n+1; i++)
    {
        cin>>ar[i].p>>ar[i].v;
        //debug cout<<ar[i].p<<es<<ar[i].v<<ln;
    }

    knapsack(mat, ar, n, s);
/*     for(auto x : mat){
        for(auto y : x)
            cout<<y<<es;
    cout<<ln;
    } */
    cout<<mat[n][s]<<ln;

    return 0;
}