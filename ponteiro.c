#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p1,*p2;
	float *f1;
	//p1 = new int;
	p1 = (int*)malloc(sizeof(int)); //Alocacao de p1 na memoria. 4 Bytes tipo inteiro
	*p1 = 100;
	//f1 = p1 ; X Tipos Diferentes
	p2 = p1;
	*p2 = *p2 + 10; //p2 recebe valor 100.
	printf("%d",*p1);
	free(p1); //Libera da memoria. p2 passa apontar pra null
	f1 = (float*)malloc(sizeof(float));// Aloca espaco no Heap 4 Byes para armazenar um valor.
	*f1 = 9.8; // Atribui o valor ao espaco alocado no Heap atraves da posicao de memoria de *f1 que fica alocada na pilha.
	// Nao se pode acessar memoria do heap quando ela nao esta alocada no caso de dar free em p2 que recebe a mesma posicao de p1;
	// Ao dar Free ele nao joga o valor null na posicao do heap.
	// Usar p1 = p2 = NULL;
	//*p2 = Conteudo onde p2 aponta.
	
}
