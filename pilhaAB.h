struct pilha
{
	Tree *arvore;
	struct pilha *prox;
};
typedef struct pilha Pilha;

void init(Pilha **P)
{
	*P = NULL;
}

char isEmpty(Pilha *P)
{
	return P==NULL;
}

Tree *top(Pilha *P)
{
	if(!isEmpty(P))
		return P->arvore;
	else
		return NULL;
}

void pop(Pilha **P,Tree *arvore)
{
	Pilha *aux;
	if(!isEmpty(*P))
	{
		aux = *P;
		arvore = (*P)->arvore;
		*P = (*P)->prox;
		free(aux);
	}
	else
		arvore = NULL;
}

void push(Pilha **P,Tree *arvore)
{
	Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
	nova->arvore = arvore;
	nova->prox = *P;
	*P = nova;
}

void exibir(Pilha *P)
{
	if(P == NULL)
		printf("Vazio");
	else
	{
		while(P != NULL)
		{
			printf("Arvore: %x\n",P->arvore);
			P = P->prox;
		}
	}
}
