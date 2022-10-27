#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define lt '\t'
#define es " "
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

struct elem
{
    int v, u;
    ull peso;
};

class dis_Subset_qunion
{
public:
    vec(int) ar;
    int n;
    dis_Subset_qunion(int num)
    {
        ar.resize(num, -1);
        n = num;
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

bool cmp(elem &a, elem &b)
{
    return a.peso < b.peso;
}

void krusk_damassa(vec(elem) &h, dis_Subset_qunion &conj, vec(ull) &out)
{
    int pos=0;
    while(pos<h.size())
    {
        elem min = h[pos];
        if(conj.find(min.v) != conj.find(min.u))
            conj.union_sets(min.v, min.u);
        else
            out.push_back(min.peso);
        pos++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, v, u, w;
    while(cin>>n>>m)
    {
        dis_Subset_qunion conj(n);
        vec(elem) heap;
        vec(ull) out;
        if(n !=0 and m != 0)
        {
            f(i, m)
            {
                elem x; //elemento x hihi
                cin>>x.v>>x.u>>x.peso;
                heap.push_back(x);
            }
            sort(all(heap), cmp); //heap bottom up
            krusk_damassa(heap, conj, out);
            if(out.empty())
                cout<<"forest"<<ln;
            else{
                cout<<out[0];
                for(int i=1; i<out.size(); i++)
                    cout<<es<<out[i];
                cout<<ln;
            }
        }
        else break;
    }
    return 0;
}