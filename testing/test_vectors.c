#include "test.h"

#include "geometry/vector2d.h"
#include "geometry/vector3d.h"

#include <math.h>
#include <stdbool.h>

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
