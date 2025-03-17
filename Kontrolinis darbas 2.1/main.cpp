#include <iostream>

using namespace std;

// Struktura kur stekas realizuotas kaip vienkryptis sarasas
struct Stekas {
    int duomenys; // Duomenis
    Stekas* kitas; // Nurodo i kita elementa
};

Stekas* pradzia = nullptr; // Rodo i steko pradzia

// Inicijuoja steką
void steko_init() {
    pradzia = nullptr;
}

// Prideda elementa i steka
void ideti(int reiksme) {
    Stekas* naujas = new Stekas{reiksme, pradzia};
    pradzia = naujas;
}

// Paaalina ir grązina viršutini steko elementa
int isimti() {
    if (!pradzia) {
        cout << "Stekas tuscias! \n";
        return -1;
    }
    int reiksme = pradzia->duomenys;
    Stekas* laikinas = pradzia;
    pradzia = pradzia->kitas;
    delete laikinas;
    return reiksme;
}

// Patikrina ar stekas tuscias
bool tuscias() {
    return pradzia == nullptr;
}

// Isveda visus steko elementus
void spausdintiSteka() {
    if (!pradzia) {
        cout << "Stekas tuscias.\n";
        return;
    }
    Stekas* laikinas = pradzia;
    cout << "Steko turinys: ";
    while (laikinas) {
        cout << laikinas->duomenys << " ";
        laikinas = laikinas->kitas;
    }
    cout << endl;
}

// Struktura dvipusiam cikliniam sarasui
struct DvipusisCiklinisMazgas {
    int duomenys; // Duomenis
    DvipusisCiklinisMazgas* kitas; // Nurodo i kita elementa
    DvipusisCiklinisMazgas* ankstesnis; // Nurodo i ankstesni elementa
};

DvipusisCiklinisMazgas* saraso_pradzia = nullptr; // Rodo i saraso pradzia

// Prideda elementa i dvipusi ciklini sarasa
void sarasas_ideti(int reiksme) {
    DvipusisCiklinisMazgas* naujas = new DvipusisCiklinisMazgas{reiksme, nullptr, nullptr};
    if (!saraso_pradzia) {
        saraso_pradzia = naujas;
        saraso_pradzia->kitas = saraso_pradzia;
        saraso_pradzia->ankstesnis = saraso_pradzia;
    } else {
        DvipusisCiklinisMazgas* paskutinis = saraso_pradzia->ankstesnis;
        paskutinis->kitas = naujas;
        naujas->ankstesnis = paskutinis;
        naujas->kitas = saraso_pradzia;
        saraso_pradzia->ankstesnis = naujas;
    }
}

// Pakeicia visus saraso neigiamus elementus i teigiamus
void keistiNeigiamus() {
    if (!saraso_pradzia) return;
    DvipusisCiklinisMazgas* laikinas = saraso_pradzia;
    do {
        if (laikinas->duomenys < 0)
            laikinas->duomenys = -laikinas->duomenys;
        laikinas = laikinas->kitas;
    } while (laikinas != saraso_pradzia);
}

// Pasalina elementus is saraso iki pirmo 0 elemento
void isimtiIkiNulio() {
    if (!saraso_pradzia) return;
    DvipusisCiklinisMazgas* laikinas = saraso_pradzia;
    while (laikinas->duomenys != 0) {
        cout << laikinas->duomenys << " ";
        DvipusisCiklinisMazgas* salinti = laikinas;
        laikinas = laikinas->kitas;
        if (salinti == saraso_pradzia) {
            if (saraso_pradzia->kitas == saraso_pradzia) {
                saraso_pradzia = nullptr;
            } else {
                saraso_pradzia = saraso_pradzia->kitas;
                saraso_pradzia->ankstesnis = salinti->ankstesnis;
                salinti->ankstesnis->kitas = saraso_pradzia;
            }
        } else {
            salinti->ankstesnis->kitas = salinti->kitas;
            salinti->kitas->ankstesnis = salinti->ankstesnis;
        }
        delete salinti;
    }
    cout << endl;
}

// Isspausdina saraso elementus
void spausdinti() {
    if (!saraso_pradzia) return;
    DvipusisCiklinisMazgas* laikinas = saraso_pradzia;
    do {
        cout << laikinas->duomenys << " ";
        laikinas = laikinas->kitas;
    } while (laikinas != saraso_pradzia);
    cout << endl;
}

int main() {
    steko_init(); // Inicijuojame steką
    int kiekis, reiksme;
    cout << "Kiek skaiciu norite ivesti i steka? \n";
    cin >> kiekis;

    // Vartotojas iveda elementus i steka
    cout << "Iveskite " << kiekis << " skaicius:\n";
    for (int i = 0; i < kiekis; i++) {
        cin >> reiksme;
        ideti(reiksme);
    }

    int op = 0;

    while (op != 5) {
        cout << "Pasirinkite norima programa:\n";
        cout << "1. Stekas.\n";
        cout << "2. Pasalintu elementu irasimas i dvikrypti sarasa.\n";
        cout << "3. Pakeistas sarasas is neigiamos reiksmes ir teigiama.\n";
        cout << "4. Pasalinti elementai iki pirmojo 0 elemento.\n";
        cout << "5. Iseiti.\n";
        cin >> op;
            switch (op) {
                case 1:
                    spausdintiSteka();
                break;
                case 2:
                    while (!tuscias()) {
                        sarasas_ideti(isimti());
                    }
                cout << "Duomenys perkelti i dvipusi ciklini ssrasa.\n";
                spausdinti();
                break;
                case 3:
                    keistiNeigiamus();
                cout << "Pakeistas sarasas. \n";
                spausdinti();
                break;
                case 4:
                isimtiIkiNulio();
                break;
                case 5:
                    cout << "Jus isejote is programos.\n";
                break;
                default:
                    cout << "Tokio pasirinkimo nera. Bandykite dar karta.\n";;
        }
    }

    return 0;
}