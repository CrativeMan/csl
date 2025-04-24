#ifndef CSL_DATATYPES_DYN_ARRAY_H
#define CSL_DATATYPES_DYN_ARRAY_H

#include "csl.h"
#include <string.h>

#define CSL_DYN_ARRAY_INITIAL_CAPACITY 2
#define CSL_DYN_ARRAY_GROWTH_FACTOR 2

#define csl_dyn_array_t(name, type)                                            \
    typedef struct {                                                           \
        type *data;                                                            \
        usize length;                                                          \
        usize capacity;                                                        \
    } csl_dyn_array_##type;                                                    \
    csl_dyn_array_##type name = {0}

#define _csl_dyn_array_grow(array)                                             \
    do {                                                                       \
        if (array.length >= array.capacity) {                                  \
            if (array.capacity == 0)                                           \
                array.capacity = CSL_DYN_ARRAY_INITIAL_CAPACITY;               \
            else {                                                             \
                array.capacity *= CSL_DYN_ARRAY_GROWTH_FACTOR;                 \
            }                                                                  \
            array.data =                                                       \
                realloc(array.data, array.capacity * sizeof(*array.data));     \
        }                                                                      \
    } while (0)

#define csl_dyn_array_append(array, value)                                     \
    do {                                                                       \
        _csl_dyn_array_grow(array);                                            \
        array.data[array.length++] = value;                                    \
    } while (0)

#define csl_dyn_array_pop(array)                                               \
    do {                                                                       \
        CSL_ASSERT(array.length > 0,                                           \
                   "csl: dyn array length should be > 0 to pop");              \
        array.data[array.length - 1] = 0;                                      \
        array.length--;                                                        \
    } while (0)

#define csl_dyn_array_shift(array)                                             \
    do {                                                                       \
        CSL_ASSERT(array.length > 0,                                           \
                   "csl: dyn array length should be > 0 to shift");            \
        memmove(&array.data[0], &array.data[1],                                \
                (array.length - 1) * sizeof(*array.data));                     \
        array.length--;                                                        \
    } while (0)

#define csl_dyn_array_unshift(array, value)                                    \
    do {                                                                       \
        _csl_dyn_array_grow(array);                                            \
        memmove(&array.data[1], &array.data[0],                                \
                array.length * sizeof(*array.data));                           \
        array.data[0] = value;                                                 \
        array.length++;                                                        \
    } while (0)

#define csl_dyn_array_insert(array, index, value)                              \
    do {                                                                       \
        _csl_dyn_array_grow(array);                                            \
        memmove(&array.data[index + 1], &array.data[index],                    \
                (array.length - index) * sizeof(*array.data));                 \
        array.data[index] = value;                                             \
        array.length++;                                                        \
    } while (0)

#define csl_dyn_array_remove(array, index)                                     \
    do {                                                                       \
        CSL_ASSERT(array.length > 0,                                           \
                   "csl: dyn array length should be > 0 to remove");           \
        memmove(&array.data[index], &array.data[index + 1],                    \
                (array.length - index - 1) * sizeof(*array.data));             \
        array.length--;                                                        \
    } while (0)

#define csl_dyn_array_at(array, index)                                         \
    ({                                                                         \
        CSL_ASSERT(index >= 0 && index < array.length,                         \
                   "csl: dyn array index out of bounds");                      \
            &array.data[index];                                                \
    })

#define csl_dyn_array_clear(array)                                             \
    do {                                                                       \
        array.length = 0;                                                      \
    } while (0)

#endif // CSL_DATATYPES_DYN_ARRAY_H
