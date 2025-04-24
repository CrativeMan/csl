#include "colors.h"
#include "csl.h"
#include "datatypes/dyn_array.h"
#include "datatypes/optional.h"
#include "datatypes/pair.h"
#include "datatypes/result.h"
#include "datatypes/stringbuilder.h"
#include "fileio/text.h"
#include "geometry/vector2d.h"
#include "geometry/vector3d.h"

#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

static int passedTests = 0;
static int testCount = 0;

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

void test_vector_set(void) {
    {
        v2i vec;
        csl_v2i_set(&vec, 5, 10);
        int passed = (vec.x == 5 && vec.y == 10);
        evaluate_test_results("csl_v2i_set", passed);
    }
    {
        v2f vec;
        csl_v2f_set(&vec, 5.5f, 10.5f);
        int passed = (vec.x == 5.5f && vec.y == 10.5f);
        evaluate_test_results("csl_v2f_set", passed);
    }
    {
        v3i vec;
        csl_v3i_set(&vec, 5, 10, 15);
        int passed = (vec.x == 5 && vec.y == 10 && vec.z == 15);
        evaluate_test_results("csl_v3i_set", passed);
    }
    {
        v3f vec;
        csl_v3f_set(&vec, 5.5f, 10.5f, 15.5f);
        int passed = (vec.x == 5.5f && vec.y == 10.5f && vec.z == 15.5f);
        evaluate_test_results("csl_v3f_set", passed);
    }
    {
        v2i vec;
        csl_v2i_zero(&vec);
        int passed = (vec.x == 0 && vec.y == 0);
        evaluate_test_results("csl_v2i_zero", passed);
    }
    {
        v2f vec;
        csl_v2f_zero(&vec);
        int passed = (vec.x == 0.0f && vec.y == 0.0f);
        evaluate_test_results("csl_v2f_zero", passed);
    }
    {
        v3i vec;
        csl_v3i_zero(&vec);
        int passed = (vec.x == 0 && vec.y == 0 && vec.z == 0);
        evaluate_test_results("csl_v3i_zero", passed);
    }
    {
        v3f vec;
        csl_v3f_zero(&vec);
        int passed = (vec.x == 0.0f && vec.y == 0.0f && vec.z == 0.0f);
        evaluate_test_results("csl_v3f_zero", passed);
    }
}

void test_vector_scale(void) {
    {
        v2i vec;
        csl_v2i_set(&vec, 5, 10);
        csl_v2i_scale(&vec, 2);
        int passed = (vec.x == 10 && vec.y == 20);
        evaluate_test_results("csl_v2i_scale", passed);
    }
    {
        v2i vec;
        csl_v2i_scale(&vec, 2);
        int passed = (vec.x == 0 && vec.y == 0);
        evaluate_test_results("csl_v2i_null_scale", passed);
    }
    {
        v2f vec;
        csl_v2f_set(&vec, 5.5f, 10.5f);
        csl_v2f_scale(&vec, 2);
        int passed = (vec.x == 11.0f && vec.y == 21.0f);
        evaluate_test_results("csl_v2f_scale", passed);
    }
    {
        v2f vec;
        csl_v2f_scale(&vec, 2);
        int passed = (isnan(vec.x) && isnan(vec.y));
        evaluate_test_results("csl_v2f_null_scale", passed);
    }
    {
        v3i vec;
        csl_v3i_set(&vec, 5, 10, 15);
        csl_v3i_scale(&vec, 2);
        int passed = (vec.x == 10 && vec.y == 20 && vec.z == 30);
        evaluate_test_results("csl_v3i_scale", passed);
    }
    {
        v3i vec;
        csl_v3i_scale(&vec, 2);
        int passed = (vec.x == 0 && vec.y == 0 && vec.z == 0);
        evaluate_test_results("csl_v3i_null_scale", passed);
    }
    {
        v3f vec;
        csl_v3f_set(&vec, 5.5f, 10.5f, 15.5f);
        csl_v3f_scale(&vec, 2.0f);
        int passed = (vec.x == 11.0f && vec.y == 21.0f && vec.z == 31.0f);
        evaluate_test_results("csl_v3f_scale", passed);
    }
    {
        v3f vec;
        csl_v3f_scale(&vec, 2);
        int passed = (isnan(vec.x) && isnan(vec.y) && isnan(vec.z));
        evaluate_test_results("csl_v3f_null_scale", passed);
    }
}

