#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nome[15];
    int mat;
    int n1,n2,n3;

}ALUNOS;

void ler( ALUNOS v){
    printf("digite o nome do aluno\n");
    gets(v.nome);
    printf("digite o nome a matricula\n");
    scanf("%d",&v.mat);
    printf("digite a primeira nota\n");
    scanf("%d",&v.n1);
    printf("digite a segunda nota\n");
    scanf("%d",&v.n2);
    printf("digite a terceira nota\n");
    scanf("%d",&v.n3);
}

void mostrar( ALUNOS v){
    printf("nome %s\n", v.nome);
    printf("matricula %d\n", v.mat);
    printf("nota 1:%d ", v.n1);
    printf("nota 2:%d", v.n2);
    printf("nota 3:%d",v.n3);

}

main();

    ALUNOS v[3];
    int i;

    for(i=0;i<3;i++){
     ler(v);
    };
