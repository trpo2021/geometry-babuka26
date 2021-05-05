#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(format_str, extra_spaces)
{
    char input[] = "circle   (   1   2   ,   3    )";
    char expected[] = "circle(1 2, 3)";

    char *result = format_str(input);
    ASSERT_STR(expected, result);
}