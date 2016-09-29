#include "csvalue.h"

static char line[MAXLINE];

// Reads the solution coalition structure

agent readcs(agent *csbuf, chunk *dr, FILE *f) {

	agent ret = 0;

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

	return ret;
}
