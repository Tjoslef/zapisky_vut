#include "error.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
    };
    //for reading to struct
    struct ppm * ppm_read(const char * filename);
    //for freeing
    void ppm_free(struct ppm *p);
