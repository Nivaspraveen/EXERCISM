#ifndef SAY_H
#define SAY_H

#include <stdint.h>

char *spell_out_two_digits(int64_t num);
char *spell_out_three_digits(int64_t num);
char *spell_out_number(int64_t num);
int say(int64_t input, char **ans);

#endif
