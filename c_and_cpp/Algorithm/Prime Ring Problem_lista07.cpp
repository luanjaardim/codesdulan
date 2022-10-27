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

int ale=0;
int n, cnt = 1;
int primos[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
bool solution(vec(int) &r, vec(bool) &used)
{
    if(r.size() == n and r[n-1] + 1 == *(lower_bound(primos, primos + n, r[n-1] + 1)))
    {
        for(int i = 0; i < n; i++)
            printf(i == n - 1? "%d" : "%d ", r[i]);
        printf("\n");
        //printf("%d\n", ++ale);
        return false;
    }
    else
    {
        for(int i=2; i<n+1; i++)
        {
            if(used[i] == 0 and r[r.size()-1] + i == *(lower_bound(primos, primos + n, r[r.size()-1] + i)))
            {
                used[i] = 1;
                r.push_back(i);

                if(solution(r, used))
                    return true;

                used[i] = 0;
                r.pop_back();
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
        vec(bool) usados (20, 0); usados[1] = 1;
        vec(int) resposta; resposta.push_back(1);
        if(cnt > 1) printf("\n");
        printf("Case %d:\n", cnt);
        solution(resposta, usados);
        cnt++;
    }

    return 0;
}