#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define pt pthread_
#define f(a, b) for(int a=0; a<b; a++)

int *ar; //global array, all threads will sort it's elements
int len = 0; //lenght of the array

typedef struct ArgPass{
    int l, r; //struct to pass arguments by pthread_create
} ArgPass;

void swap(int *arg1, int *arg2){ //swap function
    int tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

void *quicksort(void *arg){
    ArgPass *tmp_arg = (ArgPass *) arg;
    int l = tmp_arg->l, r = tmp_arg->r;
    int i = l, j = r;
    if(l < r) { //one element subarrays won't pass
        while(i < j){ //Hoare Partition algorithm begins
            while(ar[i] <= ar[l] && i < r) i++;
            while(ar[j] >= ar[l] && j > l) j--;        
            swap(&ar[i], &ar[j]);
        }
        swap(&ar[i], &ar[j]);
        swap(&ar[l], &ar[j]);
        //Hoare Partition algorithm ends
        // j will be the partition index's

        ArgPass arg1 = { l, j-1 }, arg2 = { j+1, r };
        pthread_t t1, t2;
        pthread_create(&t1, NULL, &quicksort, (void *) &arg1); //subarray at left recursion
        pthread_create(&t2, NULL, &quicksort, (void *) &arg2); //subarray at right recursion
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
    }
}

int main(int argc, char **argv){
    
    if(argc == 1) {
        printf("Insuficient arguments\n");
    }
    else{
        //storing elements in the global array
        for(int i = 1; i<argc; i++){
            ar = (int *) realloc(ar, sizeof(int) * (++len));
            if(ar == NULL) exit(1);

            ar[i-1] = atoi(argv[i]);
        }

        ArgPass arg = {0, len-1};
        pthread_t th;
        pthread_create(&th, NULL, &quicksort, (void *) &arg);
        pthread_join(th, NULL);

        f(i, len) printf("%d ", ar[i]);
        printf("\n");
    }
    return 0;
}
