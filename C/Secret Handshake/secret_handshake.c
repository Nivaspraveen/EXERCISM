#include "secret_handshake.h"
#include <stdio.h>
#include <stdlib.h>

static const char *actions[] = {
    "wink",
    "double blink",
    "close your eyes",
    "jump"
};

const char **commands(size_t number) {
    const char **handshake = (const char **)malloc(5 * sizeof(char *));
    if (!handshake) return NULL;
    size_t action_count = 0;
    int reverse = number & 0x10;

    for (int i = 0; i < 4; i++) {
        if (number & (1 << i)) handshake[action_count++] = actions[i];
    }
    if (reverse) {
        for (size_t i = 0; i < action_count / 2; i++) {
            const char *temp = handshake[i];
            handshake[i] = handshake[action_count - i - 1];
            handshake[action_count - i - 1] = temp;
        }
    }
    handshake[action_count] = NULL;
    return handshake;
}