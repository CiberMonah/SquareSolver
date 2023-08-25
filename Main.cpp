#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "Eqio.h"
#include "SolveEquation.h"
#include "Test.h"

int main(void) {
    Coefficients coefficients {NAN, NAN, NAN};
    Solutions solutions {NO_ROOTS, NAN, NAN};
    int ch = 0;

    greeting();
    printf("Choose mode\n1 - Start session\n2 - Testing mode\n");
    ch = getchar();
    switch (ch)
    {
    case '1':
        do {
            print_instructions();
            if(input_coefficients(&coefficients)) {
                solve_quadratic(coefficients, &solutions);
                print_solutions(solutions);
                printf("# type e to stop or anything to continue\n");
                do {
                    ch = getchar();
                } while (ch == ' ' or ch == '\t');
            }
            skip_line();
        } while (ch != 'e');
        break;
    case '2':
        test_all();
        break;
    default:
        printf("Error\n");
    }
}
