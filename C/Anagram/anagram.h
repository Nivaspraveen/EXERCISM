#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STR_LEN 20

enum anagram_status { UNCHECKED = -1, NOT_ANAGRAM, IS_ANAGRAM };

struct candidate {
   enum anagram_status is_anagram;
   const char *word;
};

struct candidates {
   struct candidate *candidate;
   size_t count;
};

/**
 * @description - determines if any of the words in candidate are anagrams
 *                for subject. Contents of candidate structures may be modified.
 */
int compare_ignore_case(const void *a, const void *b);
int is_anagram(const char *word1, const char *word2);
void find_anagrams(const char *subject, struct candidates *candidates);

#endif
