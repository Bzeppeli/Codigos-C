#include <stdio.h>


int a;
int dobro(){
    a*=2;
    return a;

}


main(){

    printf("digite um valor");
    scanf("%d", &a);
    printf("%d\n", dobro());
    printf("%d", a);
}
