#include <bits/stdc++.h>
using namespace std;

// Optimizuota Bubble Sort realizacija
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Jei  nei vieno elemento, baigiame ciklą
        if (!swapped)
            break;
    }
}

// Funkcija vektoriaus spausdinimui
void printVector(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr;
    int n, num;

    cout << "Iveskite skaiciu kieki: ";
    cin >> n;

    cout << "Iveskite " << n << " skaicius, atskirtus tarpais arba naujomis eilutemis:\n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    bubbleSort(arr);

    cout << "Surusiuotas masyvas:\n";
    printVector(arr);

    return 0;
}