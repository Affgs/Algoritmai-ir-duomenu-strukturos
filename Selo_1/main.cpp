#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm> // swap funkcijai

using namespace std;

// Shell Sort (Selo rikiavimas)
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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
    shellSort(arr, SIZE);
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Shell Sort su " << SIZE << " elementu uztruko: " << timeTaken << " sekundziu\n";

    return 0;
}