#include <stdio.h>
#include <math.h>

#define PI 3.1416

int main() {

    float x, y, z;

    printf("Introduceti o valoarea pentru x: ");
    scanf("%g", &x);

    printf("Introduceti o valoarea pentru y: ");
    scanf("%g", &y);

    printf("Introduceti o valoarea pentru z: ");
    scanf("%g", &z);

    float a = (2 * cos(x - (PI / 6))) / ((1 / 2) + pow(sin(y), 2));

    printf("\nPentru formula a = (2 * cos(x - (pi/6))) / ((1/2) + sin^2(y)) = %g\n", a);

    float b = 1 + (pow(z, 2) / (3 + (pow(z, 2) / 5)));

    printf("Pentru formula b = 1 + ((z^2)/(3 + ((z^2)/5)) = %g\n", b);

    return 0;
}
