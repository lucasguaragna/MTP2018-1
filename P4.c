//Nome: Lucas Guaragna Guedes
//Matricula: 11721EBI005


#include <stdio.h>

int main ()

{	int retorno[256], cont = 0;
	char numero[256];
	printf("Digite um numero: ");
	scanf("%s", &numero);	
	for(int i = 0; numero[i] != '\0'; i++) //Percorre a string numero[256];
	{	
		if(numero[i] >= 48 && numero[i] <= 57) //De 48 a 57, encontram-se os números de 0 a 9 na tabela ASCII;
		{	
			retorno[cont] = numero[i] - 48; //Se subtrairmos 48 desse 'char', obteremos um dado do tipo 'int';
			cont++;	
		}
	}	
	printf("\n");
	for(int j = 0; j < cont; j++) printf("%d", retorno[j]); 
	return 0;
}
