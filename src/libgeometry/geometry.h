#pragma once

int space_counter(char str_arr[], int i);
int check_str(char str_arr[], int i, int* j);
int check_coordinates(char str_arr[], int i, int* j);
int check_radius(char str_arr[], int i, int* j);
int is_input_correct(char str_arr[]);
void format_str(char str_arr[], char* output_arr);
double get_cooordinate_x(char *str);
double get_cooordinate_y(char *str);
double get_rad(char *str);
double get_perimetr(double rad);
double get_area(double rad);
