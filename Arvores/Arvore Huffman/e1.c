#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct tabela
{
	int simbolo;
	float frequencia;
	char palavra[30];	
	struct tabela *prox;
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


int main()
{
	char string[200];
	strcpy(string,"Amo como ama o amor. Nao conheco nenhuma outra razao para amar senao amar. Que queres que te diga, alem de que te amo, se o que quero dizer-te e que te amo?");
	int total = 0;
	ProcessarString(string,&total);
	printf("%d",total);
	return 0;
}

void ProcessarString(char string[200],int *total)
{
	char *pch;
	pch = strtok(string," ");
	int i = 0;
	char palavras[50][10];
	while(pch != NULL)
	{
		strcpy(palavras[i],pch);
		i++;
		pch = strtok(NULL," ");
	}
	*total = i;
	int j,k;
	float freq[50];
	freq[0] = 0;
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
	for(j = 0;j < i;j++)
	{
		printf("%s - %f\n",palavras[j],freq[j]);
	}
}
