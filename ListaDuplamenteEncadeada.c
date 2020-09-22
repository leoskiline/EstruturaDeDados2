#include <stdio.h>
#include <stdlib.h>

struct caixa
{
	int info;
	struct caixa *ant;
	struct caixa *prox;
};

typedef struct caixa Caixa;

struct descritor
{
	Caixa *inicio;
	Caixa *fim;
};

typedef struct descritor Descritor;

void initP(Descritor *LD)
{
	(*LD).inicio = (*LD).fim = NULL;
}


void initH(Descritor **LD)
{
	*LD = (Descritor*)malloc(sizeof(Descritor));
	(*LD)->inicio = (*LD)->fim = NULL;
}

int main()
{
	//pilha
	Descritor LDP;
	initP(&LDP);
	
	//heap
	Descritor *LDH;
	initH(&LDH);
	return 0;
}
