#include <stdio.h>
#include <stdlib.h>

#include "swap.c"
#include "bubbleSort.c"
#include "heapSort.c"
#include "cases.c"
#include "insertionSort.c"
#include "mergeSort.c"
#include "radixSort.c"

int* clone(int v[], int n) {
    int* c = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        c[i] = v[i];
    }

    return c;
}

void runTestAndRecord(FILE *file, int* v, int currentVectorSize) {
    int bubbleSortResult = bubbleSort(clone(v, currentVectorSize), currentVectorSize);
    int insertionSortResult = insertionSort(clone(v, currentVectorSize), currentVectorSize);
    int heapSortResult = heapSort(clone(v, currentVectorSize), currentVectorSize);
    int mergeSortResult = mergeSortPrincipal(clone(v, currentVectorSize), currentVectorSize);
    int radixSortResult = radixsort(clone(v, currentVectorSize), currentVectorSize);
    fprintf(file, "%i,%d,%d,%d,%d,%d\n", currentVectorSize, bubbleSortResult, insertionSortResult, heapSortResult, mergeSortResult, radixSortResult);
}

void main() {
    int maxSize = 1000;
    FILE *worstCaseFile = fopen("/home/asaas/CLionProjects/trabalho/worstCase.csv", "w+");
    FILE *averageCaseFile = fopen("/home/asaas/CLionProjects/trabalho/averageCase.csv", "w+");
    FILE *bestCaseFile = fopen("/home/asaas/CLionProjects/trabalho/bestCase.csv", "w+");

    fprintf(worstCaseFile, "%s", "tamanho;bubble;insertion;heap;merge;radix\n");
    fprintf(bestCaseFile, "%s", "tamanho;bubble;insertion;heap;merge;radix\n");
    fprintf(averageCaseFile, "%s", "tamanho;bubble;insertion;heap;merge;radix\n");

    for (int currentVectorSize = 1; currentVectorSize <= maxSize; currentVectorSize++) {
        int* vWorstCase = worstCase(currentVectorSize);
        int* vAverageCase = averageCase(currentVectorSize);
        int* vBestCase = bestCase(currentVectorSize);

        runTestAndRecord(worstCaseFile, vWorstCase, currentVectorSize);
        runTestAndRecord(averageCaseFile, vAverageCase, currentVectorSize);
        runTestAndRecord(bestCaseFile, vBestCase, currentVectorSize);
    }

    fclose(worstCaseFile);
    fclose(bestCaseFile);
    fclose(averageCaseFile);

    printf("Arquivo csv gerado.\nTrabalho feito por JOAO PEDRO TRUCHINSKI BORBA, EMANOEL DA SILVA DELFINO e LUCAS DE ANDRADE MARTINS");
}