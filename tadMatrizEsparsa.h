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
				
			}
		}
	}
	else
		printf("As coordenadas estao fora da Matriz!\n");
}
