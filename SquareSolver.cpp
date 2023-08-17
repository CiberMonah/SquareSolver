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

struct Solutions *calculate_solutions(struct Coeficients coeficients);
void print_solutions(struct Solutions *solutions);
void greeting(void);
bool check_input(void);
void input_coeficients(float *a, float *b, float *c);

const int esc_button = 27;
const float EPSILON = float(0.00001);

int main(void) {
    struct Coeficients coeficients;
    int ch;

    do {
        greeting();
        input_coeficients(&coeficients.a, &coeficients.b, &coeficients.c);//in order
        if (check_input()) {
            print_solutions(calculate_solutions(coeficients));
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

struct Solutions *calculate_solutions(struct Coeficients coeficients) {
    float D = float(pow(coeficients.b, 2)) - 4 * coeficients.a * coeficients.c;
    static struct Solutions solutions;

    if (fabs(coeficients.a) < EPSILON) {
        if (fabs(coeficients.b) < FLT_EPSILON)
            solutions.quantity = 3;
        else {
            solutions.quantity = 1;
            solutions.solution_1 = -coeficients.c / coeficients.b;
        }
    } else {
        if (fabs(D) < EPSILON){
            solutions.quantity = 1;
            solutions.solution_1 = -coeficients.b / (2 * coeficients.a);
        } else if (D - EPSILON > 0) {
            solutions.quantity = 2;
            solutions.solution_1 = (-coeficients.b  + float(sqrt(D))) / (2 * coeficients.a);
            solutions.solution_2 = (-coeficients.b  - float(sqrt(D))) / (2 * coeficients.a);
        } else
            solutions.quantity = 0;
    }
    return &solutions;
}

void print_solutions(struct Solutions *solutions) {
    if(fabs(solutions->quantity - 3) <= EPSILON)
        printf("infinity quantity of solutions\n");
    else if(fabs(solutions->quantity) <= EPSILON)
        printf("No solutions\n");
    else if(fabs(solutions->quantity - 2) <= EPSILON)
        printf("Solution_1 = %f\nSolution_2 = %f\n", solutions->solution_1, solutions->solution_2);
    else
        printf("Solution_1 = %f\n", solutions->solution_1);
}
