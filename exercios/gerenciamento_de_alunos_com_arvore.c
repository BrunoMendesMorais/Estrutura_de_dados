#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
	int ra;
	char nome[50];
	char curso[50];
	float notas[4];
	int anoInicio;
	int idade;
	struct NO* esq;
	struct NO* dir;
} Aluno;


void fim(){
	getchar();
	getchar();
}

float media(int a[]){
	return (a[0]+a[1]+a[2]+a[3])/4;
}

void exibir(Aluno* a){
	int i;
	printf("\nNome: %s",a->nome);
	printf("\nra: %d",a->ra);
	printf("\nIdade: %d",a->idade);
	printf("\n\nCurso: %s",a->curso);
	printf("\nAno de inicio: %d\n",a->anoInicio);
	for(i = 0; i<=3; i++){
		printf("\nNota %d: %.2f",i+1,a->notas[i]);
	}
	printf("\nMedia: %.2f", media(a->notas));
}

Aluno* registrar(int ra){
	int i;	
	Aluno *a = (Aluno*)malloc(sizeof(Aluno));
	printf("ra: %d", ra);
	printf("Nome: ");
	getchar(); 
	fgets(a->nome, 50, stdin);
	printf("Curso:");
	getchar(); 
	fgets(a->curso, 50, stdin);
	printf("Idade:");
	scanf("%d",&a->idade);
	for(i = 0; i<=3; i++){
		printf("Nota %d:",i+1);
		scanf("%f",&a->notas[i]);
	}
	printf("Ano de inicio:");
	scanf("%d",&a->anoInicio);
	a->esq = NULL;
	a->dir = NULL;
	system("cls");
	exibir(a);
	fim();
	return a;
}

Aluno* atribuirArvore(int ra,Aluno* b){
	if(!b){
		return b;	
	if(ra<b->ra)
		b->esq = atribuirArvore(ra,b->esq);
	if(b->ra)
		b->dir = atribuirArvore(ra,b->dir);
	else if(ra == b->ra){
		printf("\n\nRA já cadastrado cadastre o aluno com um RA diferente\n\n");
		return b;
	}
	registrar(ra);
}

void print_arvore(Aluno *no, int espaco){
    int i;
    if (!no) 
        return;
    print_arvore(no->dir, espaco + 1);
    for (i = 0; i < espaco; ++i)
        printf("  ");
    printf("%i\n", no->ra); 
    print_arvore(no->esq, espaco + 1);
}


int main(int argc, char *argv[]) {
	int cont = 1, op, ra, i;
	Aluno alunos[40];
	for(i = 0; i < 40; i++)
    	alunos[i].f = 0;
	do{
		system("cls");
		printf("------------------------------ LISTA DE FUNCOES ------------------------------\n\n");
		printf("[1]-Cadastrar novo aluno\n");
		printf("[2]-Listar arvore inteira\n");
		printf("[3]-Buscar aluno pelo RA\n");
		printf("[4]-Excluir um aluno pelo RA\n");	
		printf("[0]-sair\n\n");
		printf("------------------------------------------------------------------------------\n");
		printf("selecione a funcao desejada:");
		scanf("%d",&op);
		switch(op){
			case 1:
				system("cls");
				printf("RA para cadastro:");
				scanf("%d"$ra);
				registrar(ra,alunos);
				break;
			case 2:
				system("cls");
				print_arvore(alunos,0);
				break;
			case 3:
				system("cls");
				printf("digite o ra");
				scanf("%d",&ra);
				buscaRa(alunos, ra);
				break;
			case 4:
				system("cls");
				printf("digite o ra");
				scanf("%d",&ra);
				excluir(alunos,ra);
				break;
			default:
				cont = 0;
		}
	}while(cont == 1);
	system("cls");
	printf("\n\n------------------------------------------------------------------------------\n\n");
	printf("Fim do programa");
	printf("\n\n------------------------------------------------------------------------------\n\n");
	return 0;
}
