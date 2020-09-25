#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define ENTER 13
#define BACKSPACE 8

struct listaH
{
	struct listaH *ant;
	char letra;
	struct listaH *prox;
	struct listaH *cursor;
	struct listaH *sentinela;
};

typedef struct listaH ListaH;

struct listaV
{
	struct listaV *linha;
	struct listaV *inicio;
	struct listaV *initela;
	struct listaV *top;
	struct listaV *botton;
	int nro;
	struct listaH *inicioL;
};
typedef struct listaV ListaV;


void initV(ListaV **v)
{
	*v = (ListaV*)malloc(sizeof(ListaV));
	(*v)->linha = NULL;
	(*v)->botton = NULL;
	(*v)->nro = -1;
	(*v)->inicio = NULL;
	(*v)->top = NULL;
	(*v)->inicioL = NULL;
}

void inserirH(ListaV **v,char letra,char controle)
{
	ListaH *nova = (ListaH*)malloc(sizeof(ListaH));
	ListaH *sentinela = (ListaH*)malloc(sizeof(ListaH));
	if(controle != ENTER)
	{
			if((*v)->inicioL == NULL)
			{
				nova->ant = NULL;
				(*v)->inicioL = nova;
				(*v)->nro++;
				nova->letra = letra;
				nova->prox = sentinela;
				sentinela->ant = nova;
				sentinela->prox = NULL;
				sentinela->letra = 'x';	
			}
		else
		{
			ListaH *percorre = (*v)->inicioL;
			while(percorre->prox != NULL)
			{
				percorre = percorre->prox;
			}
			nova->letra = letra;
			percorre->ant->prox = nova;
			percorre->ant = nova;
			sentinela = percorre;
			sentinela->ant = nova;
			(*v)->nro++;
			sentinela->prox = NULL;
			nova->prox = sentinela;
		}
	}
	else
	{
		
	}
}

void exibir(ListaV *v)
{
	ListaH *aux = v->inicioL;
	while(aux != NULL && aux->letra != 'x')
	{
		printf("%c",aux->letra);
		aux = aux->prox;
	}
}

void capturaEntrada(ListaV **Lista)
{
	int linha = 4;
	int caracter = 8;
	int col = 0;
	int lin = 1;
	char letra = ' ';
	while(letra != F4)
	{
		gotoxy(caracter,linha);
		letra = getche();
		if(letra != 8 && letra != F4 && letra != ENTER)
		{
			inserirH(&(*Lista),letra,letra);
			gotoxy(12,19);
			printf("%d",++col);
		}
		else
		{
			//remove
		}
		if(letra == ENTER)
		{
			gotoxy(20,19);
			printf("%d",++lin);
			linha++;
			gotoxy(12,19);
			printf("0  ");
			col = 0;
			caracter = 8;
		}	
		else if(letra != BACKSPACE)
		    caracter++;
	}
}

void DesenhaTela()
{
	int i;
	//usleep(20000);
	gotoxy(5,1);
	printf("%c",218);
	//usleep(20000);
	gotoxy(100,1);
	printf("%c",191);
	//usleep(20000);
	gotoxy(5,20);
	printf("%c",192);
	//usleep(20000);
	gotoxy(100,20);
	printf("%c",217);
	for(i = 6;i < 100;i++)//1
	{
		//usleep(20000);
		gotoxy(i,1);
		printf("%c",196);
	}
	for(i = 2;i < 20;i++)
	{
		//usleep(20000);;
		gotoxy(100,i);//2
		printf("%c",179);
	}
	for(i = 99;i > 5;i--)
	{
		//usleep(20000);
		gotoxy(i,20);//3
		printf("%c",196);
	}
	for(i = 19;i > 1;i--)
	{
		//usleep(20000);
		gotoxy(5,i);//4
		printf("%c",179);
	}
	//usleep(20000);	
	gotoxy(8,2);
	printf("F2 - ABRIR  |");
	//usleep(20000);
	gotoxy(23,2);
	printf("F3 - SALVAR  |");
	//usleep(20000);
	gotoxy(39,2);
	printf("F4 - SAIR  |");
	//usleep(20000);
	gotoxy(54,2);
	printf("F5 - EXIBIR");
	for(i = 7;i < 99;i++)
	{
		//usleep(20000);
		gotoxy(i,3);
		printf("-");
	}
	for(i = 7;i < 99;i++)
	{
		//usleep(20000);
		gotoxy(i,18);
		printf("-");
	}
	//usleep(20000);
	gotoxy(8,19);
	printf("COL=0");
	//usleep(20000);
	gotoxy(16,19);
	printf("LIN=1");
	//usleep(20000);
	gotoxy(25,19);
	printf("INSERT");
	//usleep(20000);
	gotoxy(35,19);
	printf("||||");
	//usleep(20000);
	gotoxy(42,19);
	printf("LISTA");
	gotoxy(8,4);
}
