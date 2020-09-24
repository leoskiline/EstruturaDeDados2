#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tadlistagen.h"


int main()
{
	ListaGen *L;
	L = Cons(Cons(CriaT("a"),Cons(CriaT("b"),NULL)),Cons(CriaT("c"),NULL));
	printf("Estrutura da Lista Gen: ");
	exibe(L);
	printf("\nExibindo Atomos: ");
	exibeAtomo(L);
	Kill(&L);
	exibeAtomo(L);
	return 0;
}
