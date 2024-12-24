#include "protein_translation.h"
#include <string.h>

#define STOP_CODON 100  
#define INVALID_CODON 101  

proteins_t proteins(const char *const rna) {
    proteins_t res = { .valid = true, .count = 0 };
    for (size_t i = 0; i < strlen(rna); i += 3) {
        const char *codon = rna + i;
        int protein = 
            !strncmp("AUG", codon, 3) ? Methionine :
            (!strncmp("UUU", codon, 3) || !strncmp("UUC", codon, 3)) ? Phenylalanine :
            (!strncmp("UUA", codon, 3) || !strncmp("UUG", codon, 3)) ? Leucine :
            (!strncmp("UCU", codon, 3) || !strncmp("UCC", codon, 3) || 
             !strncmp("UCA", codon, 3) || !strncmp("UCG", codon, 3)) ? Serine :
            (!strncmp("UAU", codon, 3) || !strncmp("UAC", codon, 3)) ? Tyrosine :
            (!strncmp("UGU", codon, 3) || !strncmp("UGC", codon, 3)) ? Cysteine :
            !strncmp("UGG", codon, 3) ? Tryptophan :
            (!strncmp("UAA", codon, 3) || !strncmp("UAG", codon, 3) || 
             !strncmp("UGA", codon, 3)) ? STOP_CODON : INVALID_CODON;

        res = (protein == STOP_CODON) ? res : 
              (protein == INVALID_CODON) ? (proteins_t){ .valid = false, .count = res.count } : 
              (res.proteins[res.count++] = (protein_t)protein, res);
        if (!res.valid || protein == STOP_CODON) return res;
    }
    return res;
}
