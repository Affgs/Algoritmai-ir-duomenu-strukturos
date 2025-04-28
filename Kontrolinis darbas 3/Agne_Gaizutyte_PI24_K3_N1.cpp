#include <iostream>

using namespace std;

// Medzio struktura
struct medis {
    int duom;
    medis *desine;
    medis *kaire;
};

// Elementas, naudojamas eilei arba dekui
struct Elementas {
    int duomuo;         // Reiksme sarase
    Elementas* kitas;   // Nuoroda į kitą elementą
};

//Sukuria nauja medzio mazga
medis* naujas_elementas(int reiksme) {
    medis* p;
    p = new medis;
    p->duom = reiksme;
    p->kaire = nullptr;
    p->desine = nullptr;
    return p;
}

//Iterpia nauja elementa i medi
medis* iterpti(medis *saknis, int reiksme) {
    if (saknis == nullptr) //Jeigu medis tuscias
        return naujas_elementas(reiksme);
    if (reiksme > saknis->duom) //Jeigu reikmes didesne eina i desine saka
            saknis->desine = iterpti(saknis->desine, reiksme);
    else //Priesingu atveju i kaire puse
        saknis->kaire = iterpti(saknis->kaire, reiksme);
    return saknis;
}

// Vykdoma paieska jei randa grazina true, o jei neranda grazina false
bool paieska(medis *saknis, int reiksme) {
    if (saknis == nullptr) {
        return false; // jei medis tuscias
    } else if (saknis->duom == reiksme) {
        return true; // jei reiksme rasta
    } else if (reiksme < saknis->duom) {
        return paieska(saknis->kaire, reiksme); // Iesko desineje medzio puseje
    } else {
        return paieska(saknis->desine, reiksme); // Iesko kaireje medzio puseje
    }
}

//Isveda medi is eiles: kaire puse tada sakni o tada desine puse
void spausdinti(medis *saknis) {
    if (saknis != nullptr) {
        spausdinti (saknis->kaire);
        cout << saknis->duom << " ";
        spausdinti (saknis->desine);
    }
}

//Randa didziausia reiksme, kuri bus reikalinga naudojama trynymui
medis* rastiMax(medis *saknis) {
    if (saknis == nullptr)
        return nullptr;
    else if (saknis->desine != nullptr)
        return rastiMax(saknis->desine);
    return saknis;
}

//Salina reiksme is medzio
medis* salinti(medis* saknis, int reiksme) {
    if (saknis == nullptr)
        return saknis;  //Medis yra tuscias
    if (reiksme > saknis->duom)
        saknis->desine = salinti(saknis->desine, reiksme);
    else if (reiksme < saknis->duom)
        saknis->kaire = salinti(saknis->kaire, reiksme);
    else {
        if (saknis->kaire == nullptr && saknis->desine == nullptr) {
            free(saknis);
            return nullptr;
        }
        else if (saknis->kaire == nullptr || saknis->desine == nullptr) {
            medis *temp;
            if (saknis->kaire == nullptr)
                temp = saknis->desine;
            else
                temp = saknis->kaire;
            free(saknis);
            return temp;
        }
        else {
            medis *temp = rastiMax(saknis->kaire);  //Surandama max reiksme kaireje puseje
            saknis->duom = temp->duom;              // Keiciami duomenis
            saknis->kaire = salinti(saknis->kaire, temp->duom); //Salinama sena reiksme
        }
    }
return saknis;
}

// a padvigubina reiksmes
void dvigubinti(medis* saknis) {
    if (saknis != nullptr) {
        dvigubinti(saknis->kaire);
        saknis->duom *= 2;
        dvigubinti(saknis->desine);
    }
}

// b Iterpia elementa i deka t.y. saraso pradzia
void iterptiIDeka(Elementas*& pradzia, int reiksme) {
    Elementas* naujas = new Elementas();
    naujas->duomuo = reiksme;
    naujas->kitas = pradzia;
    pradzia = naujas;
}

// c Iterpia elementa i eile t.y. saraso gala
void iterptiIEile(Elementas*& pradzia, int reiksme) {
    Elementas* naujas = new Elementas();
    naujas->duomuo = reiksme;
    naujas->kitas = nullptr;

    if (pradzia == nullptr) {
        pradzia = naujas;
    } else {
        Elementas* laik = pradzia;
        while (laik->kitas != nullptr)
            laik = laik->kitas;
        laik->kitas = naujas;
    }
}

