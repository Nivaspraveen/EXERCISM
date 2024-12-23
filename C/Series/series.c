#include "series.h"
#include <stdlib.h>
#include <string.h>

slices_t slices(char *input_text, unsigned int substring_length) {
    slices_t result;
    result.substring_count = 0;
    result.substring = NULL;
    
    if (substring_length > MAX_SERIES_LENGTH || substring_length == 0 || strlen(input_text) < substring_length) return result;

    unsigned int input_length = strlen(input_text);
    unsigned int count = input_length - substring_length + 1;
    
    result.substring_count = count;
    result.substring = (char **)malloc(count * sizeof(char *));
    
    for (unsigned int i = 0; i < count; i++) {
        result.substring[i] = (char *)malloc((substring_length + 1) * sizeof(char));
        strncpy(result.substring[i], input_text + i, substring_length);
        result.substring[i][substring_length] = '\0';
    }
    
    return result;
}