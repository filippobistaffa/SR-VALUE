#ifndef IO_H_
#define IO_H_

// Prints the content given buffer

#include <iostream>
template <typename type>
__attribute__((always_inline)) inline
void printbuf(const type *buf, unsigned n, const char *name = NULL) {

	if (name) printf("%s = [ ", name);
	else printf("[ ");
	while (n--) cout << *(buf++) << " ";
	printf("]\n");
}

// Reads the solution coalition structure

agent readcs(const char *filename, agent *csbuf, chunk *dr);

#endif /* IO_H_ */
