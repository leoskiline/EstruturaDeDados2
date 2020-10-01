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
	//exibeAtomo(L);
	exibeAtomoI(L);
	//Kill(&L);
	//exibeAtomo(L);
	int prof = 0;
	deph(L,1,&prof);
	printf("\nProfundidade: %d",prof);
	int largura = 1;
	len(L,&largura);
	printf("\nLargura: %d",largura);
	return 0;
}
