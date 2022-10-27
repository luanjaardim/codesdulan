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
#define maxim 7490

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int moedas[] = {5, 10, 25, 50}; //todas os valores podem ser calculados para 1 moeda (n moedas de 1)
    vec(ull) out(maxim+1, 1);
    f(j, 4) 
        for(int i=1; i<maxim; i++)        
            if(i >= moedas[j]) out[i] += out[i - moedas[j]];

    int t;
    while(cin>>t)
    {
        cout<<out[t]<<ln;
    }

    return 0;
}