#include<stdio.h>
#include <string.h>
    typedef struct{
        int hora;
        int minutos;
        int segundos;
    }HORARIO;

    typedef struct{
        int dia;
        int mes;
        int ano;
    }DATA;

    typedef struct{
        DATA a;
        HORARIO b;
        char descricao;

    }COMPROMISSO;

    typedef struct{
        char nome[10];
        int idade;
        char endereco[15];
    }DADOS;

    void ler (DADOS a){
        fflush(stdin);
        printf("digite o nome\n");
        gets(a.nome);
        fflush(stdin);
        printf("digite a idade\n");
        scanf("%d",&a.idade);
        fflush(stdin);
        printf("digite o endereço\n");
        gets(a.endereco);
        putchar('\n');
        }

    void mostrar(DADOS a){
        printf("nome %s\n", a.nome);
        printf("idade %d\n", a.idade);
        printf("endereço %s", a.endereco);
    }
main(){
    DADOS a;
    ler(a);
    mostrar(a);

}
