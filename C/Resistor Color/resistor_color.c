#include "resistor_color.h"
#include <stdio.h>

const char *color_to_name(resistor_band_t color)
{
    switch (color)
    {
    case BLACK:
        return "black";
    case BROWN:
        return "brown";
    case RED:
        return "red";
    case ORANGE:
        return "orange";
    case YELLOW:
        return "yelow";
    case GREEN:
        return "green";
    case BLUE:
        return "blue";
    case VIOLET:
        return "violet";
    case GREY:
        return "grey";
    case WHITE:
        return "white";
    default:
        return "unknown";
    }
}

int color_code(resistor_band_t color)
{
    return color;
}

void list_colors(void)
{
    for (int i = BLACK; i <= WHITE; i++)
        printf("%s: %d\n", color_to_name((resistor_band_t)i), i);
}

const resistor_band_t *colors(void)
{
    static resistor_band_t color_array[] = {
        BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};
    return color_array;
}