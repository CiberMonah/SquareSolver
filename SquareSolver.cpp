#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#define eps 0.00001

void SquareSol(float a, float b, float c);

int main (void) {
    float a, b, c;
    int ch;

     do {
        printf("Enter in a row, separated by spaces, the coefficients of the quadratic equation of the form: ax^2 + bx + c = 0\n");
        scanf("%f%f%f", &a, &b, &c);
        if (getchar()!= '\n') {
        printf("Please, follow instructions\n");
        return 0;
        }
        else {
            SquareSol(a, b, c);
            printf("Press esc to stop or any button to continue\n");
            ch = _getch();
        }
    }while (ch!= 27);

}

void SquareSol(float a, float b, float c) {
    float D = float(pow(b, 2)) - 4 * a * c;

    if (fabs(a - 0) < eps) {
        if (fabs(b - 0) < eps) printf("infinite number of solutions");
        else printf("Sol1 = %.5f", -c / b);
    }
    else {
        if (fabs(D - 0) < eps)
            printf("Sol1 = %.5f\n", -b / (2 * a));
        else if (fabs(D - eps) > 0) {
            printf("Sol1 = %.5f\n", ((-b  + sqrt(D)) / (2 * a)));
            printf("Sol2 = %.5f\n", ((-b  - sqrt(D)) / (2 * a)));
        }
        else printf("There is no solutions\n");
    }
}
