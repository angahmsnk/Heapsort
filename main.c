#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], const int index1, const int index2) {
    const int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void heapify(int arr[], const int n, const int i) {
    int largest = i;
    const int leftChild = 2 * i + 1;
    const int rightChild = 2 * i + 2;
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;
    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i);
        heapify(arr, --n, 0);
    }
}

int main(void) {

    int tab[50];
    const int length = sizeof(tab) / sizeof(tab[0]);
    for (int i = 0; i < length; i++) {
        tab[i] = rand() % 100 + 1;
    }

    printf("Tablica przed sortowaniem:\n");
    for (int i = 0; i < length; i++) {
        printf("%d, ", tab[i]);
    }
    printf("\n\n");

    heapsort(tab, length);

    printf("Posortowana tablica:\n");
    for (int i = 0; i < length; i++) {
        printf("%d, ", tab[i]);
    }

    return 0;
}