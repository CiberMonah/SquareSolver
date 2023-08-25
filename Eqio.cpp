#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "SolveEquation.h"
#include "Test.h"
#include "Eqio.h"

#define NAME_OF_FILE "my.txt"

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

void print_instructions(void) {
    printf("# Enter in a row, separated by spaces, the coefficients of the quadratic equation of the form: ax^2 + bx + c = 0\n");
}

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

void skip_line(void) {
    while(getchar() != '\n')
        ;
}

void greeting(void) {
    printf("# Author: Glisanov Andrej\n\n");
}

float roots_to_float(float root) {
    if(check_float_equality(root, VOID_ROOT_CODE))
        return NAN;
    else
        return root;
}

unsigned int read_test_from_file(Test_data *all_data) {
    FILE *fp;
    char name[] = NAME_OF_FILE;
    int number_of_roots = 0;
    unsigned int i = 0;
    float sol_1, sol_2;

    if ((fp = fopen(name, "r")) == NULL)
    {
      printf("Error: file didnt open\n");
      return 1;
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
