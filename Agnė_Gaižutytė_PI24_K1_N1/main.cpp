#include <iostream>

using namespace std;

//Pirma uzduotis su masyvais

//Ieskome neigiamu elementu sandaugos
int SandaugaNeigiamaisElementais(int masyvas[], int n ) {
    int san = 1;
    int neigElIeskojimas = 0; //skaiciuoja kiek yra neigiamu elementu
    for (int i = 0; i < n; i++) {
        if (masyvas[i] < 0) {
            san = san * masyvas[i];
            neigElIeskojimas++;
        }

    }

    cout << "Sandauga elementu yra: \n" << san << '\n';

    //Ieskoma ar yra neigiamu elementu jei yra grazina reiksme, o jei nera isveda 0
    if (neigElIeskojimas == 0) {
        return 0;
    }
        return san;
}

//Surandame maximalu elementa ir tada iki jo suskaiciuojame elementu suma
int sumaTeigElPriesMaxEl(int masyvas[], int n) {
    //Ieskoma maximali reiksme
    int Maximalus = 0;
    for (int i = 1; i < n; i++) {
        if (masyvas[i] > masyvas[Maximalus]) {
            Maximalus = i; //pvz reiksme didziausia kuri buvo is visu elementu yra 9
        }
    }
//Apskaiciave Maximaluji elementa randama suma elementu kurie yra pries ji
    int suma = 0;
    for (int i = 0; i < Maximalus; i++) {
        if (masyvas[i] > 0) {
            //Pvz skaiciai pries elementa 9 buvo 5 4 1 9 6 2 tai bus 5+4+1=10 ir suma bus 10
            suma = suma + masyvas[i];
        }
    }
    return suma;
}

//Apverciame masyva
int MasyvoApvertimas(int masyvas[], int n) {
    // ciklas vyksta iki masyvo vidurio ir keiciame elementus is abieju ju pusiu
    for (int i = 0; i < n/2; i++) {
       int temp = masyvas[i]; //Laikinai saugomos elementu reiksmes
        masyvas[i] = masyvas[n-1-i]; // Paskutinis elementas pereina i pirmo elemento vieta
        masyvas[n-1-i] = temp; // Pirmas elementas pereina i paskutinio elemento vieta
    }

    cout << "Apversto elemento isdestymas: \n";
    for (int i = 0; i < n; i++) {
        cout << masyvas[i] << " ";
    }
}

int main() {

    //Yra nezinomas masyvo dydis todel vartotojas gali pasirinkti pats jo dydi.
    int n;
    cout << "Iveskine masyvo dydi.\n";
    cin >> n;

    //Vartotojas iveda masyvo dydi ir po to norimus elementus.
    //Iveda tiek elementu kiek reikia pagal pasirinkta dydi.
    int masyvas[n];
    for (int i = 0; i < n; i++) {
        cin >> masyvas[i];
    }

    //Sukuriamas vartotojo meniu, kur gali pasirinkti norima programa
    int op = 0;

    while (op != 4) {
        cout << "Pasirinkite norima programa:\n";
        cout << "1. Sandauga visu neigiamu elementu.\n";
        cout << "2. Suma teigiamu elementu einancio pries pirmaji maksimalu elementa.\n";
        cout << "3. Apverstas masyvas.\n";
        cout << "4. Iseiti.\n";
        cout << "Jusu pasirinkimas:\n";
        cin >> op;
        switch (op) {
            case 1:
                SandaugaNeigiamaisElementais(masyvas, n);
                break;
            case 2:
                //Isvedama reiksme yra sumos
                cout << "Sumos reiksme yra: " << sumaTeigElPriesMaxEl(masyvas, n) << '\n';
                break;
            case 3:
                MasyvoApvertimas(masyvas, n);
                break;
            case 4:
                cout << "Jus isejote is programos pasirinkimo.\n";
                break;
            default:
                cout << "Tokio pasirinkimo nera bandykite dar karta.\n";
        }

    }


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.