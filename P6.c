//Lucas Guaragna Guedes
//11721EBI005

#include <stdio.h>
#define N 20
int soma(int*, int);
float media(float, float);
int main()
{
	int vet[N], tamanho, somatorio, *p;
	p = (int*)vet; //"Aponta" o ponteiro 'p' para o vetor 'vet';
	for(int i = 0; i < N; i++) vet[i] = 0; //Preenche o vetor com zeros;
	printf("Digite a quantidade de numeros desejados (de 5 a 20): "); scanf("%d", &tamanho); getchar(); //Pede o tamanho desejado para 'vet';
	printf("Preencha o vetor: \n");
	for(int i = 0; i < tamanho; i++) { printf("vet[%d]: ", i + 1); scanf("%d", &vet[i]); getchar(); } //Preenche o vetor, digitando número a número;
	somatorio = soma(p, tamanho);
	float somatorio2 = somatorio, tamanho2 = tamanho; //Transforma, por associação, os ints 'somatorio' e 'tamanho', nos floats 'somatorio2' e 'tamanho2', respectivamente;
	printf("Media: %.1f", media(somatorio2, tamanho2)); //Printa os números na forma 'float' com 1 algarismo após a vírgula;
	return 0;
}
int soma (int *vet, int tamanho)
{
	int aux = 0;
	for(int i = 0; i < tamanho; i++) aux += vet[i]; //Somatorio dos termos de 'vet';
	return aux;
}

float media(float somatorio, float tamanho) { return somatorio/tamanho; }
