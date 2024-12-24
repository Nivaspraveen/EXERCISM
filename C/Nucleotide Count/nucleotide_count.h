#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H
#include <stdbool.h>

enum {
    STRAND_A, STRAND_C, STRAND_G, STRAND_T
};

bool is_valid_dna(const char *dna_strand);
char *count(const char *dna_strand);

#endif
