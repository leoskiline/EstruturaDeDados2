#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <conio.h>
#include "tadtrabED2.h"


int main()
{
	DesenhaTela(0,0);
	ListaV *Lista = NULL;
	initV(&Lista);
	capturaEntrada(&Lista);
	gotoxy(8,25);
	exibir(Lista);
	printf("%d",Lista->nro);
	getch();
	return 0;
}
