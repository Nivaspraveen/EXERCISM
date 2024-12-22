#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>

int ability(void)
{
    int rolls[4], total = 0, min_roll = 7;
    for (int i = 0; i < 4; i++)
    {
        rolls[i] = (rand() % 6) + 1;
        total += rolls[i];
        if (rolls[i] < min_roll)
            min_roll = rolls[i];
    }
    return total - min_roll;
}

int modifier(int score)
{
    return (score - 10) / 2 - ((score - 10) % 2 < 0);
}

dnd_character_t make_dnd_character(void)
{
    dnd_character_t character;
    srand((unsigned int)time(NULL));

    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();

    character.hitpoints = 10 + modifier(character.constitution);
    return character;
}