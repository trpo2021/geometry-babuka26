#pragma once

double sqr(double x);
int space_counter(char str_arr[], int i);
int check_str(char str_arr[], int i, int* j);
int check_coordinates(char str_arr[], int i, int* j);
int check_radius(char str_arr[], int i, int* j);
int is_input_correct(char str_arr[]);
char *format_str(char* str_arr);
double get_cooordinate_x(char *str);
double get_cooordinate_y(char *str);
double get_rad(char *str);
double get_perimetr(double rad);
double get_area(double rad);
double calculate_distance(double x1, double y1, double x2, double y2);
int is_intersect(char *output_arr_1, char *output_arr_2);
