#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int variavel1 = 1;
int variavel2 = 0;
pthread_mutex_t mutex;

void* dobro(void* arg) {
    for (long i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        variavel1 = variavel1 * 2;
        printf("Valor dobrado: %d\n", variavel1);
        printf("Novo valor atual: %d\n", variavel1);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

void* anterior(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        variavel2 = variavel1;
        printf("\nValor atual: %d\n", variavel2);
        pthread_mutex_unlock(&mutex);
        sleep(1.5);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t2, NULL, anterior, NULL);
    pthread_create(&t1, NULL, dobro, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
