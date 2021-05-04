#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sqr(double x)
{
    return x * x;
}

int space_counter(char str_arr[], int i)
{
    while (str_arr[i] == ' ') {
        i++;
    }
    return i;
}

int check_str(char str_arr[], int i, int* j)
{
    char check_arr[] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int k = 0;
    i = space_counter(str_arr, i);
    while ((str_arr[i] != '(') && (isalpha(str_arr[i]) > 0)) {
        if (check_arr[k] != (tolower(str_arr[i]))) {
            printf("Error: expected 'circle'");
            return 0;
        }
        i++;
        (*j)++;
        k++;
    }
    return i;
}

int check_coordinates(char str_arr[], int i, int* j)
{
    int k = 0;
    if (str_arr[i] == '-') {
        i++;
        (*j)++;
    }
    if (isdigit(str_arr[i]) == 0) {
        printf("Error :expected digit");
        return 0;
    }
    while ((isdigit(str_arr[i]) > 0) || (str_arr[i] == '.')) {
        if ((str_arr[i] == '.') && (k == 0)) {
            k = i;
        }
        i++;
        (*j)++;
        if ((str_arr[i] == '.') && (k > 0)) {
            printf("Error: expected digit");
            return 0;
        }
    }
    if ((str_arr[k] == '.') && (isdigit(str_arr[k + 1]) == 0)) {
        printf("Error: expected digit");
        return 0;
    }
    return i;
}

int check_radius(char str_arr[], int i, int* j)
{
    int k = 0;
    if (isdigit(str_arr[i]) == 0) {
        printf("Error: expected digit");
        return 0;
    }
    while ((isdigit(str_arr[i]) > 0) || (str_arr[i] == '.')) {
        if ((str_arr[i] == '.') && (k == 0)) {
            k = i;
        }
        i++;
        (*j)++;
        if ((str_arr[i] == '.') && (k > 0)) {
            printf("Error: expected digit");
            return 0;
        }
    }
    if ((str_arr[k] == '.') && (isdigit(str_arr[k + 1]) == 0)) {
        printf("Error: expected digit");
        return 0;
    }
    return i;
}

int is_input_correct(char str_arr[])
{
    int i = 0, j = 0;
    i = check_str(str_arr, i, &j);
    i = space_counter(str_arr, i);
    if (str_arr[i] == '(') {
        j++;
        i++;
    } else {
        printf("Error: expected '('\n");
        return 0;
    }
    i = space_counter(str_arr, i);
    i = check_coordinates(str_arr, i, &j);
    j++;
    i = space_counter(str_arr, i);
    i = check_coordinates(str_arr, i, &j);
    i = space_counter(str_arr, i);
    if (str_arr[i] != ',') {
        printf("Error: expected ','\n");
        return 0;
    } else {
        j++;
        i++;
    }
    j++;
    i = space_counter(str_arr, i);
    i = check_radius(str_arr, i, &j);
    i = space_counter(str_arr, i);
    if (str_arr[i] != ')') {
        printf("Error: expected ')'");
    } else {
        j++;
        i++;
    }
    return j;
}

void format_str(char* str_arr, char* output_arr)
{
    int i = 0, j;
    i = space_counter(str_arr, i);
    for (j = 0; (str_arr[i] != '(') && (str_arr[i] != ' '); i++, j++) {
        output_arr[j] = str_arr[i];
    }
    output_arr[j] = '(';
    j++;
    while ((str_arr[i] != '-') && (isdigit(str_arr[i]) == 0)) {
        i++;
    }
    for (; str_arr[i] != ' '; i++, j++) {
        output_arr[j] = str_arr[i];
    }
    output_arr[j] = ' ';
    j++;
    i = space_counter(str_arr, i);
    for (; (str_arr[i] != ',') && (str_arr[i] != ' '); i++, j++) {
        output_arr[j] = str_arr[i];
    }
    output_arr[j] = ',';
    j++;
    output_arr[j] = ' ';
    j++;
    i = space_counter(str_arr, i);
    if (str_arr[i] == ',') {
        i++;
    }
    i = space_counter(str_arr, i);
    for (; (str_arr[i] != ')') && (str_arr[i] != ' '); i++, j++) {
        output_arr[j] = str_arr[i];
    }
    output_arr[j] = ')';
    j++;
    output_arr[j] = '\0';
}

double get_cooordinate_x(char *str)
{
    int i = 0;
    int minus = 1;
    double x;
    
    while(isdigit(str[i]) == 0){
        if(str[i] == '-') {
            minus = -1;
        }
        i++;
    }
    x = atof(&str[i]);
    x *= minus;
    return x;
}

double get_cooordinate_y(char *str)
{
    int i = 0;
    int minus = 1;

    double y;
    
    while(str[i] != ' ') {
        i++;
    }
    if(isdigit(str[i] == 1) && str[i - 1] == '-') {
            minus = -1;
    }
    y = atof(&str[i]);
    y *= minus;
    return y;
}

double get_rad(char *str)
{
    int i = 0;
    int minus = 1;
    double rad;

    while (str[i] != ',') {
        i++;
    }
    i = i + 2;
    if (str[i] == '-') {
        minus = -1;
        i++;
    }

    rad = atof(&str[i]);
    rad *= minus;
    return rad;
}

double get_perimetr(double rad)
{
    return 2 * M_PI * rad;
}

double get_area(double rad)
{
    return M_PI * rad * rad;
}

double calculate_distance(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x2 - x1) + sqr(y2 - y1));
}

int is_intersect(char *output_arr_1, char *output_arr_2)
{
    double x1, x2, y1, y2, rad1, rad2;
    double dist;

    x1 = get_cooordinate_x(output_arr_1);
    y1 = get_cooordinate_y(output_arr_1);
    rad1 = get_rad(output_arr_1);

    x2 = get_cooordinate_x(output_arr_2);
    y2 = get_cooordinate_y(output_arr_2);
    rad2 = get_rad(output_arr_2);

    dist = calculate_distance(x1, y1, x2, y2);
    if (dist > (rad1 + rad2)) {
        //не пересекаются
        return 0;
    } else if ((x1 == x2) && (y1 == y2) && (rad1 == rad2)) {
        return 3;
    } else if (dist < (rad1 + rad2)) {
        //пересекаются в 2 точке
        return 2;
    } else if ((dist = rad1 + rad2)) {
        //пересекаются в 1 точках
        return 1;
    } else {
        return -1;
    }
}