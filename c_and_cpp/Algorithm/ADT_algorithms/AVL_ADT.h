#include <bits/stdc++.h>
using namespace std;
//AVL as Dictionary

class AVL_Node
{
public:
    int key, value, height;
    AVL_Node *left, *right;

    AVL_Node(int chave, int valor)
    {
        key=chave; value=valor; height = 0;
        left = NULL; right = NULL;
    }
    AVL_Node()
    {
        key = 0; value = 0;
        left = NULL; right = NULL;
    }
};

class AVL
{
private:
    AVL_Node *root;
    int node_count;
    int findhelp(AVL_Node *rt, int chave_buscada)
    {
        if(rt == NULL) return NULL;
        if(rt->key == chave_buscada) return rt->value;
        else if(rt->key > chave_buscada) return findhelp(rt->left, chave_buscada);
        else return findhelp(rt->right, chave_buscada);
    }
    int h(AVL_Node *rt) //pega a altura do nó
    {
        if(rt == NULL) return -1;

        else return rt->height;
    }
    int getBalance(AVL_Node *rt) //pega o balanço das alturas de cada lado
    {
        if(rt == NULL) return 0;

        else return h(rt->left) - h(rt->right);
    }
    AVL_Node *leftRotate(AVL_Node *rt)
    {
        AVL_Node *r = rt->right;
        AVL_Node *rl = r->left;
        r->left = rt;
        rt->right = rl;
        rt->height = 1 + max(h(rt->right), h(rt->left));
        r->height = 1 + max(h(r->right), h(r->left));
    return r;
    }
    AVL_Node *rightRotate(AVL_Node *rt)
    {
        AVL_Node *l = rt->left; //filho esquerdo de rt
        AVL_Node *lr = l->right; //filho direito do filho esquerdo de rt
        l->right = rt; // a nova raiz vai ficar com a antiga na sua direita, pois é uma rotacao para direita
        rt->left = lr;  // a antiga raiz pega o que estava na direita da nova e coloca na sua esquerda
        rt->height = 1 + max(h(rt->right), h(rt->left));
        l->height = 1 + max(h(l->right), h(l->left));
    return l; //nova raiz
    }
    AVL_Node *inserthelp(AVL_Node *rt, int chave_insert, int valor_insert)
    {
        if(rt == NULL)
        { 
            node_count++;
            AVL_Node *tmp = new AVL_Node(chave_insert, valor_insert);
            return tmp;
        }
        if(rt->key > chave_insert)
            rt->left = inserthelp(rt->left, chave_insert, valor_insert);
        else if(rt->key < chave_insert)
            rt->right = inserthelp(rt->right, chave_insert, valor_insert);
        else
            rt->value = valor_insert; //valores repetidos sobrescrevem o valor

        rt->height = 1 + max(h(rt->left), h(rt->right));
        int balance = getBalance(rt);

            if(balance < -1 and chave_insert > rt->right->key) //inserido à direita do elemento da direita, L rotation.
                return leftRotate(rt);
            if(balance > 1 and chave_insert < rt->left->key) //inserido à esquerda do elemento da esquerda, R rotation.
                return rightRotate(rt);
            if(balance > 1 and chave_insert > rt->right->key){
                rt->left = leftRotate(rt->left);
                return rightRotate(rt);
            }
            if(balance < -1 and chave_insert < rt->right->key){
                rt->right = rightRotate(rt->right);
                return leftRotate(rt);
            }

        return rt; //está balanceada
    }
    /* AVL_Node *removehelp(AVL_Node *rt, int chave_remove)
    {
        if(rt == NULL) return NULL;
        if(rt->key > chave_remove) rt->left = removehelp(rt->left, chave_remove);
        else if(rt->key < chave_remove) rt->right = removehelp(rt->right, chave_remove);
        else
        {
            if(rt->left == NULL){
                AVL_Node *tmp = rt->right;
                //cout<<rt->key<<" "<<rt->value<<ln<<ln;
                delete rt;
                return tmp;
            }
            else if(rt->right == NULL){
                AVL_Node *tmp = rt->left;
                //cout<<rt->key<<" "<<rt->value<<ln<<ln;
                delete rt;
                return tmp; 
            } 
            else
            {
                //o elemento a ser deletado possui filhos na direita e esquerda, nesse caso
                //pegamos o menor elemento maior que ele, o menor à direita e colocamos no lugar do elemento
                //a ser removido, este procedimento nao altera as propriedades da AVL.
                //no final o elemento copiado deve ser eliminado, para evitar sua repeticao.
                AVL_Node *tmp = getmin(rt->right);
                rt->key = tmp->key;
                rt->value = tmp->value;
                rt->right = deletemin(rt->right);
                //cout<<tmp->key<<" "<<tmp->value<<ln<<ln;
                delete tmp;
            }
        }
        return rt;
    } */
    void destructor(AVL_Node *rt)
    {
        if(rt != NULL)
        {
            destructor(rt->left);
            destructor(rt->right);
            delete rt;
        }
    }
    void inorder_print_help(AVL_Node *rt)
    {
        if(rt != NULL)
        {
            inorder_print_help(rt->left);
            cout<<rt->key<<" "<<rt->value<<'\n';
            inorder_print_help(rt->right);
        }
    }
public:
    AVL()
    {
        root = NULL;
        node_count = 0;
    }
    ~AVL()
    {
        destructor(root);
    }
    int find(int chave)
    {
        return findhelp(root, chave);
    }
    void insert(int chave, int valor)
    {
        root = inserthelp(root, chave, valor);
    }
    /* int remove(int chave)
    {
        int tmp = findhelp(root, chave);
        if(tmp == NULL) return tmp; //sai logo se for NULL
        
        root = removehelp(root, chave);
        node_count--;
        return tmp;
    } */
    AVL_Node *getmin(AVL_Node *rt) //procura o ultimo node mais à esquerda que nao tenha nada ligado na sua esquerda
    {
        if(rt->left == NULL) 
            return rt;
        else 
            return getmin(rt->left);
    }
    AVL_Node *deletemin(AVL_Node *rt) //retira o node menor da direita e devolve o que estiver na direta dele.
    {
        if(rt->left == NULL)
            return rt->right;

        rt->left = deletemin(rt->left);
        return rt;
    }
    void inorder_print()
    {
        if(root != NULL)
        {
            inorder_print_help(root->left);
            cout<<root->key<<" "<<root->value<<'\n';
            inorder_print_help(root->right);
        }
    }
};