#include<stdio.h>
int a,b;
void horizontal(int v[a][b]){

    int i, aux, x, j;
    printf("digite o valor para x\n");
    scanf("%d", &x);
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            if (x>0){
                aux=i+x;
                i=aux;
            }else if(i<0){
                aux=i-x;
                i=aux;

            }else{
             aux=i;
        }
        putchar('\n');
        printf(v[a][b]);
        }

    }

}

void vertical(int v[a][b]){

    int i, aux, y, j;
    printf("digite o valor para y\n");
    scanf("%d", &y);
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            if (y>0){
                aux=j+y;
                j=aux;
            }else if(j<0){
                aux=j-y;
                j=aux;

            }else{
             aux=j;
        }

        putchar('\n');
        printf(v[a][b]);
    }

    }

}


main( ){

    int linhas,colunas, i, j;
    int ln, cn;

    ln = 0;
    cn = 0;


    printf("digite as dimensões da matriz\n ");
    scanf("%d %d",&linhas,&colunas);


    int A[linhas][colunas];


        for (i=0; i<linhas; i++)
          for(j=0; j<colunas; j++)
          {
          printf(" Entre com os elementos da matriz 1 [%d][%d]:",i,j);
          scanf("%d",&A[i][j]);
          }

           printf("\n\nA matriz A criada é: \n\n");
             for (i=0; i<linhas; i++)
             {
                for(j=0; j<colunas;j++)
                printf("%3.d\t",A[i][j]);
                printf("\n\n");
             }

               printf("\n\n\n");
              //getch();
             // return 0;
        horizontal(A[linhas][colunas]);
        vertical(A[linhas][colunas]);
}

