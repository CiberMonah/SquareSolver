#include <stdio.h>
#include <math.h>
#include <TXLib.h>

void SquareSol(float a, float b, float c)
{
    float D = float(pow(b, 2)) - 4 * a * c;
    if ( D == 0 )
        printf("Sol1 = %.5f\n", -b / (2 * a) );
    else if ( D > 0 )
    {
        printf("Sol1 = %.5f\n", ((-b  + sqrt(D))/ (2 * a)));
        printf("Sol2 = %.5f\n", ((-b  - sqrt(D)) / (2 * a)));
    }
    else printf("There is no solutions\n");
}


int main (void){
    float a, b, c;

    printf("Enter in a row, separated by spaces, the coefficients of the quadratic equation of the form: ax^2 + bx + c = 0\n");
    scanf("%f %f %f", &a, &b, &c);
    SquareSol(a, b , c);

    return 0;
}
