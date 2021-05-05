#include "libgeometry/geometry.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max_str = 100;
    char* str_arr = NULL;
    str_arr = calloc(max_str, sizeof(char));
    char *output_arr_1 = NULL, *output_arr_2 = NULL;
    double x1, y1, rad1, per1, area1, x2, y2, rad2, per2, area2;

    printf("Input first figure and cooordinates: ");
    fgets(str_arr, max_str, stdin);
    output_arr_1 = format_str(str_arr);
    printf("Correct coordinates: ");
    puts(output_arr_1);

    x1 = get_cooordinate_x(output_arr_1);
    y1 = get_cooordinate_y(output_arr_1);
    rad1 = get_rad(output_arr_1);
    printf("x - %f, y - %f, rad - %f\n", x1, y1, rad1);
    per1 = get_perimetr(rad1);
    area1 = get_area(rad1);
    printf("Perimetr - %f   Area - %f\n", per1, area1);

    printf("Input second figure and cooordinates: ");
    fgets(str_arr, max_str, stdin);
    output_arr_2 = format_str(str_arr);
    printf("Correct coordinates: ");
    puts(output_arr_2);

    x2 = get_cooordinate_x(output_arr_2);
    y2 = get_cooordinate_y(output_arr_2);
    rad2 = get_rad(output_arr_2);
    printf("x - %f, y - %f, rad - %f\n", x2, y2, rad2);
    per2 = get_perimetr(rad2);
    area2 = get_area(rad2);
    printf("Perimetr - %f   Area - %f\n", per2, area2);

    int intersect = is_intersect(output_arr_1, output_arr_2);

    if (intersect == 0) {
        printf("Don't intersect\n");
    } else if (intersect == 1) {
        printf("Intersect in 1 point\n");
    } else if (intersect == 2) {
        printf("Intersect in 2 points\n");
    } else if (intersect == -1) {
        printf("ERROR\n");
    } else if (intersect == 3) {
        printf("Match\n");
    }
}