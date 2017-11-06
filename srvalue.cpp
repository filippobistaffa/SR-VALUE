#include "srvalue.h"

template <typename type>
__attribute__((always_inline)) inline
unsigned maskcount(const type *buf, unsigned n, const chunk *mask) {

	unsigned ret = 0;
	do {
		ret += GET(mask, *buf);
		buf++;
	} while (--n);
	return ret;
}

int main(int argc, char *argv[]) {

	agent *csbuf = (agent *)malloc(sizeof(agent) * (K + 1) * N);
	chunk l[C] = {0};

	agent nc = readcs(argv[1], csbuf, l);
	unsigned seed = atoi(argv[2]);

	for (agent i = 0; i < nc; i++)
		QSORT(agent, csbuf + i * (K + 1) + 1, csbuf[i * (K + 1)], LTL);

	meter *sp = createsp(seed);
	value tot = 0;

	for (agent i = 0; i < nc; i++) {
		const value val = srvalue(csbuf + i * (K + 1), maskcount(csbuf + i * (K + 1) + 1, csbuf[i * (K + 1)], l), sp);
		#ifndef CSV
		printbuf(csbuf + i * (K + 1) + 1, csbuf[i * (K + 1)], NULL, NULL, " = ");
		printf("%.2f\n", val);
		#endif
		tot += val;
	}

	#ifdef CSV
	printf("%.2f\n", tot);
	#else
	printf("Solution = %.2f\n", tot);
	#endif

	if (argc == 4) {
		FILE *output = fopen(argv[3], "w+");
		fprintf(output, "%.2f\n", tot);
		fclose(output);
	}

	free(csbuf);
	free(sp);

	return 0;
}
