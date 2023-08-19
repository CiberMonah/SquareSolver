#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#define INF 9999

struct Solutions {
    int quantity;
    float solution_1, solution_2;
};

struct Coefficients {
    float a, b, c;
};

void calculate_solutions(struct Coefficients coefficients, struct Solutions *solutions);
void print_solutions(struct Solutions solutions);
void greeting(void);
bool check_input(void);
bool check_float_equality(float f_1, float f_2);
void input_coefficients(struct Coefficients *coefficients);

const int esc_button_code = 27;
short unsigned int set_color_green = 10;
const float epsilon = float(0.00001);

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
