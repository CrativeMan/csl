#ifndef CSL_CSL_H
#define CSL_CSL_H

#include <stdint.h>
#include <stdlib.h>

#define CSL_ASSERT(_e, ...)                                                    \
  if (!(_e)) {                                                                 \
    fprintf(stderr, __VA_ARGS__);                                              \
    exit(1);                                                                   \
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
  do {                                                                         \
    __typeof__(a) temp = (a);                                                  \
    (a) = (b);                                                                 \
    (b) = temp;                                                                \
  } while (0)

#endif // CSL_CSL_H
