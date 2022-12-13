#include <stdio.h>
#include <stdlib.h>

#include "utils.c"
#include "bubbleSort.c"
#include "heapSort.c"
#include "cases.c"

int* clone(int v[], int n) {
    int* c = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        c[i] = v[i];
    }

    return c;
}

int main() {
    int n = 10000;
    int* vPiorCaso = piorCaso(n);
    int* vMelhorCaso = melhorCaso(n);
    int* vCasoMedio = casoMedio(n);

    printf("Bubblesort v1\n");
    printf("Pior caso: %d\n", bubbleSort(clone(vPiorCaso, n), n));
    printf("Melhor caso: %d\n", bubbleSort(clone(vMelhorCaso, n), n));
    printf("Caso medio: %d\n", bubbleSort(clone(vCasoMedio, n), n));

    printf("Heapsort\n");
    printf("Pior caso: %d\n", heapSort(clone(vPiorCaso, n), n));
    printf("Melhor caso: %d\n", heapSort(clone(vMelhorCaso, n), n));
    printf("Caso medio: %d\n", heapSort(clone(vCasoMedio, n), n));
}