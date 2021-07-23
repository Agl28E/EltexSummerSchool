#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define a 10 

void* func(void* args)
{
    int *ptr;
    ptr = (int*)args;
    printf("%d\n", *ptr);
    pthread_exit(NULL);
}

int main()
{
    
    int arr[a];
    int* p;
    pthread_t tid;
    p = arr;

    for(int i = 1; i < a; i++, p++){

        *p = i;
        pthread_create(&tid, NULL, func, p);

    }

    sleep(2);
    return 0;
}
