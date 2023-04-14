//This is the program created on the Numerical Methods lab on Warsaw University on Technology in March2023
//This is Problem from lab2. You can find the description here http://ccfd.github.io/courses/metnum_lab2.html

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "meslib.h"
#include "winbgi2.h"
#include "mysolver.h"

int MX = 30;                      // number of horizontal elements
int MY = 5;                       // number of vertical elements
int N = 2 * (MX + 1) * (MY + 1);  // total DOF

int main()
{
    int* fix;
    double* d;
    double* f;
    double** Kg, * Kg_row;

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
    f[P(MX, 0, 1)] = -1;                           //forces declaration
    f[P(MX, MY, 0)] = -3;

    double thick = 2;
    int g_dof_1, g_dof_2;                   //index in global stiffnes matrix
    for (int elx = 0; elx < MX; elx++) {                //creating global matrix  (using local matricies from the library)
        for (int ely = 0; ely < MY; ely++) {
            for (int dof_1 = 0; dof_1 < 8; dof_1++) {
                g_dof_1 = DOF(elx, ely, dof_1);
                for (int dof_2 = 0; dof_2 < 8; dof_2++) {
                    g_dof_2 = DOF(elx, ely, dof_2);
                    Kg[g_dof_1][g_dof_2] += thick * Md * K[dof_1][dof_2];
                }
            }
        }
    }
   
    for (int i = 0; i < N; i++) {       //configuration of system of equations, based on the fixed elements
        if (fix[i] == 1) {
            for (int j = 0; j < N; j++) {
                Kg[i][j] = 0;
                Kg[j][i] = 0;
            }
            Kg[i][i] = 1;   //ones on the diagonal
            f[i] = 0;       //zero the force here
        }
    }

    //gauss(N, Kg, f, d);                             //SOLUTION basic
    solve_cg(N, Kg, d, f, 30, 1e-8, precond_i);     //SOLUTION using Conjugate Greadient Method

    /*double* residuum;
    residuum = (double*)calloc(N, sizeof(double));
    res(N, Kg, d, f, residuum);
    for (int i = 0; i < N; i++) printf("%lf ", residuum[i]);*/

    graphics(700, 700);                            //draw a solution
    scale(0, 0.5 * (MY - MX - 3), MX + 3, 0.5 * (MY + MX + 3));
    title("X", "Y", "MES");
    draw(d, f, fix);
    wait();

    free(fix);
    free(d);
    free(f);
    free(Kg_row);
    free(Kg);

    return 0;
}