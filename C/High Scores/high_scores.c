#include "high_scores.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

int cmp_func(const void *a, const void *b);

int32_t latest(const int32_t *scores, size_t scores_len)
{
    if (scores_len == 0)
        return -1;
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    if (scores_len == 0)
        return -1;
    int32_t highest_score = scores[0];
    for (size_t i = 1; i < scores_len; i++)
    {
        if (scores[i] > highest_score)
            highest_score = scores[i];
    }
    return highest_score;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
    if (scores_len == 0)
        return -1;
    size_t count = scores_len < 3 ? scores_len : 3;
    int32_t *sorted_scores = (int32_t *)malloc(scores_len * sizeof(int32_t));
    for (size_t i = 0; i < scores_len; i++)
        sorted_scores[i] = scores[i];
    qsort(sorted_scores, scores_len, sizeof(int32_t), (int (*)(const void *, const void *))cmp_func);
    for (size_t i = 0; i < count; i++)
        output[i] = sorted_scores[i];
    free(sorted_scores);
    return count;
}

int cmp_func(const void *a, const void *b)
{
    return (*(int32_t *)b - *(int32_t *)a);
}
