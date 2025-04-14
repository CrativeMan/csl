#ifndef CSL_DATATYPES_OPTIONAL_H
#define CSL_DATATYPES_OPTIONAL_H

#include <stdbool.h>
#include <stdio.h>

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

static inline csl_optional csl_optional_none(void) {
    return (csl_optional){.data = NULL, .has_value = false};
}

#endif // !CSL_DATATYPES_OPTIONAL_H
