#ifndef CSL_DATATYPES_CORE_H
#define CSL_DATATYPES_CORE_H

#include <stdbool.h>
#include <stdio.h>

// ===============================================
// Pair
// ===============================================

/**
 * A define that creates a struct with two parameters
 * @NAME the name for the to defined struct
 * @TYPE1 the first type of the pair being created
 * @TYPE2 the second type of the pair being created
 */
#define CSL_DEFINE_PAIR(NAME, TYPE1, TYPE2)                                    \
  typedef struct {                                                             \
    TYPE1 first;                                                               \
    TYPE2 second;                                                              \
  } NAME;

// ===============================================
// Optional
// ===============================================

/**
 * An optional is a datatype that can either have or have not a value.
 * This is indicated through a bool and/or a null or full data parameter.
 * @data the optional data, pointing to any data that is returned
 * !!! Ownership is transferd to the user having the optional !!!
 * @has_value, just a bool to check if a value is present or not
 */
typedef struct {
  void *data;
  bool has_value;
} csl_optional;

static inline int csl_validate_optional(csl_optional *o) {
  return (o->has_value && o->data != NULL) ||
         (!o->has_value && o->data == NULL);
}

static inline csl_optional csl_optional_some(void *value) {
  return (csl_optional){.data = value, .has_value = true};
}

static inline csl_optional csl_optional_none() {
  return (csl_optional){.data = NULL, .has_value = false};
}

// ===============================================
// Result
// ===============================================

typedef enum {
  CSL_RESULT_OK = 0,
  CSL_RESULT_WARN,
  CSL_RESULT_ERROR,
} csl_result_status;

/**
 * A result can be returned from, e.g. a function interacting with a database.
 * This can fail for example in which case we might want to return an error
 * message to the user using our api.
 * @status a quick status code, to check the result's outcome
 * @value this can be a value that is e.g. returned by the db connection
 * @error_message a const char* where we can pass in the error message that is
 * created when our result should fail
 */
typedef struct {
  csl_result_status status;
  void *value;
  const char *error_message;
} csl_result;

static inline csl_result csl_result_ok(void *value) {
  return (csl_result){
      .status = CSL_RESULT_OK, .value = value, .error_message = NULL};
}

static inline csl_result csl_result_warn(void *value, const char *message) {
  return (csl_result){
      .status = CSL_RESULT_OK, .value = value, .error_message = message};
}

static inline csl_result csl_result_error(const char *message) {
  return (csl_result){
      .status = CSL_RESULT_ERROR, .value = NULL, .error_message = message};
}

#endif // !CSL_DATATYPES_CORE_H
