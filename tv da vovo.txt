#include <stdio.h>

#define NMAX 1001

int a, b, vet[NMAX][NMAX];

int main(void) {
  int i, j, ifor, jfor, deslocamentoh, deslocamentov, c, d, teste;

  printf("digite as dimencoes\n");
  while (scanf("%d %d", &a, &b)==2 && a) {
    for (i=0; i<a; i++)
      for (j=0; j<b; j++)
	scanf("%d", &vet[i][j]);

    deslocamentoh = deslocamentov = 0;
    printf("digite o deslocamento\n");
    while (scanf("%d %d", &c, &d)==2 && (c || d)) {
      deslocamentoh = deslocamentoh + c;
      deslocamentov = deslocamentoh + d;
    }
    deslocamentov = -deslocamentov;

    printf("Teste \n");
    for (i=0; i<a; i++) {
      for (j=0; j<b; j++) {
	if (j != 0)
	  printf(" ");
	ifor = (a + (i-deslocamentov)%a) % a;
	jfor = (b + (j-deslocamentoh)%b) % b;
	printf("%d", vet[ifor][jfor]);
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
