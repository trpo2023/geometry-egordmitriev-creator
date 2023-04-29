#include <ctest.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <libgeometry/area.h>
#include <libgeometry/checkarg.h>
#include <libgeometry/perimetr.h>
#include <libgeometry/vocabulary.h>

CTEST(check_figure_name, correct_figure)
{
    char* str = "circle(2.3, 3.2, 4.0)";
    const int expected = 0;
    const int result = Figure(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_figure_name, incorrect_figure)
{
    char* str = "ciirrcle(2.3, 3.2, 4.0)";
    const int excpected = 1;
    const int result = Figure(str);
    ASSERT_EQUAL(excpected, result);
}

CTEST(check_argument, int_arguments)
{
    char* str = "circle(1 2, 3)";
    const int expected = 0;
    const int result = checkArg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_argument, float_arguments)
{
    char* str = "circle(1.0 2.0, 3.0)";
    const int expected = 0;
    const int result = checkArg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_argument, incorrect_coordinate_arguments)
{
    char* str = "circle(x 2.0, 3.0)";
    const int expected = 2;
    const int result = checkArg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_argument, incorrect_radius_arguments)
{
    char* str = "circle(2.0 3.0, X)";
    const int expected = 3;
    const int result = checkArg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_end, corretc_end)
{
    char* str = "circle(1.0 2.0, 3.0)\n ";
    const int expected = 0;
    const int result = End(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_end, incorrect_end)
{
    char* str = "circle(2.0 2.0, 3.0(";
    const int expected = 4;
    const int result = End(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_area, correct_area)
{
    char* str = "circle(2 2, 3)";
    const double expected = 9 * M_PI;
    const double result = Area(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(check_area, incorrect_area)
{
    char* str = "circle(2 2, x)";
    const double expected = -1;
    const double result = Area(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}

CTEST(check_perimetr, correct_perinetr)
{
    char* str = "circle(2 2, 3)";
    const double expected = 2 * M_PI * 3;
    const double result = Perimetr(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(check_perimetr, incorrect_perinetr)
{
    char* str = "circle(2 2, x)";
    const double expected = -1;
    const double result = Perimetr(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}