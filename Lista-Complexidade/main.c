#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(){
    printf("\n===== MENU DE ORDENACAO =====\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Shell Sort\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void bubbleSort(int vet[], int tam){
	int troca = 0;
	int aux, i, j;
	for(i=tam-1;i>0;i--){
		troca = 0;
		for(j=0;j<i;j++){
			if(vet[j] > vet[j+1]){
				aux=vet[j];
				vet[j]=vet[j+1];
				vet[j+1]=aux;
				troca =1;
			}
		}	
	}
	
}

void selectionSort(int vet[], int max){
	int min, au, i, x;
	for(i=0;i<max-1;i++){
		min = i;
		for(x=i;x<max;x++){
			if(vet[x]<vet[min])
				min = x;
		}
		au = vet[i];
		vet[i] = vet[min];
		vet[min] = au;
	}
}

void insertionSort(int vet[], int tam){
	
}

void merge(int vec[], int vecSize){
    int mid, i, j, k;
    int *tmp;

    tmp = (int *) malloc(vecSize * sizeof(int));
    if(!tmp) exit(1);

    mid = vecSize / 2;

    i = 0;
    j = mid;
    k = 0;

    while(i < mid && j < vecSize)
        if(vec[i] <= vec[j])
            tmp[k++] = vec[i++];
        else
            tmp[k++] = vec[j++];

    if(i == mid)
        while(j < vecSize)
            tmp[k++] = vec[j++];
    else
        while(i < mid)
            tmp[k++] = vec[i++];

    for(i = 0; i < vecSize; i++)
        vec[i] = tmp[i];

    free(tmp);
}


void mergeSort(int vet[], int tam){
	int mid;
	if(tam > 1){
		mid = tam/2;
		mergeSort(vet,mid);
		mergeSort(vet+mid,tam - mid);
		merge(vet,tam);
	}
}

void quickSort(int v[],int ini, int fim){
	if(ini < fim){
		int posPivo = particionar(v,ini,fim);
		quickSort(v,ini,posPivo-1);
		quickSort(v,posPivo+1,fim);
	}
}

int particionar(int v[], int esq, int dir){
    int posPivo = dir;
    int i, j, aux;

    i = esq;  
    j = dir - 1;  

    while(i < j){
        while(i <= j && v[i] <= v[posPivo]) 
            i++;

        while(j >= i && v[j] >= v[posPivo]) 
            j--;

        if(i < j){
            aux = v[j];
            v[j] = v[i];
            v[i] = aux;
        }
        else
            break;
    }

    aux = v[posPivo]; 
    v[posPivo] = v[i];
    v[i] = aux;

    return i; 
}

void shellSort(int v[], int tam){
	int i, j, evi, gap;

    for (gap = tam / 2; gap > 0; gap /= 2) {
        for (i = gap; i < tam; i++) {
            for (evi = v[i], j = i;
                 j >= gap && v[j - gap] > evi;
                 j -= gap)
            {
                v[j] = v[j - gap];
            }
            v[j] = evi;
        }
    }
}

int main(int argc, char *argv[]) {
	int opt,tam;
	printf("Tamanho do vetor:");
	scanf("%d",&tam);
	int vet[tam];
	
	do{
		menu();
		scanf("%d",&opt);
		switch(opt){
			case 1:
				bubbleSort(vet,tam);
				break;
			case 2:
				selectionSort(vet,tam);
				break;
			case 3:
				insertionSort(vet,tam);
				break;
			case 4:
				mergeSort(vet,tam);
				break;
			case 5:
				quickSort(vet, 0, tam);
				break;
			case 6:
				shellSort(vet,tam);
				break;
		}
	}while(opt);
}
