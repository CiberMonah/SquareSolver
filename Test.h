#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

const int MAX_LENGTH_OF_TEST_NAME = 256;

struct Test_data {
    Coefficients coefficients;
    Solutions solutions_ref;
    const char Name[MAX_LENGTH_OF_TEST_NAME];
};

int test_one(Test_data *data);
void test_all(void);
bool check_roots(float root_1, float root_2, float root_1_ref, float root_2_ref);

#endif // TEST_H_INCLUDED
