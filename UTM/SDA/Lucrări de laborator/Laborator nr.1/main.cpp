#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct rutaAeriana {
    string codZbor;
    string destinatie;
    string oraPlecare;
    string oraSosire;
    float costBilet;
};

void alocare(rutaAeriana*& tab, int& n) {
    cout << "Introduceti numarul de rute: ";
    cin >> n;

    tab = new rutaAeriana[n];
}

void introducere(rutaAeriana* tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nRuta " << i + 1 << ":\n";
        cout << "Cod zbor: ";
        cin >> tab[i].codZbor;
        cout << "Destinatie: ";
        cin >> tab[i].destinatie;
        cout << "Ora plecare: ";
        cin >> tab[i].oraPlecare;
        cout << "Ora sosire: ";
        cin >> tab[i].oraSosire;
        cout << "Cost bilet: ";
        cin >> tab[i].costBilet;
    }
}

void afisare(rutaAeriana* tab, int n) {
    if (n == 0) {
        cout << "Tabloul este gol!";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". "
             << tab[i].codZbor << " | "
             << tab[i].destinatie << " | "
             << tab[i].oraPlecare << " | "
             << tab[i].oraSosire << " | "
             << tab[i].costBilet << " MDL\n";
    }
}

int cautare(rutaAeriana* tab, int n) {
    string cod;
    cout << "Introdu codul zborului: ";
    cin >> cod;

    for (int i = 0; i < n; i++) {
        if (tab[i].codZbor == cod)
            return i;
    }
    return -1;
}

void modificare(rutaAeriana* tab, int n) {
    int poz = cautare(tab, n);

    if (poz == -1) {
        cout << "Poziția nu a fost găsită";
        return;
    }

    cout << "Noua destinatie: ";
    cin >> tab[poz].destinatie;
    cout << "Noul cost: ";
    cin >> tab[poz].costBilet;
}

