#ifndef _MYLIB_PRECOND_H_
#define _MYLIB_PRECOND_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void res(int N, double** A, double* x, double* b, double* r);

double norm(int N, double* res);

void precond_i(int N, double** A, double* r, double* p);

void solve(int N);

#endif