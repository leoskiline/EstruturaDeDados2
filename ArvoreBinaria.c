#include <stdlib.h>
#include <stdio.h>
#include "tadpilha.h"
#include <conio.h>

struct tree
{
	int info;
	struct tree *esq,*dir;
};
typedef struct tree Tree;

Tree *CriaNo(int info)
{
	Tree *nova = (Tree*)malloc(sizeof(Tree));
	nova->info = info;
	nova->esq = nova->dir = NULL;
	return nova;
}

void localizaNo(Tree *raiz,int info,Tree **saida)
{
	if(raiz != NULL)
	{
		if(raiz->info == info)
			*saida = raiz;
		else
		{
			localizaNo(raiz->esq,info,&*saida);
			if(*saida == NULL)
				localizaNo(raiz->dir,info,&*saida);
		}
	}
}

void insere(Tree **raiz, int info, int info_pai,char lado)
{
	Tree *pai = NULL;
	if(*raiz == NULL)
		*raiz = CriaNo(info);
	else
	{
		localizaNo(*raiz,info_pai,&pai);
		if(pai != NULL)
		{
			if(lado == 'e' && pai->esq == NULL)
				pai->esq = CriaNo(info);
			else if(lado == 'd' && pai->dir == NULL)
				pai->dir = CriaNo(info);
			else
				printf("Lado Ocupado!\n");
		}
		else
			printf("Pai nao encontrado!\n");
	}
}

void verificarNivel(Tree *raiz,int info,int cont,int *nivel)
{
	if(raiz != NULL)
	{
		if(raiz->info == info)
			*nivel = cont;
		else
		{
			verificarNivel(raiz->esq,info,cont+1,&*nivel);
			if(*nivel == 0)
				verificarNivel(raiz->dir,info,cont+1,&*nivel);
		}
	}
}

void buscarPai(Tree *raiz,int info,Tree **pai)
{
	if(raiz != NULL)
	{
		if(raiz->info == info || (raiz->esq != NULL && raiz->esq->info==info) || (raiz->dir!=NULL && raiz->dir->info==info))
			*pai,raiz;
		else
		{
			buscarPai(raiz->esq,info,&*pai);
			if(*pai == NULL)
				buscarPai(raiz->dir,info,&*pai);
		}
	}
}

void preOrdem(Tree *raiz)
{
	if(raiz!=NULL)
	{
		printf("%d ",raiz->info);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void inOrdem(Tree *raiz)
{
	if(raiz != NULL)
	{
		inOrdem(raiz->esq);
		printf("%d ",raiz->info);
		inOrdem(raiz->dir);
	}
}

void posOrdem(Tree *raiz)
{
	if(raiz != NULL)
	{
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf("%d ",raiz->info);
	}
}

void *esvaziaArvore(Tree **raiz)
{
	if(*raiz != NULL)
	{
		esvaziaArvore(&(*raiz)->esq);
		esvaziaArvore(&(*raiz)->dir);
		free(&*raiz);
	}
}

void desenhaArvore(Tree *raiz)
{
	while(raiz != NULL )
	{
		if(raiz->dir != NULL)
			raiz = raiz->dir;
		else if(raiz->esq != NULL)
			raiz = raiz->esq;
	}
}

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
