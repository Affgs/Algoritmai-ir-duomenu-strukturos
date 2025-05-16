#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

void bubbleSortOptimized(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Nutraukia, jei jokių keitimų
    }
}

int main() {
    const int SIZE = 10000;
    int arr[SIZE];

    // Generuojame jau surikiuotus duomenis
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    clock_t start = clock();
    bubbleSortOptimized(arr, SIZE);
    clock_t end = clock();

    double time = double(end - start)/CLOCKS_PER_SEC;
    cout << fixed << setprecision(9);
    cout << "Bubble Sort su jau surikiuotais duomenimis: " << time << " sek.\n";

    return 0;
}