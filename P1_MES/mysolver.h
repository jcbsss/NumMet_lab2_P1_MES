#ifndef _MYSOLVER_H_
#define _MYSOLVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Calculates a residuum of a set of equations*/
void res(int N, double** A, double* x, double* b, double* r);

/*Calculates and returns the form od a vector*/
double norm(int N, double* res);

/*Sets simplified preconditioner, the same as residuum*/
void precond_i(int N, double** A, double* r, double* p);

/*Preconditioner from Jacobi method*/
void precond_Jacobi(int N, double** A, double* r, double* p);

/*Preconditioner from Gauss-Seidel Method*/
void precond_GS(int N, double** A, double* r, double* p);

/*Solver with gminres method; with a pointer to preconditioner function*/
void solve_gminres(int N, double** A, double* x, double* b, int iter_max, double eps,
	void (*precond)(int N, double** A, double* r, double* p));

/*Solve with conjugate gradient method; with a pointer to preconditioner function*/
void solve_cg(int N, double** A, double* x, double* b, int iter_max, double eps,
	void (*precond)(int N, double** A, double* r, double* p));

/*Matrix vector multiplication*/
void multiply_matvec(int N, double** M, double* v, double* r);

/*Dot product*/
double dot_prod(int N, double* x, double* y);

/****************LAB4****************/
/*Mat-vec multiplication devoted to optimisation on lab4*/
void SMult(double* x, double* y);

/*Alternative solver. Optimized*/
void solve_cg_optim(int N, void (*mult)(double*, double*), double* x, double* b, int iter_max, double eps);

#endif