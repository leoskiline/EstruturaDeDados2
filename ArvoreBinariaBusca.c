#include <stdio.h>
#include <stdlib.h>

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

void insere(Tree **raiz,int info)
{
	Tree *ant,*aux;
	if(*raiz == NULL)
	{
		*raiz = CriaNo(info);	
	}
	else
	{
		aux = *raiz;
		while(aux != NULL)
		{
			ant = aux;
			if(info>aux->info)
				aux = aux->dir;
			else
				aux = aux->esq;
		}
		if(info<ant->info)
			ant->esq = CriaNo(info);
		else
			ant->dir = CriaNo(info);
	}
}

void InsereR(Tree **raiz,int info)
{
	if(*raiz == NULL)
		*raiz = CriaNo(info);
	else
	{
		if(info>(*raiz)->info)
			InsereR(&(*raiz)->dir,info);
		else
			InsereR(&(*raiz)->esq,info);
	}
}

Tree *Busca(Tree *raiz,int info)
{
	while(raiz != NULL  && raiz->info != info)
	{
		if(info > raiz->info)
			raiz = raiz->dir;
		else
			raiz = raiz->esq;
	}
	return raiz;
}


void *BuscaR(Tree *raiz,int info,Tree **busca)
{
	if(raiz != NULL)
	{
		if(raiz->info == info)
			*busca = raiz;
		else
		{
			if(info > raiz->info)
				BuscaR(raiz->dir,info,&*busca);
			else
				BuscaR(raiz->esq,info,&*busca);
		}
	}
}

int main()
{
	Tree *raiz = NULL;
	InsereR(&raiz,10);
	InsereR(&raiz,12);
	InsereR(&raiz,11);
	InsereR(&raiz,30);
	InsereR(&raiz,5);
	return 0;
}

