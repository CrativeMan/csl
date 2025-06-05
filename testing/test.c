#include "test.h"
#include "colors.h"
#include "csl.h"
#include "logging.h"

#include <limits.h>
#include <locale.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int passedTests = 0;
int testCount = 0;
char *testValue = "Hello, World!";

void cslint_test(const char *test_name, bool should_fail, bool result) {
    testCount++;

    bool passed = (result && !should_fail) || (!result && should_fail);
    passed ? passedTests++ : passedTests;

    char *symbol = passed ? "✓" : "◯";
    char *color = passed ? CSL_COLOR_GREEN : CSL_COLOR_RED;
    char *context = passed ? "PASSED" : "FAILED";
    printf("%d. %s %s: %s%s%s\n", testCount, symbol, test_name, color, context,
           CSL_COLOR_RESET);

    if (should_fail && result) {
        printf("Test %s failed unexpectedly.\n", test_name);
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    setlocale(LC_ALL, "");

    printf("Running datatype tests...\n");
    {
        printf("Running vector tests...\n");
        test_vector_set();
        test_vector_scale();
        test_vector_add();
        test_vector_subtract();
        test_vector_dot();
        test_vector_cross();

        printf("Running pair tests...\n");
        test_datatype_pair();

        printf("Running optional tests...\n");
        test_datatype_optional();

        printf("Running result tests...\n");
        test_datatype_result();

        printf("Running string builder tests...\n");
        test_string_builder();

        printf("Running dyn array tests...\n");
        test_dyn_array();
    }
    printf("Running fileio tests...\n");
    {
        test_fileio_readFile();
        test_fileio_writeFile();
    }
    printf("Running define basic function tests...\n");
    {
        test_defines();
        test_min_max();
    }
    printf("Running logger tests...\n");
    {
        LOGDEV("This is a dev log message");
        LOG("This is a normal log message");
        LOGWRN("This is a warning log message");
        LOGERR("This is an error log message");
    }
    printf("\nTests completed.\n");

    char *color = passedTests == testCount ? CSL_COLOR_GREEN : CSL_COLOR_RED;
    printf("\n%s%d/%d Tests passed.%s\n", color, passedTests, testCount,
           CSL_COLOR_RESET);

    printf("\nTesting assertion...\n");
    printf("(Only false assertion should display)\n");
    CSL_ASSERT(true, "True assertion\n");
    CSL_ASSERT(false, "False assertion\n");

    return 0;
}
