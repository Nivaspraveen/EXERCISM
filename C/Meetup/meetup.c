#include "meetup.h"
#include <string.h>
#include <stdlib.h>

const char *day_map[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Helper functions
static int numberOfDays(int monthNumber, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (monthNumber == 2) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            days[1] = 29;
    }
    return days[monthNumber - 1];
}

static day_week_t dayNumber(int day, int month, int year) {
    day_week_t day_week = SUNDAY;
    const int t[] = {0, 3, 2, 5, 0, 3,
                     5, 1, 4, 6, 2, 4};
    year -= month < 3;
    day_week = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
    return day_week;
}

static int week_to_index(const char *week) {
    if (strcmp(week, "first") == 0) return 1;
    if (strcmp(week, "second") == 0) return 2;
    if (strcmp(week, "third") == 0) return 3;
    if (strcmp(week, "fourth") == 0) return 4;
    if (strcmp(week, "last") == 0) return -1;
    if (strcmp(week, "teenth") == 0) return 0;
    return -2; 
}

// Main function
int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week) {
    int week_index = week_to_index(week);
    if (week_index == -2) return 0; 

    int num_of_days = numberOfDays(month, year);
    int hit = 0;

    if (week_index == 0) {  
        for (int d = 13; d < 20; d++) {
            const char *day = day_map[dayNumber(d, month, year)];
            if (!strcmp(day_of_week, day)) return d;
        }
    } else if (week_index > 0) {  
        for (int d = 1; d <= num_of_days; d++) {
            const char *day = day_map[dayNumber(d, month, year)];
            if (!strcmp(day_of_week, day)) {
                if (++hit == week_index) return d;
            }
        }
    } else if (week_index == -1) {  
        for (int d = num_of_days; d > 0; d--) {
            const char *day = day_map[dayNumber(d, month, year)];
            if (!strcmp(day_of_week, day)) return d;
        }
    }
    return 0; 
}
