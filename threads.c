#inlcude <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREAD 4

void delay(){
 int j,k,l;
 int valor=1000;
  for(j=0;j<valor;j++){
    for(k=0;k<valor;k++){
        for(l=0;l<valor;l++)
            valor=valor;
    }
  }
}

void *função(void*arg){
     int *pvalor;
     pvalor = arg;

     printf("thread i% executando . . . \n", *pvalor);
     delay();
     printf("thread finalizado . . . \n", *pvalor);
}

int main(){

    pthread_t threads[N_THREAD];
    int i, arg[N_THREAD];
    for(i=0;i<N_THREAD;i++){
        pthread_join(threads[i], NULL);
        printf("\n");
    }

}
