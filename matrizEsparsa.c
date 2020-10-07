#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadMatrizEsparsa.h"


int main()
{
	MatEsp *vetlinA[nl], *vetcolA[nc];
	MatEsp *vetlinB[nl], *vetcolB[nc];
	MatEsp *vetlinC[nl], *vetcolC[nc];
	inicializa(vetlinA,vetcolA);
	inicializa(vetlinB,vetcolB);
	inicializa(vetlinC,vetcolC);
	insere(vetlinA,vetcolA,1,1,15);
	insere(vetlinA,vetcolA,2,2,22);
	insere(vetlinA,vetcolA,3,3,33);
	insere(vetlinA,vetcolA,3,1,20);
	exibe(vetlinA); // parei no minuto 25;
	printf("------------------------\n");
	insere(vetlinB,vetcolB,1,1,-5);
	insere(vetlinB,vetcolB,2,2,3);
	exibe(vetlinB);
	soma(vetlinA,vetlinB,vetlinC,vetcolC);
	printf("------------------------\n");
	exibe(vetlinC);
	return 0;
}
