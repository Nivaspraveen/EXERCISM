#include "matching_brackets.h"
#include <string.h>
#include <stdlib.h>

bool is_paired(const char *input)
{
    char *stack = malloc(strlen(input) + 1);
    if (!stack)
        return false;

    size_t stack_top = 0;
    for (const char *c = input; *c != '\0'; ++c)
    {
        if (*c == '(' || *c == '[' || *c == '{')
            stack[stack_top++] = *c;
        else if (*c == ')' || *c == ']' || *c == '}')
        {
            if (stack_top == 0)
            {
                free(stack);
                return false;
            }
            char top = stack[--stack_top];
            if ((*c == ')' && top != '(') ||
                (*c == ']' && top != '[') ||
                (*c == '}' && top != '{'))
            {
                free(stack);
                return false;
            }
        }
    }
    bool result = (stack_top == 0);
    free(stack);
    return result;
}