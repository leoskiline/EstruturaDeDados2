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
	Tree *info;
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
		freq[j] = 0;	
	for(j = 0;j<i;j++)
	{
		for(k = 0;k < i;k++)
		{
			if(stricmp(palavras[j],palavras[k]) == 0)
			{
				freq[j]++;
			}
		}
		freq[j] = freq[j] / *total;	
	}
}


int main()
{
	char string[200];
	strcpy(string,"Amo como ama o amor. Nao conheco nenhuma outra razao para amar senao amar. Que queres que te diga, alem de que te amo, se o que quero dizer-te e que te amo?");
	int total = 0;
	char palavras[50][10];
	float freq[50];
	ProcessarString(string,&total,palavras,freq);
	Tabela tab[total];
	preencherTabela(tab,total,palavras,freq);
	Tree *arq[total];
	CriarNosArvore(arq,total,freq);
	return 0;
}
