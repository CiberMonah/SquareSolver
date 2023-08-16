#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#define eps 0.00001

void calculate_solutions(float a, float b, float c);
void print_solutions(float solution1);
void print_solutions(float solution1, float solution2);
void greeting(void);
bool check_input(void);
void input_coeficients(float *a, float *b, float *c);

int main(void) {
    float a, b, c;
    int ch;

    do {
        greeting();
        input_coeficients(&a, &b, &c);//in order
        if (check_input()) {
                calculate_solutions(a, b, c);
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

void calculate_solutions(float a, float b, float c) {
    float D = float(pow(b, 2)) - 4 * a * c;

    if (fabs(a) < eps) {
        if (fabs(b) < eps) printf("infinite number of solutions\n");
        else print_solutions(-c / b);
    }
    else {
        if (fabs(D) < eps)
            print_solutions(-b / (2 * a));
        else if (D - eps > 0) {
            print_solutions((-b  + float(sqrt(D))) / (2 * a), (-b  - float(sqrt(D))) / (2 * a));
        }
        else printf("There is no solutions\n");
    }
}

void print_solutions(float solution1, float solution2) {
    printf("Solution_1 = %.5f\n", solution1);
    printf("Solution_2 = %.5f\n", solution2);
}

void print_solutions(float solution1) {
    printf("Solution_1 = %.5f\n", solution1);
}
