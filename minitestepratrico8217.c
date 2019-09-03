#include <stdio.h>

main()
{
    int an,a1,n,r;

    printf("digite o numero de termos\n");
    scanf("%d", &n);
    printf("digite a razao\n");
    scanf("%d", &r);

        for(a1=0;a1<=r;a1++){
            an = a1+(n-1)*r;

            printf("%d\n", an);
        }
        return 0;
}

