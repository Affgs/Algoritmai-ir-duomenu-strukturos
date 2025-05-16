#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>

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

void generateReverseArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

int main() {
    const int SIZE = 5000;
    int arr[SIZE];

    generateReverseArray(arr, SIZE);

    clock_t start = clock();
    bubbleSort(arr, SIZE);
    clock_t end = clock();

    double time = double(end - start) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(6);
    cout << "Bubble Sort su 5000 atvirkst. surik. duom.: " << time << " sek.\n";

    return 0;
}