#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "pthread.h"
#include "semaphore.h"

#define N           5           /* número de filósofos*/
#define ESQUERDA        (i+N-1)%N   /* número do vizinho à esquerda de i*/
#define DIREITA       (i+1)%N     /* número do vizinho à direito de i*/
#define PENSANDO    0           /* o filósofo está pensando*/
#define FAMINTO      1           /* o filósofo está tentando pegar garfos*/
#define COMENDO      2           /* o filósofo está comendo*/
#define TRUE        1
//#define sleep(x) Sleep(5000 * x)

int state[N];                   /* arranjo para controlar o estado de cada um*/
sem_t mutex;                    /* exclusão mútua para as regiões críticas*/
sem_t s[N];                     /* um semáforo por filósofo*/

/* protótipos */
void* filosofo(void* arg);
void pegar_hashi(int i);
void soltar_hashi(int i);
void test(int i);
void comer(int i);
void pensar(int i);

int main() {
 int i;

 sem_init(&mutex, TRUE, 1);

 for(i = 0; i < N; i++) {
     sem_init(&s[i], TRUE, 1);
 }

 pthread_t tphil[5];

   /* criando os 5 filósofo - 1 thread para cada*/
   for(i = 0; i < N; i++) {
     pthread_create(&tphil[i], NULL, (void *) filosofo, (void *) &i);
 }

 for(i = 0; i < N; i++) {
     pthread_join(tphil[i], NULL);
 }

 return 0;
}

void* filosofo(void * arg) { /*i: o número do filósofo, de 0 a N-1*/
 int i = *((int *) arg);

 while(TRUE) {               /* repete para sempre*/
     pensar(i);               /* o filósofo está pensando*/
     pegar_hashi(i);          /* pega dois garfos ou bloqueia*/
     comer(i);                 /* o filósofo está comendo*/
     soltar_hashi(i);           /* devolve os dois garfos à mesa*/
 }

 pthread_exit(NULL);
}

void pegar_hashi(int i) {        /*i: o número do filósofo, de 0 a N-1*/
 sem_wait(&mutex);           /* entra na região crítica*/
 state[i] = FAMINTO;          /* registra que o filósofo está faminto*/
 test(i);                    /* tenta pegar dois garfos*/
 sem_post(&mutex);           /* sai da região crítica*/
 sem_wait(&s[i]);            /* bloqueia se os garfos não foram pegos*/
}

void soltar_hashi(int i) {         /*i: o número do filósofo, de 0 a N-1*/
 sem_wait(&mutex);           /* entra na região crítica*/
 state[i] = PENSANDO;        /* o filósofo acabou de comer*/
 test(ESQUERDA);                 /* vê se o vizinho da esquerda pode comer agora*/
 test(DIREITA);                /* vê se o vizinho da direito pode comer agora*/
 sem_post(&mutex);           /* sai da região crítica*/
}

void test(int i) {
 if (state[i] == FAMINTO && state[ESQUERDA] != COMENDO && state[DIREITA] != COMENDO) {
     state[i] = COMENDO;
     sem_post(&s[i]);
 }
}

void comer(int i) {               /*i: o número do filósofo, de 0 a N-1*/
 printf("Filosofo %d esta comendo!\n", i);
Sleep( rand()%5 );
}

void pensar(int i) {             /*i: o número do filósofo, de 0 a N-1*/
 printf("Filosofo %d esta pensando!\n", i);
Sleep( rand()%10 );
}
