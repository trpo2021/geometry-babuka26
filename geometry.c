#include <stdio.h>
#include <string.h>
#include <ctype.h>

void SpaceDelete(char *str_arr, int position)
{
    int lenght;
    
    lenght = strlen(str_arr);
    while(position < lenght) {
        str_arr[position] = str_arr[position + 1];
        position++;
    }   
}

void SpaceSerch(char *str_arr)
{
    int i = 0, lenght;

    lenght = strlen(str_arr);
    while(i < lenght) {
        if(str_arr[i] == ' ' && str_arr[i + 1] == ' ') {
            SpaceDelete(str_arr, i + 1);
            lenght--;
        } else {
            i++;
        }
    }
}

void Correct(char *str_arr, int size)
{
    int check, i;
    char check_arr[] = {'c', 'i', 'r', 'c', 'l', 'e'};
    char aux_arr[size];

    for(i = 0; i <= size; i++) {
        str_arr[i] = tolower(str_arr[i]);
    }
    SpaceSerch(str_arr);
    
    for (i = 0; str_arr[i] != '('; i++) {
        aux_arr[i] = str_arr[i];
    }
    check = strcmp(aux_arr, check_arr);
    if (check != 0) {
        printf("Input is not correct\n");
        printf("\"%s\" Not found\nDid you mean \"circle\"?\n", aux_arr);
    }
}

int main() {
    int max_str = 100;
    char str_arr[max_str];
    FILE *file;

    file = fopen("input.txt", "r");
    fgets(str_arr, max_str, file);

    Correct(str_arr, max_str);

    puts(str_arr);


}