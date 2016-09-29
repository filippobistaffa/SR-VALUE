#include "csvalue.h"

static char line[MAXLINE];

#define LTDR(X, Y) (GET(dr, *(X)) == GET(dr, *(Y)) ? (*(X)) < (*(Y)) : GET(dr, *(X)) > GET(dr, *(Y)))

__attribute__((always_inline)) inline
void printc(const agent *c, penny v) {

	agent n = *c;
	printf("[ ");
	while (n--) printf("%u ", *(++c));
	printf("] = %.2f£\n", 0.01 * v);
}

int main(int argc, char *argv[]) {

	agent *csbuf = (agent *)malloc(sizeof(agent) * (K + 1) * N);
	chunk dr[C] = {0};

	// Read input file

	FILE *f = fopen(INPUTFILE, "rt");
	// Skip first 2 lines (N, K)
	fgets(line, MAXLINE, f);
	fgets(line, MAXLINE, f);
	// Read seed
	fgets(line, MAXLINE, f);
	unsigned seed = atoi(line);
	agent nc = readcs(csbuf, dr, f);
	fclose(f);

	for (agent i = 0; i < nc; i++)
		QSORT(agent, csbuf + i * (K + 1) + 1, csbuf[i * (K + 1)], LTDR);

	meter *sp = createsp(seed);
	penny tot = 0;

	for (agent i = 0; i < nc; i++) {
		const penny val = COALVALUE(csbuf + i * (K + 1), GET(dr, csbuf[i * (K + 1) + 1]), sp);
		printc(csbuf + i * (K + 1), val);
		tot += val;
	}

	printf("Solution = %.2f£\n", 0.01 * tot);
	free(csbuf);
	free(sp);

	return 0;
}
