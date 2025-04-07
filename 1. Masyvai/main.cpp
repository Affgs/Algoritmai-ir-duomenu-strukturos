#include <iostream>

using namespace std;

//------------------------------------------------------------------------------1---------------------------------------------------------------------------------------

//Ieskome neigiamu elementu suma
void NeigiamuElementuSuma(int masyvas[], int n) {
    int suma = 0;
    int neigEl = 0;
    for (int i = 0; i < n; i++) {
        //Tikrina as elementas yra neigiams ar teigiamas jei neigiamas tesia toliau jei teigiamas praleidzia ir toliau su kitu el daro darba
        if (masyvas[i] < neigEl) {
            suma = suma + masyvas[i];
            neigEl++;
        }
    }
    cout << suma << '\n';
}

//Ieskome elementu sandauga tarp didziausio ir maziausio elementu
int SandaugaTMaxiIrMiniEl(int masyvas[], int n) {
    int maximalus = 0;
for (int i=0; i<n; i++) {
    if (masyvas[i] > maximalus) {
        maximalus = masyvas[i];
    }
    }
    int minimalus = 0;
    for (int i=0; i<n; i++) {
        if (masyvas[i] < minimalus) {
            minimalus = masyvas[i];
        }
    }
}


// Masyvo rikiavimas didejimo tvarka
void rikiavimasMas(int masyvas[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (masyvas[i] < masyvas[j]) {
                swap(masyvas[i], masyvas[j]);
            }
        }


    }

    cout << "Surikiuotas masyvas: \n";
    for (int i = 0; i < n; i++) {
        cout << masyvas[i] << " ";
    }
    cout << '\n';

}

int main() {
    int n;
     cout << "Iveskite norima dydi:\n";
    cin >> n;

    int masyvas[n];

   cout << "Iveskite norimus elementus: \n";
    for (int i = 0; i < n; i++) {
        cin >> masyvas[i];
        cout << masyvas[i] << " ";
    }

     int op = 0;

    while (op != 4) {
        cout << "Programos, kurias galite pasirinkti: \n";
        cout << "1. Neigiamu skaiciu sudetis.\n";
        cout << "2. Sandauga tarp didziausio ir maziausio elemento.\n";
        cout << "3. Masyvo rikiavimas didejimo tvarka.\n";
        cout << "4. Iseiti.\n";
        cin >> op;
        switch (op) {
            case 1:
                NeigiamuElementuSuma(masyvas,n);
                break;
            case 2:
                SandaugaTMaxiIrMiniEl(masyvas, n);
                break;
            case 3:
                rikiavimasMas(masyvas, n);
                break;
            case 4:
                cout << "Jus isejote is programos.\n";
            break;
            default:
                cout << "Tokios pasirinkimo nera. Bandykite dar karta.\n";
        }
    }


    return 0;
}
// ----------------------------------------------------------------------------------------- 2 ---------------------------------------------------------------------------------------------
