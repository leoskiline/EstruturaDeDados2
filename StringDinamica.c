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

void concatena(String *source1,String *source2,String **destino)
{
	copiaStrings(source1,&*destino);
	copiaStrings(source2,&*destino);
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

void RemoveApartir(String **str,int nro,int start)
{
	String *aux,*ant;
	aux = *str;
	if(start == 0)
	{
		while(*str!= NULL && nro > 0)
		{
			aux = *str;
			*str=(*str)->prox;
			free(aux);
			nro--;
		}
	}
	else
	{
		ant = *str;
		while(aux!=NULL && start > 1)
		{
			ant=ant->prox;
			start--;
		}
		if(ant!=NULL)
		{
			while(ant->prox != NULL && nro > 0)
			{
				aux = ant->prox;
				ant->prox = aux->prox;
				free(aux);
				nro--;
			}
		}
	}
}

void buscaPosicao(String *str1,String *subs,int *local)
{
	*local = -1;
	int pos = 0;
	while(str1 !=NULL && *local==-1)
	{
		if(str1->letra == subs->letra) // Acha a Primeira Letra
		{
			String *auxStr1 = str1;
			String *auxSubs = subs;
			while(auxStr1!= NULL && auxSubs != NULL && auxStr1->letra == auxSubs->letra)
			{
				auxStr1 = auxStr1->prox;
				auxSubs = auxSubs->prox;
				
			}
			if(auxSubs == NULL)
			{
				*local = pos;
			}
		}
		str1 = str1->prox;
		pos++;
	}
}

int main()
{
	String *string;
	String *copia;
	String *concatenada;
	String *subs;
	initString(&subs);
	int cont = 0;
	int local;
	initString(&copia);
	initString(&string);
	initString(&concatenada);
	insereLetraFim(&subs,'r');
	insereLetraFim(&subs,'d');
	insereLetraFim(&subs,'o');
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
	exibeStringContrarioR(string);
	printf("\nTamanho da String %d ",cont);
	copiaStrings(string,&copia);
	printf("\nString copiada: ");
	exibeStringR(copia);
	concatena(copia,string,&concatenada);
	printf("\nStrings Concatenadas: ");
	exibeStringR(concatenada);
	buscaPosicao(string,subs,&local);
	printf("Posicao da Substring: %d",local);
	return 0;
}
