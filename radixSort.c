// Pega o maior elemento da lista
int getMax(int array[], int n, int *contador) {
    int max = array[0];

    ++*contador;
    for (int i = 1; i < n; i++) {

        ++*contador;
        if (array[i] > max) {
            max = array[i];
        }
        ++*contador;
    }
    return max;
}

void countingSort(int array[], int size, int place, int *contador) {
    int output[size + 1];
    int max = (array[0] / place) % 10;

    ++*contador;
    for (int i = 1; i < size; i++) {

        ++*contador;
        if (((array[i] / place) % 10) > max) {
            max = array[i];
        }
    }
    int count[max + 1];

    ++*contador;
    for (int i = 0; i < max; ++i){
        count[i] = 0;
        ++*contador;
    }

    // qtde de elementos
    ++*contador;
    for (int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
        ++*contador;
    }

    // contagem cumulativa
    ++*contador;
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        ++*contador;
    }

    ++*contador;
    for (int i = size - 1; i >= 0; i--) {
        // output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
        ++*contador;
    }

    ++*contador;
    for (int i = 0; i < size; i++) {
        // array[i] = output[i];
        ++*contador;
    }
}

int radixsort(int array[], int size) {
    int contador = 0;
    int max = getMax(array, size, &contador);

    ++contador;
    for (int place = 1; max / place > 0; place *= 10) {
        ++contador;
        countingSort(array, size, place, &contador);
    }

    return contador;
}