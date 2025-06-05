#ifndef CSL_GEOMETRY_VECTOR2D_H
#define CSL_GEOMETRY_VECTOR2D_H

#include "../csl.h"

// ===============================================
// Vector 2d definitions
// ===============================================
struct vec2i_t {
    i32 x, y;
};

struct vec2f_t {
    f32 x, y;
};

typedef struct vec2i_t v2i;
typedef struct vec2f_t v2f;

// Setting vectors
inline void csl_v2i_set(v2i *v, i32 x, i32 y) {
    v->x = x;
    v->y = y;
}
inline void csl_v2f_set(v2f *v, f32 x, f32 y) {
    v->x = x;
    v->y = y;
}
inline void csl_v2i_set_value(v2i *v, i32 value) {
    v->x = value;
    v->y = value;
}
inline void csl_v2f_set_value(v2f *v, f32 value) {
    v->x = value;
    v->y = value;
}

// Initialising with zero
inline void csl_v2i_zero(v2i *v) {
    v->x = 0;
    v->y = 0;
}
inline void csl_v2f_zero(v2f *v) {
    v->x = 0.0f;
    v->y = 0.0f;
}

// ===============================================
// Vector operations
// ===============================================

// Scaling
inline void csl_v2i_scale(v2i *v, i32 scale) {
    if (!v)
        return;
    v->x *= scale;
    v->y *= scale;
}
inline void csl_v2f_scale(v2f *v, i32 scale) {
    if (!v)
        return;
    v->x *= scale;
    v->y *= scale;
}

// Addition
inline void csl_v2i_add_vec(v2i *vto, v2i *v) {
    if (!vto || !v)
        return;
    vto->x += v->x;
    vto->y += v->y;
}
inline void csl_v2f_add_vec(v2f *vto, v2f *v) {
    if (!vto || !v)
        return;
    vto->x += v->x;
    vto->y += v->y;
}

// Subtraction
inline void csl_v2i_subtract(v2i *vfrom, v2i *v) {
    if (!vfrom || !v)
        return;
    vfrom->x -= v->x;
    vfrom->y -= v->y;
}
inline void csl_v2f_subtract(v2f *vfrom, v2f *v) {
    if (!vfrom || !v)
        return;
    vfrom->x -= v->x;
    vfrom->y -= v->y;
}

// Dot Product
inline i32 csl_v2i_dot(v2i *a, v2i *b) {
    if (!a || !b)
        return -1;
    return a->x * b->x + a->y * b->y;
}
inline f32 csl_v2f_dot(v2f *a, v2f *b) {
    if (!a || !b)
        return -1;
    return a->x * b->x + a->y * b->y;
}
#endif // !CSL_GEOMETRY_VECTOR2D_H
