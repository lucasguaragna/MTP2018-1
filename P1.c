//Lucas Guaragna Guedes
//11721EBI005

#include <stdio.h> 
int main()

{
	char num[256];
	int x = 0, r = 0;
	printf("\nDigite o numero binario: ");
	scanf("%s", &num);
	for(int i = 0; num [i] != '\0'; i++)
	{
		if(num[i] == '0' && x == 0)r = 0;
		if(num[i] == '1' && x == 0)r = 1;
		if(num[i] == '0' && x == 1)r = 2;
		if(num[i] == '1' && x == 1)r = 0;
		if(num[i] == '0' && x == 2)r = 1;
		if(num[i] == '1' && x == 2)r = 2;
	x = r;
	r = 0;
	}
	if(x == 0) printf("eh multiplo de 3");
	else printf("nao eh multiplo de 3");
	return 0;
}
