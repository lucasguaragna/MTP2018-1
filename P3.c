//Nome: Lucas Guaragna Guedes
//Matrícula: 11721EBI005


#include <stdio.h>

void decimal_para_binario(int vet[], int numdec) // Conversão de decimais POSITIVOS OU NEGATIVOS para binario
{
	int j = 0, k = 0, i = 0, aux, nvet[256], cont = 0, vetaux[32];
	if(numdec > 0) //POSITIVOS
	{	
		for (i = 0; numdec > 0; i++) 
		{
        	vet[i] = numdec % 2;
         	numdec /=  2;
    	}	
		for (int j = i - 1; j >= 0; j--) printf("%d", vet[j]);
	}
	else if(numdec < 0) //NEGATIVOS
	{
		aux = ((-numdec) - 1);

		for (i = 0; aux > 1; i++) 
		{
        	vet[i] = aux % 2;
         	aux /=  2;
         	if(aux == 1)
         	{	
			 	i++;
         		vet[i] = aux;
			}
    	}
    	i--;
		for(j = 0; j < 32; j++)
		{
			if(j < (32 - (i+1)))
			 {nvet[j] = 0;}
			else 
			{
				nvet[j] = vet[i];
				i--;
			}	
		}
		for(int w = 0; w < 32; w++) // inverte '0' e '1' de nvet[] e salva em vetaux[];
		{
			if(nvet[w] == 0) vetaux[w] = 1;
			else vetaux[w] = 0;
		}
		for(k = 0; k < 32; k++) printf("%d", vetaux[k]);
	}
}

int main()
{
	int option, num, num_not, num_and, num_or, num_xor, num_right, num_left;
	int vetbin1[100], vetbin2[100], vetbin3[100], a, b;
	printf("*CALCULADORA BITWISE*"
		   "\n\nEscolha dentre as opcoes:"
		   "\n1. NOT (~);"
		   "\n2. AND (&);"
		   "\n3. OR (|);"
		   "\n4. XOR (^);"
		   "\n5. Right Shift (>>);"
		   "\n6. Left Shift (<<).\n");
	scanf("%d", &option);	
	switch(option)
	{
		case 1:
			printf("Digite um numero: ");
			scanf("%d", &num);
			getchar();
			num_not = ~num;
			printf("NOT %d (", num); decimal_para_binario(vetbin1, num); printf(") :");
			printf(" %d (", num_not); decimal_para_binario(vetbin2, num_not);
			printf(")");
			break;
		case 2:
			printf("Digite dois numeros a serem comparados: ");
			scanf("%d\n%d", &a, &b);
			getchar();
			num_and = a & b;
			printf("%d (", a); decimal_para_binario(vetbin1, a); printf(") AND ");
			printf("%d (", b); decimal_para_binario(vetbin2, b); printf(") : ");
			printf("%d (", num_and); decimal_para_binario(vetbin3, num_and); printf(")");
			break;
		case 3:
			printf("Digite dois numeros a serem comparados: ");
			scanf("%d\n%d", &a, &b);
			getchar();
			num_or = a | b;
			printf("%d (", a); decimal_para_binario(vetbin1, a); printf(") OR ");
			printf("%d (", b); decimal_para_binario(vetbin2, b); printf(") : ");
			printf("%d (", num_or); decimal_para_binario(vetbin3, num_or); printf(")");
			break;
		case 4:
			printf("Digite dois numeros a serem comparados: ");
			scanf("%d\n%d", &a, &b);
			getchar();
			num_xor = a ^ b;
			printf("%d (", a); decimal_para_binario(vetbin1, a); printf(") XOR ");
			printf("%d (", b); decimal_para_binario(vetbin2, b); printf(") : ");
			printf("%d (", num_xor); decimal_para_binario(vetbin3, num_xor); printf(")");
			break;
		case 5:
			printf("Digite dois numeros a serem comparados: ");
			scanf("%d\n%d", &a, &b);
			getchar();
			num_right = a >> b;
			printf("%d (", a); decimal_para_binario(vetbin1, a); printf(") >> ");
			printf("%d (", b); decimal_para_binario(vetbin2, b); printf(") : ");
			printf("%d (", num_right); decimal_para_binario(vetbin3, num_right); printf(")");
			break;
		case 6:
			printf("Digite dois numeros a serem comparados: ");
			scanf("%d\n%d", &a, &b);
			getchar();
			num_left = a << b;
			printf("%d (", a); decimal_para_binario(vetbin1, a); printf(") << ");
			printf("%d (", b); decimal_para_binario(vetbin2, b); printf(") : ");
			printf("%d (", num_left); decimal_para_binario(vetbin3, num_left); printf(")");
			break;
		default: 
		    printf("Valor Invalido!");
		    break;
	}
	return 0;
}