#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct listagen
{
	char letra[8];
	char terminal;
	struct listagen *cabeca;
	struct listagen *cauda;
};
typedef struct listagen ListaGen;

struct pilha
{
	struct listagen *lista;
	struct pilha *prox;
};
typedef struct pilha Pilha;

char Nula(ListaGen *L)
{
	return L==NULL;
}

void init(Pilha **P)
{
	*P = NULL;
}

char isEmpty(Pilha *P)
{
	return P==NULL;
}

void pop(Pilha **P,ListaGen **L)
{
	Pilha *aux;
	if(!isEmpty(*P))
	{
		aux = *P;
		*L = (*P)->lista;
		*P = (*P)->prox;
		free(aux);
	}
	else
		*L = NULL;
}

void push(Pilha **P,ListaGen *L)
{
	Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
	nova->lista = L;
	nova->prox = *P;
	*P = nova;
}

char Atomo(ListaGen *L)
{
	return !Nula(L) && L->terminal=='T';
}

ListaGen *Cons(ListaGen *H,ListaGen *T)
{
	if(Atomo(T))
	{
		printf("Cons: Segundo argumento nao pode ser atomo!");
		return NULL;
	}
	else
	{
		ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
		L->terminal = 'F';
		L->cabeca = H;
		L->cauda = T;
		return L;
	}
}

ListaGen *Head(ListaGen *L)
{
	if( Nula(L) || Atomo(L))
	{
		printf("Head: argumento deve ser lista nao vazia!");
		return NULL;
	}
	else
		return L->cabeca;
}

ListaGen *Tail(ListaGen *L)
{
	if( Nula(L) || Atomo(L))
	{
		printf("Tail: argumento deve ser lista nao vazia!");
		return NULL;
	}
	else
		return L->cauda;
}

void exibe(ListaGen *L)
{
	if(Atomo(L))
		printf("%s",L->letra);
	else
	{
		printf("[");
		while(!Nula(L))
		{
			exibe(Head(L));
			L = Tail(L);
			if(!Nula(L))
				printf(",");
		}
		printf("]");
	}
}

void exibeAtomo(ListaGen *L)
{
	if(!Nula(L))
	{
		if(Atomo(L))
			printf("%s",L->letra);
		else
		{
			exibeAtomo(Head(L));
			exibeAtomo(Tail(L));
		}			
	}
}

void exibeAtomoI(ListaGen *L)
{
	Pilha *P;
	init(&P);
	push(&P,L);
	while(!isEmpty(P))
	{
		if(!Nula(L))
		{
			pop(&P,&L);
			while(!Nula(L) && !Atomo(L))
			{
				push(&P,L);
				L = Head(L);
			}
			if(Atomo(L))
				printf("%s",L->letra);
		}
		pop(&P,&L);
		L = Tail(L);
		if(!Nula(L))
			push(&P,L);
	}	
}

ListaGen *CriaT(char *letra)
{
	ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
	L->terminal = 'T';
	strcpy(L->letra,letra);
	return L;
}

int main()
{
	ListaGen *L;
	printf("Estrutura da Lista Gen: ");
	exibe(L);
	
	return 0;
}
