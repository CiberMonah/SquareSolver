#include <stdio.h>
#include <math.h>
#include <TXLib.h>

struct solutions {
    int quantity;
    float solution_1, solution_2;
};

struct coeficients {
    float a, b, c;
};

struct solutions *calculate_solutions(struct coeficients coeficient);
void print_solutions(struct solutions *solution);
void greeting(void);
bool check_input(void);
void input_coeficients(float *a, float *b, float *c);

const int esc_button = 27;
const float EPSILON = float(0.00001);

int main(void) {
    struct coeficients coeficient;
    int ch;

    do {
        greeting();
        input_coeficients(&coeficient.a, &coeficient.b, &coeficient.c);//in order
        if (check_input()) {
            print_solutions(calculate_solutions(coeficient));
            printf("Press esc to stop or any button to continue\n");
            ch = _getch();
        } else
            printf("Please, follow instructions\n");
    } while (ch != esc_button);
}

void greeting(void) {
    printf("Enter in a row, separated by spaces, the coefficients of the quadratic equation of the form: ax^2 + bx + c = 0\n");
}

bool check_input(void) {
    if (getchar() != '\n') {
        return false;
    } else {
        return true;
    }
}

void input_coeficients(float *a, float *b, float *c) {
    while (scanf("%f%f%f", a, b, c) != 3) {
        while (getchar() != '\n')
            ;
        printf("Wrong input\n");
        }
}

struct solutions *calculate_solutions(struct coeficients coeficient) {
    float D = float(pow(coeficient.b, 2)) - 4 * coeficient.a * coeficient.c;
    static struct solutions solution;

    if (fabs(coeficient.a) < EPSILON) {
        if (fabs(coeficient.b) < FLT_EPSILON)
            solution.quantity = 3;
        else {
            solution.quantity = 1;
            solution.solution_1 = -coeficient.c / coeficient.b;
        }
    } else {
        if (fabs(D) < EPSILON){
            solution.quantity = 1;
            solution.solution_1 = -coeficient.b / (2 * coeficient.a);
        } else if (D - EPSILON > 0) {
            solution.quantity = 2;
            solution.solution_1 = (-coeficient.b  + float(sqrt(D))) / (2 * coeficient.a);
            solution.solution_2 = (-coeficient.b  - float(sqrt(D))) / (2 * coeficient.a);
        } else
            solution.quantity = 0;
    }
    return &solution;
}

void print_solutions(struct solutions *solution) {
    if(fabs(solution->quantity - 3) <= EPSILON)
        printf("infinity quantity of solutions\n");
    else if(fabs(solution->quantity) <= EPSILON)
        printf("No solutions\n");
    else if(fabs(solution->quantity - 2) <= EPSILON)
        printf("Solution_1 = %f\nSolution_2 = %f\n", solution->solution_1, solution->solution_2);
    else
        printf("Solution_1 = %f\n", solution->solution_1);
}
