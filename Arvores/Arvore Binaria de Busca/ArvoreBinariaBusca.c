struct tree
{
	int info;
	struct tree *esq,*dir;
};
typedef struct tree Tree;


#include <stdio.h>
#include <stdlib.h>
#include "pilhaAB.h"



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

void pre_ordem(Tree *raiz)
{
	if(raiz != NULL)
	{
		printf(" %d -",raiz->info);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}


void pre_ordemI(Tree *raiz)
{
	Pilha *P;
	init(&P);
	if(P != NULL)
	{
		push(&p,raiz);
	}
}

void in_ordem(Tree *raiz)
{
	if(raiz != NULL)
	{
		in_ordem(raiz->esq);
		printf(" %d -",raiz->info);
		in_ordem(raiz->dir);
	}
}

void pos_ordem(Tree *raiz)
{
	if(raiz != NULL)
	{
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf(" %d -",raiz->info);
	}
}

void esvaziarArvore(Tree **raiz)
{
	if(*raiz != NULL)
	{
		esvaziarArvore(&(*raiz)->esq);
		esvaziarArvore(&(*raiz)->dir);
		free(*raiz);
		*raiz = NULL;
	}
}

int Nivel(Tree *raiz,int info)
{
	int nivel = 1;
	while(raiz != NULL && raiz->info != info)
	{
		if(info > raiz->info)
			raiz = raiz->dir;
		else
			raiz = raiz->esq;
		nivel++;
	}
	return nivel;
}

Tree *Pai(Tree *raiz,int info)
{
	Tree *pai = NULL;
	if(raiz->info == info)
	{
		pai = raiz;
	}
	else
	{
		while(raiz != NULL && raiz->info != info)
		{
			pai = raiz;
			if(info > raiz->info)
				raiz = raiz->dir;
			else
				raiz = raiz->esq;
		}
	}	
	return pai;
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

/*void balanceamento(Tree **raiz)
{
	Tree *no,*e,*pai;
	int aux,qdir,qesq,FB;
	Fila *F;
	init(&F);
	enqueue(&F,*raiz);
	while(!isEmpty(F))
	{
		dequeue(&F,&no);
		do{
			qdir = qesq = 0;
			quantNo(no->dir,&qdir);
			quantoNo(no->esq,&qesq); // usar pre ordem
			FB = qdir - qesq;
			if(FB < -1 || FB > 1)// abs(FB) > 1
			{
				int aux = no->info;
				Busca(*raiz,aux,&e,&pai);
				if(no->esq == NULL)
					no = no->dir;
				else if(no->dir == null)
					no = no->esq;
					
				if(fb > 0)
					exclusao(&*raiz,e,pai,'d');
				else
					exclusao(&*raiz,e,pai,'e');
				insere(&*raiz,aux);
			}
		}while(FB< -1 || FB > 1);
		if(no->esq != null)
			enqueue(&F,no->esq);
		if(no->dir != null)
			enqueue(&F,no->dir);
	}
}*/

void exclusao(Tree **raiz,Tree *e,Tree *pai,char lado)
{
	if(e!=NULL)
	{
		if(e->esq == NULL && e->dir==NULL)//eh folha
		{
			if(e != pai)
			{
				if(e->info > pai->info) //Lado Direito
					pai->dir = NULL;
				else//Lado Esquerdo
					pai->esq = NULL;
			}
			else // e == pai
				*raiz = NULL;
			free(e);
		}
		else
		if(e->dir == NULL && e->esq != NULL || e->dir != NULL && e->esq == NULL)// e tem 1 filho
		{
			
		}
		else// tem 2 filhos
		{
			if(lado == 'e') // FB = SomaDir-SomaEsq = + ou -. Se + Direita, se - Esquerda o substituto
			{
				//substituto da esquerda
			}
			else // lado == 'd'
			{
				//substituto da direita
			}
		}
	}
}

int main()
{
	Tree *raiz = NULL;
	insere(&raiz,10);
	insere(&raiz,12);
	insere(&raiz,11);
	insere(&raiz,30);
	insere(&raiz,5);
	insere(&raiz,4);
	//printf("Nivel de %d eh %d.\n",5,Nivel(raiz,5));
	//printf("Pai: %d\n",Pai(raiz,5)->info);
	pos_ordem(raiz);
	esvaziarArvore(&raiz);
	pos_ordem(raiz);
	return 0;
}

