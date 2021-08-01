#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUMBER_OF_STORES 5
#define NUMBER_OF_BUYERS 5
#define STORE_SIZE 1000
#define STORE_DEVIATION 100
#define BUYER_NEED 10000
#define BUYER_DEVIATION 300
#define LOADER_ADD 200

int buyer[NUMBER_OF_BUYERS];
int store[NUMBER_OF_STORES];
int done = 0;

pthread_mutex_t mutex;

void *buy(void *arg) {
    int current_buyer = *(int*)arg;
    while (buyer[current_buyer] > 0) {
        pthread_mutex_lock(&mutex);
        int choise_store = rand() % NUMBER_OF_STORES;
        buyer[current_buyer] -= store[choise_store]; 
        printf("Buyer number %d, buy %d, need %d\n", current_buyer, store[choise_store], buyer[current_buyer]);
        store[choise_store] = 0;
        pthread_mutex_unlock(&mutex);
        sleep(3);
        
    }
    done++;
}

void *load(void *arg) {
    while (done < NUMBER_OF_BUYERS) {
        int choise_store = rand() % NUMBER_OF_STORES;
        store[choise_store] += LOADER_ADD;
        sleep(1);
        printf("Загрузчик добавил %d\n", LOADER_ADD);
    }
}


int main(void) {
    
    int i;
    
    for (i = 0; i < NUMBER_OF_STORES; i++) {
        store[i] = STORE_SIZE - STORE_DEVIATION + rand() % (2 * STORE_DEVIATION);
        printf("Магазин %d пополнен на %d\n", i, store[i]);
    }
    
    for (i = 0; i < NUMBER_OF_BUYERS; i++) {
        buyer[i] = BUYER_NEED - BUYER_DEVIATION + rand() % (2 * STORE_DEVIATION);
        printf("Покупателю %d необходимо %d\n", i, buyer[i]);
    }
    
    pthread_t th_l;
    pthread_t th_b[NUMBER_OF_BUYERS];
    pthread_mutex_init(&mutex, NULL);  

    for (i = 0; i < NUMBER_OF_BUYERS; i++) {
        if (pthread_create(&th_b[i], NULL, &buy, &i) != 0) {
            perror("Failed to create thread bayer");
        }
    }

    if (pthread_create(&th_l, NULL, &load, NULL) != 0) {
        perror("Failed to create thread loader");    
    }

    for (i = 0; i < NUMBER_OF_BUYERS; i++) {
        if (pthread_join(th_b[i], NULL) != 0) {
            perror("Failed to join thread of bayer");
        }
    }

    if (pthread_join(th_l, NULL) != 0) {
        perror("Failed to join thread of loader");
    }
    pthread_mutex_destroy(&mutex);

    return 0;
}
