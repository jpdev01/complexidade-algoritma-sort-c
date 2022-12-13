#include <stdio.h>
#include "bubbleSort.c"

void main() {

    int* melhorCaso(int n) {
        int* vetor = malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++) {
            vetor[i] = i;
        }

        return vetor;
    }

    int* piorCaso(int n) {
        int* vetor = malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++) {
            vetor[i] = (n - 1) - i;
        }

        return vetor;
    }

    int* casoMedio(int n) {
        int* vetor = malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++) {
            vetor[i] = rand() % n;
        }

        return vetor;
    }
}