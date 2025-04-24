#ifndef CSL_DATATYPES_PAIR_H
#define CSL_DATATYPES_PAIR_H

// ===============================================
// Pair
// ===============================================

#include "../csl.h"

typedef struct {
    f32 first;
    f32 second;
} csl_f32_pair;

typedef struct {
    i32 first;
    i32 second;
} csl_i32_pair;

typedef struct {
    u32 first;
    u32 second;
} csl_u32_pair;

/**
 * A define that creates a struct with two parameters
 * @NAME the name for the to defined struct
 * @TYPE1 the first type of the pair being created
 * @TYPE2 the second type of the pair being created
 */
#define CSL_DEFINE_PAIR(NAME, TYPE1, TYPE2)                                    \
    typedef struct {                                                           \
        TYPE1 first;                                                           \
        TYPE2 second;                                                          \
    } NAME;

#endif // !CSL_DATATYPES_PAIR_H
