#include <stdio.h>

char maior(int a,int b){
    if(a>b){
        return 'S';
    }else{
    if(a<b){
        return 'N';
    }else{
        return '=';
            }

        }

}


void linha(int x, char n){
    int i;
    for(i=0;i<x;i++){
        printf("%c",n );
    }
    putchar('\n');
}

main(){
    int x,y;


    printf("digite um valor\n");
    scanf("%d", &x);
    printf("digite um valor\n");
    scanf("%d", &y);
    linha(10, 'l');
    printf("%c\n", maior(x,y));
}
