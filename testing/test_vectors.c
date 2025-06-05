#include "test.h"

#include "math/vector2d.h"
#include "math/vector3d.h"

#include <math.h>
#include <stdbool.h>

void test_vector_set(void) {
    {
        v2i vec;
        csl_v2i_set(&vec, 5, 10);
        int passed = (vec.x == 5 && vec.y == 10);
        cslint_test("csl_v2i_set", false, passed);
    }
    {
        v2f vec;
        csl_v2f_set(&vec, 5.5f, 10.5f);
        int passed = (vec.x == 5.5f && vec.y == 10.5f);
        cslint_test("csl_v2f_set", false, passed);
    }
    {
        v3i vec;
        csl_v3i_set(&vec, 5, 10, 15);
        int passed = (vec.x == 5 && vec.y == 10 && vec.z == 15);
        cslint_test("csl_v3i_set", false, passed);
    }
    {
        v3f vec;
        csl_v3f_set(&vec, 5.5f, 10.5f, 15.5f);
        int passed = (vec.x == 5.5f && vec.y == 10.5f && vec.z == 15.5f);
        cslint_test("csl_v3f_set", false, passed);
    }
    {
        v2i vec;
        csl_v2i_zero(&vec);
        int passed = (vec.x == 0 && vec.y == 0);
        cslint_test("csl_v2i_zero", false, passed);
    }
    {
        v2f vec;
        csl_v2f_zero(&vec);
        int passed = (vec.x == 0.0f && vec.y == 0.0f);
        cslint_test("csl_v2f_zero", false, passed);
    }
    {
        v3i vec;
        csl_v3i_zero(&vec);
        int passed = (vec.x == 0 && vec.y == 0 && vec.z == 0);
        cslint_test("csl_v3i_zero", false, passed);
    }
    {
        v3f vec;
        csl_v3f_zero(&vec);
        int passed = (vec.x == 0.0f && vec.y == 0.0f && vec.z == 0.0f);
        cslint_test("csl_v3f_zero", false, passed);
    }
}

void test_vector_scale(void) {
    {
        v2i vec;
        csl_v2i_set(&vec, 5, 10);
        csl_v2i_scale(&vec, 2);
        int passed = (vec.x == 10 && vec.y == 20);
        cslint_test("csl_v2i_scale", false, passed);
    }
    {
        v2i vec;
        csl_v2i_scale(&vec, 2);
        int passed = (vec.x == 0 && vec.y == 0);
        cslint_test("csl_v2i_null_scale", false, passed);
    }
    {
        v2f vec;
        csl_v2f_set(&vec, 5.5f, 10.5f);
        csl_v2f_scale(&vec, 2);
        int passed = (vec.x == 11.0f && vec.y == 21.0f);
        cslint_test("csl_v2f_scale", false, passed);
    }
    {
        v2f vec;
        csl_v2f_scale(&vec, 2);
        int passed = (isnan(vec.x) && isnan(vec.y));
        cslint_test("csl_v2f_null_scale", false, passed);
    }
    {
        v3i vec;
        csl_v3i_set(&vec, 5, 10, 15);
        csl_v3i_scale(&vec, 2);
        int passed = (vec.x == 10 && vec.y == 20 && vec.z == 30);
        cslint_test("csl_v3i_scale", false, passed);
    }
    {
        v3i vec;
        csl_v3i_scale(&vec, 2);
        int passed = (vec.x == 0 && vec.y == 0 && vec.z == 0);
        cslint_test("csl_v3i_null_scale", false, passed);
    }
    {
        v3f vec;
        csl_v3f_set(&vec, 5.5f, 10.5f, 15.5f);
        csl_v3f_scale(&vec, 2.0f);
        int passed = (vec.x == 11.0f && vec.y == 21.0f && vec.z == 31.0f);
        cslint_test("csl_v3f_scale", false, passed);
    }
    {
        v3f vec;
        csl_v3f_scale(&vec, 2);
        int passed = (isnan(vec.x) && isnan(vec.y) && isnan(vec.z));
        cslint_test("csl_v3f_null_scale", false, passed);
    }
}

void test_vector_add(void) {
    {
        v2i vec1, vec2;
        csl_v2i_set(&vec1, 5, 10);
        csl_v2i_set(&vec2, 3, 4);
        csl_v2i_add_vec(&vec1, &vec2);
        int passed = (vec1.x == 8 && vec1.y == 14);
        cslint_test("csl_v2i_add_vec", false, passed);
    }
    {
        int passed = true;
        csl_v2i_add_vec(NULL, NULL);
        cslint_test("csl_v2i_add_vec_null_ptrs", false, passed);
    }
    {
        v2f vec1, vec2;
        csl_v2f_set(&vec1, 5.5f, 10.5f);
        csl_v2f_set(&vec2, 3.5f, 4.5f);
        csl_v2f_add_vec(&vec1, &vec2);
        int passed = (vec1.x == 9 && vec1.y == 15);
        cslint_test("csl_v2f_add_vec", false, passed);
    }
    {
        int passed = true;
        csl_v2f_add_vec(NULL, NULL);
        cslint_test("csl_v2f_add_vec_null_ptrs", false, passed);
    }
    {
        v3i vec1, vec2;
        csl_v3i_set(&vec1, 5, 10, 15);
        csl_v3i_set(&vec2, 3, 4, 5);
        csl_v3i_add_vec(&vec1, &vec2);
        int passed = (vec1.x == 8 && vec1.y == 14 && vec1.z == 20);
        cslint_test("csl_v3i_add_vec", false, passed);
    }
    {
        int passed = true;
        csl_v3i_add_vec(NULL, NULL);
        cslint_test("csl_v3i_add_vec_null_ptrs", false, passed);
    }
    {
        v3f vec1, vec2;
        csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
        csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
        csl_v3f_add_vec(&vec1, &vec2);
        int passed = (vec1.x == 9 && vec1.y == 15 && vec1.z == 21);
        cslint_test("csl_v3f_add_vec", false, passed);
    }
    {
        int passed = true;
        csl_v3f_add_vec(NULL, NULL);
        cslint_test("csl_v3f_add_vec_null_ptrs", false, passed);
    }
}

