#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm> // swap funkcijai

using namespace std;

// Bubble Sort (Burbulo rikiavimas)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Jei jokiu keitimu - masyvas jau surikiuotas
    }
}

// Sugeneruoja atsitiktinius duomenis
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Skaiciai nuo 0 iki 9999
    }
}

int main() {
    const int SIZE = 5000;
    int arr[SIZE];

    srand(time(0)); // Atsitiktiniu skaiciu generatoriaus inicializavimas

    // Generuojame atsitiktinius duomenis
    generateRandomArray(arr, SIZE);

    // Pradedame laiko matavima
    clock_t start = clock();
    bubbleSort(arr, SIZE);
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Bubble Sort su " << SIZE << " elementu uztruko: " << timeTaken << " sekundziu\n";

    return 0;
}