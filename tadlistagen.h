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

ListaGen *CriaT(char *info)
{
	ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
	L->terminal = 1;
	strcpy(L->no.info,info);
	return L;
}
