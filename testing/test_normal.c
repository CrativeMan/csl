#include "test.h"
#include "datatypes/optional.h"
#include "logging.h"
#include "datatypes/pair.h"
#include "datatypes/result.h"

#include <string.h>

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

void test_logging(void) {
    LOGDEV("This is a dev log message");
    LOG("This is a normal log message");
    LOGWRN("This is a warning log message");
    LOGERR("This is an error log message");
    evaluate_test_results("csl_logging_test", true);
}
