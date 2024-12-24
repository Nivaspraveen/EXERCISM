#include "nucleotide_count.h"
#include <stdlib.h>
#include<stdio.h>

char *count(const char *dna_strand) {
    int strands[4] = { 0 };
    char *res;
    for (int i = 0; dna_strand[i] != '\0'; i++) {
        switch (dna_strand[i]) {
            case 'A': 
                strands[STRAND_A]++;
                break;
            case 'C':
                strands[STRAND_C]++;
                break;
            case 'G':
                strands[STRAND_G]++;
                break;
            case 'T':
                strands[STRAND_T]++;
                break;
            default: 
                res = malloc(1);
                res[0] = '\0';
                return res;
        }
    }
    res = malloc(255);
    snprintf(res, 255, "A:%d C:%d G:%d T:%d", strands[STRAND_A], strands[STRAND_C],
            strands[STRAND_G], strands[STRAND_T]);
    return res;
}
