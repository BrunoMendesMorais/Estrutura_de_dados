#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int achaposicao(int ultimo, int primeiro,unsigned int data,unsigned int V[]){
	while(ultimo >= primeiro){
		int meio = (primeiro + ultimo)/2;
		if(V[meio] == data)
			return -1;
		data < V[meio] ? (ultimo = meio-1):(primeiro = meio +1);
	}
	return primeiro;
}

void definirAutomatico(int tamanho,unsigned int numeros[]){
	int posicao,i,valor,resposta;
	for(i = 0; i < tamanho; i++){
		valor = rand();
		posicao = achaposicao(i-1,0,valor,numeros);
		resposta = add(posicao,numeros,valor,i);
		i = i + resposta;
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

int BinariaRec(unsigned int v[],unsigned int val, int esq, int dir){
	int meio = (esq + dir)/2;
	if((v[meio]==val) || (esq>dir))
		return meio;
	v[meio]< val?(BinariaRec(v,val,meio+1,dir)):(BinariaRec(v,val,esq,meio-1));
}

int main(int argc, char *argv[]) {
	int tamanho, i;
	unsigned int val;
	
	printf("Tamanho do vetor:");
	scanf("%d",&tamanho);
	
	unsigned numeros[tamanho];
	
	for(i = 0; i < tamanho; i++){
		numeros[i] = 0;
	}
	definirAutomatico(tamanho,numeros);
	
	printf("Valor deseja procurar:");
	scanf("%u",&val);
	i = BinariaRec(numeros,val,0,tamanho-1);
	
	if(numeros[i] == val)
		printf("o %u foi encontrado na posicao %d",val,i);
	else
		printf("valor nao encontrado");
	return 0;
}
