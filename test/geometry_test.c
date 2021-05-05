#include <stdlib.h>

#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(format_str, extra_spaces)
{
    char input[] = "circle   (   1   2   ,   3    )";
    char expected[] = "circle(1 2, 3)";
    char* result = malloc(100 * sizeof(int));

    result = format_str(input);
    ASSERT_STR(expected, result);
}

CTEST(format_str, float_digits)
{
    char input[] = "circle(1.123 2.123, 3.123)";
    char expected[] = "circle(1.123 2.123, 3.123)";
    char* result = malloc(100 * sizeof(int));

    result = format_str(input);
    ASSERT_STR(expected, result);
}

CTEST(format_str, negative_digits)
{
    char input[] = "circle(-1 -2, -3)";
    char expected[] = "circle(-1 -2, -3)";
    char* result = malloc(100 * sizeof(int));

    result = format_str(input);
    ASSERT_STR(expected, result);
}

CTEST(format_str, uppercase)
{
    char input[] = "CIRCLE(1 2, 3)";
    char expected[] = "circle(1 2, 3)";
    char* result = malloc(100 * sizeof(int));

    result = format_str(input);
    ASSERT_STR(expected, result);
}

CTEST(is_input_correct, figure_name)
{
    char input[] = "not_circle(1 2, 3)";
    int expected = 0;
    int result = -1;

    result = is_input_correct(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(is_input_correct, first_bracket)
{
    char input[] = "circle1 2, 3)";
    int expected = 0;
    int result = -1;

    result = is_input_correct(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(is_input_correct, comma)
{
    char input[] = "circle(1 2 3)";
    int expected = 0;
    int result = -1;

    result = is_input_correct(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(is_input_correct, second_bracket)
{
    char input[] = "circle(1 2, 3";
    int expected = 0;
    int result = -1;

    result = is_input_correct(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_cooordinate_x, digit)
{
    char input[] = "circle(1 2, 3)";
    int expected = 1;
    int result;

    result = get_cooordinate_x(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_cooordinate_x, negative_digit)
{
    char input[] = "circle(-1 2, 3)";
    int expected = -1;
    int result;

    result = get_cooordinate_x(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_cooordinate_x, float_digit)
{
    char input[] = "circle(1.124 2, 3)";
    int expected = 1.124;
    int result;

    result = get_cooordinate_x(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_cooordinate_y, digit)
{
    char input[] = "circle(1 2, 3)";
    int expected = 2;
    int result;

    result = get_cooordinate_y(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_cooordinate_y, negative_digit)
{
    char input[] = "circle(1 -2, 3)";
    int expected = -2;
    int result;

    result = get_cooordinate_y(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_cooordinate_y, float_digit)
{
    char input[] = "circle(1 2.234, 3)";
    int expected = 2.234;
    int result;

    result = get_cooordinate_y(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_rad, digit)
{
    char input[] = "circle(1 2, 3)";
    int expected = 3;
    int result;

    result = get_rad(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_rad, negative_digit)
{
    char input[] = "circle(1 2, -3)";
    int expected = -3;
    int result;

    result = get_rad(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_rad, float_digit)
{
    char input[] = "circle(1 2, 3.2356)";
    int expected = 3.2356;
    int result;

    result = get_rad(input);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_perimetr, digit)
{
    char input[] = "circle(1 2, 3)";
    double expected = 18;
    double result;
    double rad = get_rad(input);

    result = get_perimetr(rad);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_perimetr, double_digit)
{
    char input[] = "circle(1 2, 3.234)";
    double expected = 20;
    double result;
    double rad = get_rad(input);

    result = get_perimetr(rad);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_area, digit)
{
    char input[] = "circle(1 2, 3)";
    double expected = 28;
    double result;
    double rad = get_rad(input);

    result = get_area(rad);
    ASSERT_EQUAL(expected, result);
}

CTEST(get_area, double_digit)
{
    char input[] = "circle(1 2, 3.234)";
    double expected = 32;
    double result;
    double rad = get_rad(input);

    result = get_area(rad);
    ASSERT_EQUAL(expected, result);
}

CTEST(is_intersect, circles_match)
{
    char input1[] = "circle(1 2, 3)";
    char input2[] = "circle(1 2, 3)";
    int expected = 3;
    int result;

    result = is_intersect(input1, input2);
    ASSERT_EQUAL(expected, result);
}

CTEST(is_intersect, circles_dont_intersect)
{
    char input1[] = "circle(5 10, 3)";
    char input2[] = "circle(1 2, 3)";
    int expected = 0;
    int result;

    result = is_intersect(input1, input2);
    ASSERT_EQUAL(expected, result);
}

CTEST(is_intersect, circles_intersect_2points)
{
    char input1[] = "circle(2 3, 7)";
    char input2[] = "circle(1 2, 3)";
    int expected = 2;
    int result;

    result = is_intersect(input1, input2);
    ASSERT_EQUAL(expected, result);
}

CTEST(is_intersect, circles_intersect_1points)
{
    char input1[] = "circle(0 0, 3)";
    char input2[] = "circle(0 6, 3)";
    int expected = 1;
    int result;

    result = is_intersect(input1, input2);
    ASSERT_EQUAL(expected, result);
}