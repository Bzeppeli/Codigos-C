#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "pthread.h"
#include "semaphore.h"

#define N           5           /* n�mero de fil�sofos*/
#define ESQUERDA        (i+N-1)%N   /* n�mero do vizinho � esquerda de i*/
#define DIREITA       (i+1)%N     /* n�mero do vizinho � direito de i*/
#define PENSANDO    0           /* o fil�sofo est� pensando*/
#define FAMINTO      1           /* o fil�sofo est� tentando pegar garfos*/
#define COMENDO      2           /* o fil�sofo est� comendo*/
#define TRUE        1
//#define sleep(x) Sleep(5000 * x)

int state[N];                   /* arranjo para controlar o estado de cada um*/
sem_t mutex;                    /* exclus�o m�tua para as regi�es cr�ticas*/
sem_t s[N];                     /* um sem�foro por fil�sofo*/

/* prot�tipos */
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

   /* criando os 5 fil�sofo - 1 thread para cada*/
   for(i = 0; i < N; i++) {
     pthread_create(&tphil[i], NULL, (void *) filosofo, (void *) &i);
 }

 for(i = 0; i < N; i++) {
     pthread_join(tphil[i], NULL);
 }

 return 0;
}

void* filosofo(void * arg) { /*i: o n�mero do fil�sofo, de 0 a N-1*/
 int i = *((int *) arg);

 while(TRUE) {               /* repete para sempre*/
     pensar(i);               /* o fil�sofo est� pensando*/
     pegar_hashi(i);          /* pega dois garfos ou bloqueia*/
     comer(i);                 /* o fil�sofo est� comendo*/
     soltar_hashi(i);           /* devolve os dois garfos � mesa*/
 }

 pthread_exit(NULL);
}

void pegar_hashi(int i) {        /*i: o n�mero do fil�sofo, de 0 a N-1*/
 sem_wait(&mutex);           /* entra na regi�o cr�tica*/
 state[i] = FAMINTO;          /* registra que o fil�sofo est� faminto*/
 test(i);                    /* tenta pegar dois garfos*/
 sem_post(&mutex);           /* sai da regi�o cr�tica*/
 sem_wait(&s[i]);            /* bloqueia se os garfos n�o foram pegos*/
}

void soltar_hashi(int i) {         /*i: o n�mero do fil�sofo, de 0 a N-1*/
 sem_wait(&mutex);           /* entra na regi�o cr�tica*/
 state[i] = PENSANDO;        /* o fil�sofo acabou de comer*/
 test(ESQUERDA);                 /* v� se o vizinho da esquerda pode comer agora*/
 test(DIREITA);                /* v� se o vizinho da direito pode comer agora*/
 sem_post(&mutex);           /* sai da regi�o cr�tica*/
}

void test(int i) {
 if (state[i] == FAMINTO && state[ESQUERDA] != COMENDO && state[DIREITA] != COMENDO) {
     state[i] = COMENDO;
     sem_post(&s[i]);
 }
}

void comer(int i) {               /*i: o n�mero do fil�sofo, de 0 a N-1*/
 printf("Filosofo %d esta comendo!\n", i);
Sleep( rand()%5 );
}

void pensar(int i) {             /*i: o n�mero do fil�sofo, de 0 a N-1*/
 printf("Filosofo %d esta pensando!\n", i);
Sleep( rand()%10 );
}
