#include <pthread.h>
#include <stdio.h>

long a = 0;

void* func(void* args){
    
    int i;
    long tmp;

    for(i = 0; i < 1000000; i++){
        tmp = a;
        tmp++;
        a = tmp;
    }
    
    return NULL;
}

int main(void)
{
    int index[5];
    int i;
    int index1;
    int *s;
    pthread_t thread[5];

    for(i = 1; i <= 5; i++){
        index[i-1] = i;
        pthread_create(&thread[i - 1], NULL, func, &index[i-1]);
    }

    for(index1 = 0; index1 < 5; index1++){
        pthread_join(thread[index1], (void**) &s);
    }

    printf("a = %ld", a);
    return 0;

}