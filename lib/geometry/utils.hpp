#ifndef LIB_GEOMETRY_UTILS
#define LIB_GEOMETRY_UTILS 1

#include <bits/stdc++.h>

namespace lib::geometry {

// dot calculates the dot product.
template <class T> T dot(std::complex<T> a, std::complex<T> b) {
    return a.real() * b.real() + a.imag() * b.imag();
};

// cross calculates the cross product.
template <class T> T cross(std::complex<T> a, std::complex<T> b) {
    return a.real() * b.imag() - a.imag() * b.real();
};

// rotate returns a new complex number that is rotated by the given radian.
template <class T> std::complex<T> rotate(std::complex<T> a, T radian) {
    return a * std::complex<T>(cos(radian), sin(radian));
};

// on_same_line checks whether 3 points are on a same line.
template <class T> bool on_same_line(std::complex<T> a, std::complex<T> b, std::complex<T> c, const T eps = std::numeric_limits<T>::epsilon()) {
    std::complex<T> d = (b - a) / (c - a);
    return abs(d.imag()) < eps;
};

// circumcenter returns the circumcenter of the given 3 points.
// This function doesn't check whether 3 points are on a same line.
template <class T> std::complex<T> circumcenter(std::complex<T> a, std::complex<T> b, std::complex<T> c) {
    a -= c;
    b -= c;
    return (a * b * (conj(a) - conj(b))) / (conj(a) * b - a * conj(b)) + c;
};

// ccw returns a counter clock wise type.
template <class T> int ccw(std::complex<T> a, std::complex<T> b, std::complex<T> c, const T eps = std::numeric_limits<T>::epsilon()) {
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
template <class T> bool is_intersected(std::complex<T> a, std::complex<T> b, std::complex<T> c, std::complex<T> d) {
    return lib::geometry::ccw(a, b, c) * lib::geometry::ccw(a, b, d) <= 0
        && lib::geometry::ccw(c, d, a) * lib::geometry::ccw(c, d, b) <= 0;
};

// projection returns the projection point of "p" onto "p1","p2".
template <class T> std::complex<T> projection(std::complex<T> p, std::complex<T> p1, std::complex<T> p2) {
    p -= p1;
    p2 -= p1;

    p /= p2;
    return std::complex<T>(p.real(), 0) * p2 + p1;
};

// reflection returns the reflection point of "p" onto "p1","p2".
template <class T> std::complex<T> reflection(std::complex<T> p, std::complex<T> p1, std::complex<T> p2) {
    p -= p1;
    p2 -= p1;

    p /= p2;
    return conj(p) * p2 + p1;
};

}  // namespace lib::geometry

#endif  // LIB_GEOMETRY_UTILS
