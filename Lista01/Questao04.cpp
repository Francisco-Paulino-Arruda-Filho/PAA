#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            print_array(arr, n);
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*
    Prova de corretude:
    - Primeiro laço:
    Invariante de laço: O subvetor de 0 até i - 1 está ordenado.
    Caso base: i = 1
        Como o subvetor só tem um elemento, ele já está ordenado. Pois, i - 1 = 0 e o vetor 
        de 0 até 0 é um vetor ordenado.
    Passo indutivo: i > 1
            Nas linhas de 10 a 16, o algoritmo guarda o valor do elemento atual em key
        e compara seu valor com o resto do vetor, que está a frente no vetor. Se o elemento for maior
        a troca é feita entre o elemento atual do vetor e o valor maior que ele. O laço termina quando o
        vetor chega ao fim. O elemento é inserido na posição correta e a posição que estava o elemento recebe o valor da key.
        Logo, o subvetor de 0 até i está ordenado.
    Término: i = n
            O laço termina quando i = n, ou seja, o vetor está ordenado. Já que o vetor estaria
        ordenado até i, e como i = n, o vetor está ordenado.
    - Segundo laço:
    Invariante de laço: O subvetor de 0 até j - 1 está ordenado.
    Caso base: j = 0
        O laço termina quando j = 0, ou seja, o vetor está ordenado.
    Passo indutivo: j > 0
            Dentro do while o algoritmo compara o valor do elemento atual com o valor do elemento anterior se o 
        elemento atual for menor que o anterior, o algoritmo troca os valores de posição. O laço termina quando o vetor
        chega ao fim ou o elemento atual for maior que o anterior. O elemento é inserido na posição correta e a posição que estava o 
        elemento recebe o valor da key.
            Logo, o vetor está ordenado para os elementos de 0 até j - 1
    Término: j = 0
            O laço termina quando j = 0, ou seja, o vetor está ordenado.
*/

int main() {
    int n;
    scanf("%d", &n);

    // Inicializa a semente do gerador de números aleatórios
    srand(time(NULL));

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    insertionSort(arr, n);
    print_array(arr, n);

    return 0;
}
