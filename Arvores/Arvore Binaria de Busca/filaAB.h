struct fila
{
	Tree *info;
	struct fila *prox;	
};

typedef struct fila Fila;

void init(Fila **F)
{
	*F = NULL;
}

void enqueue(Fila **F,Tree *info)
{
	Fila *aux;
	Fila *nova = (Fila*)malloc(sizeof(Fila));
	nova->info = info;
	nova->prox = NULL;
	if(*F == NULL)
		*F = nova;
	else
	{
		aux = *F;
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = nova;
	}
}
char isEmpty(Fila *F)
{
	return F==NULL;
}

void dequeue(Fila **F,Tree *info)
{
	Fila *aux;
	if(!isEmpty(*F))
	{
		aux = *F;
		info = (*F)->info;
		*F = (*F)->prox;
		free(aux);
	}
}

void exibir(Fila *F)
{
	if(F == NULL)
		printf("Vazio");
	else
	{
		while(F != NULL)
		{
			printf("Info: %d\n",F->info->info);
			F = F->prox;
		}
	}
}
