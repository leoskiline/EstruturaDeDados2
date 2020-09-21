#include <stdio.h>
#include <stdlib.h>
#include "tadfila.h"

int main()
{
	int valor;
	Fila *F;
	init(&F);
	enqueue(&F,10);
	enqueue(&F,20);
	enqueue(&F,30);
	dequeue(&F,&valor);
	printf("Dequeue: %d\n",valor);
	exibir(F);
}
