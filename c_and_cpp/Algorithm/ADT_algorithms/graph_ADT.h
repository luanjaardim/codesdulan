#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long

class Graph
{
public:
    int numEdge;
    vector<vector<int>> vertices; //lista dos correspondentes de cada vertice
    vector<bool> visited; //lista de visitados

    Graph(int n)
    {
        for(int i=0; i<n; i++)
            vertices.push_back(vector<int>(n, 0));
        for(int i=0; i<n; i++)
            visited.push_back(false);
        numEdge = 0;
    }
    void setEdge(int x, int y, int val)
    {
        if(val == 0) return;
        if(vertices[x][y] == 0) numEdge++; //nao tinha nada na posicao
        vertices[x][y] = val;
    }
    void delEdge(int x, int y)
    {
        if(vertices[x][y] != 0) numEdge--;
        vertices[x][y] = 0;
    }
    int first(int vx)
    {
        for(int i=0; i<vertices[vx].size(); i++)
            if(vertices[vx][i] != 0) return i;
        return vertices[vx].size();
    }
    int next(int vx, int w)
    {
        for(int i=w+1; i<vertices[vx].size(); i++)
            if(vertices[vx][i] != 0) return i;
        return vertices[vx].size();
    }
    void graphTraverse()
    {
        for(int i=0; i<visited.size(); i++)
            visited[i] = false;
        for(int v=0; v<visited.size(); v++)
        {
            if(visited[v] == false)
                DFS(v); // ou BSF, topoSort
        }
    }
    void DFS(int v)
    {
        //previsit de v
        visited[v] = true;
        int w = first(v);
        while(w < vertices[v].size())
        {
            if(visited[w] == false)
                DFS(w);
            w = next(v, w);
        }
        //posvisit de v
    }
    void BFS(int v)
    {
        queue<int> ordem_visita;
        ordem_visita.push(v);
        visited[v] = true;
        while(!ordem_visita.empty())
        {
            v = ordem_visita.front();
            ordem_visita.pop();
            //previsit de v
            int w = first(v);
            while(w < vertices[v].size())
            {
                if(visited[w] == false)
                {
                    visited[w] = true;
                    ordem_visita.push(w);
                }
                w = next(v, w);
            }
            //posvisit v
        }
    }
    void topoSort(int v, stack<int> &ordem) //utilizado em conjunto com uma pilha, q guarda a ordem topologica    a lógica é a mesma de uma DFS
    {
        visited[v] = true; //marca o vertice q chega como visitado
        int w = first(v);
        while(w < vertices[v].size())
        {
            if(visited[w] == false)
                topoSort(w, ordem);
            w = next(v, w);
        }
        ordem.push(v);
    }
};