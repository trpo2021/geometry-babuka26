#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int i = 0, j = 0;
    int minus = 1;
    char x_arr[100];
    double x;
    
    while(isdigit(str[i]) == 0){
        if(str[i] == '-') {
            minus = -1;
        }
        i++;
    }
    while(str[i] != ' ') {
        x_arr[j] = str[i];
        i++;
        j++;
    }
    x = atof(x_arr);
    x *= minus;
    return x;
}

double get_cooordinate_y(char *str)
{
    int i = 0, j = 0;
    int minus = 1;
    char y_arr[100];
    double y;
    
    while(str[i] != ' ') {
        i++;
    }
    if(isdigit(str[i] == 1) && str[i - 1] == '-') {
            minus = -1;
    }
    while(str[i] != ',') {
        y_arr[j] = str[i];
        i++;
        j++;
    }
    y = atof(y_arr);
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