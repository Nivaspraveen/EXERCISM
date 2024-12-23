#include "resistor_color_trio.h"
#include <stdint.h>

resistor_value_t color_code(const resistor_band_t colors[]) {
    uint16_t main_value = colors[0] * 10 + colors[1];
    uint32_t multiplier = 1;
    
    for (uint8_t i = 0; i < colors[2]; i++) multiplier *= 10;  
    uint64_t total_value = (uint64_t)main_value * multiplier;
    resistor_value_t result;
    
    if (total_value >= 1000000000) { 
        result.value = total_value / 1000000000; 
        result.unit = GIGAOHMS; 
    } else if (total_value >= 1000000) {
        result.value = total_value / 1000000; 
        result.unit = MEGAOHMS;
    } else if (total_value >= 1000) {
        result.value = total_value / 1000; 
        result.unit = KILOOHMS;
    } else {
        result.value = total_value; 
        result.unit = OHMS;
    }
    return result;
}
