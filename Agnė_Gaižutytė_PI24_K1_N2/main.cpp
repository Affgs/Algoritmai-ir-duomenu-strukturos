#include <iostream>

using namespace std;

//Darbas su vienkrypciu sarasu Nr2
//Vienkryptis sarasas

struct sarasas {
    int duom;
    sarasas *kitas;
};

//Elemento pridejimas i sarasa
void ElementoPridejimas(sarasas*& p, int reiksme) {
    sarasas* naujasSarasas = new sarasas;
    naujasSarasas->duom = reiksme;
    naujasSarasas->kitas = p;
    p = naujasSarasas;
}

//Ieskoma is saraso teigiamu elementu suma
int TeigiamuSkSuma(sarasas* p) {
    int suma = 0;
    while (p) {
        if (p->duom > 0) suma += p->duom; //Jei skaicius yra teigiamas ji prideda
        //Prieiname prie kito elemento ikr taip kartojasi iki kol randamik visi teigiami elementai
        p = p->kitas;
    }
    return suma; //Grazinama reiksme
}

int sandauga(sarasas* p) {
    if (!p) return 0; //Tikrinama ar sarasas nera tuscias

    sarasas* maximalus = p; //Ieskosime didziausio elemento
    sarasas* minimalus = p; //Ieskosime maziausio elemento

    //Ieskome absoliuciasias reiksmes
    for (sarasas* temp = p; temp; temp = temp->kitas) {
        if (abs(temp->duom) > abs(maximalus->duom)) maximalus = temp;
        if (abs(temp->duom) < abs(minimalus->duom)) minimalus = temp;
    }

    // Jei mazgai yra greta, nėra tarpinių elementų → grąžiname 1
    if (maximalus->kitas == minimalus || minimalus->kitas == maximalus) {
        return 1;
    }

    // Nustatome teisingą eiliškumą su if/else
    sarasas* pradzia;
    sarasas* pabaiga;

    if (maximalus->duom < minimalus->duom) {
        pradzia = maximalus->kitas;
        pabaiga = minimalus;
    } else {
        pradzia = minimalus->kitas;
        pabaiga = maximalus;
    }

    int sandauga = 1;

    // Apskaičiuojame sandaugą
    for (sarasas* temp = pradzia; temp && temp != pabaiga; temp = temp->kitas) {
        sandauga *= temp->duom;
    }

    return sandauga;

}

//Rikiavimas mazejimo tvarka
void rusiuotiSarasa(sarasas* p) {
    if (!p || !p->kitas) return; // Jei sąrašas tuščias arba turi tik vieną elementą, nieko nedarome

    for (sarasas* i = p; i; i = i->kitas) {
        for (sarasas* j = p; j->kitas; j = j->kitas) {
            if (j->duom > j->kitas->duom) { // Jei esamas elementas didesnis už kitą, sukeičiam (didėjimo tvarka)
                swap(j->duom, j->kitas->duom);
            }
        }
    }
}

int main() {

    sarasas* Sarasas = NULL;
//Vartotojas iveda saraso ilgi pagal save
    int n, reiksme;
    cout << "Iveskite saraso elementu skaiciu.\n";
    cin >> n;

    //Vartotojas iveda saraso elementus
    cout << "Iveskite elementus.\n";
    for (int i = 0; i < n; i++) {
        cin >> reiksme;
        ElementoPridejimas(Sarasas, reiksme);
    }

    //Sukuriamas meniu, kur vartotojas pasirenka norima programa
   int op = 0;

    while (op != 5) {
        cout << "Pasirinkite norima programa.\n";
        cout << "1. Sarasas.\n";
        cout << "2. Elementu suma.\n";
        cout << "3. Sandauga.\n";
        cout << "4. Saraso surikiavimas mazejimo tvarka.\n";
        cout << "5. Iseiti.\n";
        cout << "Jusu pasirinkimas: \n";
        cin >> op;
        switch (op) {
            case 1:
                cout << "Saraso elementai: ";
            for (sarasas* temp = Sarasas; temp; temp = temp->kitas) {
                cout << temp->duom << " ";
            }
            cout << '\n';
                break;
            case 2:
                cout << "Teigiamu elementu suma yra: " << TeigiamuSkSuma(Sarasas) << '\n';
                break;
            case 3:
                cout << "Sandauga tarp minimalaus ir maximalaus elementu: " << sandauga(Sarasas) << '\n';
                break;
            case 4:
                rusiuotiSarasa(Sarasas);
            cout << "Surusiuoti saraso elementai: ";
            for (sarasas* temp = Sarasas; temp; temp = temp->kitas) {
                cout << temp->duom << " ";
            }
            cout << '\n';
                break;
            case 5:
                cout << "Jus isejote is programos.\n";
            default:
                cout << "Tokios operacijos nera. Bandykite dar karta.\n";
        }
    }

    return 0;
}
