#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

typedef enum
{
    BLACK = 0,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

const char *color_to_name(resistor_band_t color);
int color_code(resistor_band_t color);
void list_colors(void);
const resistor_band_t *colors(void);

#endif
