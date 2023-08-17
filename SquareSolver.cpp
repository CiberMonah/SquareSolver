#include <stdio.h>
#include <math.h>
#include <TXLib.h>

struct Solutions {
    int quantity;
    float solution_1, solution_2;
};

struct Coeficients {
    float a, b, c;
};

void calculate_solutions(struct Coeficients coeficients, struct Solutions *solutions);
void print_solutions(struct Solutions solutions);
void greeting(void);
bool check_input(void);
bool check_float_equality(float f_1, float f_2);
void input_coeficients(struct Coeficients *coeficients);

const int esc_button = 27;
const float EPSILON = float(0.00001);

int main(void) {
    struct Coeficients coeficients;
    struct Solutions solutions;
    int ch;

    do {
        greeting();
        input_coeficients(&coeficients);
        calculate_solutions(coeficients, &solutions);
        print_solutions(solutions);
        printf("Press esc to stop or any button to continue\n");
        ch = _getch();
    } while (ch != esc_button);
}

void greeting(void) {
    printf("Enter in a row, separated by spaces, the coefficients of the quadratic equation of the form: ax^2 + bx + c = 0\n");
}

void input_coeficients(struct Coeficients *coeficients) {
    while (scanf("%f%f%f", &coeficients->a, &coeficients->b, &coeficients->c) != 3) {
        while (getchar() != '\n')
            ;
        printf("Wrong input\n");
    }
}

void calculate_solutions(struct Coeficients coeficients, struct Solutions *solutions) {
    float D = float(pow(coeficients.b, 2)) - 4 * coeficients.a * coeficients.c;

    if (fabs(coeficients.a) < EPSILON) {
        if (fabs(coeficients.b) < EPSILON)
            solutions->quantity = 3;
        else {
            solutions->quantity = 1;
            solutions->solution_1 = -coeficients.c / coeficients.b;
        }
    } else {
        if (check_float_equality(D, 0)){
            solutions->quantity = 1;
            solutions->solution_1 = -coeficients.b / (2 * coeficients.a);
        } else if (D > 0) {
            solutions->quantity = 2;
            solutions->solution_1 = (-coeficients.b  + float(sqrt(D))) / (2 * coeficients.a);
            solutions->solution_2 = (-coeficients.b  - float(sqrt(D))) / (2 * coeficients.a);
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
