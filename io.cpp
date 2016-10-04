#include "srvalue.h"

#define MAXLINE 1000
static char line[MAXLINE];

// Reads the solution coalition structure

agent readcs(const char *filename, agent *csbuf, chunk *dr) {

	agent ret = 0;
	FILE *f = fopen(filename, "r");
	// Skip first 2 lines (N, K)
	fgets(line, MAXLINE, f);
	fgets(line, MAXLINE, f);

	while (fgets(line, MAXLINE, f) != NULL) {
		*csbuf = 0;
		char *pch = strtok(line, " ");
		while (pch != NULL) {
			if (*pch == '*') {
				pch++;
				SET(dr, atoi(pch));
			}
			csbuf[(*csbuf)++ + 1] = atoi(pch);
			pch = strtok(NULL, " ");
		}
		csbuf += K + 1;
		ret++;
	}

	fclose(f);
	return ret;
}
