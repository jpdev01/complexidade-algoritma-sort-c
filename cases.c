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

int *averageCase(int n) {
    int *vetor = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        int averageTestTimes = 10;
        // média de 10 execuções distintas.
        for (int media = 0; media < averageTestTimes; media++) {
            vetor[i] += rand() % n;
        }
        vetor[i] = vetor[i] / averageTestTimes;
    }

    return vetor;
}