void test_vector_add(void) {
    {
        v2i vec1, vec2;
        csl_v2i_set(&vec1, 5, 10);
        csl_v2i_set(&vec2, 3, 4);
        csl_v2i_add_vec(&vec1, &vec2);
        int passed = (vec1.x == 8 && vec1.y == 14);
        evaluate_test_results("csl_v2i_add_vec", passed);
    }
    {
        int passed = true;
        csl_v2i_add_vec(NULL, NULL);
        evaluate_test_results("csl_v2i_add_vec_null_ptrs", passed);
    }
    {
        v2f vec1, vec2;
        csl_v2f_set(&vec1, 5.5f, 10.5f);
        csl_v2f_set(&vec2, 3.5f, 4.5f);
        csl_v2f_add_vec(&vec1, &vec2);
        int passed = (vec1.x == 9 && vec1.y == 15);
        evaluate_test_results("csl_v2f_add_vec", passed);
    }
    {
        int passed = true;
        csl_v2f_add_vec(NULL, NULL);
        evaluate_test_results("csl_v2f_add_vec_null_ptrs", passed);
    }
    {
        v3i vec1, vec2;
        csl_v3i_set(&vec1, 5, 10, 15);
        csl_v3i_set(&vec2, 3, 4, 5);
        csl_v3i_add_vec(&vec1, &vec2);
        int passed = (vec1.x == 8 && vec1.y == 14 && vec1.z == 20);
        evaluate_test_results("csl_v3i_add_vec", passed);
    }
    {
        int passed = true;
        csl_v3i_add_vec(NULL, NULL);
        evaluate_test_results("csl_v3i_add_vec_null_ptrs", passed);
    }
    {
        v3f vec1, vec2;
        csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
        csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
        csl_v3f_add_vec(&vec1, &vec2);
        int passed = (vec1.x == 9 && vec1.y == 15 && vec1.z == 21);
        evaluate_test_results("csl_v3f_add_vec", passed);
    }
    {
        int passed = true;
        csl_v3f_add_vec(NULL, NULL);
        evaluate_test_results("csl_v3f_add_vec_null_ptrs", passed);
    }
}

void test_vector_subtract(void) {
    {
        v2i vec1, vec2;
        csl_v2i_set(&vec1, 5, 10);
        csl_v2i_set(&vec2, 3, 4);
        csl_v2i_subtract(&vec1, &vec2);
        int passed = (vec1.x == 2 && vec1.y == 6);
        evaluate_test_results("csl_v2i_subtract", passed);
    }
    {
        int passed = true;
        csl_v2i_subtract(NULL, NULL);
        evaluate_test_results("csl_v2i_subtract_null_ptrs", passed);
    }
    {
        v2f vec1, vec2;
        csl_v2f_set(&vec1, 5.5f, 10.5f);
        csl_v2f_set(&vec2, 3.5f, 4.5f);
        csl_v2f_subtract(&vec1, &vec2);
        int passed = (vec1.x == 2 && vec1.y == 6);
        evaluate_test_results("csl_v2f_subtract", passed);
    }
    {
        int passed = true;
        csl_v2f_subtract(NULL, NULL);
        evaluate_test_results("csl_v2f_subtract_null_ptrs", passed);
    }
    {
        v3i vec1, vec2;
        csl_v3i_set(&vec1, 5, 10, 15);
        csl_v3i_set(&vec2, 3, 4, 5);
        csl_v3i_subtract(&vec1, &vec2);
        int passed = (vec1.x == 2 && vec1.y == 6 && vec1.z == 10);
        evaluate_test_results("csl_v3i_subtract", passed);
    }
    {
        int passed = true;
        csl_v3i_subtract(NULL, NULL);
        evaluate_test_results("csl_v3i_subtract_null_ptrs", passed);
    }
    {
        v3f vec1, vec2;
        csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
        csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
        csl_v3f_subtract(&vec1, &vec2);
        int passed = (vec1.x == 2 && vec1.y == 6 && vec1.z == 10);
        evaluate_test_results("csl_v3f_subtract", passed);
    }
    {
        int passed = true;
        csl_v3f_subtract(NULL, NULL);
        evaluate_test_results("csl_v3f_subtract_null_ptrs", passed);
    }
}

