#ifndef SOLVEEQUATION_H_INCLUDED
#define SOLVEEQUATION_H_INCLUDED

const float EPSILON = 0.00001f;

typedef enum Quantity_of_roots {
    SINGLE_ROOT = 0,
    REPEATED_ROOT = 1,
    TWO_ROOTS = 3,
    NO_ROOTS = -1,
    INF_ROOTS = 999
} Quantity;

struct Solutions {
    Quantity quantity_of_roots;
    float solution_1, solution_2;
};

struct Coefficients {
    float a, b, c;
};

void solve_quadratic(const Coefficients coefficients, Solutions *solutions);
void print_solutions(Solutions solutions);
float solve_line(float coef_1, float coef_2);
bool check_float_equality(const float, const float);
const char *enum_to_string(Quantity quantity_of_roots);
Quantity int_to_enum(int quantity_of_roots);


#endif // SOLVEEQUATION_H_INCLUDED
