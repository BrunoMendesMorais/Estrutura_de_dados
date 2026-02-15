#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int achaposicao(int ultimo, int primeiro,unsigned int data,unsigned int V[]){
	int meio = trunc((primeiro + ultimo) /2);
	if(V[meio] == data)
		return -1;
	if(ultimo == primeiro && data < V[meio])
		return meio;
	if(ultimo == primeiro && data > V[meio])
		return meio;
	if(data < V[meio]){
		achaposicao(meio,primeiro,data,V);	
	}
	else{
		achaposicao(ultimo,meio+1,data,V);	
	}
}

int add(int posicao,unsigned int V[], unsigned int data,int fim){
	if(posicao == -1)
		return -1;
	int i;
	unsigned int ut = V[posicao];
	V[posicao] = data;
	for(i = posicao+1;i <= fim; i++){
		data = V[i];
		V[i] = ut;
		ut = data;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	
	int tamanho,i,ultPos,posicao,resposta;
	
	printf("Tamho do vetor:");
	scanf("%d",&tamanho);
	
	unsigned int valor, numeros[tamanho];
	
	for(i = 0; i < tamanho; i++){
		numeros[i] = 0;
	}
	
	
	numeros[0] = rand;
	
	for(i = 1; i < tamanho; i++){
		valor = rand();
		posicao = achaposicao(i-1,0,valor,numeros);
		resposta = add(posicao,numeros,valor,i);
		i = i + resposta;
	}
	for(i = 0; i < tamanho-1; i++){
		printf("\n%u",numeros[i]);
	}
	return 0;
}
