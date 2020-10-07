#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tadlistagen.h"



int main()
{
	ListaGen *L;
	L = Cons(CriaT("a"),Cons(Cons(Cons(CriaT("b"),Cons(CriaT("c"),NULL)),Cons(CriaT("d"),NULL)),NULL));
	
	
	
	//Cons(CriaT("a"),Cons(Cons(Cons(CriaT("b"),Cons(CriaT("c"),NULL)),Cons(CriaT("d"),NULL)),NULL));
	printf("Estrutura da Lista Gen: ");
	exibe(L);
	printf("\nExibindo Atomos: ");
	//exibeAtomo(L);
	exibeAtomoI(L);
	//Kill(&L);
	//exibeAtomo(L);
	int prof = 0;
	int comp = 0;
	//deph(L,1,&prof);
	lenD(L,1,&comp,&prof);
	printf("\nProfundidade: %d",prof);
	//len(L,prof,&comp);
	printf("\nComprimento: %d",comp);
	
	return 0;
}
