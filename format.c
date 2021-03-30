#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int space_counter(char str_arr[], int i)
{
    while(str_arr[i] == ' ') {
        i++;
    }
    return i;
}


int check_str(char str_arr[],int i, int *j)
{
    char check_arr[] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int k = 0;
    i = space_counter(str_arr, i);
    while((str_arr[i] != '(') && (isalpha(str_arr[i]) > 0)) {
        if(check_arr[k] != (tolower(str_arr[i]))) {
            printf("Error: expected 'circle'");
            exit(0);
        }
        i++;
        j++;
        k++;
    }
    return i;
}

int check_coordinates(char str_arr[], int i, int *j)
{
    int k = 0;

    if(str_arr[i] == '-') {
        i++;
        k++;
    }
    if(isdigit(str_arr[i] == 0)) {
        printf("Error: expected digit");
        exit(0);
    }
    while((isdigit(str_arr[i] > 0)) || (str_arr[i] == '.')) {
        if((k > 0) && (str_arr[i]) == '.') {
            k = i;
        }
        if((str_arr[i] == '.') && (j > 0)) {
            printf("Error: expected digit");
            exit(0);
        }
    }
    return i;
}

int check_radius(char str_arr[], int i, int *j)
{
    int k = 0;

    if(str_arr[i] == '-') {
        printf("Error: the radius cannot be negative");
    }
    if(isdigit(str_arr[i] == 0)) {
        printf("Error: expected digit");
        exit(0);
    }
    while((isdigit(str_arr[i] > 0)) || (str_arr[i] == '.')) {
        if((k == 0) && (str_arr[i]) == '.') {
            k = i;
        }
        k++;
        i++;
        if((str_arr[i] == '.') && (j > 0)) {
            printf("Error: expected digit");
            exit(0);
        }
    }
    return i;
}

int is_input_correct()
{
    int i = 0, j = 0;
    i = space_counter(str_arr, i);
    if(str_arr[i] == '(') {
        j++;
        i++;
    } else {
        printf("Error: expected '(");
    }
    i = space_counter(str_arr, i);
    i = check_coordinates(str_arr, i, &j);
    j++;
    i = space_counter(str_arr, i);
    i = check_coordinates(str_arr, i, &j);
    i = space_counter(str_arr, i);
    if(str_arr[i] != ',') {
        printf("Error: expected ','");
        exit(0);
    } else {
        j++;
        i++;
    }
    j++;
    i = space_counter(str_arr, i);
    i = check_radius(str_arr, i, &j);
    i = space_counter(str_arr, i);
    if(str_arr[i] != ')') {
        printf("Error: expected ')'");
    } else {
        j++;
        i++;
    }
    return j;
}