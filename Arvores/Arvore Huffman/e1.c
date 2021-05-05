#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct tabela
{
	int simbolo;
	float frequencia;
	char letra[30];	
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
	ConstroiTabela(string);
	return 0;
}

void ConstroiTabela(char string[200])
{
	char *pch;
	pch = strtok(string," ");
	char palavra[50][10];
	int i = 0;
	while(pch != NULL)
	{
		strcpy(palavra[i],pch);
		i++;
		pch = strtok(NULL," ");
	}
	int j = 0;
	for(j = 0; j < 50 && !strchr(palavra[i],'\0');j++)
	{
		printf("%s\n",palavra[j]);
	}
}
