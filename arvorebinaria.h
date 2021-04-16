struct tree
{
	int info;
	struct tree *esq,*dir;
};
typedef struct tree Tree;

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

void verificarNivel(Tree *raiz,int info,int cont,int *nivel)
{
	if(raiz != NULL)
	{
		if(raiz->info == info)
			*nivel = cont;
		else
		{
			verificarNivel(raiz->esq,info,cont+1,&*nivel);
			if(*nivel == 0)
				verificarNivel(raiz->dir,info,cont+1,&*nivel);
		}
	}
}

void buscarPai(Tree *raiz,int info,Tree **pai)
{
	if(raiz != NULL)
	{
		if(raiz->info == info || (raiz->esq != NULL && raiz->esq->info==info) || (raiz->dir!=NULL && raiz->dir->info==info))
			*pai,raiz;
		else
		{
			buscarPai(raiz->esq,info,&*pai);
			if(*pai == NULL)
				buscarPai(raiz->dir,info,&*pai);
		}
	}
}

void preOrdem(Tree *raiz)
{
	if(raiz!=NULL)
	{
		printf("%d ",raiz->info);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void inOrdem(Tree *raiz)
{
	if(raiz != NULL)
	{
		inOrdem(raiz->esq);
		printf("%d ",raiz->info);
		inOrdem(raiz->dir);
	}
}

void posOrdem(Tree *raiz)
{
	if(raiz != NULL)
	{
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf("%d ",raiz->info);
	}
}

void *esvaziaArvore(Tree **raiz)
{
	if(*raiz != NULL)
	{
		esvaziaArvore(&(*raiz)->esq);
		esvaziaArvore(&(*raiz)->dir);
		free(&*raiz);
	}
}

void desenhaArvore(Tree *raiz)
{
	Pilha *P = NULL;
	init(&P);
	push(&P,raiz);
	while(raiz != NULL )
	{
		pop(&P,raiz);
		if(raiz != NULL)
		{
			push(&P,raiz);
			push(&P,raiz->esq);
		}
		else
		{
			if(!isEmpty(P))
			{
				pop(&P,raiz);
				printf("%d",raiz->info);
			}
		}
	}
}
