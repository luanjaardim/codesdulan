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

class Graph
{
public:
    vvi vertices;
    vi ordem;
    vi visitados;
    stack<int> topo;
    Graph(int n){
        vertices = vector<vector<int>>(n, vi(0));
        visitados = vi(n, 0);
    }
    void graphTraverse()
    {
        for(int i=0; i<visitados.size(); i++)
        {
            if(visitados[i] == 0)
                topoSort(i);
        }
    }
    int first(int v)
    {
        if(vertices[v].empty())
            return -1;
        return vertices[v][0];
    }
    int next(int v, int w)
    {
        for(int i=0; i<vertices[v].size(); i++)
            if(vertices[v][i] == w)
            {
                if(++i != vertices[v].size())
                    return vertices[v][i];
                else
                    return -1;
            }
        return -1;
    }
    void topoSort(int v)
    {
        visitados[v] = 1; //marca o vertice q chega como visitado
        int w = first(v);
        while(w != -1)
        {
            if(visitados[w] == 0)
                topoSort(w);
            w = next(v, w);
        }
        topo.push(v);
    }
    void printTopo()
    {
        while(!topo.empty())
        {
            int num = topo.top();
            topo.pop();
            cout<<num<<ln;
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int v, e;
    cin>>v>>e;
    Graph grafo(v);
    for(int i=0; i<e; i++)
    {
        int tmp, tmp2;
        cin>>tmp>>tmp2;
        grafo.vertices[tmp].push_back(tmp2);
    }
    grafo.graphTraverse();
    grafo.printTopo();

    return 0;
}



/* #include <bits/stdc++.h>
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

class Graph
{
public:
    si pilha_topo; //salva a ordem topologica
    vvi vertices; //salva as ligacoes
    vector<bool> visited; //vertices visitados ou n
    unordered_map<int, int> conversao; //converte os valores lidos para comecar com uma ordem do 0
    vi decoder; //vai decodificar a saida, ja q conversao mudou as coisas
    int qtd;
    Graph(int v) { 
        qtd=0;
        visited = vector<bool> (v, 0); 
    }
    void graphTraverse()
    {
        for(int i=0; i<vertices.size(); i++)
        {
            if(visited[i] == false)
                topoSort(i);
        }
    }
    void insert(int v, int w)
    {
        if(conversao.find(v) != conversao.end()){ //o vertice ja tinha ligacoes
            vertices[conversao[v]].push_back(w);
        }
        else //vertice novo, n tinha ligacoes
        {
            conversao[v] = qtd;
            decoder.push_back(v);
            vertices.push_back(vi(0));
            vertices[conversao[v]].push_back(w);
            qtd++;
        }
    }
    int first(int v)
    {
        if(vertices[v].empty())
            return -1;
        else
            return conversao[vertices[v][0]];
    }
    int next(int v, int w)
    {

    }
    void topoSort(int vertex)
    {
        visited[vertex] = true; //marca o vertice q chega como visitado
        int w = first(vertex);
        while(w != -1)
        {
            if(visited[w] == false)
                topoSort(w);
            w = next(vertex, w);
        }
        pilha_topo.push(vertex);
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int v, e;
    cin>>v>>e;
    Graph grafo(v);
    for(int i=0; i<e; i++)
    {
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        grafo.insert(tmp1, tmp2);
    }
    grafo.graphTraverse();


    return 0;
} */