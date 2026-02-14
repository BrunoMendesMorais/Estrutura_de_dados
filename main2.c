#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int achaposicao(int U, int P,unsigned int data,unsigned int V[]){
	int M = (U + P) /2;
	if(U == 0)
		return M;
	if(M == U && data < V[M])
		return M-1;
	if(M == U && data > V[M])
		return M+1;
	if(V[M] == data || data == 0)
		return -1;
	if(V[M] < data)
		achaposicao(M-1,P,data,V);
	achaposicao(U,M+1,data,V);
}

int add(int M,unsigned int V[], unsigned int data,int T){
	if(M == -1)
		return -1;
	int i;
	unsigned int ut = V[M];
	V[M] = data;
	for(i = M;i != T+1; i++)
		V[i] = ut;
	return 0;
}

int main(int argc, char *argv[]) {
	int tamanho,i,ultPos,posicao,resposta;
	
	printf("Tamho do vetor:");
	scanf("%d",&tamanho);
	
	unsigned int valor, numeros[tamanho];
	
	for(i = 0; i < tamanho; i++){
		ultPos = i;
		valor = i;
		posicao = achaposicao(ultPos,0,valor,numeros);
		resposta = add(posicao,numeros,valor,i);
		i = i + resposta;
	}
	for(i = 0; i < tamanho; i++){
		printf("\n%u",numeros[i]);
	}
	return 0;
}
