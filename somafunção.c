#include <stdio.h>

soma(int x, int y){
    return x+y;
}
float media(int s, int m){
    return ((float)soma(s,m))/2.0;
}

int valor()
{
    int x;
    printf("digite um numero\n");
    scanf("%d", &x);
    return x;

}

main()
{
    int a,b;
    a=valor();
    b=valor();

    printf("a soma %d\n", soma(a,b));
    printf(" a media %.2f", media(a,b));
}
