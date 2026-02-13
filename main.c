#include <stdio.h>
#include <time.h>
#include <unistd.h>

void main(int argc, char *argv[]) {
	int i,tempo;
	unsigned int valor, numeros[500];
	clock_t c,f;
	
	for(i=0;i<500;i++){
		numeros[i] = rand() % 10;
 	}
 	
	printf("Qual valor deseja buscar?\n");
	scanf("%u",&valor);
	
	c = clock();
	for(i=0;i<500 && numeros[i]!=valor;i++){
		usleep(1000);
 	}
 	f = clock();
 	
 	tempo = f-c;
 	numeros[i]!=valor ? printf("numero nao encontrado"):printf("O numero que pediu esta na posicao: %d", i);
	printf("\n\n\ntempo de execucao: %d",tempo);
}
