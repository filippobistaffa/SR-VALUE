#include "srvalue.h"

#define LTDR(X, Y) (GET(dr, *(X)) == GET(dr, *(Y)) ? (*(X)) < (*(Y)) : GET(dr, *(X)) > GET(dr, *(Y)))

__attribute__((always_inline)) inline
void printc(const agent *c, penny v) {

	agent n = *c;
	printf("[ ");
	while (n--) printf("%u ", *(++c));
	printf("] = %.2f\n", 0.01 * v);
}

int main(int argc, char *argv[]) {

	agent *csbuf = (agent *)malloc(sizeof(agent) * (K + 1) * N);
	chunk dr[C] = {0};

	agent nc = readcs(argv[1], csbuf, dr);
	unsigned seed = atoi(argv[2]);

	for (agent i = 0; i < nc; i++)
		QSORT(agent, csbuf + i * (K + 1) + 1, csbuf[i * (K + 1)], LTDR);

	meter *sp = createsp(seed);
	penny tot = 0;

	for (agent i = 0; i < nc; i++) {
		const penny val = COALVALUE(csbuf + i * (K + 1), GET(dr, csbuf[i * (K + 1) + 1]), sp);
		#ifndef CSV
		printc(csbuf + i * (K + 1), val);
		#endif
		tot += val;
	}

	#ifdef CSV
	printf("%.2f\n", 0.01 * tot);
	#else
	printf("Solution = %.2f\n", 0.01 * tot);
	#endif
	free(csbuf);
	free(sp);

	return 0;
}
