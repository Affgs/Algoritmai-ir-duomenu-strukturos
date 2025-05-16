#include <iostream>
using namespace std;

// Dvikryptes saraso struktura
struct sarasas {
    int duom;
    sarasas* ankstesnis;
    sarasas* kitas;
};

// Steko struktura (vienkryptis sarasas)
struct stekas {
    int duom;
    stekas* kitas;
};

// Iterpia i dvikrypti sarasa i prieki
void iterptiPradzioje(sarasas** pradzia, int duom) {
    sarasas* naujas = new sarasas;
    naujas->duom = duom;
    naujas->ankstesnis = nullptr;
    naujas->kitas = *pradzia;

    if (*pradzia != nullptr)
        (*pradzia)->ankstesnis = naujas;

    *pradzia = naujas;
}

// Pasalina elementa pagal reiksme is dvikrypcio saraso
void pasalinti(sarasas** pradzia, int reiksme) {
    sarasas* laikinas = *pradzia;

    while (laikinas != nullptr && laikinas->duom != reiksme)
        laikinas = laikinas->kitas;

    if (laikinas == nullptr) {
        cout << "Reiksme " << reiksme << " nerasta" << endl;
        return;
    }

    if (laikinas->ankstesnis)
        laikinas->ankstesnis->kitas = laikinas->kitas;
    else
        *pradzia = laikinas->kitas;

    if (laikinas->kitas)
        laikinas->kitas->ankstesnis = laikinas->ankstesnis;

    delete laikinas;
}

// Spausdina dvikrypti sarasa
void spausdintiDvikrypti(sarasas* pradzia) {
    cout << "Dvikryptis sarasas: ";
    while (pradzia != nullptr) {
        cout << pradzia->duom << " ";
        pradzia = pradzia->kitas;
    }
    cout << endl;
}

// Paieska dvikrypciame sarase
bool ieskoti(sarasas* pradzia, int reiksme) {
    while (pradzia != nullptr) {
        if (pradzia->duom == reiksme)
            return true;
        pradzia = pradzia->kitas;
    }
    return false;
}

// Prideda i steka
void detiISteka(stekas** virsus, int duom) {
    stekas* naujas = new stekas;
    naujas->duom = duom;
    naujas->kitas = *virsus;
    *virsus = naujas;
}

// Isima is steko (pop)
int isimtiIsSteko(stekas** virsus) {
    if (*virsus == nullptr) return -1;

    stekas* laikinas = *virsus;
    int duom = laikinas->duom;
    *virsus = (*virsus)->kitas;
    delete laikinas;
    return duom;
}

// Perkelia visus dvikrypcio saraso elementus i steka
void perkeltiIstek(sarasas* pradzia, stekas** virsus) {
    while (pradzia != nullptr) {
        detiISteka(virsus, pradzia->duom);
        pradzia = pradzia->kitas;
    }
}

// Spausdina steka
void spausdintiSteka(stekas* virsus) {
    cout << "Stekas: ";
    while (virsus != nullptr) {
        cout << virsus->duom << " ";
        virsus = virsus->kitas;
    }
    cout << endl;
}

// Pagrindine programa su switch ir meniu
int main() {
    sarasas* dPradzia = nullptr;
    stekas* stekoVirsus = nullptr;

    int op = 0;
    int reiksme;

    while (op != 8) {
        cout << "\nPasirinkite norima programa:\n";
        cout << "1. Iterpti i dvikrypti sarasa\n";
        cout << "2. Pasalinti is dvikrypcio saraso\n";
        cout << "3. Spausdinti dvikrypti sarasa\n";
        cout << "4. Ieskoti dvikrypciame sarase\n";
        cout << "5. Perkelti dvikrypti sarasa i steka\n";
        cout << "6. Spausdinti steka\n";
        cout << "7. Isimti is steko\n";
        cout << "8. Iseiti\n";
        cout << "Jusu pasirinkimas: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Iveskite reiksme: ";
                cin >> reiksme;
                iterptiPradzioje(&dPradzia, reiksme);
                break;
            case 2:
                cout << "Iveskite reiksme, kuria norite pasalinti: ";
                cin >> reiksme;
                pasalinti(&dPradzia, reiksme);
                break;
            case 3:
                spausdintiDvikrypti(dPradzia);
                break;
            case 4:
                cout << "Iveskite reiksme paieskai: ";
                cin >> reiksme;
                if (ieskoti(dPradzia, reiksme))
                    cout << "Reiksme rasta\n";
                else
                    cout << "Reiksme nerasta\n";
                break;
            case 5:
                perkeltiIstek(dPradzia, &stekoVirsus);
                cout << "Duomenys perkelti i steka.\n";
                break;
            case 6:
                spausdintiSteka(stekoVirsus);
                break;
            case 7:
                reiksme = isimtiIsSteko(&stekoVirsus);
                if (reiksme == -1)
                    cout << "Stekas tuscias\n";
                else
                    cout << "Isimta reiksme: " << reiksme << endl;
                break;
            case 0:
                cout << "Iseiti.\n";
                break;
            default:
                cout << "Tokio pasirinkimo nera. Bandykite dar karta.\n";
                break;
        }
    }

    return 0;
}