void test_vector_subtract(void) {
    {
        v2i vec1, vec2;
        csl_v2i_set(&vec1, 5, 10);
        csl_v2i_set(&vec2, 3, 4);
        csl_v2i_subtract(&vec1, &vec2);
        int passed = (vec1.x == 2 && vec1.y == 6);
        cslint_test("csl_v2i_subtract", false, passed);
    }
    {
        int passed = true;
        csl_v2i_subtract(NULL, NULL);
        cslint_test("csl_v2i_subtract_null_ptrs", false, passed);
    }
    {
        v2f vec1, vec2;
        csl_v2f_set(&vec1, 5.5f, 10.5f);
        csl_v2f_set(&vec2, 3.5f, 4.5f);
        csl_v2f_subtract(&vec1, &vec2);
        int passed = (vec1.x == 2 && vec1.y == 6);
        cslint_test("csl_v2f_subtract", false, passed);
    }
    {
        int passed = true;
        csl_v2f_subtract(NULL, NULL);
        cslint_test("csl_v2f_subtract_null_ptrs", false, passed);
    }
    {
        v3i vec1, vec2;
        csl_v3i_set(&vec1, 5, 10, 15);
        csl_v3i_set(&vec2, 3, 4, 5);
        csl_v3i_subtract(&vec1, &vec2);
        int passed = (vec1.x == 2 && vec1.y == 6 && vec1.z == 10);
        cslint_test("csl_v3i_subtract", false, passed);
    }
    {
        int passed = true;
        csl_v3i_subtract(NULL, NULL);
        cslint_test("csl_v3i_subtract_null_ptrs", false, passed);
    }
    {
        v3f vec1, vec2;
        csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
        csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
        csl_v3f_subtract(&vec1, &vec2);
        int passed = (vec1.x == 2 && vec1.y == 6 && vec1.z == 10);
        cslint_test("csl_v3f_subtract", false, passed);
    }
    {
        int passed = true;
        csl_v3f_subtract(NULL, NULL);
        cslint_test("csl_v3f_subtract_null_ptrs", false, passed);
    }
}

void test_vector_dot(void) {
    {
        v2i vec1, vec2;
        csl_v2i_set(&vec1, 5, 10);
        csl_v2i_set(&vec2, 3, 4);
        i32 result = csl_v2i_dot(&vec1, &vec2);
        int passed = (result == 55);
        cslint_test("csl_v2i_dot", false, passed);
    }
    {
        i32 result = csl_v2i_dot(NULL, NULL);
        int passed = (result == -1);
        cslint_test("csl_v2i_dot_null_ptrs", false, passed);
    }
    {
        v2f vec1, vec2;
        csl_v2f_set(&vec1, 5.5f, 10.5f);
        csl_v2f_set(&vec2, 3.5f, 4.5f);
        f32 result = csl_v2f_dot(&vec1, &vec2);
        int passed = (result == 66.5f);
        cslint_test("csl_v2f_dot", false, passed);
    }
    {
        f32 result = csl_v2f_dot(NULL, NULL);
        int passed = (result == -1);
        cslint_test("csl_v2f_dot_null_ptrs", false, passed);
    }
    {
        v3i vec1, vec2;
        csl_v3i_set(&vec1, 5, 10, 15);
        csl_v3i_set(&vec2, 3, 4, 5);
        i32 result = csl_v3i_dot(&vec1, &vec2);
        int passed = (result == 130);
        cslint_test("csl_v3i_dot", false, passed);
    }
    {
        i32 result = csl_v3i_dot(NULL, NULL);
        int passed = (result == -1);
        cslint_test("csl_v3i_dot_null_ptrs", false, passed);
    }
    {
        v3f vec1, vec2;
        csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
        csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
        f32 result = csl_v3f_dot(&vec1, &vec2);
        int passed = (result == 151.75f);
        cslint_test("csl_v3f_dot", false, passed);
    }
    {
        f32 result = csl_v3f_dot(NULL, NULL);
        int passed = (result == -1);
        cslint_test("csl_v3f_dot_null_ptrs", false, passed);
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
        cslint_test("csl_v3i_cross", false, passed);
    }
    {
        int passed = true;
        csl_v3i_cross(NULL, NULL, NULL);
        cslint_test("csl_v3i_cross_null_ptrs", false, passed);
    }
    {
        v3f vec1, vec2, result;
        csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
        csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
        csl_v3f_zero(&result);
        csl_v3f_cross(&result, &vec1, &vec2);
        int passed = (result.x == -12 && result.y == 24 && result.z == -12);
        cslint_test("csl_v3f_cross", false, passed);
    }
    {
        int passed = true;
        csl_v3f_cross(NULL, NULL, NULL);
        cslint_test("csl_v3f_cross_null_ptrs", false, passed);
    }
}
