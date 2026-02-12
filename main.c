#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	unsigned int numeros[500];
	unsigned int valor;
	clock_t c,f;
	int tempo;
	
	for(i=0;i<500;i++){
		numeros[i] = rand() % 10;
 	}
 	
	printf("\nQual valor deseja buscar?\n");
	scanf("%u",&valor);
	
	c = clock();
	
	for(i=0;i<500 && numeros[i]!=valor;i++){
		numeros[i];
		usleep(1000);
 	}
 	
 	f = clock();
 	
 	tempo = f-c;
 	
 	if(numeros[i]!=valor){
 		printf("numero nao encontrado");
	 }
	else
		printf("O numero que pediu esta na posicao: %d", i);
	printf("\n\n\ntempo de execucao: %d",tempo);
	 	
	return 0;
	
}
