#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "SolveEquation.h"

const float VOID_ROOT_CODE = 909;   /// \const Using to set code for void roots when program reading from file
struct Test_data {
    Coefficients coefficients;      ///<Struct of coefficients {first_coef, second_coef, third_coef}
    Solutions solutions_ref;        ///<Struct of reference solutions {number_of_roots, 1_sol, 2_sol}
};

void test_all(void);
float roots_to_float(float root);
bool check_roots(float root_1, float root_2, float root_1_ref, float root_2_ref);
unsigned int read_test_from_file(Test_data *all_data);

#endif // TEST_H_INCLUDED
