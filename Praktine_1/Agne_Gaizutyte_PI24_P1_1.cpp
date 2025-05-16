#include <iostream>

using namespace std;

struct sarasas {
    char simbolis;
    sarasas* kitas;
};

// sukuria nauja sarasa su duotu simboliu
sarasas* sukurtiSarasa(char simbolis) {
    sarasas* m = new sarasas;
    m->simbolis = simbolis;
    m->kitas = nullptr;
    return m;
}

// prideda simboli i saraso gala
void pridetiGale(sarasas*& galva, char simbolis) {
    sarasas* m = sukurtiSarasa(simbolis);
    if (galva == nullptr) {
        galva = m;
    } else {
        sarasas* dabartinis = galva;
        while (dabartinis->kitas != nullptr) {
            dabartinis = dabartinis->kitas;
        }
        dabartinis->kitas = m;
    }
}

// Atspausdina sarasa
void spausdinti(sarasas* galva) {
    while (galva) {
        cout << galva->simbolis;
        galva = galva->kitas;
    }
    cout << '\n';
}

// atlaisvina atmintyje uzimta vieta
void naikinti(sarasas* galva) {
    while (galva) {
        sarasas* temp = galva;
        galva = galva->kitas;
        delete temp;
    }
}

// atlieka perstatyma: simboliai po tarpo i pradzia
sarasas* perkeltiPoTarpo(sarasas* galva) {
    sarasas* dabartinis = galva;
    sarasas* tarp = nullptr;
    while (dabartinis) {
        if (dabartinis->simbolis == ' ') {
            tarp = dabartinis;
            break;
        }
        dabartinis = dabartinis->kitas;
    }
    if (!tarp || !tarp->kitas) {
        return galva; // nieko nekeiciam
    }
    sarasas* naujaPradzia = tarp->kitas;
    sarasas* tail = naujaPradzia;
    while (tail->kitas) {
        tail = tail->kitas;
    }
    tail->kitas = galva;
    tarp->kitas = nullptr;
    return naujaPradzia;
}

int main() {
    int n;
    cout << "Iveskite simboliu skaiciu n: ";
    if (!(cin >> n)) {
        cout << "Neteisingas skaiciaus formatas\n";
        return 1;
    }
    cin.get(); // suvalgo '\n'

    sarasas* galva = nullptr;
    cout << "Iveskite " << n << " simbolius (vienas is ju tarpas):\n";
    for (int i = 0; i < n; ++i) {
        char c;
        cin.get(c);
        pridetiGale(galva, c);
    }

    int op = 0;
    while (op != 3) {
        cout << "\nPasirinkite norima programa:\n";
        cout << "1. Perkelti simbolius po tarpo i pradzia.\n";
        cout << "2. Isvesti sarasa.\n";
        cout << "3. Iseiti.\n";
        cout << "Jusu pasirinkimas: ";
        cin >> op;
        cin.get(); // suvalgo '\n', kad cin.get(c) veiktų vėliau

        switch (op) {
            case 1: {
                // atnaujiname galvos rodyklę
                galva = perkeltiPoTarpo(galva);
                cout << "Rezultatas: ";
                spausdinti(galva);
                break;
            }
            case 2:
                cout << "Sarasas: ";
                spausdinti(galva);
                break;

            case 3:
                cout << "Baigiame darba.\n";
                break;

            default:
                cout << "Tokio pasirinkimo nera. Bandykite dar karta.\n";
                break;
        }
    }

    // atlaisviname atmintį tik vieną kartą, prieš išeinant
    naikinti(galva);
    return 0;
}