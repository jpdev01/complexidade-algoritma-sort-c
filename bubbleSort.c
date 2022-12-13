#include <stdio.h>

void swap2(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int bubbleSort(int v[], int n) {
    int contador = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            contador++;
            if (v[i] > v[j]) {
                swap2(v, i, j);
            }
        }
    }

    return contador;
}
