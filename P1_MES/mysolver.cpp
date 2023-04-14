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
	for (int i = 1; i < N; i++) {
		p[i] = r[i] / A[i][i];
		for (int j = 0; j < i; j++) {
			p[i] = p[i] - A[i][j]*p[j];
		}
	}
}


void solve(int N, double** A, double* x, double* b, int iter_max, double eps,
	void (*precond)(int N, double** A, double* r, double* p)) {
	int i = 0;
}

void solve_cg(int N, double** A, double* x, double* b, int iter_max, double eps,
	void (*precond)(int N, double** A, double* r, double* p)) {
	double* r;
	r = (double*)calloc(N, sizeof(double));
	double* Ap;
	Ap = (double*)calloc(N, sizeof(double));
	double* Ap_old;
	Ap_old = (double*)calloc(N, sizeof(double));
	double* p;
	p = (double*)calloc(N, sizeof(double));
	double* p_old;
	p_old = (double*)calloc(N, sizeof(double));

	for (int iter = 0; iter < N; iter++) {
		/*1*/
		res(N, A, x, b, r);

		/*2*/
		if (norm(N, r) < eps) break; //WILL IT BREAK THE WHOLE FUNCTION OR WHAT

		/*3*/
		precond(N, A, r, p);

		/*4*/
		if (iter > 0) {
			double Beta;
			Beta = dot_prod(N, p, Ap_old) / dot_prod(N, p_old, Ap_old);

			for (int i = 0; i < N; i++) {
				p[i] = p[i] - Beta * p_old[i];
			}
		}

		/*5*/
		double alpha;
		multiply_matvec(N, A, p, Ap);
		alpha = dot_prod(N, r, p) / dot_prod(N, p, Ap);

		for (int i = 0; i < N; i++) x[i] = x[i] + alpha * p[i];

		/*6*/
		for (int i = 0; i < N; i++) p_old[i] = p[i];
		for (int i = 0; i < N; i++) Ap_old[i] = Ap[i];
	}
	}

void multiply_matvec(int N, double** Mtrx, double* vec, double* result) {
	for (int i = 0; i < N; i++) {
		result[i] = 0;
		for (int j = 0; j < N; j++) {
			result[i] = result[i] + Mtrx[i][j] * vec[j];
		}
	}
}

double dot_prod(int N, double* x, double* y) {
	double dot = 0;
	for (int i = 0; i < N; i++) {
		dot = dot + x[i] * y[i];
	}
	return dot;
}