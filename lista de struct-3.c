#include <stdio.h>
#include <string.h>
#include <stdlib.h>
   typedef struct{
        char nome[10];
        int  mat;
        char curso[10];
   }ALUNOS;

    /*void ler(ALUNOS a){
        printf("digite o nome\n");
        gets(a.nome);
        printf("digite a matricula\n");
        scanf("%d",&a.mat);
        printf("digite o curso\n");
        gets(a.curso);
    */

   /* void mostrar(ALUNOS a){
        printf("nome %s\n", a.nome);
        printf("matricula %d\n", a.mat);
        printf("curso %s\n", a.curso);

    }*/
main()
{
    int i;
    ALUNOS v[3];
    for(i=0;i<3;i++){
       // ler(v);
    printf("digite o nome\n");
        gets(v[i].nome);
        printf("digite a matricula\n");
        scanf("%d",&v[i].mat);
        printf("digite o curso\n");
        gets(v[i].curso);
        putchar('\n');
    };
    for(i=0;i<3;i++){
        printf("nome %s\n", v[i].nome);
        printf("matricula %d\n", v[i].mat);
        printf("curso %s\n", v[i].curso);
    }

}
