#include <stdio.h>
#include <stdlib.h>

#include "bubbleSort.c"
#include "heapSort.c"
#include "cases.c"

int* clone(int v[], int n) {
    int* c = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        c[i] = v[i];
    }

    return c;
}

void teste() {
    //http://www.cplusplus.com/reference/cstdio/fopen/
    FILE *file = fopen("archive.txt", "wt");

    char *varTexto = "texto";
    int varInt = 1;
    float varFloat = 3.1416;

    //fprintf funciona de maneira semelhante a printf http://www.cplusplus.com/reference/cstdio/fprintf/
    fprintf(file, "%s,%d,%f", varTexto, varInt, varFloat);

    char *varTexto2 = "texto com , virgula";
    int varInt2 = 2;
    float varFloat2 = 1.2;

    //Caso o campo possua virgula(,) ele deve ser gravado entre aspas.
    fprintf(file, "\"%s\",%d,%f", varTexto2, varInt2, varFloat2);

    //http://www.cplusplus.com/reference/cstdio/fclose/
    fclose(file);
}

int main() {
    teste();
    int maxSize = 1000;
    printf("tamanho;bubble;insertion;heap;merge;quick;radix");
    for (int currentVectorSize = 1; currentVectorSize <= maxSize; currentVectorSize++) {
        int* vPiorCaso = piorCaso(currentVectorSize);
        int* vMelhorCaso = melhorCaso(currentVectorSize);
        int* vCasoMedio = casoMedio(currentVectorSize);

        // PIOR CASO.
        printf("%i", currentVectorSize);
        printf(";%d", bubbleSort(clone(vPiorCaso, currentVectorSize), currentVectorSize));
        printf(";%d", heapSort(clone(vPiorCaso, currentVectorSize), currentVectorSize));

//
//        printf(";%d", bubbleSort(clone(vMelhorCaso, currentVectorSize), currentVectorSize));
//        printf(";%d", bubbleSort(clone(vCasoMedio, currentVectorSize), currentVectorSize));

//        printf(";%d", heapSort(clone(vPiorCaso, currentVectorSize), currentVectorSize));
//        printf(";%d", heapSort(clone(vMelhorCaso, currentVectorSize), currentVectorSize));
//        printf(";%d", heapSort(clone(vCasoMedio, currentVectorSize), currentVectorSize));

        //TODO padrao csv
        // tamanho;bubble;insertion;heap;merge;quick;radix ->
        // n;n;n;n;n;n;n

        // UM csv pro melhor, um pro medio, um pro pior.
    }
}