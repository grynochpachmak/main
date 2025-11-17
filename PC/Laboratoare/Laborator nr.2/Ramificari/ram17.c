// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a găsi toate rădăcinile unei ecuații pătratice.

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Avand forma ax^2 + bx + c = 0, introduceti datele:\n");

    printf("Pentru a: ");
    scanf("%lf", &a);
    printf("Pentru b: ");
    scanf("%lf", &b);
    printf("Pentru c: ");
    scanf("%lf", &c);

    double d = b*b - 4*a*c;

    if (d > 0) {
        double x1 = (-b - sqrt(d)) / (2*a);
        double x2 = (-b + sqrt(d)) / (2*a);
        printf("Radacinile sunt: x1 = %g, x2 = %g\n", x1, x2);
    } 
    else if (d == 0) {
        double x = -b / (2*a);
        printf("Radacina este: x = %g\n", x);
    } 
    else {
        printf("Ecuatia nu are radacini reale.\n");
    }

    return 0;
}