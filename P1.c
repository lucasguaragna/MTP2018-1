//Nome: Lucas Guaragna Guedes	
//Matricula: 11721EBI005

#include <stdio.h>
#include <locale.h> 

int main()
{
	char num[256];
	int x = 0, r = 0;
	printf_s("\nDigite o número binário: ");
	scanf_s("%s", &num);
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
	
	if(x == 0)
	{
	printf("O número binário %s é múltiplo de 3", num);
	else printf("O número binário %s não é múltiplo de 3 e o resto da sua divisão por 3 é: %d", num, x);
	}
	return 0;
}
