#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <climits>
#include <vector>
#define nl printf("\n")
#define pt pthread_
#define ll long long

pthread_mutex_t mut;

typedef struct elem{
    float *val;
    int *ind;
    long a, b, c;
} elem;

typedef struct tupple
{
	float a, p;
} tupple;

typedef struct teste
{
	void (* constructor)(struct teste *self, float a, float p);
	void (* printing) (struct teste *self);
	tupple tupla;
}teste;

void constructor(teste *self, float a, float p){
	self->tupla.a = a;
	self->tupla.p = p;
}
void printing(teste *self)
{
	printf("altura: %.2f, peso: %.2f\n", self->tupla.a, self->tupla.p);
}

int b_search(std::vector<int> v, int val)
{
    int first = 0, last = v.size()-1;
    while(first <= last)
    {
        int mid = (first + last)/2;

        if(v[mid] == val) return mid;
        else if(v[mid] < val) first = mid + 1;
        else last = mid - 1;
    }  
    return -1;
}

int res(int a=0, int b=0)
{
    return a + b;
}

int func(int (* new_func)(int, int), int a, int b){
    return new_func(a, b);
}

int main(int argc, char *argv[])
{
    
	teste t = {&constructor, &printing, {0.0, 0.0}};
	t.constructor(&t, 4.9, 5.8);
	t.printing(&t);
	
    int cnt = 3;
    while (cnt--)
    {
        time_t timing;
        time(&timing);
        printf("%llu\n", (unsigned long long) timing);
        sleep(2);
    }
	
    int sla;
    scanf("%d", &sla);
    std::vector<int> v = {1, 2, 3, 4, 5, 5};
    int index = b_search(v, sla);
	printf("%d\n", index);
	
    elem a;
    int b;
    a.ind = &b;
    *(a.ind) = 5;
    printf("%d", *(a.ind));
    nl;
    
    printf("%d\n", res());

    printf("%d\n", func(res, 1, 2));

	return 0;
}
