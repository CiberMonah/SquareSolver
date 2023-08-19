#ifndef SQUARESOLVER_H_INCLUDED
#define SQUARESOLVER_H_INCLUDED

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

#endif // SQUARESOLVER_H_INCLUDED
