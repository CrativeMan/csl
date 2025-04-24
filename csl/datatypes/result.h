#ifndef CSL_DATATYPES_RESULT_H
#define CSL_DATATYPES_RESULT_H

#include <stdio.h>

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

#endif // !CSL_DATATYPES_RESULT_H
