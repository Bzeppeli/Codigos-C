#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define CADEIRAS 5
#define N 60

int a, b, int_rand, esperando;
float float_rand;

//semaforos usados

sem_t mutex;  //semaforo de exclus�o mutua
sem_t customers; // semaforo chamado customers que � usado na fun��o do mesmo para organizar o fluxo de clientes
sem_t barbers; //semaforo para o barbeiro



//acao do barbeiro

void *barber(void *arg){ // essa fun��o basicamente faz com que o semaforo funcionando como um fifo, conrtrolando o barbbeiro, para que toda vez que um cliente cortar o cabelo, ele libere uma cadeira.
   while(1){
    sem_wait(&customers);
    sem_wait(&mutex);
    esperando=esperando-1;
    sem_post(&barbers);
    sem_post(&mutex);
    cut_hair();
   }

}

//acao do cliente
void *customer(void *b){  //essa � a fun��o para os clientes, ela usa o semaforo criado anteriormente, com o mutex, que faz exclus�o mutua de threads, para que regi�es crticas do codigi sejam executadas simultaneamente.
   int a= *(int*) b;
   sem_wait(&mutex);
    if(esperando < CADEIRAS){ //if para incrementar o numero de pessoas esperando, se for maior do que o numero de cadeiras restantes, o cliente vai embora.
    printf("o cliente %d chegou na barbearia!\n",a);
    esperando=esperando+1;
    sem_post(&customers);
    sem_post(&mutex);
    sem_wait(&barbers);
    get_cuthair(a);
   }else{
        sem_post(&mutex);
    printf("o cliente %d foi embora por que cansou de esperar\n",a);
   }

}

void cut_hair(){ // fun��o para o barbeiro cortar o cabelo.
   printf("Barbeiro pregui�oso corta cabelo de um cliente!\n");
   float_rand=0.000001;
   int_rand=float_rand;
   usleep(int_rand);
}

void get_cuthair(int a){ //fun��o para o barbeiro depoois de cortar o cabelo.
    printf("Cliente %d tem o cabelo cortado pelo barbeiro sonhador!\n",a);
}

void main(){

   esperando=0;

    int res;

    pthread_t thread[N]; //threads criadas, de acordo com o numero de cadeiras

    void *thread_result;

    res = sem_init(&mutex,0,1); //inicializa��o do semaforo
    if(res!=0){ // verifica��o dos semaforos para que se for diferente de 0, ent�o n�o inicie.
       perror("Erro na inicializa��o do semaforo!");
       exit(EXIT_FAILURE);
    }

    res = sem_init(&customers,0,0);
    if(res!=0){
       perror("Erro na inicializa��o do semaforo!");
       exit(EXIT_FAILURE);
    }

    res = sem_init(&barbers,0,0);
    if(res!=0){
       perror("Erro na inicializa��o do semaforo!");
       exit(EXIT_FAILURE);
    }

    res = pthread_create(&thread[0],NULL,barber,NULL);
    if(res!=0){ // verifica��o do funcionamento da thread, se retornar um valor diferente de zero, ent�o da erro.
       perror("Erro na inicializa��o da thread!");
           exit(EXIT_FAILURE);
    }

    for(a=1; a<N; a++){
       res = pthread_create(&thread[a],NULL,customer,&a);
       if(res!=0){ // a mesma verfica��o anterior, por�m � para todas as threads criadas
          perror("Erro na inicializa��o da thread!");
          exit(EXIT_FAILURE);
       }
    }

        for(a=0; a<N; a++){
       res = pthread_join(thread[a],&thread_result);
       if(res!=0){ //verifica��o para o valor retornado da thread.
          perror("Erro ao fazer join nas threads!");
          exit(EXIT_FAILURE);
       }
    }
}

