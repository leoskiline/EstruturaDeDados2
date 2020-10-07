#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int dia1,dia2,dia3;
	int subiu1,subiu2;
	char output[10];
	strcpy(output,":(\n");
	scanf("%d%d%d",&dia1,&dia2,&dia3);
	subiu1 = dia2 - dia1;
	subiu2 = dia3 - dia2;
	if(dia1 > dia2)
	{
		if(dia3 >= dia2)
		{
			strcpy(output,":)\n");
		}
		if(subiu2 < subiu1)
		{
			strcpy(output,":(\n");
		}
		
	}
	else if(dia1 < dia2)
	{
		if(dia3 <= dia2)
		{
			strcpy(output,":)\n");
			if(subiu2 >= subiu1)
			{
				strcpy(output,":)\n");
			}	
		}
		
	}
		
	printf("%s",output);
	return 0;
}
