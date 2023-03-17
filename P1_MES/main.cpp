//This is the program created on the Numerical Methods lab on Warsaw University on Technology in March2023
//This is Problem from lab2. You can find the description here http://ccfd.github.io/courses/metnum_lab2.html

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "meslib.h"
#include "winbgi2.h"

int MX = 20;                      // number of horizontal elements
int MY = 15;                      // number of vertical elements
int N = 2 * (MX + 1) * (MY + 1); // total DOF

int main()
{
    int* fix;
    double* d;
    double* f;
    double** K, * K_row;

    fix = (int*)calloc(N, sizeof(int)); //alloc constrraints
    if (fix == NULL) {
        perror("main (fix)");
        exit(1);
    }
    d = (double*)calloc(N, sizeof(double));       //alloc displacements
    if (d == NULL) {
        perror("main (d)");
        exit(1);
    }
    f = (double*)calloc(N, sizeof(double));       //alloc forces
    if (f == NULL) {
        perror("main (f)");
        exit(1);
    }
    K_row = (double*)calloc(N*N, sizeof(double)); //alloc stiffness matrix
    if (K_row == NULL) {
        perror("main (K_row)");
        exit(1);
    }
    K = (double**)calloc(N, sizeof(double*));       //alloc stiffness matrix
    for (int i = 0; i < N; i++) K[i] = &K_row[N * i];



    // uzupelnienie globalnej macierzy sztywnosci oraz wektorow wiezow i sil

    for (int i = 0; i < MY + 1; i++) {
        fix[P(0, i, 0)] = 1;
        fix[P(0, i, 1)] = 1;
    }


    // modyfikacja ukladu r-n ze wzgledu na wiezy
    // 
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
}