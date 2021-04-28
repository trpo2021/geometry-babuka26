#include "libgeometry/geometry.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max_str = 100, size_output;
    char* str_arr = NULL;
    str_arr = calloc(max_str, sizeof(char));
    char* output_arr = NULL;
    double x, y, rad, per, area;

    printf("Input figure and cooordinates: ");
    fgets(str_arr, max_str, stdin);
    size_output = is_input_correct(str_arr);
    output_arr = calloc(size_output, sizeof(char));
    format_str(str_arr, output_arr);
    printf("Correct coordinates: ");
    puts(output_arr);
    
    x = get_cooordinate_x(output_arr);
    y = get_cooordinate_y(output_arr);
    rad = get_rad(output_arr);
    printf("x - %f, y - %f, rad - %f\n", x ,y ,rad);
    
    per = get_perimetr(rad);
    area = get_area(rad);
    printf("Perimetr - %f   Area - %f\n", per, area);  
}