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

void copiaStrings(String *source,String **destino)
{
	if(source == NULL)
		printf("vazia");
	else
	{
		while(source != NULL)
		{
			insereLetraFim(&(*destino),source->letra);
			source = source->prox;
		}
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

void reiniciaStringR(String **valor)
{
	if((*valor) != NULL)
	{
		reiniciaStringR(&(*valor)->prox);
		free(*valor);
		*valor = NULL;
	}
}

void exibeStringR(String *valor)
{
	if(valor != NULL)
	{
		printf("%c",valor->letra);
		exibeStringR(valor->prox);
	}
}

void exibeStringContrarioR(String *valor)
{
	if(valor != NULL)
	{
		exibeStringContrarioR(valor->prox);
		printf("%c",valor->letra);
	}
}

int StringLengthR(String *valor)
{
	if(valor != NULL)
	{
		return StringLengthR(valor->prox)+1;
	}
	return 0;
}

void StringLength(String *valor,int *cont)
{
	if(valor != NULL)
	{
		StringLength(valor->prox,&*cont);
		(*cont)++;
	}
}

int main()
{
	String *string;
	String *copia;
	int cont = 0;
	initString(&copia);
	initString(&string);
	insereLetraFim(&string,'L');
	insereLetraFim(&string,'e');
	insereLetraFim(&string,'o');
	insereLetraFim(&string,'n');
	insereLetraFim(&string,'a');
	insereLetraFim(&string,'r');
	insereLetraFim(&string,'d');
	insereLetraFim(&string,'o');
	//reiniciaStringR(&string);
	exibeStringR(string);
	StringLength(string,&cont);
	printf("\nTamanho da String %d \n",cont);
	exibeStringContrarioR(string);
	copiaStrings(string,&copia);
	printf("\nString copiada: ");
	exibeStringR(copia);
}
