#include "word_count.h"
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

static int index_of_word(const char *word, word_count_word_t *words) {
    if (!word || !words) return -1;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word, words[i].text) == 0)
            return i;
    }
    return -1;
}

static int update_words(const char *word, int word_len, word_count_word_t *words, int *word_cnt) {
    if (!word || !words)
        return 0;
    int index = index_of_word(word, words);
    if (index != -1) { 
        words[index].count++;
        return *word_cnt;
    }
    if (*word_cnt >= MAX_WORDS)
        return EXCESSIVE_NUMBER_OF_WORDS;

    index = *word_cnt; 
    memcpy(words[index].text, word, word_len);
    words[index].count = 1;
    (*word_cnt)++;
    return *word_cnt;
}

int count_words(const char *sentence, word_count_word_t *words) {
    if (!sentence || !words)
        return -3;
    
    bool word_start = true;
    char word[MAX_WORD_LENGTH + 1] = {'\0'};
    int word_cnt = 0;
    int chr_index = 0;
    for (; *sentence; sentence++) {
        if (!isalnum(*sentence)) {
            if (*sentence == '\'' && !word_start && isalnum(*(sentence+1))) {
                if (chr_index >= MAX_WORD_LENGTH)
                    return EXCESSIVE_LENGTH_WORD;
                word[chr_index++] = '\'';
            } else {
                word_start = true;
                if (chr_index) {
                    int ret = update_words(word, chr_index, words, &word_cnt);
                    if (ret < 0)
                        return ret;
                    chr_index = 0;
                    memset(word, '\0', sizeof(word));
                }
            }
        } else {
            word_start = false;
            if (chr_index >= MAX_WORD_LENGTH)
                return EXCESSIVE_LENGTH_WORD;
            word[chr_index++] = tolower(*sentence);
        }
    }
    if (chr_index) { 
        int ret = update_words(word, chr_index, words, &word_cnt);
        if (ret < 0)
            return ret;
    }
    return word_cnt;
}