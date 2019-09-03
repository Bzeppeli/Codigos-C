#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define CADEIRAS 5
#define N 61

int a, b, int_rand, esperando;
float float_rand;

sem_t mutex;
sem_t customers;
sem_t barbers;



//acao do barbeiro

void *barber(void *arg){
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
void *customer(void *b){
   int a= *(int*) b;
   sem_wait(&mutex);
    if(esperando < CADEIRAS){
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

void cut_hair(){
   printf("Barbeiro preguiçoso corta cabelo de um cliente!\n");
   float_rand=0.000001;
   int_rand=float_rand;
   usleep(int_rand);
}

void get_cuthair(int a){
    printf("Cliente %d tem o cabelo cortado pelo barbeiro sonhador!\n",a);
}

void main(){

   esperando=0;

    int res;

    pthread_t thread[N];

    void *thread_result;

    res = sem_init(&mutex,0,1);
    if(res!=0){
       perror("Erro na inicialização do semaforo!");
       exit(EXIT_FAILURE);
    }

    res = sem_init(&customers,0,0);
    if(res!=0){
       perror("Erro na inicialização do semaforo!");
       exit(EXIT_FAILURE);
    }

    res = sem_init(&barbers,0,0);
    if(res!=0){
       perror("Erro na inicialização do semaforo!");
       exit(EXIT_FAILURE);
    }

    res = pthread_create(&thread[0],NULL,barber,NULL);
    if(res!=0){
       perror("Erro na inicialização da thread!");
           exit(EXIT_FAILURE);
    }

    for(a=1; a<N; a++){
       res = pthread_create(&thread[a],NULL,customer,&a);
       if(res!=0){
          perror("Erro na inicialização da thread!");
          exit(EXIT_FAILURE);
       }
    }

        for(a=0; a<N; a++){
       res = pthread_join(thread[a],&thread_result);
       if(res!=0){
          perror("Erro ao fazer join nas threads!");
          exit(EXIT_FAILURE);
       }
    }
}

