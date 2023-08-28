#ifndef SOLVEEQUATION_H_INCLUDED
#define SOLVEEQUATION_H_INCLUDED
/*!Constant to compare floats with chosen accuracy*/
const float EPSILON = 0.00001f;
/// \enum  Enumeration of all possible options of quantity of roots square equation

typedef enum Quantity_of_roots /*!Enumeration using to store codes of types quantites of roots*/{
    SINGLE_ROOT = 0,///<One root of linear equation
    REPEATED_ROOT = 1,///<One root of square equation
    TWO_ROOTS = 3,///<Two roots of square equation
    NO_ROOTS = -1,///<No roots
    INF_ROOTS = 999///<Infinite roots
} Quantity;

/// \brief struct stores quantity of solutions and solutions of equation
struct Solutions {
    Quantity quantity_of_roots;///<Quantity of roots of square equation
    float solution_1/*!First solution, if solution not exist it equals NAN*/, solution_2/*! Float second solution, if solution not exist it equals NAN*/;
};

/// \brief struct stores coefficients of equation
struct Coefficients {
    float a/*!First coefficient of square equation*/,
    b/*!Second coefficient of square equation*/,
    c/*!Third coefficient of square equation*/;
};

void solve_quadratic(const Coefficients coefficients, Solutions *solutions);
void print_solutions(Solutions solutions);
float solve_line(float coef_1, float coef_2);
bool check_float_equality(const float, const float);
const char *enum_to_string(Quantity quantity_of_roots);
Quantity int_to_enum(int quantity_of_roots);

#endif // SOLVEEQUATION_H_INCLUDED
