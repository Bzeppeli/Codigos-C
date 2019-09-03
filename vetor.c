#include <stdio.h>

void mostrar(int a[3][2]){
    int c,b;
    for(c=0;c<3;c++){
        for(b=0;b<2;b++){
            printf("%d", a[c][b]);

        }
        putchar('\n');
    }
}

void preencher(int x[3][2]){
    int i,j;
        for(i=0;i<3;i++){
            for(j=0;j<2;j++){
                printf("valor n[%d][%d]", i,j);
                scanf("%d", &x[i][j]);
            }
        }
}


main(){
 int n[3][2] = {{2,4},{1,1},{2,0}};
    mostrar(n);
    preencher(n);
}
