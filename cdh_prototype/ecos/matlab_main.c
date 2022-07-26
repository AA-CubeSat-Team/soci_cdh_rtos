# include "ecos.h"

void callecos(int n, int m, int p, int l, int ncones, double *c, int *Gjc, int *Gir, double *Gpr,
			  double* h, int* q, int* Ajc, int* Air, double *Apr, double *b, double *y) {
	/* Initialize */
	pwork* mywork = ECOS_setup(n, m, p, l, ncones, q, 0, Gpr, Gjc, Gir, Apr, Ajc, Air, c, h, b);
	/* Solve */
	idxint exitflag = ECOS_solve(mywork);
	/* Extract optimal solution */
	int i;
    int N=332; // c_size
	// Save optimal decision vector
	for(i=0;i<N;i++) {
		y[i] = mywork->x[i];
	}
	// Save exitflag
	y[N] = exitflag;
	// Save solution time
	// UPDATE May 25 2021:
	// 	Removing timer.h from everything because it cannot be included in the OBC build
	// y[N+1] = mywork->info->tsetup + mywork->info->tsolve;
	// Clean up memory
	ECOS_cleanup(mywork, 0);
}






