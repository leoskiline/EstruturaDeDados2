#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tadlistagen.h"


int main()
{
	ListaGen *L;
	L = Cons(CriaT("a"),Cons(Cons(CriaT("b"),Cons(Cons(CriaT("c"),NULL),NULL)),NULL));
	return 0;
}
