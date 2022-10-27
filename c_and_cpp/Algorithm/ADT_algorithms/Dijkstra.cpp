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

class graph
{
public:
    int n;
    priority_queue<pii, vpii, greater<pii>> pq;
    vector<bool> visitados;
    vvi mat;
    vi dists;
    graph(int tam)
    {
        n = tam;
        visitados.resize(tam);
        mat.resize(tam);
        dists.resize(tam);
    }
    void insertEdge(int v, int w)
    {
        setEdge(v, w);
        setEdge(w, v);
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
    void Dijkstra(int source)
    {
        for(int i=0; i<n; i++)
            dists[i] = INT_MAX;
        pq.push({0, source}); dists[source] = 0;

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
                if(visitados[mat[x.second][w]] == 0 and dists[mat[x.second][w]] > x.first + 1) //mat[x.v][w] é um elemento ligado a x.v
                {
                    dists[mat[x.second][w]] = x.first + 1;
                    pq.push({dists[mat[x.second][w]], mat[x.second][w]});
                }
                w = next(x.second, w);
            }
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    graph grafo(5);

    int t, q;
    while(cin>>t>>q)
    {
        grafo.setEdge(t, q);
    }
    grafo.Dijkstra(0);

    return 0;
}