#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include "SquareSolver.h"

int main(void) {
    struct Coefficients coefficients;
    struct Solutions solutions;
    int ch;

    GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), set_color_green);

    do {
        greeting();
        input_coefficients(&coefficients);
        calculate_solutions(coefficients, &solutions);
        print_solutions(solutions);
        printf("Press esc to stop or any button to continue\n");
        ch = _getch();
    } while (ch != esc_button_code);
}
