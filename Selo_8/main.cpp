#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iomanip>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
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
    const int SIZE = 50000;
    std::vector<int> arr(SIZE);

    // Atvirkščiai surikiuoti duomenys
    for (int i = 0; i < SIZE; i++) {
        arr[i] = SIZE - i;
    }

    clock_t start = clock();
    shellSort(arr);
    clock_t end = clock();

    double time = double(end-start)/CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Shell Sort: " << time << " sek.\n";

    return 0;
}