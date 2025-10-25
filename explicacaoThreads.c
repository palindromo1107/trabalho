#include <stdio.h> //adicional para função printf
#include <pthread.h> //biblioteca necessaria para as THREADS
#include <unistd.h> //adicional para função sleep

//estrutura da thread
void* thread(void* arg) {
    
    sleep(1);
    
    printf("thread iniciada!\n");

    sleep(2);
    
    printf("thread finalizada!\n");

    pthread_exit(NULL);
    
    // O tipo de retorno é void* (como exigido pela pthread).

    // O argumento é void* arg (para permitir passar qualquer tipo de dado, se necessário).
    
    // A função faz pausas (sleep) e imprime mensagens.
    
    // Termina com pthread_exit(NULL);, que encerra a thread de forma limpa.
    
}

//MAIN
int main() {
    
    //cria um endereço para a thread
    // pthread_t é o tipo que representa uma thread.
    pthread_t thread1;
    
    //cria a thread e armazena em uma variavel RES
    int res = pthread_create(&thread1, NULL, thread, NULL);

    /* pthread_create() cria uma nova thread e ela recebe:
    1- Endereço da variável thread1;
    2- Atributos da thread (NULL = padrão);
    3- A função a ser executada (thread);
    4- Argumentos da função (NULL neste caso). */

    //verifica se a thread foi criada
    if (res != 0) {
        perror("Erro ao criar a thread");
        return 1;
    }

    //acessa a thread e aguarda ela encerrar sua execução
    pthread_join(thread1, NULL);
    
    //tudo que esta abaixo so é executado quando a thread acaba
    
    sleep(1);

    printf("\ntodas as threads foram finalizadas!");
    return 0;
}

/*as threads podem ser executadas simultaneamente com o codigo principal
Threads permitem executar várias tarefas em paralelo (ou quase, dependendo do processador e do sistema operacional). */
