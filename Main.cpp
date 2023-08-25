#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "Eqio.h"
#include "SolveEquation.h"
#include "Test.h"
/// \brief
/*!
    Main have two modes mode to make user session and test mode to check if program work correctly
*/
/*!
    In session mode you can type coefficients and split them by spaces or tabs, if there are any another symbols, programm outputs Wrong input
*/
/*!
    To finish program in session mode type <b>e</b>, it permissible to type tabs ore spaces before/after 'e'
*/
/*!
    \code
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
    \endcode
*/
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
