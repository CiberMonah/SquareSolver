#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "Eqio.h"
#include "SolveEquation.h"

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
    printf("# Author: Glisanov Andrej\n# Last update 22/08 17:13\n\n");
}