void test_vector_dot(void) {
    {
        v2i vec1, vec2;
        csl_v2i_set(&vec1, 5, 10);
        csl_v2i_set(&vec2, 3, 4);
        i32 result = csl_v2i_dot(&vec1, &vec2);
        int passed = (result == 55);
        evaluate_test_results("csl_v2i_dot", passed);
    }
    {
        i32 result = csl_v2i_dot(NULL, NULL);
        int passed = (result == -1);
        evaluate_test_results("csl_v2i_dot_null_ptrs", passed);
    }
    {
        v2f vec1, vec2;
        csl_v2f_set(&vec1, 5.5f, 10.5f);
        csl_v2f_set(&vec2, 3.5f, 4.5f);
        f32 result = csl_v2f_dot(&vec1, &vec2);
        int passed = (result == 66.5f);
        evaluate_test_results("csl_v2f_dot", passed);
    }
    {
        f32 result = csl_v2f_dot(NULL, NULL);
        int passed = (result == -1);
        evaluate_test_results("csl_v2f_dot_null_ptrs", passed);
    }
    {
        v3i vec1, vec2;
        csl_v3i_set(&vec1, 5, 10, 15);
        csl_v3i_set(&vec2, 3, 4, 5);
        i32 result = csl_v3i_dot(&vec1, &vec2);
        int passed = (result == 130);
        evaluate_test_results("csl_v3i_dot", passed);
    }
    {
        i32 result = csl_v3i_dot(NULL, NULL);
        int passed = (result == -1);
        evaluate_test_results("csl_v3i_dot_null_ptrs", passed);
    }
    {
        v3f vec1, vec2;
        csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
        csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
        f32 result = csl_v3f_dot(&vec1, &vec2);
        int passed = (result == 151.75f);
        evaluate_test_results("csl_v3f_dot", passed);
    }
    {
        f32 result = csl_v3f_dot(NULL, NULL);
        int passed = (result == -1);
        evaluate_test_results("csl_v3f_dot_null_ptrs", passed);
    }
}

void test_vector_cross(void) {
    {
        v3i vec1, vec2, result;
        csl_v3i_set(&vec1, 5, 10, 15);
        csl_v3i_set(&vec2, 3, 4, 5);
        csl_v3i_zero(&result);
        csl_v3i_cross(&result, &vec1, &vec2);
        int passed = (result.x == -10 && result.y == 20 && result.z == -10);
        evaluate_test_results("csl_v3i_cross", passed);
    }
    {
        int passed = true;
        csl_v3i_cross(NULL, NULL, NULL);
        evaluate_test_results("csl_v3i_cross_null_ptrs", passed);
    }
    {
        v3f vec1, vec2, result;
        csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
        csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
        csl_v3f_zero(&result);
        csl_v3f_cross(&result, &vec1, &vec2);
        int passed = (result.x == -12 && result.y == 24 && result.z == -12);
        evaluate_test_results("csl_v3f_cross", passed);
    }
    {
        int passed = true;
        csl_v3f_cross(NULL, NULL, NULL);
        evaluate_test_results("csl_v3f_cross_null_ptrs", passed);
    }
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

void test_fileio_readFile(void) {
    {
        char *buffer = csl_read_string_from_file("testing/testtxt.txt");
        int passed = (strcmp(buffer, "Hello, World!\nLorem Ipsum\n") == 0);
        evaluate_test_results("csl_read_string_from_file_txt", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/testmd.md");
        int passed = (strcmp(buffer, "# Heading1\n## Heading2\n") == 0);
        evaluate_test_results("csl_read_string_from_file_md", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/testbin");
        int passed = (buffer == NULL);
        evaluate_test_results("csl_read_string_from_file_bin", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/testpng.png");
        int passed = (buffer == NULL);
        evaluate_test_results("csl_read_string_from_file_png", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/testjpg.jpg");
        int passed = (buffer == NULL);
        evaluate_test_results("csl_read_string_from_file_jpg", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/notfound.txt");
        int passed = (buffer == NULL);
        evaluate_test_results("csl_read_string_from_file_not_found", passed);
        free(buffer);
    }
}

void test_fileio_writeFile(void) {
    {
        const char *buffer = "Hello, World!\nThis is a new line.\nThis is a "
                             "new line with numbers.";
        int result = csl_write_string_to_file(buffer, "testing/wrote.txt");
        evaluate_test_results("csl_write_string_to_file_txt", result);
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
}

int main(void) {
    setlocale(LC_ALL, "");
    printf("Running vector tests...\n");

    test_vector_set();
    test_vector_scale();
    test_vector_add();
    test_vector_subtract();
    test_vector_dot();
    test_vector_cross();

    printf("Running datatype tests...\n");

    test_datatype_pair();
    test_datatype_optional();
    test_datatype_result();

    printf("Running fileio tests...\n");

    test_fileio_readFile();
    test_fileio_writeFile();

    printf("Running define basic function tests...\n");
    test_defines();
    test_min_max();

    printf("Running string builder tests...\n");
    test_string_builder();

    printf("Running dyn array tests...\n");
    test_dyn_array();

    printf("\nTests completed.\n");

    char *color = passedTests == testCount ? CSL_COLOR_GREEN : CSL_COLOR_RED;
    printf("\n%s%d/%d Tests passed.%s\n", color, passedTests, testCount,
           CSL_COLOR_RESET);

    return 0;
}
