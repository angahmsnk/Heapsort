#include <stdio.h>
#include <stdlib.h>

// Funkcja zamieniająca dwa elementy w tablicy
void swap(int arr[], const int index1, const int index2) {
    const int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

// Funkcja budująca kopiec maksymalny
void heapify(int arr[], const int n, const int i) {
	
    int largest = i;                  // Indeks największego elementu
    const int leftChild = 2 * i + 1;  // Lewe dziecko
    const int rightChild = 2 * i + 2; // Prawe dziecko

    // Sprawdź, czy lewe dziecko jest większe od korzenia
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // Sprawdź, czy prawe dziecko jest większe od największego elementu
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // Jeśli największy element nie jest korzeniem, zamień i rekursywnie wywołaj heapify
    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

// Funkcja implementująca Heapsort
void heapsort(int arr[], int n) {
	
    // Budowa kopca maksymalnego
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Ekstrakcja elementów z kopca
    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i);     	// Zamień największy element na koniec
        heapify(arr, --n, 0); 	// Odbuduj kopiec
    }
}

int main(void) {
	
    // Inicjalizacja tablicy testowej
    int rand(void);
    int tab[20];
    const int length = sizeof(tab) / sizeof(tab[0]);

    // Wypełnienie tablicy losowymi liczbami od 1 do 100
    for (int i = 0; i < length; i++) {
        tab[i] = rand() % 100 + 1;
    }

    // Wyświetlenie tablicy przed sortowaniem
    printf("Tablica przed sortowaniem:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n\n");

    // Sortowanie tablicy za pomocą Heapsort
    heapsort(tab, length);

    // Wyświetlenie posortowanej tablicy
    printf("\nTablica po sortowaniu:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", tab[i]);
    }

    printf("\n");
    return 0;
}