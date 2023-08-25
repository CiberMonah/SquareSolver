#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "Eqio.h"
#include "SolveEquation.h"

void solve_quadratic(const Coefficients coefficients, Solutions *solutions) {

    assert(solutions != NULL);

    float discriminant = float(coefficients.b * coefficients.b) - 4 * coefficients.a * coefficients.c;

    if (check_float_equality(coefficients.a, 0)) {
        if (check_float_equality(coefficients.b, 0)) {
            solutions->quantity_of_roots = INF_ROOTS;
        } else {
            solutions->quantity_of_roots = SINGLE_ROOT;
            solutions->solution_1 = solve_line(coefficients.b, coefficients.c);

        }
    } else {
        if (check_float_equality(discriminant, 0)) {
            solutions->quantity_of_roots = REPEATED_ROOT;
            solutions->solution_1 = -coefficients.b / (2 * coefficients.a);
        } else if (discriminant > 0) {

            assert(discriminant > 0);

            float sqrted_disc = float(sqrt(discriminant));

            assert(!check_float_equality(coefficients.a, 0));

            solutions->quantity_of_roots = TWO_ROOTS;
            solutions->solution_1 = (-coefficients.b  + sqrted_disc) / (2 * coefficients.a);
            solutions->solution_2 = (-coefficients.b  - sqrted_disc) / (2 * coefficients.a);
        } else {
            solutions->quantity_of_roots = NO_ROOTS;
        }
    }
}

float solve_line(float coef_1, float coef_2) {
    assert(!check_float_equality(coef_1, 0));
    return -coef_2 / coef_1;
}

bool check_float_equality(const float f_1, const float f_2) {
    return (float(fabs(f_1 - f_2)) <= EPSILON);
}

const char *enum_to_string(Quantity quantity_of_roots) {
    switch (quantity_of_roots)
    {
    case SINGLE_ROOT:
        return "SINGLE ROOT";
        break;
    case REPEATED_ROOT:
        return "REPEATED_ROOT";
        break;
    case TWO_ROOTS:
        return "TWO_ROOTS";
        break;
    case NO_ROOTS:
        return "NO_ROOTS";
        break;
    case INF_ROOTS:
        return "INF_ROOTS";
        break;
    default:
        return "WRONG QUANTITY OF ROOTS";
        break;
    }
}

Quantity int_to_enum(int quantity_of_roots) {
    switch(quantity_of_roots) {
        case 0:
            return SINGLE_ROOT;
            break;
        case 1:
            return REPEATED_ROOT;
            break;
        case 3:
            return TWO_ROOTS;
            break;
        case 999:
            return INF_ROOTS;
            break;
        default:
            return NO_ROOTS;
    }
}
