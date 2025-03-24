#include "csl/colors.h"
#include "csl/geometry/vectors.h"

#include <locale.h>
#include <stdio.h>

static int passedTests = 0;
static int testCount = 0;

void print_test_result(const char *test_name, int passed) {
  testCount++;
  if (passed)
    passedTests++;
  char *symbol = passed ? "✓" : "◯";
  char *color = passed ? CSL_COLOR_GREEN : CSL_COLOR_RED;
  char *context = passed ? "PASSED" : "FAILED";
  printf("%s %s: %s%s%s\n", symbol, test_name, color, context, CSL_COLOR_RESET);
}

void test_vector_set() {
  {
    v2i vec;
    csl_v2i_set(&vec, 5, 10);
    int passed = (vec.x == 5 && vec.y == 10);
    print_test_result("csl_v2i_set", passed);
  }
  {
    v2f vec;
    csl_v2f_set(&vec, 5.5f, 10.5f);
    int passed = (vec.x == 5.5f && vec.y == 10.5f);
    print_test_result("csl_v2f_set", passed);
  }
  {
    v3i vec;
    csl_v3i_set(&vec, 5, 10, 15);
    int passed = (vec.x == 5 && vec.y == 10 && vec.z == 15);
    print_test_result("csl_v3i_set", passed);
  }
  {
    v3f vec;
    csl_v3f_set(&vec, 5.5f, 10.5f, 15.5f);
    int passed = (vec.x == 5.5f && vec.y == 10.5f && vec.z == 15.5f);
    print_test_result("csl_v3f_set", passed);
  }
  // Initialize to zero
  {
    v2i vec;
    csl_v2i_zero(&vec);
    int passed = (vec.x == 0 && vec.y == 0);
    print_test_result("csl_v2i_zero", passed);
  }
  {
    v2f vec;
    csl_v2f_zero(&vec);
    int passed = (vec.x == 0.0f && vec.y == 0.0f);
    print_test_result("csl_v2f_zero", passed);
  }
  {
    v3i vec;
    csl_v3i_zero(&vec);
    int passed = (vec.x == 0 && vec.y == 0 && vec.z == 0);
    print_test_result("csl_v3i_zero", passed);
  }
  {
    v3f vec;
    csl_v3f_zero(&vec);
    int passed = (vec.x == 0.0f && vec.y == 0.0f && vec.z == 0.0f);
    print_test_result("csl_v3f_zero", passed);
  }
}

void test_vector_scale() {
  {
    v2i vec;
    csl_v2i_set(&vec, 5, 10);
    csl_v2i_scale(&vec, 2);
    int passed = (vec.x == 10 && vec.y == 20);
    print_test_result("csl_v2i_scale", passed);
  }
  {
    v2f vec;
    csl_v2f_set(&vec, 5.5f, 10.5f);
    csl_v2f_scale(&vec, 2);
    int passed = (vec.x == 11.0f && vec.y == 21.0f);
    print_test_result("csl_v2f_scale", passed);
  }
  {
    v3i vec;
    csl_v3i_set(&vec, 5, 10, 15);
    csl_v3i_scale(&vec, 2);
    int passed = (vec.x == 10 && vec.y == 20 && vec.z == 30);
    print_test_result("csl_v3i_scale", passed);
  }
  {
    v3f vec;
    csl_v3f_set(&vec, 5.5f, 10.5f, 15.5f);
    csl_v3f_scale(&vec, 2.0f);
    int passed = (vec.x == 11.0f && vec.y == 21.0f && vec.z == 31.0f);
    print_test_result("csl_v3f_scale", passed);
  }
}

void test_vector_add() {
  {
    v2i vec1, vec2;
    csl_v2i_set(&vec1, 5, 10);
    csl_v2i_set(&vec2, 3, 4);
    csl_v2i_add_vec(&vec1, &vec2);
    int passed = (vec1.x == 8 && vec1.y == 14);
    print_test_result("csl_v2i_add_vec", passed);
  }
  {
    v2f vec1, vec2;
    csl_v2f_set(&vec1, 5.5f, 10.5f);
    csl_v2f_set(&vec2, 3.5f, 4.5f);
    csl_v2f_add_vec(&vec1, &vec2);
    int passed = (vec1.x == 9 && vec1.y == 15);
    print_test_result("csl_v2f_add_vec", passed);
  }
  {
    v3i vec1, vec2;
    csl_v3i_set(&vec1, 5, 10, 15);
    csl_v3i_set(&vec2, 3, 4, 5);
    csl_v3i_add_vec(&vec1, &vec2);
    int passed = (vec1.x == 8 && vec1.y == 14 && vec1.z == 20);
    print_test_result("csl_v3i_add_vec", passed);
  }
  {
    v3f vec1, vec2;
    csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
    csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
    csl_v3f_add_vec(&vec1, &vec2);
    int passed = (vec1.x == 9 && vec1.y == 15 && vec1.z == 21);
    print_test_result("csl_v3f_add_vec", passed);
  }
}

