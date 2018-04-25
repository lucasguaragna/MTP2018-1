//Nome: Lucas Guaragna Guedes
//Matrícula: 11721EBI005

#include <stdio.h>

int binario_para_decimal(char bits[], char aux[], int cont, int dec, int pow, int j)
{
	for (int i = 0, j = cont - 1; i < cont; i++, j--) aux[j] = bits[i]; // inverte a string
	for (int k = 1; aux[k] != '\0'; k++) // percorre a partir da segunda posicao da string
	{
		pow *= 2;
		if (aux[k] == '1') dec += pow;
	}
	if (aux[0] == '1') dec += 1; // primeira posicao da string: 2^0 x 1 = 1, por isso devemos somar com 1 (se o primeiro elemento for 1)
	return dec;
}

int hexadecimal_para_decimal(char bits[], char aux[], int cont, int dec, int pow, int j)
{
	for (int i = 0, j = cont - 1; i < cont; i++, j--) aux[j] = bits[i]; // inverte a string
	for (int k = 1; k < cont; k++) // a partir da segunda posicao da string
	{
		pow *= 16;
		if (aux[k] == '1') dec += pow; if (aux[k] == '2') dec += pow*2; if (aux[k] == '3') dec += pow*3;
		if (aux[k] == '4') dec += pow*4; if (aux[k] == '5') dec += pow*5; if (aux[k] == '6') dec += pow*6;
		if (aux[k] == '7') dec += pow*7; if (aux[k] == '8') dec += pow*8; if (aux[k] == '9') dec += pow*9;
		if (aux[k] == 'a') dec += pow*10; if (aux[k] == 'b') dec += pow*11; if (aux[k] == 'c') dec += pow*12;
		if (aux[k] == 'd') dec += pow*13; if (aux[k] == 'e') dec += pow*14; if (aux[k] == 'f') dec += pow*15;
	}
	if (aux[0] == '1') dec += 1; if (aux[0] == '2') dec += 2; if (aux[0] == '3') dec += 3;
	if (aux[0] == '4') dec += 4; if (aux[0] == '5') dec += 5; if (aux[0] == '6') dec += 6;
	if (aux[0] == '7') dec += 7; if (aux[0] == '8') dec += 8; if (aux[0] == '9') dec += 9;
	if (aux[0] == 'a') dec += 10; if (aux[0] == 'b') dec += 11; if (aux[0] == 'c') dec += 12;
	if (aux[0] == 'd') dec += 13; if (aux[0] == 'e') dec += 14; if (aux[0] == 'f') dec += 15;

	return dec;
}

void decimal_para_binario(int vet[], int numdec)
{
	int i = 0;
	for (i = 0; numdec > 0; i++) 
	{
         vet[i] = numdec % 2;
         numdec /=  2;
    }
	for (int j = i - 1; j >= 0; j--) printf("%d", vet[j]);
}

void decimal_para_hexadecimal(int vet[], int numdec)
{
	int i = 0;
	for (i = 0; numdec > 0; i++)
	{
		vet[i] = numdec % 16;
		numdec /= 16;
	}
	for (int j = i - 1; j >= 0; j--) 
	{
		if (vet[j] >= 0 && vet[j] <= 9) printf("%d", vet[j]);
		if (vet[j] == 10) printf("a");
		if (vet[j] == 11) printf("b");
        if (vet[j] == 12) printf("c");
        if (vet[j] == 13) printf("d");
        if (vet[j] == 14) printf("e");
        if (vet[j] == 15) printf("f");
	}
}

int octal_para_decimal(char bits[], char aux[], int cont, int dec, int pow, int j)
{
	for (int i = 0, j = cont - 1; i < cont; i++, j--) aux[j] = bits[i]; // inverte a string
	for (int k = 1; k < cont; k++) // a partir da segunda posicao da string
	{
		pow *= 8;
		if (aux[k] == '1') dec += pow; if (aux[k] == '2') dec += pow*2; if (aux[k] == '3') dec += pow*3;
		if (aux[k] == '4') dec += pow*4; if (aux[k] == '5') dec += pow*5; if (aux[k] == '6') dec += pow*6;
		if (aux[k] == '7') dec += pow*7;
	}
	if (aux[0] == '1') dec += 1; if (aux[0] == '2') dec += 2; if (aux[0] == '3') dec += 3;
	if (aux[0] == '4') dec += 4; if (aux[0] == '5') dec += 5; if (aux[0] == '6') dec += 6;
	if (aux[0] == '7') dec += 7;

	return dec;
}

