#include "triangle.h"

triangle_type_t get_triangle_type(triangle_t triangle) {
    double a = triangle.a, b = triangle.b, c = triangle.c;
    if (a <= 0 || b <= 0 || c <= 0 || (a + b < c) || (b + c < a) || (a + c < b)) return INVALID;
    return (a == b && b == c) ? EQUILATERAL : 
        (a == b || b == c || a == c) ? ISOSCELES : SCALENE;
}

int is_equilateral(triangle_t triangle) { 
    return get_triangle_type(triangle) == EQUILATERAL; 
} 

int is_isosceles(triangle_t triangle) { 
    triangle_type_t type = get_triangle_type(triangle);
    return type == ISOSCELES || type == EQUILATERAL;
} 

int is_scalene(triangle_t triangle) { 
    return get_triangle_type(triangle) == SCALENE;
}