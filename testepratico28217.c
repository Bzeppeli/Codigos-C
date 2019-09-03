#include <stdio.h>

main()
{
    int n,i;

    printf("digite um numero\n");
    scanf("%d", &n);

    for(i=0;i<=n;i++){
        if(n%2==0){
            n=n/2;
        }else{
            n=3*n+1;
        }
    }

 }

