#include <stdlib.h>
#include <stdio.h>
#include <conio2.h>
#define K 2

struct kdtree
{
	int ponto[K];
	struct kdtree *dir,*esq;
} typedef kdTree;

kdTree *Cria_no(int ponto[K])
{
	int i;
	kdTree *no = (kdTree*)malloc(sizeof(kdTree));
	for(i = 0;i < K;i++)
		no->ponto[i] = ponto[i];
	no->dir = NULL;
	no->esq = NULL;
	return no;
}

void insereR(kdTree **raiz,int ponto[K],int n)
{
	int d;
	if(*raiz==NULL)
		*raiz=Cria_no(ponto);
		else
		{
			d=n%K;
			if(ponto[d] < (*raiz)->ponto[d])
				insereR(&(*raiz)->esq,ponto,n+1);
			else
				insereR(&(*raiz)->dir,ponto,n+1);
		}
}

void exibeKdTree(kdTree *raiz,int x,int y,int dist)
{
	int i;
	if(raiz!=NULL)
	{
		gotoxy(x,y);
		for(i = 0;i < K;i++)
		{
			if(i == K-1)
				printf("%d",raiz->ponto[i]);
			else
				printf("%d,",raiz->ponto[i]);
		}
			
		if(raiz->esq != NULL)
		{
			gotoxy(x-dist/2,y+1);
			printf("/");
		}
		if(raiz->dir != NULL)
		{
			gotoxy(x+dist/2,y+1);
			printf("\\");
		}
		exibeKdTree(raiz->esq,x-dist,y+2,dist/2);
		exibeKdTree(raiz->dir,x+dist,y+2,dist/2);
	}
}

int main()
{
	kdTree *raiz = NULL;
	int pontos[7][K] = {{30,40},{5,25},{20,30},{10,12},{70,70},{50,30},{35,45}};
	int i;
	for(i = 0;i<7;i++)
		insereR(&raiz,pontos[i],0);
	exibeKdTree(raiz,40,1,17);
	return 0;
}
