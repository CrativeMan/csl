#ifndef CSL_GEOMETRY_VECTOR3D_H
#define CSL_GEOMETRY_VECTOR3D_H

#include "../csl.h"

// ===============================================
// Vector 3d definitions
// ===============================================
struct vec3i_t {
    i32 x, y, z;
};

struct vec3f_t {
    f32 x, y, z;
};

// Definitions
typedef struct vec3i_t v3i;
typedef struct vec3f_t v3f;

// Setting vectors
inline void csl_v3i_set(v3i *v, i32 x, i32 y, i32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
inline void csl_v3f_set(v3f *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
inline void csl_v3i_set_value(v3i *v, i32 value) {
    v->x = value;
    v->y = value;
    v->z = value;
}
inline void csl_v3f_set_value(v3f *v, f32 value) {
    v->x = value;
    v->y = value;
    v->z = value;
}

// Initialising with zero
inline void csl_v3i_zero(v3i *v) {
    v->x = 0;
    v->y = 0;
    v->z = 0;
}
inline void csl_v3f_zero(v3f *v) {
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
}

// ===============================================
// Vector operations
// ===============================================

// Scaling
inline void csl_v3i_scale(v3i *v, f32 scale) {
    if (!v)
        return;
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;
}
inline void csl_v3f_scale(v3f *v, f32 scale) {
    if (!v)
        return;
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;
}

// Addition
inline void csl_v3i_add_vec(v3i *vto, v3i *v) {
    if (!vto || !v)
        return;
    vto->x += v->x;
    vto->y += v->y;
    vto->z += v->z;
}
inline void csl_v3f_add_vec(v3f *vto, v3f *v) {
    if (!vto || !v)
        return;
    vto->x += v->x;
    vto->y += v->y;
    vto->z += v->z;
}

// Subtraction
inline void csl_v3i_subtract(v3i *vfrom, v3i *v) {
    if (!vfrom || !v)
        return;
    vfrom->x -= v->x;
    vfrom->y -= v->y;
    vfrom->z -= v->z;
}
inline void csl_v3f_subtract(v3f *vfrom, v3f *v) {
    if (!vfrom || !v)
        return;
    vfrom->x -= v->x;
    vfrom->y -= v->y;
    vfrom->z -= v->z;
}

// Dot Product
inline i32 csl_v3i_dot(v3i *a, v3i *b) {
    if (!a || !b)
        return -1;
    return a->x * b->x + a->y * b->y + a->z * b->z;
}
inline f32 csl_v3f_dot(v3f *a, v3f *b) {
    if (!a || !b)
        return -1;
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

// Cross Product
inline void csl_v3i_cross(v3i *result, const v3i *a, const v3i *b) {
    if (! result || !a || !b)
        return;
    i32 ay_bz = a->y * b->z;
    i32 az_bx = a->z * b->x;
    i32 ax_by = a->x * b->y;
    i32 by_az = b->y * a->z;
    i32 bz_ax = b->z * a->x;
    i32 bx_ay = b->x * a->y;

    result->x = ay_bz - by_az;
    result->y = az_bx - bz_ax;
    result->z = ax_by - bx_ay;
}
inline void csl_v3f_cross(v3f *result, const v3f *a, const v3f *b) {
    if (! result || !a || !b)
        return;
    f32 ay_bz = a->y * b->z;
    f32 az_bx = a->z * b->x;
    f32 ax_by = a->x * b->y;
    f32 by_az = b->y * a->z;
    f32 bz_ax = b->z * a->x;
    f32 bx_ay = b->x * a->y;

    result->x = ay_bz - by_az;
    result->y = az_bx - bz_ax;
    result->z = ax_by - bx_ay;
}

#endif // CSL_GEOMETRY_VECTOR3D_H
