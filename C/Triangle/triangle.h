#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef enum {
    INVALID,
    EQUILATERAL,
    ISOSCELES,
    SCALENE
} triangle_type_t;

typedef struct {
    double a, b, c;
} triangle_t;

triangle_type_t get_triangle_type(triangle_t triangle);

int is_equilateral(triangle_t triangle);
int is_isosceles(triangle_t triangle);
int is_scalene(triangle_t triangle);

#endif
