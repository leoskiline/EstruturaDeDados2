#include <stdlib.h>
#include <stdio.h>
#include "tadpilha.h"

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

void verificarNivel(Tree *raiz,int info,int nivel)
{
	if(raiz != NULL)
	{
		if(raiz->info == info)
		{
			printf("Nivel Encontrado: %d",++nivel);
		}
		else
		{
			nivel++;
			verificarNivel(raiz->esq,info,nivel);
			verificarNivel(raiz->dir,info,nivel);
			
		}
	}
}

void buscarPai(Tree *raiz,int info,Tree *pai)
{
	if(raiz != NULL)
	{
		if(raiz->info == info)
		{
			printf("Pai: %d",pai->info);
		}
		else
		{
			if(pai->esq == raiz)
				pai = pai->esq;
			else if(pai->dir == raiz)
				pai = pai->dir;
			buscarPai(raiz->esq,info,pai);
			buscarPai(raiz->dir,info,pai);
		}		
	}
}

int main()
{
	Tree *raiz = NULL;
	Tree *pai = NULL;
	int nivel = 0;
	insere(&raiz,1,0,' ');
	insere(&raiz,2,1, 'e');
	insere(&raiz,3,1, 'd');
	insere(&raiz,4,2, 'e');
	insere(&raiz,5,2, 'd');
	insere(&raiz,6,3, 'e');
	insere(&raiz,7,3, 'd');
	pai = raiz;
	//verificarNivel(raiz,7,nivel);
	buscarPai(raiz,7,pai);
	return 0;
}

//Verificar qual o nivel ou profundidade de um nó
//Retorno o pai de um nó
