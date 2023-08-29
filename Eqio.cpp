#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "SolveEquation.h"
#include "Test.h"
#include "Eqio.h"
/*! name of testing file */
#define NAME_OF_FILE "my.txt"
/// \brief Function to print solutions in case of numbers of roots
/// \param <input> struct of solutions {int number_of_roots, float sol_1, float sol_2}
/// \param <output> void
void print_solutions(const Solutions solutions) {
    switch (solutions.quantity_of_roots) {
        case NO_ROOTS:
            printf("# No solutions\n");
            break;
        case INF_ROOTS:
            printf("# Infinity quantity of solutions\n");
            break;
        case SINGLE_ROOT:
            printf("# Solution = %.5f\n", solutions.solution_1);
            break;
        case REPEATED_ROOT:
            printf("# Repeated solution = %.5f\n", solutions.solution_1);
            break;
        case TWO_ROOTS:
            printf("# First solution = %.5f\n# Second solution = %.5f\n", solutions.solution_1, solutions.solution_2);
            break;
        default:
            printf("# Error wrong quantity of solutions");
            break;
    }
}
/// \brief Use it to print instructions use this function to explain user how to enter numbers
/// \param <input> void
/// \param <output> void
void print_instructions(void) {
    printf("# Enter in a row, separated by spaces, the coefficients of the quadratic equation of the form: ax^2 + bx + c = 0\n");
}
/// \brief Use it to input coefficiens of square equation
/*!
    Returns true when input is correct,
    returns false when input is incorrect
*/
/// \param <input> pointer on struct Coefficients{float a, float b, float c}
/// \param <output> bool
/// \return True if input correct, false otherwise.
bool input_coefficients(struct Coefficients *coefficients) {
    while (true){
        if (scanf("%f%f%f", &coefficients->a, &coefficients->b, &coefficients->c) == 3) {
            int ch = 0;
            do {
            ch = getchar();
            } while (ch == ' ' or ch == '\t');
            if (ch != '\n') {
                printf("# Wrong input\n");
                return false;
            } else {
                return true;
            }
        } else {
            printf("# Wrong input\n");
            return false;
        }
    }
}


/// \brief Use it to clean stdin

void skip_line(void) {
    while(getchar() != '\n')
        ;
}
/// \brief Use it output info about creator

void greeting(void) {
    printf("# Author: Glisanov Andrej\n\n");
}

/// \brief Use it to avoid errors in reading from file
/*!
    When input root has VOID_ROOT_CODE it value turns to NAN
*/
/// \param <input> float
/// \param <output> float

float roots_to_float(float root) {
    if(check_float_equality(root, VOID_ROOT_CODE))
        return NAN;
    else
        return root;
}

/// \brief Use it to read tests from defined file and put them to array by pointer

/// \param <input> pointer on array of structs
/// \param <output> int - quantity of tests


unsigned int read_test_from_file(Test_data *all_data) {
    FILE *fp;
    char name[] = NAME_OF_FILE;
    int number_of_roots = 0;
    unsigned int i = 0;
    float sol_1, sol_2;

    if ((fp = fopen(name, "r")) == NULL)
    {
      printf("Error: file didnt open\n");
      return 0;
    }

    while(fscanf(fp, "%f %f %f %d %f %f",
        &all_data[i].coefficients.a,
        &all_data[i].coefficients.b,
        &all_data[i].coefficients.c,
        &number_of_roots,
        &sol_1, &sol_2) ==  6) {
        all_data[i].solutions_ref.quantity_of_roots = int_to_enum(number_of_roots);
        all_data[i].solutions_ref.solution_1 = roots_to_float(sol_1);
        all_data[i].solutions_ref.solution_2 = roots_to_float(sol_2);
        i++;
    }
    fclose(fp);

    return i;
}
