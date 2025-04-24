#include "colors.h"
#include "csl.h"
#include "logging.h"
#include "datatypes/optional.h"
#include "datatypes/pair.h"
#include "datatypes/result.h"
#include "datatypes/stringbuilder.h"

#include "test.h"

#include <limits.h>
#include <locale.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int passedTests = 0;
int testCount = 0;

static char *testValue = "Hello, World!";

void evaluate_test_results(const char *test_name, int passed) {
    testCount++;
    if (passed)
        passedTests++;
    char *symbol = passed ? "✓" : "◯";
    char *color = passed ? CSL_COLOR_GREEN : CSL_COLOR_RED;
    char *context = passed ? "PASSED" : "FAILED";
    printf("%d. %s %s: %s%s%s\n", testCount, symbol, test_name, color, context,
           CSL_COLOR_RESET);
}

void test_datatype_pair(void) {
    {
        CSL_DEFINE_PAIR(test, int, float);
        test testt;
        testt.first = 10;
        testt.second = 20.5f;
        int passed = (testt.first == 10 && testt.second == 20.5f);
        evaluate_test_results("csl_pair", passed);
    }
}

void test_datatype_optional(void) {
    {
        csl_optional test;
        test = csl_optional_some(testValue);
        int passed =
            (test.has_value == true && strcmp(test.data, "Hello, World!") == 0);
        evaluate_test_results("csl_optional_some", passed);
    }
    {
        csl_optional test;
        test = csl_optional_none();
        int passed = (test.has_value == false && test.data == NULL);
        evaluate_test_results("csl_optional_none", passed);
    }
    {
        csl_optional some;
        csl_optional none;
        some = csl_optional_some(testValue);
        none = csl_optional_none();
        int passed =
            (csl_validate_optional(&some) && csl_validate_optional(&none));
        evaluate_test_results("csl_validate_optional", passed);
    }
}

void test_datatype_result(void) {
    {
        csl_result test;
        test = csl_result_ok(testValue);
        int passed =
            (test.status == CSL_RESULT_OK && test.error_message == NULL &&
             strcmp(test.value, "Hello, World!") == 0);
        evaluate_test_results("csl_result_ok", passed);
    }
    {
        csl_result test;
        test = csl_result_warn(testValue, "Warning");
        int passed = (test.status == CSL_RESULT_OK &&
                      strcmp(test.error_message, "Warning") == 0 &&
                      strcmp(test.value, "Hello, World!") == 0);
        evaluate_test_results("csl_result_warn", passed);
    }
    {
        csl_result test;
        test = csl_result_error("Failed");
        int passed =
            (test.status == CSL_RESULT_ERROR &&
             strcmp(test.error_message, "Failed") == 0 && test.value == NULL);
        evaluate_test_results("csl_result_error", passed);
    }
}

void test_defines(void) {
    // write more tests
    // same value, diffrent data types
    {
        int a = 10;
        int b = 20;
        CSL_SWAP(a, b);
        int passed = (a == 20 && b == 10);
        evaluate_test_results("csl_swap", passed);
    }
    // write more tests
    // no array, empty array
    {
        int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        size_t length = CSL_ARRAY_LENGTH(a);
        int passed = (length == 10);
        evaluate_test_results("csl_array_length", passed);
    }
}

void test_min_max(void) {
    {
        int a = 45;
        int b = 20;
        int result = CSL_MIN(a, b);
        int passed = (result == 20);
        evaluate_test_results("csl_min_int_different", passed);
    }
    {
        float a = 30.5f;
        float b = 40.3f;
        float result = CSL_MIN(a, b);
        int passed = (result == 30.5f);
        evaluate_test_results("csl_min_float_different", passed);
    }
    {
        int a = 45;
        int b = 20;
        int result = CSL_MAX(a, b);
        int passed = (result == 45);
        evaluate_test_results("csl_max_int_different", passed);
    }
    {
        float a = 30.5f;
        float b = 40.3f;
        float result = CSL_MAX(a, b);
        int passed = (result == 40.3f);
        evaluate_test_results("csl_max_float_different", passed);
    }
    {
        int a = 20;
        int b = 20;
        int result = CSL_MAX(a, b);
        int passed = (result == 20);
        evaluate_test_results("csl_max_int_same", passed);
    }
    {
        float a = 30.5f;
        float b = 30.5f;
        float result = CSL_MAX(a, b);
        int passed = (result == 30.5f);
        evaluate_test_results("csl_max_float_same", passed);
    }
}

void test_string_builder(void) {
    {
        csl_sb *sb = csl_sb_init();
        csl_sb_delete(sb);
        evaluate_test_results("csl_sb_init (just check if error)", 1);
    }
    {
        csl_sb *sb = csl_sb_init();
        int result = csl_sb_append(sb, "Hello, World");
        int passed =
            (result == 1 && strcmp(sb->contents, "Hello, World") == 0 &&
             sb->length == 12);
        evaluate_test_results("csl_sb_append", passed);
        csl_sb_delete(sb);
    }
    {
        csl_sb *sb = csl_sb_init();
        int result = csl_sb_append(sb, "Hello, World");
        csl_sb_clear(sb);
        int passed = (result == 1 && strcmp(sb->contents, "") == 0 &&
                      sb->length == 0 && sb->contents[0] == '\0');
        evaluate_test_results("csl_sb_clear", passed);
        csl_sb_delete(sb);
    }
    {
        csl_sb *sb = csl_sb_init();
        int result = csl_sb_append(sb, "Hello, World");
        char *rb = csl_sb_to_string(sb);
        int passed = (result == 1 && strcmp(rb, "Hello, World") == 0);
        evaluate_test_results("csl_sb_to_string", passed);
        csl_sb_delete(sb);
        free(rb);
    }
}

void test_logging(void) {
    LOGDEV("This is a dev log message");
    LOG("This is a normal log message");
    LOGWRN("This is a warning log message");
    LOGERR("This is an error log message");
    print_test_result("csl_logging_test", true);
}

int main(void) {
    setlocale(LC_ALL, "");

    printf("Running vector tests...\n");
    {
        test_vector_set();
        test_vector_scale();
        test_vector_add();
        test_vector_subtract();
        test_vector_dot();
        test_vector_cross();
    }
    printf("Running datatype tests...\n");
    {
        test_datatype_pair();
        test_datatype_optional();
        test_datatype_result();
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
        test_logging();
    }

    printf("Running string builder tests...\n");
    {
        test_string_builder();
    }
    printf("Running dyn array tests...\n");
    {
        test_dyn_array();
    }
    printf("\nTests completed.\n");

    char *color = passedTests == testCount ? CSL_COLOR_GREEN : CSL_COLOR_RED;
    printf("\n%s%d/%d Tests passed.%s\n", color, passedTests, testCount,
           CSL_COLOR_RESET);

    return 0;
}
