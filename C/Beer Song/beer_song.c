#include "beer_song.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void str_join(char* dest, int num, ...);

void str_join(char* dest, int num, ...){
    va_list valist;
    va_start(valist, num);
    dest[0] = '\0';
    for (int i=0; i<num; i++) {
        char* str = va_arg(valist, char*);
        strcat(dest, str);
    }
    va_end(valist);
}

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    const char* const term1 = " of beer on the wall, ";
    const char* const term2 = " of beer.";
    const char* const term3 = "Take ";
    const char* const term4 = " down and pass it around, ";
    const char* const term5 = "Go to the store and buy some more, ";
    const char* const term6 = " of beer on the wall.";
    
    char bottles[12];
    char left[12];
    
    unsigned row_index = 0;
    for (uint8_t i = 0; i < take_down; i++, start_bottles--) {
        if(start_bottles > 1) {
            bottles[0] = left[0] = 0;
            sprintf(bottles, "%d bottles", start_bottles);
            sprintf(left, "%d bottles", start_bottles-1);
        }
        if(start_bottles == 0){
            str_join(song[row_index++], 4, "No more bottles", term1, "no more bottles", term2);
            str_join(song[row_index++], 3, term5, "99 bottles", term6);
        }
        else if(start_bottles == 1){
            str_join(song[row_index++], 4, "1 bottle", term1, "1 bottle", term2);
            str_join(song[row_index++], 5, term3, "it", term4, "no more bottles", term6);
        }
        else if (start_bottles == 2) {
            str_join(song[row_index++], 4, bottles, term1, bottles, term2);
            str_join(song[row_index++], 5, term3, "one", term4, "1 bottle", term6);
        }
        else {
            str_join(song[row_index++], 4, bottles, term1, bottles, term2);
            str_join(song[row_index++], 5, term3, "one", term4, left, term6);
        }
        if (take_down > 1) row_index++;
    }
}