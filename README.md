# Aulas de Estrutura de Dados - 2026
Temas tratados
* Métodos de Pesquisa e ordenação
* Árvores e suas generalizações
* Complexidade e eficiência de algoritmos
---
## Aula 1 - Introdução a EDD 2

Nesta aula foi feita um pequena revisão de EDD 1 e apresentação dos temas tratados em EDD 2, e abordar a importancia da estrutura de dados

**Exercicio proposto:** <br>`Criação de um vetor de 500 unsigned int, peça para o usuario o numero desejado, informe a posição que o valor foi encontrado ou informe que não foi encontrado e em ambos os casos, exiba o tempo de execução em millisegundos.`

Para o calculo de tempo foi necessario importar as seguintes bibliotecas:
```c
#include <time.h> //Calculo de tempo
#include <unistd.h> //Causar pequnos atrasos 
```
---
## Aula 2 - Busca Sequencial

Nesta aula foi tratado termologia basica importancia e aplicações de Método de busca além da apresentação do tema principal Busca sequêncial.

**Exercicio proposto:** <br>`Implementação recursiva do algoritmo pedido na aula anterior`

## Aula 3 - Busca Binária

Nesta aula foi tratada a termologia basica, Apresentado o funcionamento do da Busca binária e mostrado o exemplo em código da versão iterativa.
```c
int PesquisaBinaria(int vet[], int chave, int tam){
    int inf = 0;
    int sup = tam - 1;
    int meio;

    while(inf <= sup){
        meio = (inf + sup) / 2;  // automaticamente truncado

        if(chave == vet[meio])
            return meio;

        if(chave < vet[meio])
            sup = meio - 1;
        else
            inf = meio + 1;
    }

    return -1;  // não encontrado
}
```
**Exercicio proposto:** <br>`Implemente a versão recursiva da busca binária, passando 4 parâmetros pré determinados, e calcule o tempo de execução`

**Exercicio Complementar:** <br>
`Implementem uma função para verificar se um vetor está ordenado ou não. A função pode retornar 0 ou 1, refletindo a não ordenação ou ordenação, respectivamente.`
