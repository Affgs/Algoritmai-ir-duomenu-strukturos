#include <iostream>
#include <string>

using namespace std;

// Dvikryptis sarasas
struct Sarasas {
    char duom;
    Sarasas* kitas;
    Sarasas* ankstesnis;
};

// Simbolis iterpiamas i gala
void iterptiGalan(Sarasas*& pradzia, Sarasas*& pabaiga, char simbolis) {
    Sarasas* naujas = new Sarasas{simbolis, nullptr, pabaiga};
    if (!pradzia) {
        pradzia = pabaiga = naujas;
    } else {
        pabaiga->kitas = naujas;
        pabaiga = naujas;
    }
}

// Randamas maziausias zodis is saraso
string rastiMaziausiaZodi(Sarasas* pradzia) {
    string maziausiasZodis = "";
    string dabartinisZodis = "";
    Sarasas* temp = pradzia;

    while (temp) {
        if (temp->duom != ' ' && temp->duom != ',' && temp->duom != '.' && temp->duom != '?' && temp->duom != '!' && temp->duom != ';' && temp->duom != ':') {
            dabartinisZodis += temp->duom;
        } else {
            if (dabartinisZodis.length() > 0 && (maziausiasZodis.empty() || dabartinisZodis.length() < maziausiasZodis.length())) {
                maziausiasZodis = dabartinisZodis;
            }
            dabartinisZodis = "";
        }
        temp = temp->kitas;
    }

    // Patikrina paskutini zodi jei nera skyrybos zenklu gale
    if (dabartinisZodis.length() > 0 && (maziausiasZodis.empty() || dabartinisZodis.length() < maziausiasZodis.length())) {
        maziausiasZodis = dabartinisZodis;
    }

    return maziausiasZodis;
}

// Atlaisvina sarasa
void istrintiSarasa(Sarasas*& pradzia) {
    while (pradzia) {
        Sarasas* sekantis = pradzia->kitas;
        delete pradzia;
        pradzia = sekantis;
    }
}

int main() {
    Sarasas* pradzia = nullptr;
    Sarasas* pabaiga = nullptr;
    int pasirinkimas;

    while (pasirinkimas != 4) {
        cout << "Pasirinkite norima funkcija:\n";
        cout << "1. Ivesti sakini\n";
        cout << "2. Spausdinti sarasa\n";
        cout << "3. Surasti maziausia zodi\n";
        cout << "4. Iseiti\n";
        cout << "Jusu pasirinkimas: ";
        cin >> pasirinkimas;
        cin.ignore();

        switch (pasirinkimas) {
            case 1: {
                cout << "Iveskite sakini: ";
                string sakinys;
                getline(cin, sakinys);

                istrintiSarasa(pradzia);
                pabaiga = nullptr;

                for (char c : sakinys) {
                    iterptiGalan(pradzia, pabaiga, c);
                }
                break;
            }
            case 2: {
                cout << "Sarasas: ";
                Sarasas* temp = pradzia;
                while (temp) {
                    cout << temp->duom;
                    temp = temp->kitas;
                }
                cout << endl;
                break;
            }
            case 3: {
                string maziausiasZodis = rastiMaziausiaZodi(pradzia);
                if (!maziausiasZodis.empty()) {
                    cout << "Maziausias zodis: " << maziausiasZodis << endl;
                } else {
                    cout << "Zodis nerastas!\n";
                }
                break;
            }
            case 4: {
                cout << "Baigiame darba.\n";
                break;
            }
            default:
                cout << "Tokio pasirinkimo nera. Bandykite dar karta.\n";
        }
    }

    istrintiSarasa(pradzia);
    return 0;
}