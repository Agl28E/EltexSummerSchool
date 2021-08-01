#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 1000

long a = 0;

pthread_t thread[N];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int counter;

void* func(void* args){
    
    pthread_mutex_lock(&lock);

    int i;
    long tmp;

    for(i = 0; i < 1000; i++){
        tmp = a;
        tmp++;
        a = tmp;
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void)
{
    int index[N];
    int i;
    int index1;
    int *s;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("error init");
        return 1;
    }


    for(i = 1; i <= N; i++){
        index[i-1] = i;
        pthread_create(&thread[i - 1], NULL, func, &index[i-1]);
        //printf("%d\n", i);
    }

    for(index1 = 0; index1 < N; index1++){
        pthread_join(thread[index1], (void**) &s);
    }

    pthread_mutex_destroy(&lock);
    printf("a = %ld", a);
    return 0;

}
