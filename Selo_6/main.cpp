#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
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
    shellSort(arr, SIZE);
    clock_t end = clock();

    double time = double(end - start)/CLOCKS_PER_SEC;
    cout << fixed << setprecision(9);
    cout << "Shell Sort su jau surikiuotais duomenimis: " << time << " sek.\n";

    return 0;
}