#define nl 5
#define nc 6

struct matrizEsp
{
	int lin,col,valor;
	struct matrizEsp *pc,*pl;
};
typedef struct matrizEsp MatEsp;

void verificaOcupado(MatEsp *vetlin[],int lin,int col,MatEsp **aux)
{
	MatEsp *p = vetlin[lin];
	while(p != NULL && col>p->col)
		p = p->pl;
	if(p!= NULL && col==p->col)
		*aux = p;
	else
		*aux = NULL;
}



void insere(MatEsp *vetlin[],MatEsp *vetcol[],int lin,int col,int valor)
{
	MatEsp *ant,*aux,*nova;
	if(lin >= 0 && lin < nl && col>=0 && col<nc)
	{
		verificaOcupado(vetlin,lin,col,&aux);
		if(aux!=NULL)
			aux->valor = valor;
		else
		{
			//Cria a celula da matriz
			nova = (MatEsp*)malloc(sizeof(MatEsp));
			nova->lin = lin;
			nova->col = col;
			nova->valor = valor;
			//ligacao horizontal
			if(vetlin[lin] == NULL)//Se linha estiver vazia insere no comeco. Primeiro Caso.
			{
				vetlin[lin]= nova;
				nova->pl = NULL;
			}
			else
			if(col < vetlin[lin]->col)// Se coluna for menos que cabeca de lista na posicao col.
			{
				nova->pl = vetlin[lin];
				vetlin[lin]=nova;
			}
			else// Inserir no meio de dois elementos.
			{
				ant = vetlin[lin];
				aux = ant->pl;
				while(aux != NULL && col > aux->col)
				{
					ant = aux;
					aux = aux->pl;
				}
				ant->pl = nova;
				nova->pl = aux;
			}
			//Ligacao Vertical
			if(vetcol[col] == NULL)
			{
				vetcol[col] = nova;
				nova->pc = NULL;
			}
			else
			if(lin < vetcol[col]->lin)
			{
				nova->pc = vetcol[col];
				vetcol[col] = nova;
			}
			else
			{
				ant = vetcol[col];
				aux = ant->pc;
				while(aux != NULL && lin > aux->lin)
				{
					ant = aux;
					aux = aux->pc;
				}
				ant->pc = nova;
				nova->pc = aux;
			}
		}
	}
	else
		printf("As coordenadas estao fora da Matriz!\n");
}

void exibe(MatEsp *vetlin[])
{
	int i,j;
	MatEsp *aux;
	for(i = 0;i < nl;i++)
	{
		for(j = 0;j<nc;j++)
		{
			verificaOcupado(vetlin,i,j,&aux);
			if(aux != NULL)
				printf("%d ",aux->valor);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

void inicializa(MatEsp *vetlin[],MatEsp *vetcol[])
{
	int i;
	for(i = 0 ; i < nl;i++)
		vetlin[i] = NULL;
	for(i = 0 ; i < nc;i++)
		vetcol[i] = NULL;
}

void soma(MatEsp *vetlinA[],MatEsp *vetlinB[],MatEsp *vetlinC[],MatEsp *vetcolC[])
{
	int i,j,soma;
	MatEsp *aux1,*aux2;
	for(i = 0;i < nl;i++)
	{
		for(j=0;j<nc;j++)
		{
			verificaOcupado(vetlinA,i,j,&aux1);
			verificaOcupado(vetlinB,i,j,&aux2);
			soma = 0;
			if(aux1!=NULL)
				soma = aux1->valor;
			if(aux2!=NULL)
				soma += aux2->valor;
				
			if(soma != 0)
				insere(vetlinC,vetcolC,i,j,soma);
		}
	}
}

void multiplica(MatEsp *vetlinA[],MatEsp *vetlinB[],MatEsp *vetlinC[],MatEsp *vetcolC[])
{
	
}
