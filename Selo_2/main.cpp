#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

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
    shellSort(arr, SIZE);
    clock_t end = clock();

    double time = double(end - start) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(6);
    cout << "Shell Sort su 5000 atvirkst. surik. duom.: " << time << " sek.\n";

    return 0;
}