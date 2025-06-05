#ifndef CSL_CSL_H
#define CSL_CSL_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Assertion that uses exit(1) to close out of the program allowing
 * for functions to run that are set to atexit
 */
#define CSL_ASSERT(_e, ...)                                                    \
    if (!(_e)) {                                                               \
        fprintf(stderr, "csl_assert: [%s:%d] ", __FILE__, __LINE__);           \
        fprintf(stderr, __VA_ARGS__);                                          \
        exit(1);                                                               \
    }

typedef float f32;
typedef double f64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef size_t usize;
typedef unsigned char uchar;

#define CSL_ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0]))
#define CSL_MIN(a, b) ((a) < (b) ? (a) : (b))
#define CSL_MAX(a, b) ((a) > (b) ? (a) : (b))
#define CSL_SWAP(a, b)                                                         \
    do {                                                                       \
        __typeof__(a) __csl_temp = (a);                                        \
        (a) = (b);                                                             \
        (b) = __csl_temp;                                                      \
    } while (0)

#endif // CSL_CSL_H
