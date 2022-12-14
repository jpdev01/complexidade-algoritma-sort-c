// Merge sort in C

#include <stdio.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r, int *contador)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    ++*contador;
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
        ++*contador;
    }
    ++*contador;
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
        ++*contador;
    }
    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    ++*contador;
    while (i < n1 && j < n2)
    {
        ++*contador;
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
        ++*contador;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    ++*contador;
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        ++*contador;
    }
    ++*contador;
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
        ++*contador;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r, int *contador)
{
    ++*contador;
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, contador);
        mergeSort(arr, m + 1, r, contador);

        // Merge the sorted subarrays
        merge(arr, l, m, r, contador);
    }
}

// Print the array
/*
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
        printf("\n");
    }
    */

int mergeSortPrincipal(int v[], int n)
{
    int contador = 0;
    mergeSort(v, 0, n - 1, &contador);
    return contador;
}
// Driver program
//int main()
//{
//    printf("%d", mergeSortPrincipal(arr, size));
//}