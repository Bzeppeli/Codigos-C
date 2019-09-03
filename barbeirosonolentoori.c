#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define CHAIRS 5
#define N 61

int i, j, int_rand, waiting;
float float_rand;

sem_t mutex;
sem_t customers;
sem_t barbers;

//acao do barbeiro

void *barber(void *arg){
   while(1){
    sem_wait(&customers);
    sem_wait(&mutex);
    waiting=waiting-1;
    sem_post(&barbers);
    sem_post(&mutex);
    cut_hair();
   }

}

//acao do cliente
void *customer(void *j){
   int i= *(int*) j;
   sem_wait(&mutex);
   if(waiting < CHAIRS){
    printf("Cliente %d entrou na barbearia!\n",i);
    waiting=waiting+1;
    sem_post(&customers);
    sem_post(&mutex);
    sem_wait(&barbers);
    get_haircut(i);
   }else{
        sem_post(&mutex);
    printf("Cliente %d saiu da barbearia porque estava lotada!\n",i);
   }

}

void cut_hair(){
   printf("Barbeiro corta cabelo de um cliente!\n");
   float_rand=0.000001;
   int_rand=float_rand;
   usleep(int_rand);
}

void get_haircut(int i){
   printf("Cliente %d corta o cabelo!\n",i);
}

void main(){

   waiting=0;

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

    for(i=1; i<N; i++){
       res = pthread_create(&thread[i],NULL,customer,&i);
       if(res!=0){
          perror("Erro na inicialização da thread!");
          exit(EXIT_FAILURE);
       }
    }

        for(i=0; i<N; i++){
       res = pthread_join(thread[i],&thread_result);
       if(res!=0){
          perror("Erro ao fazer join nas threads!");
          exit(EXIT_FAILURE);
       }
    }
}
