#include "phone_number.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h>

char *phone_number_clean(const char *input) {
    char *cleaned = (char *)malloc(11 * sizeof(char));
    if (cleaned == NULL) return NULL;
    
    int j = 0, len = strlen(input), digit_count = 0;
    for (int k = 0; k < len; k++) {
        if (isdigit(input[k])) digit_count++;
    }
    if (digit_count > 11) {
        strcpy(cleaned, "0000000000");
        return cleaned;
    }

    int i = 0;
    if (input[0] == '+' && input[1] == '1') i = 2;
    else if (input[0] == '1') i = 1;

    for (; i < len; i++) {
        if (isdigit(input[i])) cleaned[j++] = input[i];
        if (j == 10) break;
    }
    cleaned[j] = '\0';
    if (j != 10 || 
        (digit_count == 11 && input[0] != '1' && input[1] != '1') || 
        cleaned[0] < '2' || cleaned[0] >'9' || 
        cleaned[3] < '2' || cleaned[3] > '9') strcpy(cleaned, "0000000000");
    return cleaned;
}