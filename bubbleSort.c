int bubbleSort(int v[], int n) {
    int contador = 0;

    ++contador;
    for (int i = 0; i < n - 1; i++) {

        ++contador;
        for (int j = i + 1; j < n; j++) {
            ++contador;
            if (v[i] > v[j]) {
                swap(v, i, j);
            }

            ++contador;
        }

        ++contador;
    }

    return contador;
}
