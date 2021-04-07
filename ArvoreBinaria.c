#include <stdlib.h>
#include <stdio.h>

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

int main()
{
	Tree *raiz = NULL;
	insere(&raiz,10,0,' ');
	insere(&raiz,30,10, 'd');
	insere(&raiz,50,30, 'e');
	return 0;
}

//Verificar qual o nivel ou profundidade de um nó
//Retorno o pai de um nó
