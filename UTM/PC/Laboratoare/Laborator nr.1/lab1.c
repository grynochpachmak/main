// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.1: Introducere in limbajul C

#include <stdio.h>
#include <math.h>

int main() {

    printf("=== OPERATORI ARITMETICI ===\n\n");

        int a, b;

        printf("Introduceti o variabila intreaga pentru a: ");
        scanf("%d", &a);

        printf("Introduceti o variabila intreaga pentru b: ");
        scanf("%d", &b);

        printf("\nValoarea pentru a + b = %d\n", a + b);
        printf("Valoarea pentru a - b = %d\n", a - b);
        printf("Valoarea pentru a * b = %d\n", a * b);
        printf("Valoarea pentru a / b = %d\n", a / b);
        printf("Valoarea pentru a %% b = %d\n", a % b);

        printf("Valoarea incrementata pentru a: %d\n", ++a);
        printf("Valoarea decrementata pentru b: %d\n", --b);

    printf("\n=== FUNCTII MATEMATICE ===\n");

        printf("\n= Radacina patrata =\n");
            
            float r;
            printf("Introduce o variabila pentru r: ");
            scanf("%g", &r);
            printf("Radacina patrata din %g este %g.\n", r, sqrt(r));

        printf("\n= Logaritm natural =\n");

            float l;
            printf("Introduce o variabila pentru l: ");
            scanf("%g", &l);
            printf("Logaritm natural din %g este %g.\n", l, log(l));

        printf("\n= Putere =\n");

            float base, exp;
            printf("Introduceti o variabila pentru baza: ");
            scanf("%g", &base);
            printf("Introduceti o variabila pentru exponent: ");
            scanf("%g", &exp);
            printf("Puterea pentru %g ridicat la %g este %g.\n", base, exp, pow(base, exp));

        printf("\n= Modul =\n");

            int m;
            printf("Introduceti o variabila intreaga: ");
            scanf("%d", &m);
            printf("Modulul lui %d este %d.\n", m, abs(m));

    printf("\n=== OPERATORI LOGICI ===\n\n");

        int a2, b2;

        printf("Introduceti o variabila intreaga pentru a: ");
        scanf("%d", &a2);

        printf("Introduceti o variabila intreaga pentru b: ");
        scanf("%d", &b2);

        printf("\n%d este mai mic ca %d? %d\n", a2, b2, a2<b2);
        printf("%d este mai mare ca %d? %d\n", a2, b2, a2>b2);
        printf("%d este mai mic sau egal ca %d? %d\n", a2, b2, a2<=b2);
        printf("%d este mai mare sau egal ca %d? %d\n", a2, b2, a2>=b2);
        printf("%d este egal cu %d? %d\n", a2, b2, a2==b2);
        printf("%d este diferit de %d? %d\n", a2, b2, a2!=b2);

        printf("%d si %d exista? %d\n", a2, b2, a2&&b2);
        printf("%d sau %d exista? %d\n", a2, b2, a2||b2);
        printf("%d nu exista? %d\n", a2, !a2);
        printf("%d nu exista? %d\n", b2, !b2);

    printf("\n=== TIPURI DE DATE ===\n\n");

    char c;
    int i;
    short s;
    long int li;
    unsigned int ui;
    float f;
    double d;

    printf("Introduceti un caracter: ");
    scanf(" %c", &c);

    printf("Introduceti un numar intreg (int): ");
    scanf("%d", &i);

    printf("Introduceti un numar scurt (short): ");
    scanf("%hd", &s);

    printf("Introduceti un numar lung (long int): ");
    scanf("%ld", &li);

    printf("Introduceti un numar intreg fara semn (unsigned int): ");
    scanf("%u", &ui);

    printf("Introduceti un numar real (float): ");
    scanf("%f", &f);

    printf("Introduceti un numar real precis (double): ");
    scanf("%lf", &d);

    printf("\n= Valorile introduse =\n");
    printf("char: %c\n", c);
    printf("int: %d\n", i);
    printf("short: %d\n", s);
    printf("long int: %ld\n", li);
    printf("unsigned int: %u\n", ui);
    printf("float: %.2f\n", f);
    printf("double: %.6f\n", d);

    return 0;
}
