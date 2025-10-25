#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//THREADS ENCADEADAS

//THREAD 1
void* t1(void* arg) {
    
    sleep(1);
    
    printf("\nthread1 iniciada!\n");
    
    sleep(1);
    
    printf("\nthread1 finalizada!\n");
    
    pthread_exit(NULL);
}

//THREAD 2
void* t2(void* arg) {
    
    sleep(1);
    
    printf("\nthread2 iniciada!\n");
    printf("aguardando thread1...\n");
    
    pthread_t thread1;
    
    int res1 = pthread_create(&thread1, NULL, t1, NULL);

    if (res1 != 0) {
        perror("Erro ao criar a thread");
        exit(1);
    }
    
    sleep(1);

    pthread_join(thread1, NULL);
    
    sleep(1);
    
    printf("\nthread2 finalizada!\n");
    
    pthread_exit(NULL);
}

//THREAD 3
void* t3(void* arg) {
    
    sleep(1);
    
    printf("\nthread3 iniciada!\n");
    printf("aguardando thread2...\n");
    
    pthread_t thread2;
    
    int res2 = pthread_create(&thread2, NULL, t2, NULL);

    if (res2 != 0) {
        perror("Erro ao criar a thread");
        exit(1);
    }

    pthread_join(thread2, NULL);
    
    sleep(1);
    
    printf("\nthread3 finalizada!\n");
    
    pthread_exit(NULL);
}

//THREAD 4
void* t4(void* arg) {
    
    sleep(1);
    
    printf("\nthread4 iniciada!\n");
    printf("aguardando thread3...\n");
    
    pthread_t thread3;

     int res3 = pthread_create(&thread3, NULL, t3, NULL);
    
    if (res3 != 0) {
        perror("Erro ao criar a thread");
        exit(1);
    }

    pthread_join(thread3, NULL);
    
    sleep(1);
    
    printf("\nthread4 finalizada!\n");
    
    pthread_exit(NULL);
}

//THREAD 5
void* t5(void* arg) {
    
    sleep(1);
    
    printf("\nthread5 iniciada!\n");
    printf("aguardando thread4...\n");
    
    pthread_t thread4;
    
    int res4 = pthread_create(&thread4, NULL, t4, NULL);

    if (res4 != 0) {
        perror("Erro ao criar a thread");
        exit(1);
    }

    pthread_join(thread4, NULL);
    
    sleep(1);
    
    printf("\nthread5 finalizada!\n");
    
    pthread_exit(NULL);
}

//MAIN
int main() {
    
    printf("processo iniciado aguardando o fim das threads!\n");
    
    pthread_t thread5;
    
    int res5 = pthread_create(&thread5, NULL, t5, NULL);

    if (res5 != 0) {
        perror("Erro ao criar a thread");
        return 1;
    }

    pthread_join(thread5, NULL);
    
    sleep(1);

    printf("\ntodas as threads foram finalizadas!");
    return 0;
}
/* EXPLICAÇÃO DO CODIGO
este codigo cria 5 threads de forma encadeada fazendo com que cada uma crie e execute a outra
começando da thread5 ate a thread1. Apos a thread ser criada e dar inicio a outra ela aguarda 
todo o procedimento de execução para so entao finalizar sua execução*/
