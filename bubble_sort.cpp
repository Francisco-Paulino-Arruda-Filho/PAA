#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;

void print_array(const vector<int>& arr) {
    for(size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(vector<int>& arr) {
    size_t n = arr.size();
    for(size_t i = 0; i < n - 1; i++) {
        print_array(arr); 
        for(size_t j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*
    Prova de corretude:(Considerando a base como 1)
        - Primeiro laço:
            Invariante de laço: O subvetor de 0 até n - (i-1) está ordenado.
            Caso base: i = 1
                    Como o subvetor só tem um elemento, ele já está ordenado. Pois, n - (i-1) = n - 0 = n e o vetor 
                de 0 até n é um vetor ordenado.
            Passo indutivo: i > 1
                    Nas linhas de 23 a 27, o algoritmo compara o valor do elemento atual com o valor do próximo elemento.
                Se o elemento atual for maior que o próximo, os elementos são trocados de posição. O laço termina quando o vetor chega ao fim.
                Logo, o subvetor de 0 até n - (i - 1) está ordenado.
            Término: i = n
                    O laço termina quando i = n, ou seja, o vetor está ordenado. Já que o vetor estaria
                ordenado até i, e como i = n, o vetor está ordenado.
        - Segundo laço:
            Invariante de laço: O subvetor de 0 até n - (j-1) está ordenado.
            Caso base: j = 1
                    O laço termina quando j = 1, ou seja, o vetor está ordenado.
            Passo indutivo: j > 1   
                    O vetor pega o elemento na posição j e compara com o elemento posterior. 
                Se o elemento atual for maior que o anterior, os elementos são trocados de posição.
            Terminação: j = n - i
                    O laço termina quando j = n - i, ou seja, o vetor está ordenado.
*/

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Assign values directly using the index
    }

    cout << "Array before sorting: ";
    print_array(arr);

    bubble_sort(arr);

    cout << "Array after sorting: ";
    print_array(arr);

    return 0;
}
