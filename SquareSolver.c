#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include "SquareSolver.h"

void greeting(void) {
    printf("Enter in a row, separated by spaces, the coefficients of the quadratic equation of the form: ax^2 + bx + c = 0\n");
}

void input_coefficients(struct Coefficients *coefficients) {
    while (scanf("%f%f%f", &coefficients->a, &coefficients->b, &coefficients->c) != 3) {
        while (getchar() != '\n')
            ;
        printf("Wrong input\n");
    }
}

void calculate_solutions(struct Coefficients coefficients, struct Solutions *solutions) {
    float discriminant = float(pow(coefficients.b, 2)) - 4 * coefficients.a * coefficients.c;

    if (fabs(coefficients.a) < epsilon) {
        if (fabs(coefficients.b) < epsilon)
            solutions->quantity = INF;
        else {
            solutions->quantity = 1;
            solutions->solution_1 = -coefficients.c / coefficients.b;
        }
    } else {
        if (check_float_equality(discriminant, 0)){
            solutions->quantity = 1;
            solutions->solution_1 = -coefficients.b / (2 * coefficients.a);
        } else if (discriminant > 0) {
            solutions->quantity = 2;
            solutions->solution_1 = (-coefficients.b  + float(sqrt(discriminant))) / (2 * coefficients.a);
            solutions->solution_2 = (-coefficients.b  - float(sqrt(discriminant))) / (2 * coefficients.a);
        } else
            solutions->quantity = 0;
    }
}

void print_solutions(struct Solutions solutions) {
    if(solutions.quantity == INF)
        printf("infinity quantity of solutions\n");
    else if(solutions.quantity == 0)
        printf("No solutions\n");
    else if(solutions.quantity == 2)
        printf("Solution_1 = %f\nSolution_2 = %f\n", solutions.solution_1, solutions.solution_2);
    else
        printf("Solution_1 = %f\n", solutions.solution_1);
}

bool check_float_equality(float f_1, float f_2) {
    return (fabs(f_1 - f_2) <= epsilon);
}
