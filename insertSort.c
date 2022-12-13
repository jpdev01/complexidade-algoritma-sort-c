int insertionsort(int v[], int n) {
    int pivo, j;
    int contador = 0;

    int i;

    for (i = 1; i < n; i++) {
        pivo = v[i];
        j = i - 1;

        contador++;
        while (j >= 0 && pivo < v[j]) {
            contador++;
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = pivo;
    }

    return contador;
}
