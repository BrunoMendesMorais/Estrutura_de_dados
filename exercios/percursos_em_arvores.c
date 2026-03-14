#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    struct No* esquerda;
    struct No* direita;
    int data;
}no;

no* criaNo(int valor) {
    no *novo = (no*) malloc(sizeof(no));
    novo->data = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

no *atribuirNo(int data,no *raiz){
    if(raiz == NULL)
        return criaNo(data);
    if(raiz->data > data)
        raiz->esquerda = atribuirNo(data, raiz->esquerda);
    if(raiz->data < data)
        raiz->direita = atribuirNo(data, raiz->direita);
    return raiz;
}

void listaIn(no *raiz){
    if(!raiz)
        return;
    listaIn(raiz->esquerda);
    printf(" %d ",raiz->data);
    listaIn(raiz->direita);
    return;
}

void listaPos(no *raiz){
    if(!raiz)
        return;
    listaPos(raiz->esquerda);
    listaPos(raiz->direita);
    printf(" %d ",raiz->data);
    return;
}

void listaPre(no *raiz){
    if(!raiz)
        return;
    printf(" %d ",raiz->data);
    listaPre(raiz->esquerda);
    listaPre(raiz->direita);
    return;
}

no *CriarCopia(no *copia, no *original){
    if(!original)
        return NULL;
    copia = criaNo(original->data);
    copia->esquerda = CriarCopia(copia->esquerda,original->esquerda);
    copia->direita = CriarCopia(copia->direita,original->direita);
    return copia;
}

no *desalocar(no *raiz){
    if(!raiz)
        return NULL;
    desalocar(raiz->esquerda);
    listaIn(raiz->direita);
    free(raiz);
    return NULL;
}

void print_arvore(no *no, int espaco){
    int i;
    if (!no) 
        return;
    print_arvore(no->direita, espaco + 1);
    for (i = 0; i < espaco; ++i)
        printf("  ");
    printf("%i\n", no->data); 
    print_arvore(no->esquerda, espaco + 1);
}

int main()
{
    int data;
    no *raiz = NULL;
    scanf("%d",&data);
    raiz = criaNo(data);
    do{
        scanf("%d",&data);
        atribuirNo(data, raiz);
    }while(data != 0);
    printf("\nTravessia Pre-Ordem\n");
    listaPre(raiz);
    printf("\n\nTravessia In-Ordem\n");
    listaIn(raiz);
    printf("\n\nTravessia Pos-Ordem\n");
    listaPos(raiz);
	no *raizCopia;
    raizCopia = CriarCopia(raizCopia, raiz);
    printf("\n\nArvore Original\n");
    print_arvore(raiz,0);
    printf("\nArvore Copia\n");
    print_arvore(raizCopia,0);
    return 1;
}
