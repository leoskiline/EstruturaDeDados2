#include <stdlib.h>
#include <stdio.h>
#include <conio2.h>
#include <math.h>
#define K 2

struct kdtree
{
	int ponto[K];
	struct kdtree *dir,*esq;
} typedef kdTree;

struct pontos
{
	int ponto[K];
	struct pontos *prox;
}typedef Ponto;

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

void pontosProximo(kdTree *raiz,Ponto **pontosProximos,int raio,int Pontos[2])
{
	int i;
	double euclidiana;
	euclidiana = sqrt(pow(raiz->ponto[0]-raiz->ponto[1],2) + pow(Pontos[0]-Pontos[1],2));
	Ponto *aux;
	if(raiz != NULL)
	{
		for(i = 0;i < K;i++)
		{		
			if(euclidiana <= raio)
			{
				if(i == K-1)
				printf("(%d) - ",raiz->ponto[i]);
				else
				printf("(%d),", raiz->ponto[i]);
				if((*pontosProximos) == NULL)
				{
					(*pontosProximos) = (Ponto*)malloc(sizeof(Ponto));
					(*pontosProximos)->ponto[i] = raiz->ponto[i];
					(*pontosProximos)->prox = NULL;
				}
				else
				{
					aux = (*pontosProximos);
					while(aux->prox != NULL)
					{
						aux = aux->prox;
					}
					aux->ponto[i] = raiz->ponto[i];
					aux->prox = NULL;
				}
				
				
			}
		}
		pontosProximo(raiz->esq,&(*pontosProximos),raio,Pontos);
		pontosProximo(raiz->dir,&(*pontosProximos),raio,Pontos);
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
			printf("(%d)",raiz->ponto[i]);
			else
			printf("(%d),",raiz->ponto[i]);
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
	Ponto *pontosProximos = NULL;
	int Ponto[2] = {8,18};
	printf("\n\n\n");
	pontosProximo(raiz,&pontosProximos,10,Ponto);
	return 0;
}
