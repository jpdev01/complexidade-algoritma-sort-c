#include <stdio.h>
#include "swap.c"

int bubbleSort(int v[], int n) {
    int contador = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            contador++;
            if (v[i] > v[j]) {
                swap(v, i, j);
            }
        }
    }

    return contador;
}
