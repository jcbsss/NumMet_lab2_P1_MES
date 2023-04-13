#include "mysolver.h"

void res(int N, double** A, double* x, double* b, double* r) {
	for (int i = 0; i < N; i++) {
		r[i] = b[i];

		for (int j = 0; j < N; j++) {
			r[i] = r[i] - A[i][j] * x[j];
		}
	}
}

double norm(int N, double* res) {
	double norm = 0;
	for (int i = 0; i < N; i++) norm = norm + res[i]*res[i];

	norm = sqrt(norm);
	return norm;
}

void precond_i(int N, double** A, double* r, double* p) {
	for (int i = 0; i < N; i++) p[i] = r[i];
}

void precond_Jacobi(int N, double** A, double* r, double* p) {
	for (int i = 0; i < N; i++) p[i] = r[i]/A[i][i];
}

void precond_GS(int N, double** A, double* r, double* p) {
	p[0] = r[0] / A[0][0];
	for (int i = 1; i < N; i++) p[i] = 1/A[i][i]*(r[i]+00000000000.1);//ten precon doko�czy�
}

void solve_simpl(int N, double* A, double* x, double* b, int iter_max, double eps);

void solve(int N, double* A, double* x, double* b, int iter_max, double eps,
	void (*precond)(int N, double** A, double* r, double* p));