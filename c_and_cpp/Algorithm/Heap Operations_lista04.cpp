#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define f(x, y) for(int x=0; x<y; x++)

typedef struct par
{
    string f;
    ll s;
};

class heap
{
public:
    ll ar[100002];
    int n;
    heap()
    { n=0; }
    void insert(int value)
    {
        n++;
        ar[n] = value;
        int tmp = n;
        bool h = false;
        while(!h and tmp/2 >= 1)
        {
            if(ar[tmp] < ar[tmp/2]){
                swap(ar[tmp], ar[tmp/2]);
                tmp/=2;
            }
            else h = true;
        }
    }
    ll removeMin()
    {
        if(n==0)
            return LONG_LONG_MAX;
        int tmp = 1;
        swap(ar[tmp], ar[n]);
        n--;
        bool h = false;
        while(!h and n>1)
        {
            if( tmp*2==n or ar[tmp*2] < ar[(tmp*2) + 1])
                tmp*=2;
            else tmp = tmp*2 + 1;
            if(ar[tmp] < ar[tmp/2] and tmp <= n)
                swap(ar[tmp], ar[tmp/2]);
            else h = true;
        }
        return ar[n+1];
    }
    ll getMin()
    {
        if(n!=0)
            return ar[1];
        return LONG_LONG_MAX;
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    heap lista;
    int t, qtd_ops=0, nums;
    string leitura;
    cin>>t;
    par output[3*t]; //chute pra cima
    ll values[t];
    while(t--)
    {
        qtd_ops++;
        cin>>leitura;
        if(leitura[0] == 'i'){
            cin>>nums;
            lista.insert(nums);
            //output.push_back({leitura, nums});
            output[qtd_ops-1].f = leitura; output[qtd_ops-1].s = nums;
        }
        else if(leitura[0] == 'r')
        {
            ll removed = lista.removeMin();
            if(removed == LONG_LONG_MAX){
                //output.push_back({"insert", 0});
                output[qtd_ops-1].f = "insert"; output[qtd_ops-1].s = 0;
                qtd_ops++;
            }
            //output.push_back({leitura, 0});
            output[qtd_ops-1].f = leitura; output[qtd_ops-1].s = 0;
        }
        else
        {
            cin>>nums;
            if(lista.getMin() > nums){
                //output.push_back({"insert", nums});
                output[qtd_ops-1].f = "insert"; output[qtd_ops-1].s = nums;
                qtd_ops++;
                //output.push_back({leitura, nums});
                output[qtd_ops-1].f = leitura; output[qtd_ops-1].s = nums;
                lista.insert(nums);
            }
            else if(lista.getMin() == nums){
                //output.push_back({leitura, nums});
                output[qtd_ops-1].f = leitura; output[qtd_ops-1].s = nums;
            }
            else
            {
                while(lista.getMin() < nums)
                {
                    output[qtd_ops-1].f = "removeMin"; output[qtd_ops-1].s = 0;
                    qtd_ops++;
                    //output.push_back({"removeMin", 0});
                    lista.removeMin();
                }
                if(lista.getMin() == nums){
                    output[qtd_ops-1].f = leitura; output[qtd_ops-1].s = nums;
                    //output.push_back({leitura, nums});
                }
                else{
                    output[qtd_ops-1].f = "insert"; output[qtd_ops-1].s = nums;
                    qtd_ops++;
                    //output.push_back({"insert", nums});
                    output[qtd_ops-1].f = leitura; output[qtd_ops-1].s = nums;
                    //output.push_back({leitura, nums});
                    lista.insert(nums);
                }
            }
        }
    }
    cout<<qtd_ops<<ln;
    f(i, qtd_ops){
        if(output[i].f[0] == 'r')
            cout<<"removeMin"<<ln;
        else
            cout<<output[i].f<<" "<<output[i].s<<ln;
    }
    
    return 0;
}