void test_vector_subtract() {
  {
    v2i vec1, vec2;
    csl_v2i_set(&vec1, 5, 10);
    csl_v2i_set(&vec2, 3, 4);
    csl_v2i_subtract(&vec1, &vec2);
    int passed = (vec1.x == 2 && vec1.y == 6);
    print_test_result("csl_v2i_subtract", passed);
  }
  {
    v2f vec1, vec2;
    csl_v2f_set(&vec1, 5.5f, 10.5f);
    csl_v2f_set(&vec2, 3.5f, 4.5f);
    csl_v2f_subtract(&vec1, &vec2);
    int passed = (vec1.x == 2 && vec1.y == 6);
    print_test_result("csl_v2f_subtract", passed);
  }
  {
    v3i vec1, vec2;
    csl_v3i_set(&vec1, 5, 10, 15);
    csl_v3i_set(&vec2, 3, 4, 5);
    csl_v3i_subtract(&vec1, &vec2);
    int passed = (vec1.x == 2 && vec1.y == 6 && vec1.z == 10);
    print_test_result("csl_v3i_subtract", passed);
  }
  {
    v3f vec1, vec2;
    csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
    csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
    csl_v3f_subtract(&vec1, &vec2);
    int passed = (vec1.x == 2 && vec1.y == 6 && vec1.z == 10);
    print_test_result("csl_v3f_subtract", passed);
  }
}

void test_vector_dot() {
  {
    v2i vec1, vec2;
    csl_v2i_set(&vec1, 5, 10);
    csl_v2i_set(&vec2, 3, 4);
    i32 result = csl_v2i_dot(&vec1, &vec2);
    int passed = (result == 55);
    print_test_result("csl_v2i_dot", passed);
  }
  {
    v2f vec1, vec2;
    csl_v2f_set(&vec1, 5.5f, 10.5f);
    csl_v2f_set(&vec2, 3.5f, 4.5f);
    f32 result = csl_v2f_dot(&vec1, &vec2);
    int passed = (result == 66.5f);
    print_test_result("csl_v2f_dot", passed);
  }
  {
    v3i vec1, vec2;
    csl_v3i_set(&vec1, 5, 10, 15);
    csl_v3i_set(&vec2, 3, 4, 5);
    i32 result = csl_v3i_dot(&vec1, &vec2);
    int passed = (result == 130);
    print_test_result("csl_v3i_dot", passed);
  }
  {
    v3f vec1, vec2;
    csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
    csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
    f32 result = csl_v3f_dot(&vec1, &vec2);
    int passed = (result == 151.75f);
    print_test_result("csl_v3f_dot", passed);
  }
}

void test_vector_cross() {
  {
    v3i vec1, vec2, result;
    csl_v3i_set(&vec1, 5, 10, 15);
    csl_v3i_set(&vec2, 3, 4, 5);
    csl_v3i_zero(&result);
    csl_v3i_cross(&result, &vec1, &vec2);
    int passed = (result.x == -10 && result.y == 20 && result.z == -10);
    print_test_result("csl_v3i_cross", passed);
  }
  {
    v3f vec1, vec2, result;
    csl_v3f_set(&vec1, 5.5f, 10.5f, 15.5f);
    csl_v3f_set(&vec2, 3.5f, 4.5f, 5.5f);
    csl_v3f_zero(&result);
    csl_v3f_cross(&result, &vec1, &vec2);
    int passed = (result.x == -12 && result.y == 24 && result.z == -12);
    print_test_result("csl_v3f_cross", passed);
  }
}

int main() {
  setlocale(LC_ALL, "");
  printf("Running vector tests...\n");

  test_vector_set();
  test_vector_scale();
  test_vector_add();
  test_vector_subtract();
  test_vector_dot();
  test_vector_cross();

  char *color = passedTests == testCount ? CSL_COLOR_GREEN : CSL_COLOR_RED;
  printf("%s%d/%d Tests passed.%s\n", color, passedTests, testCount,
         CSL_COLOR_RESET);
  printf("Tests completed.\n");

  return 0;
}
