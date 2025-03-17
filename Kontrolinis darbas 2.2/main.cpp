#include <iostream>

using namespace std;

// Struktura, kuri saugo saraso elementa
struct Mazgas {
    int duomenys;
    Mazgas* kitas;
    Mazgas* ankstesnis;
    Mazgas(int reiksme) {
        duomenys = reiksme;
        kitas = nullptr;
        ankstesnis = nullptr;
    }
};

// Dvikryptis sarasas
struct Sarasas {
    Mazgas* pradzia;
    Mazgas* pabaiga;

    Sarasas() {
        pradzia = nullptr;
        pabaiga = nullptr;
    }

    // Elementas yra pridedamas i saraso gala
    void prideti(int reiksme) {
        Mazgas* naujas = new Mazgas(reiksme);
        if (pradzia == nullptr) {
            pradzia = naujas;
            pabaiga = naujas;
        } else {
            pabaiga->kitas = naujas;
            naujas->ankstesnis = pabaiga;
            pabaiga = naujas;
        }
    }

    // Funkcija, kuri randa didziausia elementa sarase
    int rastiDidziausia() {
        if (pradzia == nullptr) {
            cout << "Sarasas tuscias." << endl;
            return 0;
        }
        int didziausias = pradzia->duomenys;
        Mazgas* laikinas = pradzia;
        while (laikinas != nullptr) {
            if (laikinas->duomenys > didziausias) {
                didziausias = laikinas->duomenys;
            }
            laikinas = laikinas->kitas;
        }
        return didziausias;
    }
};

// Steko struktura
struct Stekas {
    Mazgas* virsus;

    Stekas() {
        virsus = nullptr;
    }

    // Funkcija, kuri prideda elementa i steka
    void ideti(int reiksme) {
        Mazgas* naujas = new Mazgas(reiksme);
        naujas->kitas = virsus;
        virsus = naujas;
    }

    // Funkcija, kuri pasalina elementa is steko
    void isimti() {
        if (virsus == nullptr) {
            return;
        }
        Mazgas* laikinas = virsus;
        virsus = virsus->kitas;
        delete laikinas;
    }

    // Grazina virsuje esanti elementa
    int virsune() {
        if (virsus == nullptr) {
            return -1;
        }
        return virsus->duomenys;
    }

    // Tikrina, ar stekas tuscias
    bool tuscias() {
        return virsus == nullptr;
    }
};

// Perkelia visus teigiamus skaicius iki pirmo neigiamo i steka
void perkeltiIKolNeigiamas(Sarasas& sarasas, Stekas& stekas) {
    Mazgas* laikinas = sarasas.pradzia;
    while (laikinas != nullptr && laikinas->duomenys >= 0) {
        stekas.ideti(laikinas->duomenys);
        cout << "I steka idetas: " << laikinas->duomenys << endl;
        laikinas = laikinas->kitas;
    }
}

// Iterpia visus nelyginius saraso elementus i steka
void iterptiNelyginius(Sarasas& sarasas, Stekas& stekas) {
    Mazgas* laikinas = sarasas.pradzia;
    while (laikinas != nullptr) {
        if (laikinas->duomenys % 2 != 0) {
            stekas.ideti(laikinas->duomenys);
            cout << "I steka idetas nelyginis: " << laikinas->duomenys << endl;
        }
        laikinas = laikinas->kitas;
    }
}

// Pasalina 5 elementus is steko ir parodo juos ekrane
void pasalinti5(Stekas& stekas) {
    for (int i = 0; i < 5; i++) {
        if (stekas.tuscias()) {
            break;
        }
        cout << "Pasalintas is steko: " << stekas.virsune() << endl;
        stekas.isimti();
    }
}

int main() {
    Sarasas sarasas;
    Stekas stekas;
    int ivestis;

    // Ivedamas sarasas
    cout << "Iveskite saraso elementus (baigti su 0): \n";
    while (cin >> ivestis && ivestis != 0) {
        sarasas.prideti(ivestis);
    }

    int op = 0;

    // Menu ciklas
    while (op != 5) {
        cout << "Pasirinkite veiksma:\n";
        cout << "1. Didziausias elementas.\n";
        cout << "2. Perkelti visus skaicius iki pirmo neigiamo i steka\n";
        cout << "3. Iterpti visus nelyginius saraso elementus i steka\n";
        cout << "4. Pasalinti 5 elementus is steko\n";
        cout << "5. Baigti\n";
        cout << "Jusu pasirinkimas: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Didziausias elementas: " << sarasas.rastiDidziausia() << endl;
                break;
            case 2:
                perkeltiIKolNeigiamas(sarasas, stekas);
                break;
            case 3:
                iterptiNelyginius(sarasas, stekas);
                break;
            case 4:
                pasalinti5(stekas);
                break;
            case 5:
                cout << "Programa baigiama." << endl;
                break;
            default:
                cout << "Tokio pasirinkimo nera. Bandykite dar karta." << endl;
        }
    }

    return 0;
}