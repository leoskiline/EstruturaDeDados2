#include <stdlib.h>
#include <stdio.h>
#include "tadpilha.h"

int main()
{
	int valor;
	Pilha *P;
	init(&P);
	push(&P,12);
	push(&P,13); // parou em 1 hora e 11
	push(&P,14);
	push(&P,15);
	pop(&P,&valor);
	exibir(P);
	printf("\nPop : %d",valor);
}
