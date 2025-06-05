
#include "datatypes/optional.h"
#include "datatypes/pair.h"
#include "datatypes/result.h"

#include "test.h"
#include <string.h>

void test_datatype_pair(void) {
    {
        CSL_DEFINE_PAIR(test, int, float);
        test testt;
        testt.first = 10;
        testt.second = 20.5f;
        int passed = (testt.first == 10 && testt.second == 20.5f);
        cslint_test("csl_pair", false, passed);
    }
}

void test_datatype_optional(void) {
    {
        csl_optional test;
        test = csl_optional_some(testValue);
        int passed =
            (test.has_value == true && strcmp(test.data, "Hello, World!") == 0);
        cslint_test("csl_optional_some", false, passed);
    }
    {
        csl_optional test;
        test = csl_optional_none();
        int passed = (test.has_value == false && test.data == NULL);
        cslint_test("csl_optional_none", false, passed);
    }
    {
        csl_optional some;
        csl_optional none;
        some = csl_optional_some(testValue);
        none = csl_optional_none();
        int passed =
            (csl_validate_optional(&some) && csl_validate_optional(&none));
        cslint_test("csl_validate_optional", false, passed);
    }
}

void test_datatype_result(void) {
    {
        csl_result test;
        test = csl_result_ok(testValue);
        int passed =
            (test.status == CSL_RESULT_OK && test.error_message == NULL &&
             strcmp(test.value, "Hello, World!") == 0);
        cslint_test("csl_result_ok", false,passed);
    }
    {
        csl_result test;
        test = csl_result_warn(testValue, "Warning");
        int passed = (test.status == CSL_RESULT_OK &&
                      strcmp(test.error_message, "Warning") == 0 &&
                      strcmp(test.value, "Hello, World!") == 0);
        cslint_test("csl_result_warn", false, passed);
    }
    {
        csl_result test;
        test = csl_result_error("Failed");
        int passed =
            (test.status == CSL_RESULT_ERROR &&
             strcmp(test.error_message, "Failed") == 0 && test.value == NULL);
        cslint_test("csl_result_error", false, passed);
    }
}
