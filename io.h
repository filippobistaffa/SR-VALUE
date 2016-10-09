#ifndef IO_H_
#define IO_H_

// Headers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instance.h"
#include "macros.h"
#include "types.h"

// Reads the solution coalition structure

agent readcs(const char *filename, agent *csbuf, chunk *dr);

#endif /* IO_H_ */
