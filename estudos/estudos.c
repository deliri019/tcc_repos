#include <stdio.h>

int x,y;
int *px, *py;

int main(void)
{
	x = 1;  /* atribui à variável x o valor 1. */
	y = 2;  /* atribui à variável y o valor 2. */
	px= &x; /* atribui ao ponteiro px o endereco da variavel x. */
	py= &y; /* atribui ao ponteiro py o endereco da variavel y. */
	printf("O endereco de x é %d e o valor de x é %d.\n",px,*px);
	printf("O endereço de y é %d e o valor de y é %d.\n",py,*py);
}
