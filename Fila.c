#include <stdio.h>
#include <stdlib.h>
struct ALUNO {
    char nome[30];
    int mat;
    float n1,n2;
};

typedef struct fila {
    struct elemento *inicio;
    struct elemento *fim;
}FILA;

typedef struct elemento{
    struct ALUNO dados;
    struct elemento *prox;
} ELEM;

FILA *criar(){
    FILA* fi = (FILA*) malloc(sizeof(FILA));
    if (if != NULL){
        fi->inicio= NULL;
        fi->fim= NULL;

    }
    return fi;
}

void liberar(FILA *fi){
 if(fi !=NULL){
    ELEM no*;
    while(fi->inicio != NULL){
        no= fi->inicio;
        fi->inicio = fi->inicio->prox;
        free(no);
    }
    free(fi);
 }

int tamanho(FILA *fi){
    if(fi==NULL){
        return 0;

    }
    int cont =0;
    ELEM *no= fi->inicio;
    while(no != NULL){
        cont++
        no= no->prox;
    }

    free(no);
    return cont;
}

void vazia(FILA *fi){
    int tam = tamanho(fi);
    if(fi !=null);
        if(fi->inicio==NULL){
            printf("\n a fila ta vazia\n");
        }else{
            printf("\n a fila não esta vazia\n");
        }
        printf("\n a fila está com %d elemento(s)\n",tam);
        }else{
            printf("\n erro de alocação\n");
        }
}

void inserir(FILA *fi, struct ALUNO al){

    if(fi==NULL){
        printf("\n erro de alocação\n");
    }else{
        ELEM *no = (ELEM*) malloc(sizeof(ELEM));
        if (no != NULL){
            no->dados= al;
            no->prox= NULL;
            if (fi->fim == NULL){
                fi->inicio=no;
            }else{
                fi->fim->prox=no;
            }
            fi->fim=no;
            printf("\n ELEMENTO INSERIDO \n");
        }else{
            printf("\n erro de alocação \n");
        }
    }

}

void remover(FILA *fi){
    if(fi==NULL){
        printf("\n Erro de alocação \n");
    }else{
        if(fi->inicio == NULL){
            printf("\n fila vazia \n");
        }else{
            ELEM *no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            if(fi->inicio = NULL){
                fi->fim=NULL;

            }

            free(no);
            printf("\n elemento removido");
        }
    }

}

