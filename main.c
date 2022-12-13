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

void runTestAndRecord(FILE *file, int* v, int currentVectorSize) {
    int piorCasoBubbleSort = bubbleSort(clone(v, currentVectorSize), currentVectorSize);
    int piorCasoHeapSort = heapSort(clone(v, currentVectorSize), currentVectorSize);
    fprintf(file, "%i,%d,%d", currentVectorSize, piorCasoBubbleSort, piorCasoHeapSort);
}

int main() {
    int maxSize = 1000;
    FILE *piorCasoFile = fopen("/home/asaas/CLionProjects/trabalho/piorCaso.txt", "w+");
    FILE *melhorCasoFile = fopen("/home/asaas/CLionProjects/trabalho/melhorCaso.txt", "w+");
    FILE *casoMedioFile = fopen("/home/asaas/CLionProjects/trabalho/casoMedio.txt", "w+");

    fprintf(piorCasoFile, "%s","tamanho;bubble;insertion;heap;merge;quick;radix");
    fprintf(melhorCasoFile, "%s","tamanho;bubble;insertion;heap;merge;quick;radix");
    fprintf(casoMedioFile, "%s","tamanho;bubble;insertion;heap;merge;quick;radix");

    for (int currentVectorSize = 1; currentVectorSize <= maxSize; currentVectorSize++) {
        int* vPiorCaso = piorCaso(currentVectorSize);
        int* vCasoMedio = piorCaso(currentVectorSize);
        int* vMelhorCaso = piorCaso(currentVectorSize);

        runTestAndRecord(piorCasoFile, vPiorCaso, currentVectorSize);
        runTestAndRecord(casoMedioFile, vCasoMedio, currentVectorSize);
        runTestAndRecord(melhorCasoFile, vMelhorCaso, currentVectorSize);
    }
    fclose(piorCasoFile);
    fclose(melhorCasoFile);
    fclose(casoMedioFile);
}