// b Pasalina visus lyginias reiksmes is medzio ir iraso i deka
medis* pasalintiLyginius(medis* saknis, Elementas*& deka) {
    if (saknis == nullptr) return nullptr;
    saknis->kaire = pasalintiLyginius(saknis->kaire, deka);
    saknis->desine = pasalintiLyginius(saknis->desine, deka);

    if (saknis->duom % 2 == 0) { //lyginis
        iterptiIDeka(deka, saknis->duom); // Iraso i deka
        saknis = salinti(saknis, saknis->duom); // Pasalina is medzio
    }
    return saknis;
}

// c Pasalina visas nelyginias reiksmes is medzio ir iraso i eile
medis* pasalintiNelyginius(medis* saknis, Elementas*& eile) {
    if (saknis == nullptr) return nullptr;
    saknis->kaire = pasalintiNelyginius(saknis->kaire, eile);
    saknis->desine = pasalintiNelyginius(saknis->desine, eile);

    if (saknis->duom % 2 != 0) { //nelyginis
        iterptiIEile(eile, saknis->duom);  // Iraso i eile
        saknis = salinti(saknis, saknis->duom); // Pasalina is medzio
    }
    return saknis;
}

// d Spausdina sarasa panaudojami dekai ir eilei
void spausdintiSarasa(Elementas* pradzia, const char* pavadinimas) {
    cout << pavadinimas << ": ";
    while (pradzia != nullptr) {
        cout << pradzia->duomuo << " ";
        pradzia = pradzia->kitas;
    }
    cout << '\n';
}

int main() {

    medis* saknis = nullptr;     // Medzio saknis
    Elementas* deka = nullptr;   // Dekas lyginiu laikymui
    Elementas* eile = nullptr;   // Eile nelyginiu laikymui

    int op = 0;
    int skaicius;

    //Sukuriamas vartotojo meniu
    while(op != 9) {
        cout << "Pasirinkite norima funkcija.\n";
        cout << "1. Iterpimas.\n";
        cout << "2. Paieska.\n";
        cout << "3. Medzio spauzdinimas.\n";
        cout << "4. Salinimas.\n";
        cout << "5. Dvigubinimas.\n";
        cout << "6. Lyginiu reiksmiu salinimas ir irasymas i deka.\n";
        cout << "7. Nelyginiu reiksmiu salinimas ir irasymas i eile.\n";
        cout << "8. Deko ir eiles spauzdinimas.\n";
        cout << "9. Isejimas.\n";
        cout << "Jusu pasirinkimas:\n";
        cin >> op;
        switch (op) {
            case 1:
                int kiek;
            cout << "Kiek skaiciu norite ivesti: \n";
            cin >> kiek;

            for (int i = 0; i < kiek; ++i) {
                cout << "Skaicius #" << i + 1 << ": ";
                cin >> skaicius;
                saknis = iterpti(saknis, skaicius);
            }
                break;
            case 2:
                cout << "Ieskoti: ";
                cin >> skaicius;
            if (paieska(saknis, skaicius))
                cout << "Rastas\n";
            else
                cout << "Nerastas\n";
                break;
            case 3:
                cout << "Medis: ";
                spausdinti(saknis);
                 cout << '\n';
                break;
            case 4:
                cout << "Salinti: ";
                cin >> skaicius;
                saknis = salinti(saknis, skaicius);
                break;
            case 5:
                dvigubinti(saknis);
                cout << "Padvigubinta\n";
                break;
            case 6:
                saknis = pasalintiLyginius(saknis, deka);
                cout << "Lyginiai perkelti i deka\n";
                break;
            case 7:
                saknis = pasalintiNelyginius(saknis, eile);
                cout << "Nelyginiai perkelti i eile\n";
                break;
            case 8:
                spausdintiSarasa(deka, "Dekos turinys");
                spausdintiSarasa(eile, "Eiles turinys");
                break;
            case 9:
                cout << "Jus isejote is programos.\n";
                break;
            default:
                cout << "Tokio pasirinkimo nera. Bandykite dar karta.\n";
        }

    }

    return 0;
}