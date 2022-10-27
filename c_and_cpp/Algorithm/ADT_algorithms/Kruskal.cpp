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

struct elem{
    int v, u, peso;
};

class dis_Subset_qunion
{
public:
    int *ar;
    dis_Subset_qunion(int n)
    {
        ar = new int[n];
        f(x, n)
            ar[x] = -1;
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


//matriz de adjacencia
class graph
{
public:
    int **vert;
    bool *visitados;
    int numEdge;
    int n;
    graph(int num)
    {
        vert = new int*[num];
        f(x, num){
            vert[x] = new int[num];
            f(y, num)
                vert[x][y] = 0;
        }

        visitados = new bool[num];
        f(x, num)
            visitados[x] = false;

        numEdge = 0;
        n = num;
    }
    ~graph()
    {
        f(x, n)
            delete[] vert[x];
        delete[] vert;

        delete[] visitados;
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

void bottomUp(vec(elem) &a)
{
    int j, k;
    for(int i=((a.size())/2) - 1; i>=0; i--)
    {
        j = i;
        while(j < (a.size())/2)
        {
            int minLeaf = (2*j)+1, rc = (2*j)+2;
            if(rc != a.size() and a[minLeaf].peso > a[rc].peso)
                minLeaf = rc;
            if(a[j].peso > a[minLeaf].peso){
                swap(a[j], a[minLeaf]);
                j = minLeaf;
            }
            else
                break;
        }
    }
}
elem removemin(vec(elem) &h)
{
    elem min = h[0];
    h[0] = h[h.size()-1];
    h.pop_back();
    int j=0;
    while(j < (h.size())/2)
    {
        int minLeaf = (2*j)+1, rc = (2*j)+2;
        if(rc != h.size() and h[minLeaf].peso > h[rc].peso)
            minLeaf = rc;
        if(h[j].peso > h[minLeaf].peso){
            swap(h[j], h[minLeaf]);
            j = minLeaf;
        }
        else
            break;
    }
    return min;
}
void Kruskal(graph &g1, graph &g2)
{
    vec(elem) heap;
    f(i, g1.n){
        elem tmp; 
        tmp.v = i; 
        tmp.u = g1.first(i);
        while(tmp.u < g1.n)
        {
            tmp.peso = g1.vert[i][tmp.u];
            heap.push_back(tmp);
            tmp.u = g1.next(i, tmp.u);
        }
    }
    bottomUp(heap);
    /* for(auto x : heap)
        cout<<x.u<<" "<<x.v<<" "<<x.peso<<ln; */
    int qtd_visited = g1.n;
    dis_Subset_qunion conj(qtd_visited);
    while(qtd_visited > 1)
    {
        elem emin = removemin(heap);
        if(conj.find(emin.v) != conj.find(emin.u))
        {
            conj.union_sets(emin.v, emin.u);
            qtd_visited--;
            g2.insertEdge(emin.v, emin.u, emin.peso);
            cout<<emin.v<<" "<<emin.u<<" "<<emin.peso<<ln;
        }
    }
    /* cout<<"removido: ";
    elem removido = removemin(heap);
    cout<<removido.u<<" "<<removido.v<<" "<<removido.peso<<ln<<ln;
    for(auto x : heap)
        cout<<x.u<<" "<<x.v<<" "<<x.peso<<ln; */
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    graph graf(5);
    graph grafo_final(5);

    int v, u, w;
    while(cin>>v>>u>>w){
        graf.insertEdge(v, u, w); //insere como não direcionais
    }
    Kruskal(graf, grafo_final);
    cout<<ln;
    f(x, 5){
        f(y, 5)
            cout<<grafo_final.vert[x][y]<<" ";
    cout<<ln;
    }

    return 0;
}