void decimal_para_octal(int vet[], int numdec)
{
	int i = 0;
	for (i = 0; numdec > 0; i++)
	{
		vet[i] = numdec % 8;
		numdec /= 8;
	}
	for (int j = i - 1; j >= 0; j--) printf("%d", vet[j]);
}


int main()
{
	char bits[256], aux[256];
	int cont = 0, valor, dec = 0, pow = 1, j = 0, vet[256], numdec;
		printf("\n\nDigite o numero da respectiva conversao desejada:\n1. Binario para Decimal\n2. Binario para Hexadecimal\n3. Hexadecimal para Decimal\n4. Hexadecimal para Binario\n5. Decimal para Binario\n6. Decimal para Hexadecimal\n7. Octal para Decimal\n8. Decimal para Octal\n");
		scanf("%d", &valor);
		switch (valor)
		{
		case 1:
			printf("\nDigite o valor desejado para conversao: "); // preencher a string
	        scanf("%s", &bits);
	        getchar();
			for (int i = 0; bits[i] != '\0'; i++, cont++); //  contador de caracteres da string (cont)
			printf("\n\nO binario digitado, convertido para decimal, sera: %d", binario_para_decimal(bits, aux, cont, dec, pow, j));
			break;
		case 2:
			//Binario --> Decimal --> Hexadecimal
			printf("\nDigite o valor desejado para conversao: "); // preencher a string
	        scanf("%s", &bits);
	        getchar();
			for (int i = 0; bits[i] != '\0'; i++, cont++); //  contador (cont)
			numdec = binario_para_decimal(bits,aux,cont,dec,pow,j);   // Binario --> Decimal
			printf("\n\nO binario digitado, convertido para hexadecimal, sera: ");
			decimal_para_hexadecimal(vet,numdec); // Decimal --> Hexadecimal 
			break;
		case 3:
		    printf("\nDigite o valor desejado para conversao: "); // preencher a string
	        scanf("%s", &bits);
	        getchar();
			for (int i = 0; bits[i] != '\0'; i++, cont++); //  contador (cont)
			printf("\n\nO hexadecimal digitado, convertido para decimal, sera: %d", hexadecimal_para_decimal(bits, aux, cont, dec, pow, j));
			break;
		case 4:
			printf("\nDigite o valor desejado para conversao: "); // preencher a string
	        scanf("%s", &bits);
	        getchar();
			for (int i = 0; bits[i] != '\0'; i++, cont++); //  contador (cont)
			printf("\n\nO numero digitado, transformado para decimal, sera: ");
			decimal_para_binario(vet, hexadecimal_para_decimal(bits, aux, cont, dec, pow, j));
			break;
		case 5:
			printf("\nInsira o numero decimal: ");
			scanf("%d", &numdec);
			printf("\n\nO decimal digitado, convertido para binario, sera: ", numdec);
			decimal_para_binario(vet, numdec);
			break;
		case 6:
			printf("\nInsira o numero decimal: ");
			scanf("%d", &numdec);
			printf("\n\nO decimal digitado, convertido para hexadecimal, sera: ", numdec);
			decimal_para_hexadecimal(vet, numdec);
			break;
		case 7:
			printf("\nDigite o valor desejado para conversao: "); // preencher a string
	        scanf("%s", &bits);
	        getchar();
			for (int i = 0; bits[i] != '\0'; i++, cont++); //  contador (cont)
			printf("\n\nO octal digitado, convertido para decimal, sera: %d", octal_para_decimal(bits, aux, cont, dec, pow, j));
			break;
		case 8:
			printf("\nInsira o numero decimal: ");
			scanf("%d", &numdec);
			printf("\n\nO decimal digitado, convertido para octal, sera: " );
			decimal_para_octal(vet, numdec);
			break;
		default:
			printf("\n\nValor Invalido!!!");
		}
    return 0;
}
