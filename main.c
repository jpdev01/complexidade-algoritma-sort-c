#include <stdio.h>
#include <stdlib.h>

#include "swap.c"
#include "bubbleSort.c"
#include "heapSort.c"
#include "cases.c"
#include "insertSort.c"

int* clone(int v[], int n) {
    int* c = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        c[i] = v[i];
    }

    return c;
}

void runTestAndRecord(FILE *file, int* v, int currentVectorSize) {
    int bubbleSortResult = bubbleSort(clone(v, currentVectorSize), currentVectorSize);
    int insertionSortResult = insertionsort(clone(v, currentVectorSize), currentVectorSize);
    int heapSortResult = heapSort(clone(v, currentVectorSize), currentVectorSize);
    fprintf(file, "%i,%d,%d,%d", currentVectorSize, bubbleSortResult, insertionSortResult, heapSortResult);
}

void main() {
    int maxSize = 1000;
    FILE *worstCaseFile = fopen("/home/asaas/CLionProjects/trabalho/worstCase.txt", "w+");
    FILE *averageCaseFile = fopen("/home/asaas/CLionProjects/trabalho/averageCase.txt", "w+");
    FILE *bestCaseFile = fopen("/home/asaas/CLionProjects/trabalho/bestCase.txt", "w+");

    fprintf(worstCaseFile, "%s", "tamanho;bubble;insertion;heap;merge;quick;radix");
    fprintf(bestCaseFile, "%s", "tamanho;bubble;insertion;heap;merge;quick;radix");
    fprintf(averageCaseFile, "%s", "tamanho;bubble;insertion;heap;merge;quick;radix");

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

    printf("Arquivo csv gerado.");
}