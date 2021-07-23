#include <pthread.h>
#include <stdio.h>

#define N 1000

long a = 0;

void* func(void* args){
    
    int i;
    long tmp;

    for(i = 0; i < 1000; i++){
        tmp = a;
        tmp++;
        a = tmp;
    }
    
    return NULL;
}

int main(void)
{
    int index[N];
    int i;
    int index1;
    int *s;
    pthread_t thread[N];

    for(i = 1; i <= N; i++){
        index[i-1] = i;
        pthread_create(&thread[i - 1], NULL, func, &index[i-1]);
        //printf("%d\n", i);
    }

    for(index1 = 0; index1 < N; index1++){
        pthread_join(thread[index1], (void**) &s);
    }

    printf("a = %ld", a);
    return 0;

}