void interschimbare(rutaAeriana* tab, int n) {
    int i, j;
    cout << "Introdu doua pozitii: ";
    cin >> i >> j;

    rutaAeriana temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

void sortare(rutaAeriana* tab, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tab[i].costBilet > tab[j].costBilet) {
                rutaAeriana temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

void adaugareCap(rutaAeriana*& tab, int& n) {
    rutaAeriana* nou = new rutaAeriana[n + 1];

    for (int i = 0; i < n; i++) {
        nou[i + 1] = tab[i];
    }

    cout << "Cod zbor: ";
    cin >> nou[0].codZbor;
    cout << "Destinatie: ";
    cin >> nou[0].destinatie;
    cout << "Ora plecare: ";
    cin >> nou[0].oraPlecare;
    cout << "Ora sosire: ";
    cin >> nou[0].oraSosire;
    cout << "Cost bilet: ";
    cin >> nou[0].costBilet;

    delete[] tab;
    tab = nou;
    n++;
}

void adaugareCoada(rutaAeriana*& tab, int& n) {
    rutaAeriana* nou = new rutaAeriana[n + 1];

    for (int i = 0; i < n; i++) {
        nou[i] = tab[i];
    }

    cout << "Cod zbor: ";
    cin >> nou[n].codZbor;
    cout << "Destinatie: ";
    cin >> nou[n].destinatie;
    cout << "Ora plecare: ";
    cin >> nou[n].oraPlecare;
    cout << "Ora sosire: ";
    cin >> nou[n].oraSosire;
    cout << "Cost bilet: ";
    cin >> nou[n].costBilet;

    delete[] tab;
    tab = nou;
    n++;
}

void inserareCapElement(rutaAeriana*& tab, int& n) {
    int poz;
    cout << "Introdu pozitia (0 - " << n << "): ";
    cin >> poz;

    if (poz < 0 || poz > n) {
        cout << "Pozitie invalida!\n";
        return;
    }

    rutaAeriana* nou = new rutaAeriana[n + 1];

    for (int i = 0; i < poz; i++) {
        nou[i] = tab[i];
    }

    cout << "Cod zbor: ";
    cin >> nou[poz].codZbor;
    cout << "Destinatie: ";
    cin >> nou[poz].destinatie;
    cout << "Ora plecare: ";
    cin >> nou[poz].oraPlecare;
    cout << "Ora sosire: ";
    cin >> nou[poz].oraSosire;
    cout << "Cost bilet: ";
    cin >> nou[poz].costBilet;

    for (int i = poz; i < n; i++) {
        nou[i + 1] = tab[i];
    }

    delete[] tab;
    tab = nou;
    n++;
}

void inserareCoadaElement(rutaAeriana*& tab, int& n) {
    int poz;
    cout << "Introdu pozitia (0 - " << n - 1 << "): ";
    cin >> poz;

    if (poz < 0 || poz >= n) {
        cout << "Pozitie invalida!\n";
        return;
    }

    rutaAeriana* nou = new rutaAeriana[n + 1];

    for (int i = 0; i <= poz; i++) {
        nou[i] = tab[i];
    }

    cout << "Cod zbor: ";
    cin >> nou[poz + 1].codZbor;
    cout << "Destinatie: ";
    cin >> nou[poz + 1].destinatie;
    cout << "Ora plecare: ";
    cin >> nou[poz + 1].oraPlecare;
    cout << "Ora sosire: ";
    cin >> nou[poz + 1].oraSosire;
    cout << "Cost bilet: ";
    cin >> nou[poz + 1].costBilet;

    for (int i = poz + 1; i < n; i++) {
        nou[i + 1] = tab[i];
    }

    delete[] tab;
    tab = nou;
    n++;
}

void stergere(rutaAeriana*& tab, int& n) {
    int poz;
    cout << "Introdu pozitia (0 - " << n - 1 << "): ";
    cin >> poz;

    if (poz < 0 || poz >= n) {
        cout << "Pozitie invalida!\n";
        return;
    }

    rutaAeriana* nou = new rutaAeriana[n - 1];

    for (int i = 0; i < poz; i++) {
        nou[i] = tab[i];
    }

    for (int i = poz; i < n - 1; i++) {
        nou[i] = tab[i + 1];
    }

    delete[] tab;
    tab = nou;
    n--;
}

void salvare(rutaAeriana* tab, int n) {
    ofstream fout("data.txt");

    if (!fout) {
        cout << "Eroare la deschiderea fisierului!\n";
        return;
    }

    fout << n << endl;

    for (int i = 0; i < n; i++) {
        fout << tab[i].codZbor << ";"
             << tab[i].destinatie << ";"
             << tab[i].oraPlecare << ";"
             << tab[i].oraSosire << ";"
             << tab[i].costBilet << endl;
    }

    fout.close();
    cout << "Datele au fost salvate cu succes in fisier.\n";
}

void citire(rutaAeriana*& tab, int& n) {
    ifstream fin("data.txt");

    if (!fin) {
        cout << "Eroare la deschiderea fisierului!\n";
        return;
    }

    delete[] tab;
    tab = nullptr;
    n = 0;

    fin >> n;
    fin.ignore();

    tab = new rutaAeriana[n];

    for (int i = 0; i < n; i++) {
        getline(fin, tab[i].codZbor, ';');
        getline(fin, tab[i].destinatie, ';');
        getline(fin, tab[i].oraPlecare, ';');
        getline(fin, tab[i].oraSosire, ';');
        fin >> tab[i].costBilet;
        fin.ignore();
    }

    fin.close();
    cout << "Datele au fost citite cu succes din fisier.\n";
}


void eliberare(rutaAeriana*& tab, int& n) {
    if (tab != nullptr) {
        delete[] tab;
        tab = nullptr;
    }
    n = 0;
    cout << "Memoria tabloului a fost eliberata.\n";
}

int main() {
    rutaAeriana* tab = nullptr;
    int n = 0;
    int optiune;

    do {
        cout << "\n===== Meniu Rute Aeriene =====\n";
        cout << "1. Alocare tablou\n";
        cout << "2. Introducere date\n";
        cout << "3. Afisare date\n";
        cout << "4. Cautare element\n";
        cout << "5. Modificare element\n";
        cout << "6. Interschimbare doua elemente\n";
        cout << "7. Sortare dupa cost\n";
        cout << "8. Adaugare element la inceput\n";
        cout << "9. Adaugare element la sfarsit\n";
        cout << "10. Inserare element la o pozitie (inainte)\n";
        cout << "11. Inserare element la o pozitie (dupa)\n";
        cout << "12. Stergere element\n";
        cout << "13. Salvare in fisier\n";
        cout << "14. Citire din fisier\n";
        cout << "15. Eliberare memorie\n";
        cout << "16. Iesire\n";
        cout << "Alegeti o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1: alocare(tab, n); break;
            case 2: introducere(tab, n); break;
            case 3: afisare(tab, n); break;
            case 4: {
                int poz = cautare(tab, n);
                if (poz == -1) cout << "Ruta nu a fost gasita!\n";
                else cout << "Ruta gasita pe pozitia " << poz << endl;
                break;
            }
            case 5: modificare(tab, n); break;
            case 6: interschimbare(tab, n); break;
            case 7: sortare(tab, n); break;
            case 8: adaugareCap(tab, n); break;
            case 9: adaugareCoada(tab, n); break;
            case 10: inserareCapElement(tab, n); break;
            case 11: inserareCoadaElement(tab, n); break;
            case 12: stergere(tab, n); break;
            case 13: salvare(tab, n); break;
            case 14: citire(tab, n); break;
            case 15: eliberare(tab,n); break;
            case 16: cout << "La revedere!\n"; break;
            default: cout << "Optiune invalida!\n"; break;
        }

    } while (optiune != 16);

    eliberare(tab, n);

    return 0;
}
