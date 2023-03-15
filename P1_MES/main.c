//This is the program created on the Numerical Methods lab on Warsaw University on Technology in March2023
//This is Problem from lab2. You can find the description here http://ccfd.github.io/courses/metnum_lab2.html

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "meslib.h"
#include "winbgi2.h"

int MX = 1;                      // liczba elementow w poziomie
int MY = 1;                      // liczba elementow w pionie
int N = 2 * (MX + 1) * (MY + 1); // calkowita liczba stopni swobody

int main()
{
    // deklaracja wskaznika i alokacja tablicy wiezow
    int* fix;

    fix = (int*)calloc(N, sizeof(int));
    if (fix == NULL) {
        perror("main (fix)");
        exit(1);
    }

    // pozostale deklaracje i alokacje pamieci

    // uzupelnienie globalnej macierzy sztywnosci oraz wektorow wiezow i sil

    // modyfikacja ukladu r-n ze wzgledu na wiezy

    // rozwiazanie ukladu za pomoca funkcji gauss

    // rysowanie rozwiazania
    graphics(700, 700);
    scale(0, 0.5 * (MY - MX - 3), MX + 3, 0.5 * (MY + MX + 3));
    title("X", "Y", "MES");
    draw(d, f, fix);
    wait();

    // zwolnienie pamieci
    free(fix);

    return 0;
}e <math.h>