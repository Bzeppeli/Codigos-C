#include <stdio.h>
#include <stdlib.h>

int main( )
{
    int linhas,colunas, i, j;
    int ln, cn;

    //Inicialização das variáveis
    ln = 0;
    cn = 0;

    /*Entrar com a dminsão da matriz desejada*/
    printf("Entre com o numero de linhas: ");
    scanf("%d",&linhas);
    printf("Entre com o numero de colunas: ");
    scanf("%d",&colunas);

    /*declaração das matrizes que serão usadas no programa*/
    int A[linhas][colunas];

        /*laço de repetição para entrar com os valores da matriz 1*/
        for (i=0; i<linhas; i++)
          for(j=0; j<colunas; j++)
          {
          printf(" Entre com os elementos da matriz 1 [%d][%d]:",i,j);
          scanf("%d",&A[i][j]);
          }

                       /*verificar linha nula*/
             if (A[i] == 0)
             ln = ln + 1;

             /*verificar coluna nula*/
             if (A[j] == 0)
             cn = cn + 1;

               if (ln > 0 && cn >0)
               printf("O número de linhas e colunas nulas é [%d] e [%d]\n\n",ln,cn);
               else
               printf("A matriz não apresenta linhas e colunas nulas\n\n");


           /*Mostra a matriz 1 criada*/
           printf("\n\nA matriz A criada é: \n\n");
             for (i=0; i<linhas; i++)
             {
                for(j=0; j<colunas;j++)
                printf("%3.d\t",A[i][j]);
                printf("\n\n");
             }

               printf("\n\n\n");
              getch();
              return 0;

}
