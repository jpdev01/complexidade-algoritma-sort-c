void swap(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void heapify(int v[], int n, int i, int* contador) {
    int raiz = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    ++*contador;
    if (esquerda < n && v[esquerda] > v[raiz]) 
        raiz = esquerda; // Troca esquerda com raiz
    
    ++*contador;
    if (direita < n && v[direita] > v[raiz]) 
        raiz = direita; // Troca direita com raiz

    ++*contador;
    if (raiz != i) { // Verifica se a raiz precisa ser alterada
        swap(v, i, raiz); // Realiza a troca
        heapify(v, n, raiz, contador); // Garante recursivamente o heap máximo
    }
}

int heapSort(int v[], int n) {
    int contador = 0;
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i, &contador);
    }
    
    for (int i = n - 1; i > 0; i--) {
        swap(v, 0, i); 
        heapify(v, i, 0, &contador); 
    }

    return contador;
}
