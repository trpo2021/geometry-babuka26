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


void check_str(char str_arr[],int i, int *j)
{
    char check_arr[10];
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
    
}

int format_str()
{
    int i = 0, j = 0;                    /*i -  номер символа, который проверяем
                                    j - кол-во символов в выходном массиве*/
    check_str(str_arr, i, &j);

}