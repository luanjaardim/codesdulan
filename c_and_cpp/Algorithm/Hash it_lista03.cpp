#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define f(x, y) for(int x=0; x<y; x++)

class hash_table
{
public:
    int qtd;
    string *keys;
    hash_table()
    {
        qtd=0;
        keys = new string [101];
    }
    ~hash_table()
    {
        delete[] keys;
    }
    bool insert(string key){
        int h = 0, pos_h;
        for(int i=0; i<key.size(); i++){
            h += int(key[i])*(i+1);
        }
        h = (h*19)%101;

        for(int j=0; j<=19; j++){
            pos_h = (h+(23*j)+(j*j))%101;
            if(keys[pos_h] == key){
                return false;
            }
        }
        for(int j=0; j<=19; j++){
            pos_h = (h+(j*j)+(23*j))%101;
            if(keys[pos_h].empty()){
                keys[pos_h] = key;
                return true;
            }
        }
        return false;
    }
    bool remove(string key){
        int h = 0, pos_h;
        for(int i=0; i<key.size(); i++){
            h += int(key[i])*(i+1);
        }
        h = (h*19)%101;

        for(int j=0; j<=19; j++){
            pos_h = (h+(23*j)+(j*j))%101;
            if(keys[pos_h] == key){
                keys[pos_h] = "";
                return true;
            }
        }
        return false;
    }
    void printizin()
    {
        cout<<qtd<<ln;
        f(i, 101)
            if(!keys[i].empty())
                cout<<i<<":"<<keys[i]<<ln;
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    f(i, t)
    {
        hash_table mesa;
        int n;
        cin>>n;
        f(i, n)
        {   
            string linha, palavra;
            cin>>linha;
            palavra = linha.substr(4);
            if(linha.substr(0, 4) == "ADD:"){ //ADD
                if(mesa.insert(palavra))
                    mesa.qtd++;
            }
            else if(linha.substr(0, 4) == "DEL:"){ //DEL
                if(mesa.remove(palavra))
                    mesa.qtd--;
            }
        }
        mesa.printizin();
    }

    return 0;
}