#ifndef DATA_H
#define DATA_H
#include <string>
using namespace std;

struct rutaAeriana {
    string codZbor;
    string destinatie;
    string oraPlecare;
    string oraSosire;
    float costBilet;
};

void alocare(rutaAeriana*& tab, int& n);
void introducere(rutaAeriana* tab, int n);
void afisare(rutaAeriana* tab, int n);
int cautare(rutaAeriana* tab, int n);
void modificare(rutaAeriana* tab, int n);
void interschimbare(rutaAeriana* tab, int n);
void sortare(rutaAeriana* tab, int n);
void adaugareCap(rutaAeriana*& tab, int& n);
void adaugareCoada(rutaAeriana*& tab, int& n);
void inserareCapElement(rutaAeriana*& tab, int& n);
void inserareCoadaElement(rutaAeriana*& tab, int& n);
void stergere(rutaAeriana*& tab, int& n);
void salvare(rutaAeriana* tab, int n);
void citire(rutaAeriana*& tab, int& n);
void eliberare(rutaAeriana*& tab);

#endif
