struct reg_lista
{
	struct listagen *cabeca;
	struct listagen *cauda;
};

union info_lista
{
	char info[8];
	struct reg_lista lista;
};

struct listagen
{
	char terminal;
	union info_lista no;
};

struct pilha
{
	struct listagen *lista;
	struct pilha *prox;
};
typedef struct pilha Pilha;

typedef struct listagen ListaGen;

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
	return !Nula(L) && L->terminal;
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
		L->terminal = 0;
		L->no.lista.cabeca = H;
		L->no.lista.cauda = T;
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
		return L->no.lista.cabeca;
}

ListaGen *Tail(ListaGen *L)
{
	if( Nula(L) || Atomo(L))
	{
		printf("Tail: argumento deve ser lista nao vazia!");
		return NULL;
	}
	else
		return L->no.lista.cauda;
}

void exibe(ListaGen *L)
{
	if(Atomo(L))
		printf("%s",L->no.info);
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
			printf("%s",L->no.info);
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
				printf("%s",L->no.info);
		}
		pop(&P,&L);
		L = Tail(L);
		if(!Nula(L))
			push(&P,L);
	}	
}

void deph(ListaGen *L,int nivel,int *maior)
{
	if(!Nula(L))
	{
		if(!Atomo(L))
		{
			if(nivel>*maior)
				*maior = nivel;
			deph(Head(L),nivel+1,&*maior);
			deph(Tail(L),nivel,&*maior);
		}
		
	}
}

void len(ListaGen *L,int *tam)
{
	while(!Nula(Tail(L)))
	{
		(*tam)++;
		L = Tail(L);
	}
}

ListaGen *append(ListaGen *L,ListaGen *L2)
{
	ListaGen *aux;
	aux = L;
	while(!Nula(Tail(aux)))
		aux = Tail(aux);
	
	aux->no.lista.cauda = L2;
	
	return aux;
}

void Kill(ListaGen **L)
{
	if(!Nula(*L))
	{
		if(Atomo(*L))
			free(*L);
		else
		{
			Kill(&(*L)->no.lista.cabeca);
			Kill(&(*L)->no.lista.cauda);
			free(*L);
			*L = NULL;
		}			
	}
}
ListaGen *CriaT(char *info)
{
	ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
	L->terminal = 1;
	strcpy(L->no.info,info);
	return L;
}

ListaGen *dup(ListaGen *L)
{
	if(Nula(L))
	{	
		return NULL;	
	}
	if(Atomo(L))
		return CriaT(L->no.info);
	return Cons( dup(Head(L)) ,dup(Tail(L)) );	
}

char compara(ListaGen *L,ListaGen *L2)
{
	if(Nula(L) && Nula(L2))
		return 1;
	if(Nula(L) || Nula(L2))
		return 0;
	if(Atomo(L) && Atomo(L2))
		return !strcmp(L->no.info,L2->no.info);
	if(Atomo(L) || Atomo(L2))
		return 0;
	return compara(Head(L),Head(L2)) && compara(Tail(L),Tail(L2));
	
}


