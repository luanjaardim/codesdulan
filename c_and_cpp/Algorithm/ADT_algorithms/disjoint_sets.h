#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define intmx INT_MAX
#define f(x, y) for(int x=0; x<y; x++)
#define vec(a) vector<a>
#define pair(a, b) pair<a, b>
#define unmap(a, b) unordered_map<a, b>
#define unset(a, b) unordered_set<a, b>
#define all(x) x.begin(), x.end()
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln


//funciona como array de listas, cada lista representa um conjunto cujo representante é o index
class dis_Subset_qfind
{
public:
    vec(int) represents;
    vec(vec(int)) sets;
    dis_Subset_qfind(int n)
    {
        represents.resize(n);
        sets.resize(n);
        for(int i=0; i<n; i++)
        {
            represents[i] = i;
            sets[i].push_back(i);
        }
    }
    ~dis_Subset_qfind() { }
    int find(int elem)
    {
        return represents[elem];
    }
    void union_sets(int s1, int s2)
    {
        int r1 = find(s1), r2 = find(s2);
        if(r1 != r2)
        {
            int conjunto1 = sets[r1][0]; int conjunto2 = sets[r2][0];
            if(sets[conjunto1].size() < sets[conjunto2].size())
                swap(conjunto1, conjunto2);
            for(int i=0; i<sets[conjunto2].size(); i++)
            {
                int tmp = sets[conjunto2][i];
                sets[conjunto1].push_back(tmp);
                represents[tmp] = sets[conjunto1][0];
            }
            sets[conjunto2].clear();
        }
    }
    void printing()
    {
        for(int i=0; i<sets.size(); i++)
        {
            if(sets[i].empty())
                continue;
            cout<<i<<":  ";
            for(int j=0; j<sets[i].size(); j++)
            {
                cout<<sets[i][j]<<" ";
            }
        cout<<ln;
        }
    }
};

//leva em conta apenas os pais de cada conjunto, é o representante de algum conjunto aquele index que não possui nenhum pai(-1)
class dis_Subset_qunion
{
public:
    vec(int) ar;
    dis_Subset_qunion(int n)
    {
        ar.resize(n, -1);
    }
    int find(int curr)
    {
        if(ar[curr] == -1) return curr; //achou o representante
        ar[curr] = find(ar[curr]); //atualiza o elemento do conjunto que poderia ser filho de um filho do representante, agr ele será o filho direto
        return ar[curr];
    }
    void union_sets(int s1, int s2)
    {
        int r1 = find(s1);
        int r2 = find(s2);
        if(r1 != r2) ar[r2] = r1; //agora o representante do outro conjunto possui um representante
    }
};