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
    if (!pradzia) {  // Jeigu sarasas tuscias
        pradzia = pabaiga = naujas;
    } else {  // Jeigu sarasas turi elementu
        pabaiga->kitas = naujas;
        pabaiga = naujas;
    }
}

// Randamas ilgiausias zodis is saraso
string rastiIlgiausiaZodi(Sarasas* pradzia) {
    string ilgiausiasZodis = "";
    string dabartinisZodis = "";
    Sarasas* temp = pradzia;

    while (temp) {
        // Jei simbolis nera tarpas, kablelis, taskas, klaustukas, šauktukas ir t.t. , tai yra zodzio dalis
        if (temp->duom != ' ' && temp->duom != ',' && temp->duom != '.' && temp->duom != '?' && temp->duom != '!' && temp->duom != ';' && temp->duom != ':') {
            dabartinisZodis += temp->duom;
        } else {
            // Jei randame tarpa ar zenkla zodis yra baigiamas
            if (dabartinisZodis.length() > ilgiausiasZodis.length()) {
                ilgiausiasZodis = dabartinisZodis;  // Atnaujinamas ilgiausias zodis
            }
            dabartinisZodis = "";  // Pasalinamas dabartinis zodis
        }
        temp = temp->kitas;
    }

    // PPatikrinamas paskutinis zodis, jei sarasas baigiasi be zenklu
    if (dabartinisZodis.length() > ilgiausiasZodis.length()) {
        ilgiausiasZodis = dabartinisZodis;
    }

    return ilgiausiasZodis;
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
        cout << "3. Surasti ilgiausia zodi\n";
        cout << "4. Iseiti\n";
        cout << "Jusu pasirinkimas: ";
        cin >> pasirinkimas;
        cin.ignore(); // Kad nuskaityti po cin

        switch (pasirinkimas) {
            case 1: {
                cout << "Iveskite sakini: ";
                string sakinys;
                getline(cin, sakinys);

                // Isvalomas senas sarasas
                istrintiSarasa(pradzia);
                pabaiga = nullptr;

                // Sukuriamas naujas sarasas
                for (char c : sakinys) {
                    iterptiGalan(pradzia, pabaiga, c);  // Itepiamas kiekvienas simbolis i sarasa
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
                string ilgiausiasZodis = rastiIlgiausiaZodi(pradzia);
                if (ilgiausiasZodis.length() > 0) {
                    cout << "Ilgiausias zodis: " << ilgiausiasZodis << endl;
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

    istrintiSarasa(pradzia);  // Isvaloma atmintis pries isejima
    return 0;
}