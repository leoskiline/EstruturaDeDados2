#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "arvorebinaria.h"


int main()
{
	Tree *raiz = NULL;
	Tree *pai = NULL;
	int nivel = 1;
	int retorno = 0;
	insere(&raiz,50,0, ' ');
	insere(&raiz,20,50, 'e');
	insere(&raiz,10,20, 'e');
	insere(&raiz,40,20, 'd');
	insere(&raiz,30,40, 'e');
	insere(&raiz,60,50, 'd');
	insere(&raiz,70,60, 'd');
	pai = raiz;
	verificarNivel(raiz,50,nivel,&retorno);
	printf("Nivel: %d\n",retorno);
	buscarPai(raiz,90,&pai);
	printf("Pai: %d\n",pai->info);
	preOrdem(raiz);
	printf("\n");
	inOrdem(raiz);
	printf("\n");
	posOrdem(raiz);
	//raiz = esvaziaArvore(&raiz);
	//insere(&raiz,50,0, ' ');
	//printf("\n");
	//posOrdem(raiz);
	printf("\n");
	desenhaArvore(raiz);
	return 0;
}

//Verificar qual o nivel ou profundidade de um nó. *Feito
//Retorno o pai de um nó. *Feito
//Tornar uma arvore Vazia( Free em todos os nodos da arvore ).
// Exibir a arvore no formato de arvore.
