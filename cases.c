#include <stdlib.h>

int* bestCase(int n) {
    int* vetor = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        vetor[i] = i;
    }

    return vetor;
}

int* worstCase(int n) {
    int* vetor = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        vetor[i] = (n - 1) - i;
    }

    return vetor;
}

int* averageCase(int n) {
    int* vetor = malloc(sizeof(int) * n);

    // TODO média de 10 execuções distintas.
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % n;
    }

    return vetor;
}