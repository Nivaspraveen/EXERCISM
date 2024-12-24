#include "pig_latin.h"
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 512
char *translate(const char *phrase) {
    char *mutable_phrase = calloc(strlen(phrase)+1, sizeof(char));
    strcpy(mutable_phrase, phrase);
    char *token = strtok(mutable_phrase, " ");
    char* new_phrase = calloc(MAX_LENGTH, sizeof(char));

    char* new_word = translate_word(token);
    strcat(new_phrase, new_word);
    free(new_word);
    token = strtok(NULL, " ");
    while(token) {
        char* new_word = translate_word(token);
        strcat(new_phrase, " ");
        strcat(new_phrase, new_word);
        free(new_word);
        token = strtok(NULL, " ");
    }
    free(mutable_phrase);
    return new_phrase;
}

char *translate_word(const char *word) {
    const char *vowels = "aeiouy";
    char *result = malloc(sizeof(char)*(strlen(word) + 3));
    char *presult = result;
    int consonants = 0;
    strcpy(result, word);
    if(word[0] == 'y' && word[1] != 't') consonants += 1;
    while(strchr(vowels, word[consonants]) == NULL) {
        if(word[consonants] == 'q' && word[consonants+1] == 'u') {
            consonants += 2;
            break;
        }
        if(word[consonants] == 'x' && word[consonants+1] == 'r') break;
        consonants += 1;
    }
    strcpy(result, word + consonants);
    strncpy(result + strlen(result), word, consonants);
    strcpy(result + strlen(presult), "ay");
    return result;
}