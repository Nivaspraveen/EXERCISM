#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

bool is_digit(char ch);
int luhn_checksum(const char *num);
bool luhn(const char *num);

#endif
