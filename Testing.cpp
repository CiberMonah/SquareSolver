#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "Test.h"
/// Name of test file
#define NAME_OF_FILE "my.txt"

static const int MAX_LENGTH_OF_TEST_NAME = 256;         /// \const Using to regulate length of tests names
static const int MAX_NUMBER_OF_TESTS = 20;              /// \const Using to set quanity of tests 

static int test_one(Test_data* data);

/// \brief Checks if roots solve_quadratic return are equal to reference roots
///<strong>Important!</strong> The order of calculated roots and reference roots is not important
///<b>BUT!</b> First two roots have to be <strong>calculated</strong>, and last one are <strong>references</strong>
bool check_roots(float root_1, float root_2, float root_1_ref, float root_2_ref) {
    if (check_float_equality(root_1, root_1_ref))
        return check_float_equality(root_2, root_2_ref);
    else if (check_float_equality(root_1, root_2_ref))
        return check_float_equality(root_2, root_1_ref);
    else
        return false;
}

/// \brief Use it to read tests from defined file and put them to array by pointer
/// \param <input> pointer on array of structs
/// \return int - quantity of tests
unsigned int read_test_from_file(Test_data* all_data) {
    FILE* fp = nullptr;
    char name[] = NAME_OF_FILE;
    int number_of_roots = 0;
    unsigned int i = 0;
    float sol_1 = NAN, sol_2 = NAN;

    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Error: file didnt open\n");
        return 0;
    }

    while (fscanf(fp, "%f %f %f %d %f %f",
                    &all_data[i].coefficients.a,
                    &all_data[i].coefficients.b,
                    &all_data[i].coefficients.c,
                    &number_of_roots,
                    &sol_1, &sol_2) == 6) {
        all_data[i].solutions_ref.quantity_of_roots = int_to_enum(number_of_roots);
        all_data[i].solutions_ref.solution_1 = roots_to_float(sol_1);
        all_data[i].solutions_ref.solution_2 = roots_to_float(sol_2);
        i++;
    }
    fclose(fp);

    return i;
}

/// \brief Checks one test
/// Uses function solve_quadratic to calculate solutions and write them in struct Test_data
/// \param <input> Test_data *data
/// \return 1 if test passed, 0 otherwise 
int test_one(Test_data *data) {
    assert(data != NULL);
    Solutions solutions {NO_ROOTS, NAN, NAN};

    solve_quadratic(data->coefficients, &solutions);
    if (solutions.quantity_of_roots != data->solutions_ref.quantity_of_roots) {
        printf("FAILED TEST:\nNumber of Roots : %s expected Number of Roots : %s\n",
                enum_to_string(solutions.quantity_of_roots),
                enum_to_string(data->solutions_ref.quantity_of_roots)
        );
    }
    switch (data->solutions_ref.quantity_of_roots) {
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
        assert(0);
        return 0;
        }
    }
}

/// \brief Function to check all tests
/// Reads all tests from file by read_test_from_file(), then by  using function test_one check all tests
void test_all() {
    int number_of_succeed = 0;
    unsigned int number_of_tests = 0;
    Test_data all_data[MAX_NUMBER_OF_TESTS];

    number_of_tests = read_test_from_file(all_data); //downloading data from file

    for(unsigned int i = 0; i < number_of_tests; i++) {
        number_of_succeed += test_one(&all_data[i]);
    }

    printf("Tests passed %d/%d\n", number_of_succeed, number_of_tests);
}
