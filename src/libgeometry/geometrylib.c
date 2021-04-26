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

float get_cooordinates(char *str)
{
    int i = 0, j = 0;
    char coord_arr[100];

    while(str[i] != '('){
        i++;
    }
    while(str[i] != ',') {
        coord_arr[j] = str[i];
        j++;
        i++;
    }
    

    return atof(coord_arr);;
}

void area_and_perimetr(char output_arr[])
{
    int i = 0, j = 0;
    char digit[100];
    float radius;
    float per, area;

    for (i = 0; i < 100; i++) {
        if ((output_arr[i] == ',') && (output_arr[i + 1] == ' ')) {
            for (j = i; output_arr[j + 1] != ')'; j++) {
                digit[j - i] = output_arr[j + 1];
            }
        }
    }
    radius = atof(digit);
    per = M_PI * radius * 2;
    area = M_PI * radius * radius;
    printf("perimetr: %f\narea: %f\n", per, area);
}