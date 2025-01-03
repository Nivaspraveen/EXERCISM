#include "space_age.h"
#include <stdio.h>
#define EARTH_YEAR_IN_SECONDS 31557600.0

static const float orbital_periods[] = {
    0.2408467,  // Mercury
    0.61519726, // Venus
    1.0,        // Earth
    1.8808158,  // Mars
    11.862615,  // Jupiter
    29.447498,  // Saturn
    84.016846,  // Uranus
    164.79132   // Neptune
};

float age(planet_t planet, int64_t seconds)
{
    if (planet < MERCURY || planet > NEPTUNE)
    {
        fprintf(stderr, "Error: Invalid planet\n");
        return -1.0;
    }
    float earth_years = seconds / EARTH_YEAR_IN_SECONDS;
    return earth_years / orbital_periods[planet];
}