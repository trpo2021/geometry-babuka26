#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int max_str = 100;
    char str_arr[max_str];
    char *output_arr;
    FILE *file;
    file = fopen("input.txt", "r");
    fgets(str_arr, max_str, file);

    

    puts(str_arr);
}