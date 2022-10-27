#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define f(x, y) for(int x=0; x<y; x++)

class node
{
public:
    int num, right_nodes, left_nodes, height;
    node *l, *r;
    node(int value = 0)
    {
        right_nodes = left_nodes = height = 0;
        num = value;
        l = r = NULL;
    }
};

void destructor(node *rt)
{
    if(rt != NULL)
    {
        destructor(rt->l);
        destructor(rt->r);
        delete rt;
    }
}

int h(node *rt) //pega a altura do nó
{
    if(rt == NULL) return -1;

    else return rt->height;
}
int getBalance(node *rt) //pega o balanço das alturas de cada lado
{
    if(rt == NULL) return 0;

    else return h(rt->l) - h(rt->r);
}
node *leftRotate(node *rt)
{
    node *r = rt->r;
    node *rl = r->l;
    r->l = rt;
    rt->r = rl;
    rt->height = 1 + max(h(rt->r), h(rt->l));
    r->height = 1 + max(h(r->r), h(r->l));

    if(rl == NULL) rt->right_nodes = 0;
    else rt->right_nodes = rl->left_nodes + rl->right_nodes + 1;

    r->left_nodes = rt->left_nodes + rt->right_nodes + 1;

return r;
}
node *rightRotate(node *rt)
{
    node *l = rt->l; //filho esquerdo de rt
    node *lr = l->r; //filho direito do filho esquerdo de rt
    l->r = rt; // a nova raiz vai ficar com a antiga na sua direita, pois é uma rotacao para direita
    rt->l = lr;  // a antiga raiz pega o que estava na direita da nova e coloca na sua esquerda
    rt->height = 1 + max(h(rt->r), h(rt->l));
    l->height = 1 + max(h(l->r), h(l->l));

    if(lr == NULL) rt->left_nodes = 0;
    else rt->left_nodes = lr->left_nodes + lr->right_nodes + 1;

    l->right_nodes = rt->left_nodes + rt->right_nodes + 1;

return l; //nova raiz
}

node *insert(node *rt, int chave_insert)
{
    if(rt == NULL)
        return new node(chave_insert);
    if(rt->num > chave_insert){
        rt->l = insert(rt->l, chave_insert);
        rt->left_nodes++;
    }
    else if(rt->num < chave_insert){
        rt->r = insert(rt->r, chave_insert);
        rt->right_nodes++;
    }
    rt->height = 1 + max(h(rt->l), h(rt->r));
    int balance = getBalance(rt);

        if(balance < -1 and chave_insert > rt->r->num) //inserido à direita do elemento da direita, L rotation.
            return leftRotate(rt);
        if(balance > 1 and chave_insert < rt->l->num) //inserido à esquerda do elemento da esquerda, R rotation.
            return rightRotate(rt);
        if(balance > 1 and chave_insert > rt->l->num){
            rt->l = leftRotate(rt->l);
            return rightRotate(rt);
        }
        if(balance < -1 and chave_insert < rt->r->num){
            rt->r = rightRotate(rt->r);
            return leftRotate(rt);
        }

    return rt; //está balanceada
}

bool exist;
int show_index(node *rt, int procurado)
{
    if(rt != NULL)
    {
        if(rt->num > procurado) return show_index(rt->l, procurado);
        else if(rt->num < procurado) return (rt->left_nodes + 1) + show_index(rt->r, procurado);
        else return rt->left_nodes;
    }
    else
    {
        exist = false;
        return 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    node *root = NULL;

    int t, op, value, index;
    cin>>t;
    f(i, t)
    {
        cin>>op>>value;
        if(op == 1)
        {
            root = insert(root, value);
        }
        else if(op == 2)
        {
            exist = true;
            index = show_index(root, value);
            if(exist) cout<<(index+1)<<ln;
            else cout<<"Data tidak ada"<<ln;
        }
    }
    destructor(root);

    return 0;
}