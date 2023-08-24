#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "SolveEquation.h"
#include "Test.h"

bool check_roots(float root_1, float root_2, float root_1_ref, float root_2_ref) {
    if (check_float_equality(root_1, root_1_ref))
        return check_float_equality(root_2, root_2_ref);
    else if (check_float_equality(root_1, root_2_ref))
        return check_float_equality(root_2, root_1_ref);
    else
        return false;
}

int test_one(Test_data *data) {
    assert(data != NULL);
    Solutions solutions {NO_ROOTS, NAN, NAN};

    solve_quadratic(data->coefficients, &solutions);
    if (solutions.quantity_of_roots != data->solutions_ref.quantity_of_roots)
        printf("FAILED TEST: %s\nNumber of Roots : %s expected Number of Roots : %s\n",
            data->Name,
            enum_to_string(solutions.quantity_of_roots),
            enum_to_string(data->solutions_ref.quantity_of_roots)
            );
    switch (data->solutions_ref.quantity_of_roots)
    {
    case NO_ROOTS:
        return 1;
    case INF_ROOTS:
        return 1;
    case REPEATED_ROOT:
        if(solutions.quantity_of_roots == data->solutions_ref.quantity_of_roots
            && check_float_equality(solutions.solution_1, data->solutions_ref.solution_1)) {
            return 1;
        } else {
            printf("x1 = %.5f expected x1 = %.5f\n",
                solutions.solution_1, data->solutions_ref.solution_1);
            return 0;
        }
    case SINGLE_ROOT:
        if(solutions.quantity_of_roots == data->solutions_ref.quantity_of_roots
            && check_float_equality(solutions.solution_1, data->solutions_ref.solution_1)) {
            return 1;
        } else {
            printf("x1 = %.5f expected x1 = %.5f\n",
                solutions.solution_1, data->solutions_ref.solution_1);
            return 0;
        }
    case TWO_ROOTS:
        if(solutions.quantity_of_roots == data->solutions_ref.quantity_of_roots
            && check_roots(solutions.solution_1, solutions.solution_2,
            data->solutions_ref.solution_1, data->solutions_ref.solution_2)) {
            return 1;
        } else {
            printf("x1 = %.5f expected x1 = %.5f\nx2 = %.5f expected x2 = %.5f\n",
                solutions.solution_1, data->solutions_ref.solution_1,
                solutions.solution_2, data->solutions_ref.solution_2);
            return 0;
    default:
        printf("Wrong quantity of roots\n");
        return 0;
        }
    }
}

void test_all() {
    int number_of_succeed = 0;

    Test_data all_data[] = {
        {{1, 2,   1}, {REPEATED_ROOT,  -1,  NAN}, "Repeated root (full square)"},
        {{1, 2, -15}, {TWO_ROOTS,      3,    -5}, "Two roots"                  },
        {{2, 2,   2}, {NO_ROOTS,       NAN, NAN}, "No root"                    },
        {{1, 0,   0}, {REPEATED_ROOT,  0,   NAN}, "Repeated root b = 0, c = 0" },
        {{0, 0,   0}, {INF_ROOTS,      NAN, NAN}, "All coefs are zero"         }
    };

    for (unsigned int i = 0; i < sizeof(all_data) / sizeof(Test_data); i++)
        number_of_succeed += test_one(&all_data[i]);

    printf("Tests passed %d\n", number_of_succeed);
}
