struct pilha
{
	int info;
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

int top(Pilha *P)
{
	if(!isEmpty(P))
		return P->info;
	else
		return -1;
}

void pop(Pilha **P,int *info)
{
	Pilha *aux;
	if(!isEmpty(*P))
	{
		aux = *P;
		*info = (*P)->info;
		*P = (*P)->prox;
		free(aux);
	}
	else
		*info = -1;
}

void push(Pilha **P,int info)
{
	Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
	nova->info = info;
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
			printf("Info: %d\n",P->info);
			P = P->prox;
		}
	}
}
