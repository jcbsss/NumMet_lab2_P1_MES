#include "mylib_precond.h"

/*Calculates a residuum of a set of equations*/
void res(int N, double** A, double* x, double* b, double* r) {
	for (int i = 0; i < N; i++) {
		r[i] = b[i];

		for (int j = 0; j < N; j++) {
			r[i] = r[i] - A[i][j] * x[j];
		}
	}
}
/*Calculates and returns the form od a vector*/
double norm(int N, double* res) {
	double norm = 0;
	for (int i = 0; i < N; i++) norm = norm + res[i]*res[i];

	norm = sqrt(norm);
	return norm;
}

/*Sets simplified vector p the same as residuum*/
void precond_i(int N, double** A, double* r, double* p) {
	for (int i = 0; i < N; i++) p[i] = r[i];
}

/*Simplified solve for testing*/
solve_XXX(int N, double* A, double* x, double* b, int iter_max, double eps);

/*General solve with a pointer to function*/
solve(int N, double* A, double* x, double* b, int iter_max, double eps,
	void (*precond)(int N, double** A, double* r, double* p));