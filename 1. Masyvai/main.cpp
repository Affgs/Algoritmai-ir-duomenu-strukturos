#include <iostream>

using namespace std;

int main() {
    int masyvas[100];
    int n;
    int size_st;

cout << "Iveskite norimus elementus.\n";
cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> masyvas[i];
        cout << masyvas[i] << " ";
    }

    for (int i=0; i<size_st; i++) {
        for (int j=0; j<n; j++) {
            swap(masyvas[i], masyvas[j]);
        }
    }
    return 0;
}
// ----------------------------------------------------------------------------------------- 2 ---------------------------------------------------------------------------------------------

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.