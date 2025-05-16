#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iomanip>

void optimizedBubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Nutraukia, jei jokių keitimų
    }
}

int main() {
    const int SIZE = 50000;
    std::vector<int> arr(SIZE);

    // Generuojame jau surikiuotus duomenis
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }

    clock_t start = clock();
    optimizedBubbleSort(arr);
    clock_t end = clock();

    double time = double(end-start)/CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Optimizuotas Bubble Sort su " << SIZE
              << " jau surikiuotu elementu: " << time << " sek.\n";

    return 0;
}