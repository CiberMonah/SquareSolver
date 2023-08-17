#include <stdio.h>
#include <math.h>
#include <TXLib.h>

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

const int esc_button = 27;
const float EPSILON = float(0.00001);

int main(void) {
    struct Coefficients coefficients;
    struct Solutions solutions;
    int ch;

    do {
        greeting();
        input_coefficients(&coefficients);
        calculate_solutions(coefficients, &solutions);
        print_solutions(solutions);
        printf("Press esc to stop or any button to continue\n");
        ch = _getch();
    } while (ch != esc_button);
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
    float D = float(pow(coefficients.b, 2)) - 4 * coefficients.a * coefficients.c;

    if (fabs(coefficients.a) < EPSILON) {
        if (fabs(coefficients.b) < EPSILON)
            solutions->quantity = 3;
        else {
            solutions->quantity = 1;
            solutions->solution_1 = -coefficients.c / coefficients.b;
        }
    } else {
        if (check_float_equality(D, 0)){
            solutions->quantity = 1;
            solutions->solution_1 = -coefficients.b / (2 * coefficients.a);
        } else if (D > 0) {
            solutions->quantity = 2;
            solutions->solution_1 = (-coefficients.b  + float(sqrt(D))) / (2 * coefficients.a);
            solutions->solution_2 = (-coefficients.b  - float(sqrt(D))) / (2 * coefficients.a);
        } else
            solutions->quantity = 0;
    }
}

void print_solutions(struct Solutions solutions) {
    if(solutions.quantity == 3)
        printf("infinity quantity of solutions\n");
    else if(solutions.quantity == 0)
        printf("No solutions\n");
    else if(solutions.quantity == 2)
        printf("Solution_1 = %f\nSolution_2 = %f\n", solutions.solution_1, solutions.solution_2);
    else
        printf("Solution_1 = %f\n", solutions.solution_1);
}

bool check_float_equality(float f_1, float f_2)
{
    if(fabs(f_1 - f_2) <= EPSILON) return true;
    else return false;
}
