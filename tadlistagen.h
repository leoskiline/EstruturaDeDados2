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

typedef struct listagen ListaGen;

char Nula(ListaGen *L)
{
	return L==NULL;
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


