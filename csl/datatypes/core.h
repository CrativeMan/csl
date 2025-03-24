#ifndef CSL_DATATYPES_CORE_H
#define CSL_DATATYPES_CORE_H

#include <stdbool.h>
#include <stdio.h>

#define CSL_DEFINE_PAIR(NAME, TYPE1, TYPE2)                                    \
  typedef struct {                                                             \
    TYPE1 first;                                                               \
    TYPE2 second;                                                              \
  } NAME;

typedef struct {
  void *data;
  bool has_value;
} csl_optional;

typedef enum { CSL_RESULT_OK = 0, CSL_RESULT_ERROR } csl_result_status;

typedef struct {
  csl_result_status status;
  void *value;
  const char *error_message;
} csl_result;

static inline csl_optional csl_optional_some(void *value) {
  return (csl_optional){.data = value, .has_value = true};
}

static inline csl_optional csl_optional_none() {
  return (csl_optional){.data = NULL, .has_value = false};
}

static inline csl_result csl_result_ok(void *value) {
  return (csl_result){
      .status = CSL_RESULT_OK, .value = value, .error_message = NULL};
}

static inline csl_result csl_result_error(const char *message) {
  return (csl_result){
      .status = CSL_RESULT_ERROR, .value = NULL, .error_message = message};
}

#endif // !CSL_DATATYPES_CORE_H
