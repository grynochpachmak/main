#include "data.h"
#include <iostream>
#include <fstream>
using namespace std;

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