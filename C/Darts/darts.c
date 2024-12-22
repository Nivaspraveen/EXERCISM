#include "darts.h"
#include <math.h>

int score(coordinate_t landing_position)
{
    double distance = sqrt(landing_position.x * landing_position.x + landing_position.y * landing_position.y);
    if (distance > 10.0)
        return 0;
    else if (distance > 5.0)
        return 1;
    else if (distance > 1.0)
        return 5;
    else
        return 10;
}