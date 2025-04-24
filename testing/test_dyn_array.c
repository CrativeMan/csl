#include "test.h"

#include "datatypes/dyn_array.h"


void test_dyn_array(void) {
    {
        csl_dyn_array_t(arr, i32);
        csl_dyn_array_append(arr, 10);
        csl_dyn_array_append(arr, 20);
        csl_dyn_array_append(arr, 30);
        int passed = (arr.length = 3 && arr.data[0] == 10 && arr.data[1] == 20 && arr.data[2] == 30);
        evaluate_test_results("csl_dyn_array_append_normal", passed);
        free(arr.data);
    }
    {
        csl_dyn_array_t(arr, i32);
        csl_dyn_array_append(arr, 10);
        csl_dyn_array_append(arr, 20);
        csl_dyn_array_append(arr, 30);
        csl_dyn_array_pop(arr);
        int passed = (arr.length = 2 && arr.data[0] == 10 && arr.data[1] == 20);
        evaluate_test_results("csl_dyn_array_pop_normal", passed);
    }
    {
        csl_dyn_array_t(arr, i32);
        csl_dyn_array_append(arr, 10);
        csl_dyn_array_append(arr, 20);
        csl_dyn_array_append(arr, 30);
        csl_dyn_array_shift(arr);
        int passed = (arr.length == 2 && arr.data[0] == 20 && arr.data[1] == 30);
        evaluate_test_results("csl_dyn_array_shift_normal", passed);
    }
    {
        csl_dyn_array_t(arr, i32);
        csl_dyn_array_append(arr, 10);
        csl_dyn_array_append(arr, 20);
        csl_dyn_array_append(arr, 30);
        csl_dyn_array_unshift(arr, 11);
        int passed = (arr.length == 4 && arr.data[0] == 11 && arr.data[1] == 10 && arr.data[2] == 20 && arr.data[3] == 30);
        evaluate_test_results("csl_dyn_array_unshift_normal", passed);
    }
    {
        csl_dyn_array_t(arr, i32);
        csl_dyn_array_append(arr, 10);
        csl_dyn_array_append(arr, 20);
        csl_dyn_array_append(arr, 30);
        csl_dyn_array_insert(arr, 1, 11);
        int passed = (arr.length == 4 && arr.data[0] == 10 && arr.data[1] == 11 && arr.data[2] == 20 && arr.data[3] == 30);
        evaluate_test_results("csl_dyn_array_insert_normal", passed);
    }
    {
        csl_dyn_array_t(arr, i32);
        csl_dyn_array_append(arr, 10);
        csl_dyn_array_append(arr, 20);
        csl_dyn_array_append(arr, 30);
        csl_dyn_array_remove(arr, 1);
        int passed = (arr.length == 2 && arr.data[0] == 10 && arr.data[1] == 30);
        evaluate_test_results("csl_dyn_array_remove_normal", passed);
    }
    {
        csl_dyn_array_t(arr, i32);
        csl_dyn_array_append(arr, 10);
        csl_dyn_array_append(arr, 20);
        csl_dyn_array_append(arr, 30);
        int passed = (arr.length == 3 && *csl_dyn_array_at(arr, 1) == 20);
        evaluate_test_results("csl_dyn_array_at_normal", passed);
    }
    {
        csl_dyn_array_t(arr, i32);
        csl_dyn_array_append(arr, 10);
        csl_dyn_array_append(arr, 20);
        csl_dyn_array_append(arr, 30);
        csl_dyn_array_clear(arr);
        int passed = (arr.length == 0);
        evaluate_test_results("csl_dyn_array_clear_normal", passed);
    }
}
