#include <stdio.h>
#include <stdlib.h>

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
    int maxSize = 1000;
    printf("tamanho;bubble;insertion;heap;merge;quick;radix");
    for (int currentVectorSize = 1; currentVectorSize <= maxSize; currentVectorSize++) {
        int* vPiorCaso = piorCaso(currentVectorSize);
        int* vMelhorCaso = melhorCaso(currentVectorSize);
        int* vCasoMedio = casoMedio(currentVectorSize);

        printf("%i", currentVectorSize);
        printf(";%d", bubbleSort(clone(vPiorCaso, currentVectorSize), currentVectorSize));
        printf(";%d", heapSort(clone(vPiorCaso, currentVectorSize), currentVectorSize));
//        printf(";%d", bubbleSort(clone(vMelhorCaso, currentVectorSize), currentVectorSize));
//        printf(";%d", bubbleSort(clone(vCasoMedio, currentVectorSize), currentVectorSize));

//        printf(";%d", heapSort(clone(vPiorCaso, currentVectorSize), currentVectorSize));
//        printf(";%d", heapSort(clone(vMelhorCaso, currentVectorSize), currentVectorSize));
//        printf(";%d", heapSort(clone(vCasoMedio, currentVectorSize), currentVectorSize));

        //TODO padrao csv
        // tamanho;bubble;insertion;heap;merge;quick;radix ->
        // n;n;n;n;n;n;n

        // UM csv pro melhor, um pro medio, um pro pior.
    }
}