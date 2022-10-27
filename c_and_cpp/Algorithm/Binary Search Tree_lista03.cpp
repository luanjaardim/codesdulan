#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define f(x, y) for(int x=0; x<y; x++)

class BST_node
{
public:
    int k;
    BST_node *l, *r;
    BST_node(int chave=0)
    {
        k = chave;
        l = NULL; r = NULL;
    }
};

class BST_tree
{
public:
    int count;
    BST_node *root, *l_greater, *r_greater;

    void inserthelp(BST_node *rt, int chave_insert)
    {
        if(chave_insert < rt->k){
            if(rt->l == NULL)
                rt->l = new BST_node(chave_insert);
            else
                inserthelp(rt->l, chave_insert);
        }
        else{
            if(rt->r == NULL)
                rt->r = new BST_node(chave_insert);
            else
                inserthelp(rt->r, chave_insert);
        }
    }
    BST_tree()
    { 
    root = l_greater = r_greater = NULL; 
    count = 0; 
    }

/*     ~BST_tree()
    { destructor(root); }
    void destructor(BST_node *rt)
    {
        if(rt != NULL)
        {
            destructor(rt->l);
            destructor(rt->r);
            delete rt;
        }
    } */

    void postorder_print(BST_node *node)
    {
        if(node->l != NULL)
            postorder_print(node->l);
        if(node->r != NULL)
            postorder_print(node->r);
        cout<<node->k<<ln;
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    BST_tree a;

    int values;
    cin>>values;
    a.root = new BST_node(values);
    a.l_greater = a.r_greater = a.root;

    while(cin>>values)
    {
        if(values < a.l_greater->k){
            a.l_greater->l = new BST_node(values);
            a.l_greater = a.l_greater->l;
        }
        else if(values > a.r_greater->k){
            a.r_greater->r = new BST_node(values);
            a.r_greater = a.r_greater->r;
        }
        else
            a.inserthelp(a.root, values);
    }
    a.postorder_print(a.root);

    return 0;
}