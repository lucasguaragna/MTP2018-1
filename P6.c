//Lucas Guaragna Guedes
//11721EBI005

#include <stdio.h>
#define N 20
int soma(int*, int*);
float media(float, float);
int main()
{
	int vet[N], tamanho, somatorio;
	for(int i = 0; i < N; i++) vet[i] = 0; //preenche o vetor com zeros;
	printf("Digite a quantidade de numeros desejados (de 5 a 20): "); scanf("%d", &tamanho); getchar();
	printf("Preencha o vetor: \n");
	for(int i = 0; i < tamanho; i++) { printf("vet[%d]: ", i + 1); scanf("%d", &vet[i]); getchar(); }
	int *primeiro = vet, *ultimo = (vet + tamanho - 1); //ponteiros
	somatorio = soma(primeiro, ultimo);
	float somatorio2 = somatorio, tamanho2 = tamanho;
	printf("Media: %.1f", media(somatorio2, tamanho2));
	return 0;
}
int soma(int *ref, int *x)
{
	return (*x) + ((x == ref) ? 0 : soma(ref, x - 1)); //recursão para a soma de valores de um vetor, endereço por endereço;
}
float media(float somatorio, float tamanho)
{
	return somatorio/tamanho;
}