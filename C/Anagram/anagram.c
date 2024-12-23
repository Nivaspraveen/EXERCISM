#include "anagram.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int compare_ignore_case(const void *a, const void *b)
{
    return tolower(*(char *)a) - tolower(*(char *)b);
}

int is_anagram(const char *word1, const char *word2)
{
    size_t len1 = strlen(word1), len2 = strlen(word2);
    if (len1 != len2)
        return 0;

    char *word1_copy = malloc(len1 + 1);
    char *word2_copy = malloc(len2 + 1);
    if (!word1_copy || !word2_copy)
    {
        free(word1_copy);
        free(word2_copy);
        return 0;
    }

    strcpy(word1_copy, word1);
    strcpy(word2_copy, word2);

    qsort(word1_copy, len1, sizeof(char), compare_ignore_case);
    qsort(word2_copy, len2, sizeof(char), compare_ignore_case);

    int result = strcmp(word1_copy, word2_copy) == 0;

    free(word1_copy);
    free(word2_copy);

    return result;
}

void find_anagrams(const char *subject, struct candidates *candidates)
{
    size_t subject_len = strlen(subject);

    char *normalized_subject = malloc(subject_len + 1);
    if (!normalized_subject)
        return;
    for (size_t i = 0; i < subject_len; i++)
    {
        normalized_subject[i] = tolower(subject[i]);
    }
    normalized_subject[subject_len] = '\0';

    for (size_t i = 0; i < candidates->count; i++)
    {
        struct candidate *current = &candidates->candidate[i];
        const char *candidate_word = current->word;

        size_t candidate_len = strlen(candidate_word);
        char *normalized_candidate = malloc(candidate_len + 1);
        if (!normalized_candidate)
            continue;

        for (size_t j = 0; j < candidate_len; j++)
            normalized_candidate[j] = tolower(candidate_word[j]);
        normalized_candidate[candidate_len] = '\0';

        if (strcmp(normalized_subject, normalized_candidate) == 0)
            current->is_anagram = NOT_ANAGRAM;
        else if (is_anagram(normalized_subject, normalized_candidate))
            current->is_anagram = IS_ANAGRAM;
        else
            current->is_anagram = NOT_ANAGRAM;

        free(normalized_candidate);
    }
    free(normalized_subject);
}