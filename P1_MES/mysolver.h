#ifndef _MYSOLVER_H_
#define _MYSOLVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Calculates a residuum of a set of equations*/
void res(int N, double** A, double* x, double* b, double* r);

/*Calculates and returns the form od a vector*/
double norm(int N, double* res);

/*Sets simplified vector p the same as residuum*/
void precond_i(int N, double** A, double* r, double* p);

/*General solve with a pointer to function*/
void solve(int N, double** A, double* x, double* b, int iter_max, double eps,
	void (*precond)(int N, double** A, double* r, double* p));

/*Solve with conjugate gradient method*/
void solve_cg(int N, double** A, double* x, double* b, int iter_max, double eps,
	void (*precond)(int N, double** A, double* r, double* p));

/*Matrix vector multiplication*/
void multiply_matvec(int N, double** M, double* v, double* r);
		
#endif