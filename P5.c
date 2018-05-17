//Nome:Lucas Guaragna Guedes
//Matrícula: 11721EBI005
#include <stdio.h>
int main()
{	
	int i, cont, txt[256], opcao, *p2;
	char str[256], *p1;
	do
	{
		do
		{
			printf(
			"Escolha dentre as opcoes(Digite seu indice): "
			"\n-----------------------"
			"\n1. Codificar;"
			"\n2. Descodificar;"
			"\n3. Sair do programa."
			"\n-----------------------"
			"\nQual sua escolha? ");
			scanf("%d", &opcao);
			getchar();
		}while(opcao <= 1 && opcao >= 3);
		i = 0;
		switch(opcao)
		{		
			case 1:
				for(int i = 0; i < 256; i++) str[i] = '\0'; 
				printf("Entre com uma mensagem de no maximo 255 caracteres: ");
				fgets(str, 256, stdin);
				for(cont = 0; str[cont] != '\0'; cont++);	
				p2 = (int*)str;
				printf("\nA frase codificada sera: \n");
				for(i = 0; i < cont; i++)	
				{	
					if(*(p2 + i) != 0 ) printf("%i ", *(p2 + i));
				} 
				break;
			
			case 2:
				p1 = (char*)txt;
				printf("\nOBS: PARA ENCERRAR A SEQUENCIA QUE SERA DIGITADA, TERMINE-A COM '0'");
				cont = 0;
				printf("\nDigite o codigo: \n");
				do
				{			
					scanf("%d", &cont);
	 				getchar();
					txt[i] = cont;
					i++;
				}while(cont != 0);
				p1 = (char*)&txt;
				printf("\nA frase descodificada sera: \n");
				for(i = 0; i < sizeof(txt) && *(p1 + i) != 0; i++) printf("%c", *(p1 + i));		
				break;

			default:
				break;
		}
		printf("\n");
	}while(opcao != 3);
	return 0;
}
