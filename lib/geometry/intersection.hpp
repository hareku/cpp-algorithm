#ifndef LIB_GEOMETRY_INTERSECTION_CHECKER
#define LIB_GEOMETRY_INTERSECTION_CHECKER 1

#include <bits/stdc++.h>

namespace lib::geometry {

// dot calculates the dot product.
template <class T> T dot(complex<T> a, complex<T> b) {
    return a.real() * b.real() + a.imag() * b.imag();
};

// cross calculates the cross product.
template <class T> T cross(complex<T> a, complex<T> b) {
    return a.real() * b.imag() - a.imag() * b.real();
};

// ccw returns a counter clock wise type.
template <class T> int ccw(complex<T> a, complex<T> b, complex<T> c) {
    const T eps = std::numeric_limits<T>::epsilon();

    if(lib::geometry::cross(b - a, c - a) > eps) {
        return 1;
    }
    if(lib::geometry::cross(b - a, c - a) < -eps) {
        return -1;
    }
    if(lib::geometry::dot(b - a, c - a) < -eps) {
        return 2;
    }
    if(norm(b - a) + eps < norm(c - a)) {
        return -2;
    }
    return 0;
};

// is_intersected checks whether line "ab" and "cd" are intersected.
// refs: https://hcpc-hokudai.github.io/archive/geometry_004.pdf
// refs: https://www.slideshare.net/hcpc_hokudai/kika-80076550
template <class T> bool is_intersected(complex<T> a, complex<T> b, complex<T> c, complex<T> d) {
    return lib::geometry::ccw(a, b, c) * lib::geometry::ccw(a, b, d) <= 0
        && lib::geometry::ccw(c, d, a) * lib::geometry::ccw(c, d, b) <= 0;
};

}  // namespace lib::geometry

#endif  // LIB_GEOMETRY_INTERSECTION_CHECKER
