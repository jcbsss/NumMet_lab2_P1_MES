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
	r
	Ap
	Ap_1
	p
	p_1

	for (int iter = 0; iter < N; iter++) {
		/*1*/
		res(N, A, x, b, r);

		/*2*/
		if (norm(N, r) < eps) break;

		/*3*/
		precond(N, A, r, p);

		/*4*/
		if (iter > 0) {
			double Beta;
			//LICZ BETE

			for (int i = 0; i < N; i++) {
				p[i] = p[i] - Beta * p_old[i]
			}
		}

		/*5*/
		double alpha;
		//LICZ ALPHE

		/*6*/
		for (int i = 0; i < N; i++) p_old[i] = p[i];



	}
	}

void multiply_matvec(int N, double** M, double* v, double* r) {
	for (int i = 0; i < N; i++) {
		r[i] = 0;
		for (int j = 0; j < N; j++) {
			r[i] = r[i] + M[i][j] * v[j];
		}
	}
}

void dot_prod(int N, );