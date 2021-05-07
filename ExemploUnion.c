//Exemplo de Union
#include <stdio.h>

struct bits
{
	unsigned char b7:1;
	unsigned char b6:1;
	unsigned char b5:1;
	unsigned char b4:1;
	unsigned char b3:1;
	unsigned char b2:1;
	unsigned char b1:1;
	unsigned char b0:1;
};

union byte
{
	struct bits bi;
	unsigned char num;
};

int main()
{
	union byte uval;
	uval.num = 12;
	printf("%d",uval.bi.b0);
	printf("%d",uval.bi.b1);
	printf("%d",uval.bi.b2);
	printf("%d",uval.bi.b3);
	printf("%d",uval.bi.b4);
	printf("%d",uval.bi.b5);
	printf("%d",uval.bi.b6);
	printf("%d",uval.bi.b7);//Converte inteiro em binario
	getch();
	return 0;
}
