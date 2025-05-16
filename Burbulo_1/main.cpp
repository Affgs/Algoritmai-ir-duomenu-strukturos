#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip> // setprecision funkcijai

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

int main() {
    const int SIZE = 5000;
    int arr[SIZE];
    srand(time(0));

    generateRandomArray(arr, SIZE);

    clock_t start = clock();
    bubbleSort(arr, SIZE);
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(6);
    cout << "Bubble Sort su " << SIZE << " elementu uztruko: " << timeTaken << " sekundziu\n";

    return 0;
}