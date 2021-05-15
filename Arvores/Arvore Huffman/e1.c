#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct tabela
{
	int simbolo;
	float frequencia;
	char palavra[30];
}typedef Tabela;

struct tree
{
	float freq;
	int simbolo;
	struct tree *esq;
	struct tree *dir;
}typedef Tree;

struct lista
{
	float freq;
	int simb;
	struct lista *prox;
}typedef Lista;


Tree *criarNoArvore(float freq[50],int i)
{
	Tree *arv = (Tree*)malloc(sizeof(Tree));
	arv->freq = freq[i];
	arv->simbolo = i;
	arv->esq = NULL;
	arv->dir = NULL;
	return arv;
}

Lista *criarNoLista(float freq,int simb)
{
	Lista *l = (Lista*)malloc(sizeof(Lista));
	l->freq = freq;
	l->simb = simb;
	l->prox = NULL;
}



void CriarNosArvore(Tree *arv[50],int total,float freq[50])
{
	int i;
	for(i = 0;i < total;i++)
	{
		arv[i] = criarNoArvore(freq,i);
	}
}


void preencherTabela(Tabela tab[50],int total,char palavras[50][10],float freq[50])
{
	int i = 0;
	for(i = 0;i < total;i++)
	{
		tab[i].simbolo = i;
		tab[i].frequencia = freq[i];
		strcpy(tab[i].palavra,palavras[i]);
	}
	FILE *ptr = fopen("tabela.bin","wb");
	fwrite(tab,sizeof(Tabela)*total,1,ptr);
	fclose(ptr);
}

void ProcessarString(char string[200],int *total,char palavras[50][10],float freq[50])
{
	char *pch;
	pch = strtok(string," ");
	int i = 0;
	while(pch != NULL)
	{
		strcpy(palavras[i],pch);
		i++;
		pch = strtok(NULL," ");
	}
	*total = i;
	int j,k;
	for(j = 0;j<50;j++)
	{
		freq[j] = 0;
	}		
	for(j = 0;j<i;j++)
	{
		for(k = 0;k < i;k++)
		{
			if(stricmp(palavras[j],palavras[k]) == 0)
			{
				freq[j]++;
			}
		}
	}
}

void popularPalavrasUnicas(int *total,char palavras[23][10],char saida[50][10],float freq[50],float freqs[23])
{
	strcpy(saida[0],palavras[0]); freqs[0] = freq[0]; // amo
	strcpy(saida[1],palavras[1]); freqs[1] = freq[1]; // como
	strcpy(saida[2],palavras[2]); freqs[2] = freq[2]; // ama
	strcpy(saida[3],palavras[3]); freqs[3] = freq[3]; // o
	strcpy(saida[4],palavras[4]); freqs[4] = freq[4]; // amor
	strcpy(saida[5],palavras[5]); freqs[5] = freq[5]; // nao
	strcpy(saida[6],palavras[6]); freqs[6] = freq[6]; // conheco
	strcpy(saida[7],palavras[7]); freqs[7] = freq[7]; // nenhuma
	strcpy(saida[8],palavras[8]); freqs[8] = freq[8]; // outra
	strcpy(saida[9],palavras[9]); freqs[9] = freq[9]; // razao
	strcpy(saida[10],palavras[10]); freqs[10] = freq[10]; // para
	strcpy(saida[11],palavras[11]); freqs[11] = freq[11]; // amar
	strcpy(saida[12],palavras[12]); freqs[12] = freq[12]; // senao
	strcpy(saida[13],palavras[14]); freqs[13] = freq[14]; // que
	strcpy(saida[14],palavras[15]); freqs[14] = freq[15]; // queres
	strcpy(saida[15],palavras[17]); freqs[15] = freq[17]; // te
	strcpy(saida[16],palavras[18]); freqs[16] = freq[18]; // diga
	strcpy(saida[17],palavras[19]); freqs[17] = freq[19]; // alem
	strcpy(saida[18],palavras[20]); freqs[18] = freq[20]; // de
	strcpy(saida[19],palavras[24]); freqs[19] = freq[24]; // se
	strcpy(saida[20],palavras[27]); freqs[20] = freq[27]; // quero
	strcpy(saida[21],palavras[28]); freqs[21] = freq[28]; // dizer-te
	strcpy(saida[22],palavras[29]); freqs[22] = freq[29]; // e
	*total = 23;
}

void Normalizar(int total,char palavras[23][10],float freq[23],float *freqtotal)
{
	int i;
	float soma = 0;
	for(i = 0;i < total;i++)
	{
		freq[i] = freq[i] / 33;	
		soma += freq[i];
	}
	*freqtotal = soma;
}

void listaOrdenada(Lista **lista,float freq[50])
{
	int i = 0;
	*lista = criarNoLista(freq[i],i);
	i++;
	int j = 0;
	Lista *aux;
	aux = criarNoLista(freq[i],i);
	(*lista)->prox = aux;
	i++;
	while(aux != NULL && i < 24)
	{
		aux->prox = criarNoLista(freq[i],i);
		i++;
		aux = aux->prox;
	}
	Lista *aux2 = *lista;
	while(aux2->prox != NULL)
	{
		printf("Simb: %d Freq %f\n",aux2->simb,aux2->freq);
		aux2 = aux2->prox;
	}
}

void ordenar(float vetor[50])
{
	float aux;
	int x,y;
	for(x = 0;x < 23;x++)
	{
		for(y = x; y < 23;y++)
		{
			if(vetor[x] > vetor[y])
			{
				aux = vetor[x];
				vetor[x] = vetor[y];
				vetor[y] = aux;
			}
		}
	}
}


int main()
{
	char string[200];
	strcpy(string,"amo como ama o amor nao conheco nenhuma outra razao para amar senao amar que queres que te diga alem de que te amo se o que quero dizer-te e que te amo");
	int total = 0;
	char palavras[50][10];
	float freq[50];
	float freqtotal;
	ProcessarString(string,&total,palavras,freq);
	popularPalavrasUnicas(&total,palavras,palavras,freq,freq);
	Normalizar(total,palavras,freq,&freqtotal);
	Lista *l = NULL;
	ordenar(freq);
	listaOrdenada(&l,freq);
	return 0;
}
