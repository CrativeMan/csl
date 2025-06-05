#include "csl.h"
#include "test.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void test_defines(void) {
    {
        int a = 10;
        int b = 20;
        CSL_SWAP(a, b);
        int passed = (a == 20 && b == 10);
        cslint_test("csl_swap_int", false, passed);
    }
    {
        float a = 13.5f;
        float b = 20.3f;
        CSL_SWAP(a, b);
        int passed = (a == 20.3f && b == 13.5f);
        cslint_test("csl_swap_float", false, passed);
    }
    {
        float a = -1.4f;
        int b = 2;
        CSL_SWAP(a, b);
        int passed = (a == 2 && b == -1.4f);
        cslint_test("csl_swap_different_types", true, passed);
    }
    {
        int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        size_t length = CSL_ARRAY_LENGTH(a);
        int passed = (length == 10);
        cslint_test("csl_array_length", false, passed);
    }
}

void test_min_max(void) {
    {
        int a = 45;
        int b = 20;
        int result = CSL_MIN(a, b);
        int passed = (result == 20);
        cslint_test("csl_min_int_different", false, passed);
    }
    {
        float a = 30.5f;
        float b = 40.3f;
        float result = CSL_MIN(a, b);
        int passed = (result == 30.5f);
        cslint_test("csl_min_float_different", false, passed);
    }
    {
        int a = 45;
        int b = 20;
        int result = CSL_MAX(a, b);
        int passed = (result == 45);
        cslint_test("csl_max_int_different", false, passed);
    }
    {
        float a = 30.5f;
        float b = 40.3f;
        float result = CSL_MAX(a, b);
        int passed = (result == 40.3f);
        cslint_test("csl_max_float_different", false, passed);
    }
    {
        int a = 20;
        int b = 20;
        int result = CSL_MAX(a, b);
        int passed = (result == 20);
        cslint_test("csl_max_int_same", false, passed);
    }
    {
        float a = 30.5f;
        float b = 30.5f;
        float result = CSL_MAX(a, b);
        int passed = (result == 30.5f);
        cslint_test("csl_max_float_same", false, passed);
    }
}
