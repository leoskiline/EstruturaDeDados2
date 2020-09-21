#include <stdlib.h>
#include <stdio.h>

struct string
{
	char letra;
	struct string *prox;
};

typedef struct string String;

void initString(String **valor)
{
	*valor = NULL;
}


void insereLetraFim(String **valor,char letra)
{
	String *nova = (String*)malloc(sizeof(String));
	nova->letra = letra;
	nova->prox = NULL;
	String *atual;
	if(*valor == NULL)
		*valor = nova;
	else
	{
		atual=*valor;
		while(atual->prox != NULL)
		{
			atual = atual->prox;
		}
		atual->prox = nova;
	}
}

void exibeString(String *valor)
{
	if(valor == NULL)
	{
		printf("String Vazia");
	}
	else
	{
		while(valor != NULL)
		{
			printf("%c",valor->letra);
			valor = valor->prox;
		}
	}
	
		
}

void reiniciaString(String **valor)
{
	String *aux = *valor;
	while(*valor != NULL)
	{
		aux = *valor;
		*valor = (*valor)->prox;
		free(aux);
	}
}

int main()
{
	String *string;
	initString(&string);
	insereLetraFim(&string,'L');
	insereLetraFim(&string,'e');
	insereLetraFim(&string,'o');
	insereLetraFim(&string,'n');
	insereLetraFim(&string,'a');
	insereLetraFim(&string,'r');
	insereLetraFim(&string,'d');
	insereLetraFim(&string,'o');
	reiniciaString(&string);
	exibeString(string);
}
