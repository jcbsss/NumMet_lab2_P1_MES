//This is the program created on the Numerical Methods lab on Warsaw University on Technology in March2023
//This is Problem from lab2. You can find the description here http://ccfd.github.io/courses/metnum_lab2.html

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "meslib.h"
#include "winbgi2.h"

int MX = 100;                      // number of horizontal elements
int MY = 50;                      // number of vertical elements
int N = 2 * (MX + 1) * (MY + 1); // total DOF

int main()
{
    int* fix;
    double* d;
    double* f;
    double** K, * K_row;

    fix = (int*)calloc(N, sizeof(int));           //alloc constrraints
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
    K_row = (double*)calloc(8 * 8, sizeof(double)); //alloc stiffness matrix
    if (K_row == NULL) {
        perror("main (K_row)");
        exit(1);
    }
    K = (double**)calloc(N, sizeof(double*));
    for (int i = 0; i < N; i++) Kg[i] = &Kg_row[N * i];
    Kg_row = (double*)calloc(N * N, sizeof(double)); //alloc of global stiffness matrix
    if (Kg_row == NULL) {
        perror("main (K_row)");
        exit(1);
    }
    Kg = (double**)calloc(N, sizeof(double*));
    for (int i = 0; i < N; i++) Kg[i] = &Kg_row[N * i];


    for (int i = 0; i < MY + 1; i++) {            //supports declaration
        fix[P(0, i, 0)] = 1;
        fix[P(0, i, 1)] = 1;
    }
    f[P(MX, 0, 1)] = 2;                           //forces declaration
    f[P(MX, 1, 1)] = 1;

    //for (int i = 0; i < MX; i++) {                //creating global matrix
    //    for (int j = 0; j < MY; j++) {
    //        for (int k = 0; k < N; k++) {
    //            g_dof_1 = DOF(elx, ely, dof_1);
    //        }
    //        for (int k = 0; k < N; k++) {
    //            g_dof_2 = DOF(elx, ely, dof_2);
    //        }
    //        K[g_dof_1][g_dof_2] += thick * Md * K[dof_1][dof_2];
    //    }
    //}
    
    gauss(N, K, f, d);                             //SOLUTION
    
    graphics(700, 700);                            //draw a solution
    scale(0, 0.5 * (MY - MX - 3), MX + 3, 0.5 * (MY + MX + 3));
    title("X", "Y", "MES");
    draw(d, f, fix);
    wait();

    free(fix);
    free(d);
    free(f);
    free(K_row);
    free(K);

    return 0;
}