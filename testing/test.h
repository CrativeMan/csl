#ifndef TESTING_TEST_H
#define TESTING_TEST_H

extern int passedTests;
extern int testCount;
extern char *testValue;

extern void evaluate_test_results(const char *test_name, int passed);

void test_datatype_pair(void);
void test_datatype_optional(void);
void test_datatype_result(void);
void test_defines(void);
void test_min_max(void);
void test_logging(void);

void test_vector_set(void);
void test_vector_scale(void);
void test_vector_add(void);
void test_vector_subtract(void);
void test_vector_dot(void);
void test_vector_cross(void);

void test_fileio_readFile(void);
void test_fileio_writeFile(void);

void test_dyn_array(void);
void test_string_builder(void);


#endif // TESTING_TEST_H
