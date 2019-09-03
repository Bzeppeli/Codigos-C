#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

#include <semaphore.h>


#define N 5 //quantidade de filososfos
#define ESQUERDA i+N-1%N //calculo do vizinho a esquerda
#define DIREITA i+N%N //calculo do vizinho a direita
#define PENSANDO 0  //filosofo pensando
#define FAMINTO 1  //filosofo tentando pegar os hashi
#define COMENDO 2   // filosofo comendo
#define TRUE 1

sem_t s[N]; //um semaforo por filosofo
sem_t mutex;    //exclusão mutua para regioes crticas


int state[N]; //vetor parar controlar os filofos

pthread_t thread1, thread2,thread3, thread4, thread5;
    //uma thread por filosofo

    //prototipos

void pegar_hashi(int i);
void soltar_hashi(int i);

void teste(int i);
void pensar(int i);

void comer(int i);

//numero de filosofos de 0 a n-1

void filosofo (int i){

    while(1){//repete infinitamente
        pensar(i); // o filosofo esta pensando

        pegar_hashi(i); //o filosofo pega os hashi ou bloqueia
        comer(i); //come o arroz
        soltar_hashi(i); //solta os hashi na mesa

    }

}

void pegar_hashi(int i){

    sem_wait(&mutex); //down(&mutex); // entra na regiao critica;
        state[i]= FAMINTO; //registra que o filosofo i esta com fome
        printf("filosofo %d esta FAMINTO \n", i);
        teste(i); //tenta pegar os dois hashi

    sem_post(&mutex); //up(&mutex); /sai da região critica
        sem_wait(&s[i]); //bloqueia os garfos que não foram pegos

}

void soltar_hashi(int i){

    sem_wait(&mutex);//down(&mutex); // entra na região critica;

        state[i] = PENSANDO; //o filosofo acabou de comer;
        printf("filosofo %d pensando\n ", i);

        teste(ESQUERDA()); //verifica se o vizinho da esqueda pode comer agora
        teste(DIREITA());   //verifica se o vizinho da direita pode comer aogra
        sem_post(&mutex);//up(&mutex); /sai da região critica


}

void teste(i){ //testa se os filosofos vizinhos podem comer

    if(state[i] == FAMINTO && state[ESQUERDA()]!= COMENDO && state[DIREITA()]!= COMENDO){

        state[i] = COMENDO;
        printf("filosofo %d está comendo", i);
        sem_post(&s[i]); //up(&s[i]);


    }

}


void pensar(int i){ //filosofo está pensando
    sleep(1);

    return;
}

void comer(int i){//filosofo esta comendo
    sleep(1);

    return;
}


////////função principal//////////

main(){

    int iret1,iret2,iret3,iret4,iret5;

    int i;
    int p[N];
    //incialização dos semaforos
    //int sem_init(sem_t *sem, int pshared, usigned int value);

    for(i=0;i<N;i++){
        sem_init(&s[i],0,1);
        p[i] = i;

    }

    sem_init(&mutex, 0,1);

  //criação de threads independentes que executam a função;

  iret1 = pthread_create(&thread1, NULL,(void *)filosofo, (int *) p[1]);
  iret2 = pthread_create(&thread2,NULL,(void *)filosofo,(int *) p[2]);
  iret3 = pthread_creat(&thread3,NULL,(void *)filosofo, (int *) p[3]);
  iret4 = pthread_creat(&thread4, NULL,(void *)filosofo, (int *) p[4]);
  iret5 = pthread_creat(&thread5,NULL,(void *)filosofo, (int *) p[0]);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  pthread_join(thread4,NULL);
  pthread_join(thread5, NULL);

  exit(0);
}
