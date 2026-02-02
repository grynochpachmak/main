#include <iostream>
#include <fstream>
#include <string>
#include "data.h"
using namespace std;

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
