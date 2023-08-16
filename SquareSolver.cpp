#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#define eps 0.000001

float *calculate_solutions(float a, float b, float c);
void print_solutions(float solutions[]);
void greeting(void);
bool check_input(void);
void input_coeficients(float *a, float *b, float *c);

float solutions[3] = {0, 0, 0};//solutions[quantity, 1_solution, 2_solution]

int main(void) {
    float a, b, c;
    int ch;

    do {
        greeting();
        input_coeficients(&a, &b, &c);//in order
        if (check_input()) {
                print_solutions(calculate_solutions(a, b, c));
                printf("Press esc to stop or any button to continue\n");
                ch = _getch();
         }
        else return 0;
    }while (ch!= 27);
}

void greeting(void) {
    printf("Enter in a row, separated by spaces, the coefficients of the quadratic equation of the form: ax^2 + bx + c = 0\n");
}

bool check_input(void) {
    if (getchar() != '\n') {
        printf("Please, follow instructions\n");
        return false;
    }
    else {
        return true;
    }
}

void input_coeficients(float *a, float *b, float *c) {
    while (scanf("%f%f%f", a, b, c) != 3) {
        while (getchar()!='\n')
            ;
        printf("Wrong input\n");
        }
}

float *calculate_solutions(float a, float b, float c) {
    float D = float(pow(b, 2)) - 4 * a * c;

    if (fabs(a) < eps) {
        if (fabs(b) < eps) solutions[0] = 3;
        else {
            solutions[0] = 1;
            solutions[1] = -c / b;
        }
    }
    else {
        if (fabs(D) < eps){
            solutions[0] = 1;
            solutions[1] = -b / (2 * a);
            }
        if  (D - eps > 0) {
            solutions[0] = 2;
            solutions[1] = (-b  + float(sqrt(D))) / (2 * a);
            solutions[2] = (-b  - float(sqrt(D))) / (2 * a);
        }
    }
    return solutions;
}

void print_solutions(float *sol) {
    if(fabs(sol[0] - 3) <= FLT_EPSILON) printf("infinity quantity of solutions\n");
    if(fabs(sol[0]) <= FLT_EPSILON) printf("No solutions\n");
    for(int i = 1;i < int(sol[0]) + 1; i++) printf("Solution%d = %f\n", i, sol[i]);
}
