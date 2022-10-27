/* #include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define lt '\t'
#define es " "
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

class graph //matriz de adj
{
public:
    vec(vec(int)) vert;
    vec(bool) visitados;
    vec(int) dists;
    int numEdge;
    int n;
    graph(int num)
    {
        vert.resize(num);
        f(x, num)
            vert[x].resize(num, 0);
        
        visitados.resize(num, false);
        dists.resize(num, intmx);


        numEdge = 0;
        n = num;
    }
    int first(int v)
    {
        f(i, n)
            if(vert[v][i] != 0)
                return i;
        return n;
    }
    int next(int v, int w)
    {
        for(int j=w+1; j<n; j++)
            if(vert[v][j] != 0)
                return j;
        return n;
    }
    void setEdge(int i, int j, int w)
    {
        if(vert[i][j] == 0 and w != 0)
        {
            vert[i][j] = w; //n há sentido em aceitar w = 0
            numEdge++;
        }
    }
    void delEdge(int i, int j)
    {
        if(vert[i][j] != 0)
        {
            numEdge--;
            vert[i][j] = 0;
        }
    }
    void insertEdge(int i, int j, int w){
        setEdge(i, j, w);
        setEdge(j, i, w);
    }
};

void djk(graph &g, int source, int dest)
{
    priority_queue<pair(int, int), vec(pair(int, int)), greater<pair(int, int)>> pq;
    pq.push({0, source});
    g.dists[source] = 0;

    f(i, g.n)
    {
        pair(int, int) x;
        do{
            if(pq.empty())
                return;
            x = pq.top();
            pq.pop();
        }while(g.visitados[x.second] == true);
            g.visitados[x.second] = true;
            if(g.visitados[dest] == true) //já achou o menor caminho
                return;

            int w = g.first(x.second);
            while(w<g.n)
            {
                if(g.visitados[w] == false and g.dists[w] > (g.dists[x.second] + g.vert[x.second][w])){
                    g.dists[w] = g.dists[x.second] + g.vert[x.second][w];
                    pq.push({g.vert[x.second][w], w});
                }
                w = g.next(x.second, w);
            }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    f(a, t)
    {
        int n, m, source, dest;
        cin>>n>>m>>source>>dest;
        graph g(n);
        f(b, m)
        {
            int u, v, w;
            cin>>u>>v>>w;
            g.insertEdge(u, v, w);
        }
        djk(g, source, dest);
        if(g.dists[dest] != intmx)
            cout<<"Case #"<<(a+1)<<": "<<g.dists[dest]<<ln; //printf("Case #%i: %i\n", a+1, g.dists[dest]);
        else
            cout<<"Case #"<<(a+1)<<": unreachable"<<ln;
    }

    return 0;
} */

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
    int n;
    priority_queue<pii, vpii, greater<pii>> pq;
    vector<bool> visitados;
    vector<vector<pair<int, int>>> mat;
    vi dists;
    graph(int tam)
    {
        n = tam;
        visitados.resize(tam, false);
        dists.resize(tam, intmx);
        mat.resize(tam);
    }
    int weight(int v, int w)
    {
        return mat[v][w].first;
    }
    void insertEdge(int v, int u, int w)
    {
        setEdge(v, u, w);
        setEdge(u, v, w);
    }
    void setEdge(int v, int u, int w)
    {
        mat[v].push_back({w, u});
    }
    int first(int v)
    {
        if(!mat[v].empty())
            return 0;
        return -1;
    }
    int next(int v, int w)
    {
        if(++w == (int) mat[v].size())
            return -1;
        return w;
    }
    void Dijkstra(int source, int dest)
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
            if(visitados[dest] == 1)
                return;

            int w = first(x.second);
            while(w != -1)
            {
                if(visitados[mat[x.second][w].second] == 0 and dists[mat[x.second][w].second] > (x.first + weight(x.second, w))) //mat[x.v][w] é um elemento ligado a x.v
                {
                    dists[mat[x.second][w].second] = x.first + weight(x.second, w);
                    pq.push({dists[mat[x.second][w].second], mat[x.second][w].second});
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

    int t;
    cin>>t;
    f(a, t)
    {
        int n, m, source, dest;
        cin>>n>>m>>source>>dest;
        graph g(n);
        f(b, m)
        {
            int u, v, w;
            cin>>u>>v>>w;
            g.insertEdge(u, v, w);
        }
        g.Dijkstra(source, dest);
        if(g.dists[dest] != intmx)
            cout<<"Case #"<<(a+1)<<": "<<g.dists[dest]<<ln; //printf("Case #%i: %i\n", a+1, g.dists[dest]);
        else
            cout<<"Case #"<<(a+1)<<": unreachable"<<ln;
    }

    return 0;
}