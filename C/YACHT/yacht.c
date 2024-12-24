#include "yacht.h"

int score(dice_t dice, category_t category) {
    int counts[7] = {0}, total = 0;
    for (int i = 0; i < 5; i++) {
        counts[dice.faces[i]]++;
        total += dice.faces[i];
    }
    switch (category) {
        case ONES:
            return counts[1];
        case TWOS:
            return counts[2] * 2;
        case THREES:
            return counts[3] * 3;
        case FOURS:
            return counts[4] * 4;
        case FIVES:
            return counts[5] * 5;
        case SIXES:
            return counts[6] * 6;
        case FULL_HOUSE:
            for (int i = 1; i <= 6; i++) {
                if (counts[i] == 3) {
                    for (int j = 1; j <= 6; j++) {
                        if (counts[j] == 2) return total;
                    }
                }
            }
            return 0;
        case FOUR_OF_A_KIND:
            for (int i = 1; i <= 6; i++) {
                if (counts[i] >= 4) return i * 4;
            }
            return 0;
        case LITTLE_STRAIGHT:
            if (counts[1] == 1 && counts[2] == 1&& counts[3] == 1 && counts[4] == 1 && counts[5] == 1) return 30;
            return 0;
        case BIG_STRAIGHT:
            if (counts[2] == 1 && counts[3] == 1 && counts[4] == 1 && counts[5] == 1 && counts[6] == 1) return 30;
            return 0;
        case CHOICE:
            return total;
        case YACHT:
            for (int i = 1; i <= 6; i++) {
                if (counts[i] == 5) return 50;
            }
            return 0;
        default:
            return 0;
    }
}