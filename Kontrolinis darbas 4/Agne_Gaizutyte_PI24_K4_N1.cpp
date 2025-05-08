#include <iostream>
using namespace std;

// Dvikryptis dinaminis sarasas
struct sarasas {
    int duom;
    sarasas* kitas;
    sarasas* ankstesnis;
};

// Vienkryptis ciklinis sarasas (dekas)
struct dekas {
    int duom;
    dekas* kitas;
};

// Sukuriamas naujas dvikryptis saraso elementas
sarasas* sukurtiDviKrypSar(int duom) {
    sarasas* naujas = new sarasas;
    naujas->duom = duom;
    naujas->kitas = nullptr;
    naujas->ankstesnis = nullptr;
    return naujas;
}

// Iterpiami elementai i saraso gala
void iterpimasElem(sarasas*& pradzia, int duom) {
    sarasas* naujas = sukurtiDviKrypSar(duom);
    if (pradzia == nullptr) {
        pradzia = naujas;
    }
    else {
        sarasas* laikinas = pradzia;
        while (laikinas->kitas != nullptr)
            laikinas = laikinas->kitas;
        laikinas->kitas = naujas;
        naujas->ankstesnis = laikinas;
    }
}

// Spausdinamas dvikryptis sarasas
void spausdinti(sarasas* pradzia) {
    cout << "Dvikryptis sarasas:\n";
    while (pradzia != nullptr) {
        cout << pradzia->duom << " ";
        pradzia = pradzia->kitas;
    }
    cout << '\n';
}

// Elemento paieska
sarasas* paieska(sarasas* pradzia, int duom) {
    while (pradzia != nullptr) {
        if (pradzia->duom == duom)
            return pradzia;
        pradzia = pradzia->kitas;
    }
    return nullptr;
}

// Elemento salinimas
void salinti(sarasas*& pradzia, int duom) {
    sarasas* rasti = paieska(pradzia, duom);
    if (rasti != nullptr) {
        if (rasti->ankstesnis != nullptr)
            rasti->ankstesnis->kitas = rasti->kitas;
        else
            pradzia = rasti->kitas;
        if (rasti->kitas != nullptr)
            rasti->kitas->ankstesnis = rasti->ankstesnis;
        delete rasti;
        cout << "Elementas pasalintas\n";
    }
    else {
        cout << "Elementas nerastas\n";
    }
}

// Perkeliami visi saraso elementai i deka
void perkialimiElemIDeka(sarasas* pradzia, dekas*& priekis, dekas*& galas) {
    while (pradzia != nullptr) {
        dekas* naujas = new dekas;
        naujas->duom = pradzia->duom;
        if (priekis == nullptr) {
            priekis = galas = naujas;
            galas->kitas = priekis;
        }
        else {
            galas->kitas = naujas;
            galas = naujas;
            galas->kitas = priekis;
        }
        pradzia = pradzia->kitas;
    }
}

// Iterpimas i deko prieki
void iterptiIPrieki(dekas*& priekis, dekas*& galas, int duom) {
    dekas* naujas = new dekas;
    naujas->duom = duom;
    if (priekis == nullptr) {
        priekis = galas = naujas;
        naujas->kitas = naujas;
    }
    else {
        naujas->kitas = priekis;
        galas->kitas = naujas;
        priekis = naujas;
    }
}

// Iterpimas i deko gala
void iterptiIGala(dekas*& priekis, dekas*& galas, int duom) {
    dekas* naujas = new dekas;
    naujas->duom = duom;
    if (priekis == nullptr) {
        priekis = galas = naujas;
        naujas->kitas = naujas;
    }
    else {
        naujas->kitas = priekis;
        galas->kitas = naujas;
        galas = naujas;
    }
}

// Spausdinti deka
void spausdintiDeka(dekas* priekis) {
    if (priekis == nullptr) {
        cout << "Dekas tuscias.\n";
        return;
    }
    cout << "Dekas: ";
    dekas* laikinas = priekis;
    do {
        cout << laikinas->duom << " ";
        laikinas = laikinas->kitas;
    } while (laikinas != priekis);
    cout << '\n';
}

// Elemento salinimas is deko priekio
void salintiIsPriekio(dekas*& priekis, dekas*& galas) {
    if (priekis == nullptr)
        return;
    if (priekis == galas) {
        delete priekis;
        priekis = galas = nullptr;
    }
    else {
        dekas* laikinas = priekis;
        priekis = priekis->kitas;
        galas->kitas = priekis;
        delete laikinas;
    }
}

// Elemento salinimas is deko galo
void salintiIsGalo(dekas*& priekis, dekas*& galas) {
    if (galas == nullptr)
        return;
    if (priekis == galas) {
        delete galas;
        priekis = galas = nullptr;
    }
    else {
        dekas* laikinas = priekis;
        while (laikinas->kitas != galas)
            laikinas = laikinas->kitas;
        laikinas->kitas = priekis;
        delete galas;
        galas = laikinas;
    }
}

// Pagrindine programa
int main() {
    sarasas* pradzia = nullptr;
    dekas* priekis = nullptr;
    dekas* galas = nullptr;

    int op = 0;

    while (op != 10) {
        cout << "\nPasirinkite norima funkcija.\n";
        cout << "1. Elemento iterpimas i dvikrypti dinamini sarasa.\n";
        cout << "2. Elemento salinimas is dvikrypcio dinaminio saraso.\n";
        cout << "3. Dvikrypcio dinaminio saraso spausdinimas.\n";
        cout << "4. Sarasas perkialiamas i deka.\n";
        cout << "5. Deko spausdinimas.\n";
        cout << "6. Iterpimas i deko pradzia.\n";
        cout << "7. Iterpimas i deko gala.\n";
        cout << "8. Deko salinimas is priekio.\n";
        cout << "9. Deko salinimas is galo.\n";
        cout << "10. Iseiti.\n";
        cout << "Jusu pasirinkimas: ";
        cin >> op;
        int sk;
        switch (op) {
            case 1:
                cout << "Iveskite skaiciu: ";
            cin >> sk;
            iterpimasElem(pradzia, sk);
            break;
            case 2:
                cout << "Kuri skaiciu norite pasalinti: ";
            cin >> sk;
            salinti(pradzia, sk);
            break;
            case 3:
                spausdinti(pradzia);
            break;
            case 4:
                perkialimiElemIDeka(pradzia, priekis, galas);
            break;
            case 5:
                spausdintiDeka(priekis);
            break;
            case 6:
                cout << "Iveskite skaiciu: ";
            cin >> sk;
            iterptiIPrieki(priekis, galas, sk);
            break;
            case 7:
                cout << "Iveskite skaiciu: ";
            cin >> sk;
            iterptiIGala(priekis, galas, sk);
            break;
            case 8:
                salintiIsPriekio(priekis, galas);
            break;
            case 9:
                salintiIsGalo(priekis, galas);
            break;
            case 10:
                cout << "Programa baigta.\n";
            break;
            default:
                cout << "Tokio pasirinkimo nera. Bandykite dar karta.\n";
        }
    }
    return 0;
}