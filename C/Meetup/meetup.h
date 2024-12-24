#ifndef MEETUP_H
#define MEETUP_H

typedef enum {
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WDNESDAY,
    THIRSDAY,
    FRIDAY,
    SATURDAY
} day_week_t;

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week);

#endif
