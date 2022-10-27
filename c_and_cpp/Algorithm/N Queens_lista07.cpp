/* #include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define lt '\t'
#define es " "
#define ll long long
#define ull unsigned long long
#define intmx INT_MAX
#define f(x, y) for(int x=0; x<y; x++)
#define vec(a) vector<a>
#define pair(a, b) pair<a, b>
#define unmap(a, b) unordered_map<a, b>
#define unset(a, b) unordered_set<a, b>
#define all(x) x.begin(), x.end()
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln

int cont=0;
vec(bool) c, dd, de;
bool valid(vec(vec(char)) &mat, int h, int g)
{
    int sub = (h-g)+(mat.size()-1), soma = h+g;
    if(!c[g] and !de[soma] and !dd[sub])
    {
        c[g] = 1; de[soma] = 1; dd[sub] = 1;
        return true;
    }
    return false;
}
bool backtr(vec(vec(vec(char))) &mat, int h)
{
    if(h == mat[0].size())
    {
    
    cont++;
    return false;         
    }
    else{
        for(int g=0; g<mat[0].size(); g++)
        {
            if(valid(mat[cont], h, g))
            {
                mat[cont][h][g] = 'Q';
                if(backtr(mat, h+1))
                    return true;
                else
                {
                    mat[cont][h][g] = '-';
                    int sub = (h-g)+(mat[0].size()-1), soma = h+g;
                    c[g] = 0; de[soma] = 0; dd[sub] = 0;
                }
            }
        }
        return false;
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    string t;
    vec(vec(vec(char))) mat4, mat5, mat6, mat7, mat8;
    while(cin>>t)
    {
        cout<<t[0]<<"."<<ln;
        cin>>n;
        if(n == 1) cout<<"Q"<<ln<<ln;
        else if(n == 2 or n == 3) cout<<"Not Possible\n\n";
        else if(n==4)
        {
            if(mat4.empty())
            {
                
            }
            else
            {
                for(int x=0; x<mat4.size(); x++)
                {
                    for(int y=0; y<mat4[x].size(); y++)
                    {
                        for(int z=0; z<mat4[x][y].size(); z++)
                            cout<<mat4[x][y][z]<<lt;
                        cout<<ln;
                    }
                cout<<ln;
                }    
            }
        }
        else if(n==5)
        {

        }
        else if(n==6)
        {

        }
        else if(n==7)
        {

        }
        else if(n==8)
        {

        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define lt '\t'
#define es " "
#define ll long long
#define ull unsigned long long
#define intmx INT_MAX
#define f(x, y) for(int x=0; x<y; x++)
#define vec(a) vector<a>
#define pair(a, b) pair<a, b>
#define unmap(a, b) unordered_map<a, b>
#define unset(a, b) unordered_set<a, b>
#define all(x) x.begin(), x.end()
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln

int cont=0;
vec(bool) c, dd, de;
bool valid(vec(vec(char)) &mat, int h, int g)
{
    int sub = (h-g)+(mat.size()-1), soma = h+g;
    if(!c[g] and !de[soma] and !dd[sub])
    {
        c[g] = 1; de[soma] = 1; dd[sub] = 1;
        return true;
    }
    return false;
}
bool backtr(vec(vec(vec(char))) &mat, int h)
{
    if(h == mat[0].size())
    {
    
    cont++;
    return false;         
    }
    else{
        for(int g=0; g<mat[0].size(); g++)
        {
            if(valid(mat[cont], h, g))
            {
                mat[cont][h][g] = 'Q';
                if(backtr(mat, h+1))
                    return true;
                else
                {
                    mat[cont][h][g] = '-';
                    int sub = (h-g)+(mat[0].size()-1), soma = h+g;
                    c[g] = 0; de[soma] = 0; dd[sub] = 0;
                }
            }
        }
        return false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    string t;
    vec(vec(vec(char))) mat4, mat5, mat6, mat7, mat8;
    while(cin>>t)
    {
        cout<<t[0]<<"."<<ln;
        cin>>n;
        if(n==1) {cout}

    }
    return 0;
} */

#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define lt '\t'
#define es " "
#define ll long long
#define ull unsigned long long
#define intmx INT_MAX
#define f(x, y) for(int x=0; x<y; x++)
#define vec(a) vector<a>
#define pair(a, b) pair<a, b>
#define unmap(a, b) unordered_map<a, b>
#define unset(a, b) unordered_set<a, b>
#define all(x) x.begin(), x.end()
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln

int n, cont;
bool valid(char mat[10][10], int h, int g, bool c[], bool dd[], bool de[])
{
    int sub = (h-g)+(n-1), soma = h+g;
    if(!c[g] and !de[soma] and !dd[sub])
    {
        c[g] = 1; de[soma] = 1; dd[sub] = 1;
        return true;
    }
    return false;
}
bool backtr(char mat[10][10], int h, bool c[], bool dd[], bool de[])
{
    if(h == n)
    {
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%c ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
    cont++;
    if(n == 5 or n == 7 or n == 8)
    {
        if(n == 5 and cont == 10) return true;
        else if(n == 7 and cont == 40) return true;
        else if(n == 8 and cont == 92) return true; 
    }
    return false;         
    }
    else{
        for(int g=0; g<n; g++)
        {
            if(valid(mat, h, g, c, dd, de))
            {
                mat[h][g] = 'Q';
                if(backtr(mat, h+1, c, dd, de))
                    return true;
                else
                {
                    mat[h][g] = '-';
                    int sub = (h-g)+(n-1), soma = h+g;
                    c[g] = 0; de[soma] = 0; dd[sub] = 0;
                }
            }
        }
        return false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(cin>>n)
    {
        if(n==2 or n==3) printf("Not Possible\n\n");
        char mat[10][10];
        f(i, n)
            f(j, n) 
                mat[i][j] = '-';
        bool c[n] = {}, dd[(2*n)-1] = {}, de[(2*n)-1] = {};
        cont = 0;
        backtr(mat, 0, c, dd, de);
        //printf("%d", cont);
    }

    return 0;
}

/* #include <stdio.h>
#include <stdlib.h>

int cnt=0;
int queens(int l, char matrix[100][100], int n);
int valid(char matrix[100][100], int l, int i, int n);

int main() {
    char m[100][100];
    int n;
   
    scanf("%d", &n);
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m[i][j] = '-';
        }
    }
        
        if (!queens(0, m, n)) printf("Not Possible");
    
    return 0;
}

int valid(char matrix[100][100], int l, int i, int n){
    int coluna = i;
    int linha = l;
    int l_aux = l;
    while(l > 0){
        if(matrix[l - 1][coluna] == 'Q') return 0;
        
        l--;
    }

    while(linha > 0 && coluna > 0){
        if(matrix[linha - 1][coluna - 1] == 'Q') return 0;
        
        linha--;
        coluna--;
    }
    while(l_aux > 0 && i < n){
        if(matrix[l_aux - 1][i + 1] == 'Q') return 0;
        
        i++;
        l_aux--;
    }

    return 1; 
}

int queens(int l, char matrix[100][100], int n){
    if(l == n){ 
      cnt++;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%c ", matrix[i][j]);
                //if(j < n - 1) printf(" ");
            }  
            
            printf("\n");
        } 
        
        printf("\n");
        
        return 1;
    }else{
        int controle = 0;
        for(int i = 0; i < n; i++){
            if(valid(matrix, l, i, n)){
                matrix[l][i] = 'Q';

                if(queens(l + 1, matrix, n)){
                    controle = 1;
                }
                matrix[l][i] = '-';
            }
        }
        return controle;  
    }
} */