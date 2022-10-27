#include <bits/stdc++.h>
using namespace std;
//Binary Search Tree as Dictionary

class BST_Node
{
public:
    int key, value;
    BST_Node *left, *right;

    BST_Node(int chave, int valor)
    {
        key=chave; value=valor;
        left = NULL; right = NULL;
    }
    BST_Node()
    {
        key = 0; value = 0;
        left = NULL; right = NULL;
    }
};

class BST
{
private:
    BST_Node *root;
    int node_count;
    int findhelp(BST_Node *rt, int chave_buscada)
    {
        if(rt == NULL) return NULL;
        if(rt->key == chave_buscada) return rt->value;
        else if(rt->key > chave_buscada) return findhelp(rt->left, chave_buscada);
        else return findhelp(rt->right, chave_buscada);
    }
    BST_Node *inserthelp(BST_Node *rt, int chave_insert, int valor_insert)
    {
        if(rt == NULL)
        { 
            node_count++;
            BST_Node *tmp = new BST_Node(chave_insert, valor_insert);
            return tmp;
        }
        if(rt->key > chave_insert)
            rt->left = inserthelp(rt->left, chave_insert, valor_insert);
        else if(rt->key < chave_insert)
            rt->right = inserthelp(rt->right, chave_insert, valor_insert);
        else{
            rt->value = valor_insert; //valores repetidos sobrescrevem o valor
            return rt;
        }
    }
    BST_Node *removehelp(BST_Node *rt, int chave_remove)
    {
        if(rt == NULL) return NULL;
        if(rt->key > chave_remove) rt->left = removehelp(rt->left, chave_remove);
        else if(rt->key < chave_remove) rt->right = removehelp(rt->right, chave_remove);
        else
        {
            if(rt->left == NULL){
                BST_Node *tmp = rt->right;
                //cout<<rt->key<<" "<<rt->value<<ln<<ln;
                delete rt;
                return tmp;
            }
            else if(rt->right == NULL){
                BST_Node *tmp = rt->left;
                //cout<<rt->key<<" "<<rt->value<<ln<<ln;
                delete rt;
                return tmp; 
            } 
            else
            {
                //o elemento a ser deletado possui filhos na direita e esquerda, nesse caso
                //pegamos o menor elemento maior que ele, o menor à direita e colocamos no lugar do elemento
                //a ser removido, este procedimento nao altera as propriedades da BST.
                //no final o elemento copiado deve ser eliminado, para evitar sua repeticao.
                BST_Node *tmp = getmin(rt->right);
                rt->key = tmp->key;
                rt->value = tmp->value;
                rt->right = deletemin(rt->right);
                //cout<<tmp->key<<" "<<tmp->value<<ln<<ln;
                delete tmp;
            }
        }
        return rt;
    }
    void destructor(BST_Node *rt)
    {
        if(rt != NULL)
        {
            destructor(rt->left);
            destructor(rt->right);
            //cout<<rt->key<<" "<<rt->value<<ln;
            delete rt;
        }
    }
    void inorder_print_help(BST_Node *rt)
    {
        if(rt != NULL)
        {
            inorder_print_help(rt->left);
            cout<<rt->key<<" "<<rt->value<<'\n';
            inorder_print_help(rt->right);
        }
    }
public:
    BST()
    {
        root = NULL;
        node_count = 0;
    }
    ~BST()
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
    int remove(int chave)
    {
        int tmp = findhelp(root, chave);
        if(tmp == NULL) return tmp; //sai logo se for NULL
        
        root = removehelp(root, chave);
        node_count--;
        return tmp;
    }
    BST_Node *getmin(BST_Node *rt) //procura o ultimo node mais à esquerda que nao tenha nada ligado na sua esquerda
    {
        if(rt->left == NULL) 
            return rt;
        else 
            return getmin(rt->left);
    }
    BST_Node *deletemin(BST_Node *rt) //retira o node menor da direita e devolve o que estiver na direta dele.
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