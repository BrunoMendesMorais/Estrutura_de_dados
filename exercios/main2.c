#include <stdio.h>
#include <stdlib.h>

typedef struct stNo{
    int info;
    struct stNo *esquerda;
    struct stNo *direita;
} tNo;

tNo *criarNo(int info){
	tNo *no = (tNo *) malloc(sizeof(tNo));
	if(!no)
		exit(0);
	no->esquerda = NULL;
	no->direita = NULL;
	no->info = info;
	return no;
}

tNo* subArvore(int info, tNo *no){
	if(no->info < info ){
		if(!no->direita)
			return no->direita=criarNo(info);
		return subArvore(info, no->direita);
	}
	if(no->info > info){
		if(!no->esquerda){
			return no->esquerda=criarNo(info);
		return subArvore(info, no->esquerda);
		}
	} 
}

void print_arvore(tNo *no, int espaco){
    int i;
    if (!no) // Se não existe nó, retorna
        return;
    print_arvore(no->direita, espaco + 1);
    for (i = 0; i < espaco; ++i)
        printf("  ");
    printf("%i\n", no->info); // Imprime o valor do nó atual
    print_arvore(no->esquerda, espaco + 1);
}

int main(){
    int num;
    tNo *raiz = NULL; // inicializa a raiz
    do {
        printf("Insira um número ou 0 para sair: ");
        scanf("%i", &num);
        if(num != 0) {
            if(!raiz)
                raiz = criarNo(num);
            else
                subArvore(num,raiz);
        }
    } while (num != 0); // Enquanto houver entrada de dados
    print_arvore(raiz, 0); // Imprime árvore
    return 0;
}
