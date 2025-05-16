#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iomanip>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    const int SIZE = 100000;
    std::vector<int> arr(SIZE);
    std::srand(std::time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 1000000;
    }

    clock_t start = clock();
    bubbleSort(arr);
    clock_t end = clock();

    double time = double(end-start)/CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Bubble Sort su 100000 elementu: " << time << " sek.\n";

    return 0;
}