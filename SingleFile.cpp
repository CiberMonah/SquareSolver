#include <stdio.h>
#include <math.h>
#include <TXLib.h>

enum Quantity_of_roots {
    SINGLE_ROOT,
    REPETED_ROOTS,
    TWO_ROOTS,
    NO_ROOTS,
    INF_ROOTS
};

typedef enum Quantity_of_roots Quantity;

struct Solutions {
    Quantity quantity;
    float solution_1, solution_2;
};

struct Coefficients {
    float a, b, c;
};

void calculate_solutions(struct Coefficients coefficients, struct Solutions *solutions);
void print_solutions(struct Solutions solutions);
void print_instructions(void);
bool check_float_equality(float f_1, float f_2);
bool input_coefficients(struct Coefficients *coefficients);
void greeting(void);
void skip_line(void);
float solve_line(float coef_1, float coef_2);

const float EPSILON = 0.00001f;

int main(void) {
    struct Coefficients coefficients {NAN, NAN, NAN};
    struct Solutions solutions {,NAN,NAN};
    int ch = 0;
    greeting();

    do {
        print_instructions();
        if(input_coefficients(&coefficients)) {
            calculate_solutions(coefficients, &solutions);
            print_solutions(solutions);
            printf("# type e to stop or anything to continue\n");
            ch = getchar();
        }
        skip_line();
    } while (ch != 'e');
}

void print_instructions(void) {
    printf("# Enter in a row, separated by spaces, the coefficients of the quadratic equation of the form: ax^2 + bx + c = 0\n");
}

bool input_coefficients(struct Coefficients *coefficients) {
    while(true){
        if (scanf("%f%f%f", &coefficients->a, &coefficients->b, &coefficients->c) == 3) {
            if (getchar() != '\n') {
                printf("# Wrong input\n");
                return false;
            } else {
                return true;
            }
        } else {
            skip_line();
            printf("Wrong input\n");
            return false;
        }
    }

}

void calculate_solutions(const struct Coefficients coefficients, struct Solutions *solutions) {
    float discriminant = float(pow(coefficients.b, 2)) - 4 * coefficients.a * coefficients.c;

    if (check_float_equality(coefficients.a, 0)) {
        if (check_float_equality(coefficients.b, 0)) {
            solutions->quantity = INF_ROOTS;
        } else {
            solutions->quantity = SINGLE_ROOT;
            solutions->solution_1 = solve_line(coefficients.b, coefficients.c);
        }
    } else {
        if (check_float_equality(discriminant, 0)) {
            solutions->quantity = REPETED_ROOTS;
            solutions->solution_1 = -coefficients.b / (2 * coefficients.a);
        } else if (discriminant > 0) {
            float sqrted = float(sqrt(discriminant));
            solutions->quantity = TWO_ROOTS;
            solutions->solution_1 = (-coefficients.b  + sqrted) / (2 * coefficients.a);
            solutions->solution_2 = (-coefficients.b  - sqrted) / (2 * coefficients.a);
        } else {
            solutions->quantity = NO_ROOTS;
        }
    }
}

void print_solutions(const struct Solutions solutions) {
    switch(solutions.quantity) {
        case NO_ROOTS:
            printf("# No solutions\n");
            break;
        case INF_ROOTS:
            printf("# Infinity quantity of solutions\n");
            break;
        case SINGLE_ROOT:
            printf("# Solution = %.5f\n", solutions.solution_1);
            break;
        case REPETED_ROOTS:
            printf("# Repeted solution = %.5f\n", solutions.solution_1);
            break;
        case TWO_ROOTS:
            printf("# First solution = %.5f\n# Second solution = %.5f\n", solutions.solution_1, solutions.solution_2);
            break;
        default:
            printf("# Error wrong quantity of solutions");
    }
}

bool check_float_equality(const float f_1, const float f_2) {
    return (fabs(f_1 - f_2) <= EPSILON);
}

void skip_line(void) {
   while(getchar() != '\n');
}

float solve_line(float coef_1, float coef_2) {
    assert(!check_float_equality(coef_1, 0));
    return -coef_2 / coef_1;
}

void greeting(void) {
    printf("#Author: Glisanov Andrej\n# Last update 22/08 21:55\n\n");
}
