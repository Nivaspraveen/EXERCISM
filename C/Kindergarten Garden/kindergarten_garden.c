#include "kindergarten_garden.h"
#include <string.h>

#define NUM_STUDENTS 12
#define NUM_PLANTS 4

const char *students[NUM_STUDENTS] = {
    "Alice", "Bob", "Charlie", "David", "Eve", "Fred", 
    "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
};

static plant_t plant_char_to_enum(char c) {
    switch (c) {
        case 'G': return GRASS;
        case 'C': return CLOVER;
        case 'R': return RADISHES;
        case 'V': return VIOLETS;
        default: return -1;
    }
}

plants_t plants(const char *diagram, const char *student) {
    const int index = student[0] - 'A';
  const int row_1_offset = 0;
  const int row_2_offset = strlen(diagram) / 2 + 1;
  return (plants_t){
    .plants = {
      plant_char_to_enum(diagram[row_1_offset + index * 2]),
      plant_char_to_enum(diagram[row_1_offset + index * 2 + 1]),
      plant_char_to_enum(diagram[row_2_offset + index * 2]),
      plant_char_to_enum(diagram[row_2_offset + index * 2 + 1]),
    }
  };
}