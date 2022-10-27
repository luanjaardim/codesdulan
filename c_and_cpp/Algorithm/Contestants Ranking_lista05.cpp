#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define mat(x, y) (x, vi(y, -69))
#define f(x, y) for(int x=0; x<y; x++)
#define vpii vector<pair<int, int>>
#define pii pair<int, int>
#define qi queue<int>
#define si stack<int>
#define pri priority_queue<int>
#define all(x) x.begin(), x.end()
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln
#define intmx INT_MAX

class graph
{
public:
    int n, qtd;
    unordered_map<string, int> convers; //passa as palavras para a forma de index
    unordered_map<int, string> deconvers; //passa os indexs para a forma de palavras
    priority_queue<pii, vpii, greater<pii>> pq;
    vector<bool> visitados;
    vvi mat;
    vector<pair<int, string>> dists;
    graph(int tam)
    {
        qtd = 0;
        n = tam;
        visitados.resize(tam);
        mat.resize(tam);
        dists.resize(tam);
    }
    void setEdge(int v, int w)
    {
        mat[v].push_back(w);
    }
    int first(int v)
    {
        if(!mat[v].empty())
            return 0;
        return -1;
    }
    int next(int v, int w)
    {
        if(++w == mat[v].size())
            return -1;
        return w;
    }
    void add_assist(int v, int w)
    {
        for(int i=0; i<mat[v].size(); i++)
        {
            if(mat[v][i] == w)
                return;
        }
        mat[v].push_back(w);
    }
    void add(string s, string p, string q)
    {
        if(convers.find(s) == convers.end()){
            convers[s] = qtd;
            deconvers[qtd] = s; qtd++;
        }
        if(convers.find(p) == convers.end()){
            convers[p] = qtd;
            deconvers[qtd] = p; qtd++;
        } 
        if(convers.find(q) == convers.end()){
            convers[q] = qtd;
            deconvers[qtd] = q; qtd++;
        }
        add_assist(convers[s], convers[p]);
        add_assist(convers[s], convers[q]);
        add_assist(convers[p], convers[s]);
        add_assist(convers[p], convers[q]);
        add_assist(convers[q], convers[s]);
        add_assist(convers[q], convers[p]);
    }


    void Dijkstra(int source)
    {
        for(int i=0; i<n; i++){
            dists[i].first = INT_MAX; 
            dists[i].second = deconvers[i];
        }
            
        pq.push({0, source}); dists[source].first = 0;// dists[source].second = "Ahmad";

        for(int i=0; i<n; i++)
        {
            pii x;
            do{
                if(pq.empty())
                    return;
                x = pq.top();
                pq.pop();
            }while(visitados[x.second] == 1);

            visitados[x.second] = 1;
            int w = first(x.second);
            while(w != -1)
            {
                if(visitados[mat[x.second][w]] == 0 and dists[mat[x.second][w]].first > x.first + 1) //mat[x.v][w] é um elemento ligado a x.v
                {
                    dists[mat[x.second][w]].first = x.first + 1;    //distancia ate source
                    pq.push({dists[mat[x.second][w]].first, mat[x.second][w]});
                }
                w = next(x.second, w);
            }
        }
    }
    void printing()
    {
        sort(dists.begin(), dists.begin() + qtd);
        cout<<qtd<<ln;
        f(i, qtd)
        {
            cout<<dists[i].second<<" ";
            if(dists[i].first == INT_MAX)
                cout<<"undefined"<<ln;
            else
                cout<<dists[i].first<<ln;
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        graph grafo(3 * n);
        f(i, n)
        {
            string s, p, q;
            cin>>s>>p>>q;
            grafo.add(s, p, q);
        }
        grafo.Dijkstra(grafo.convers["Ahmad"]);
        grafo.printing();
    }

    return 0;
}