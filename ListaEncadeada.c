#include <stdio.h>
#include <stdlib.h>

struct pont
{
	int info;
	struct pont *prox;	
};

typedef struct pont Pont;

Pont *insere(Pont *p,int info)
{
	Pont *nova=(Pont*)malloc(sizeof(Pont));
	Pont *atual;
	nova->info = info;
	nova->prox = NULL;
	if(p == NULL)
		p = nova;
	else
	{
		atual = p;
		while(atual->prox != NULL)
		{
			atual = atual->prox;
		}
		atual->prox = nova;
	}
	return p;
}

Pont *busca(Pont *p,int info)
{
	Pont *aux = p;
	while(aux != NULL && aux->info != info)
		aux = aux->prox;
	return aux;
}

void removeReferencia(Pont **p,int info)
{
	Pont *aux = *p;
	Pont *ant;
	while(aux!=NULL && aux->info != info)
	{
		ant = aux;
		aux = aux->prox;
	}
	if(aux != NULL)
	{
		if(*p == aux)
			*p = aux->prox;
		else
			ant->prox = aux->prox;
		free(aux);
	}
}

void insereReferencia(Pont **p,int info) //Ponteiro de Ponteiro
{
	Pont *nova=(Pont*)malloc(sizeof(Pont));
	Pont *atual;
	nova->info = info;
	nova->prox = NULL;
	if(*p == NULL)
		*p = nova;
	else
	{
		atual = *p;
		while(atual->prox != NULL)
		{
			atual = atual->prox;
		}
		atual->prox = nova;
	}
}

//Alteracao no Heap eh efetuado mesmo que nao tenha um funcao com return.

void exibir(Pont *p)
{
	Pont *aux = p;
	int i = 0;
	if(aux == NULL)
	{
		printf("Lista Vazia\n");
	}
	else
	{
		while(aux != NULL)
		{
			printf("Valor[%d]: %d\n",i,aux->info);
			aux = aux->prox;
			i++;
		}
	}
	
}

int main()
{
	Pont *p = NULL;
	Pont *res = NULL;
    p = insere(p,20);
	p = insere(p,30);
	insereReferencia(&p,40); // Endereco do Ponteiro na pilha de variaveis.
	//res = busca(p,204);
	//printf("Resultado: %x",res);
	removeReferencia(&p,20);
	removeReferencia(&p,40);
	//p = remove(p,20);
	exibir(p);
	// parei no minuto 21 e 25 da aula
}
