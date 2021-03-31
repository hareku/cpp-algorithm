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
template <class T> bool on_same_line(std::complex<T> a, std::complex<T> b, std::complex<T> c) {
    std::complex<T> d = (b - a) / (c - a);
    return abs(d.imag()) < std::numeric_limits<T>::epsilon();
};

// circumcenter returns the circumcenter of the given 3 points.
// This function doesn't check whether 3 points are on a same line.
// refs: https://examist.jp/mathematics/complex-plane/gaisin-fukusosuu/
template <class T> std::complex<T> circumcenter(std::complex<T> a, std::complex<T> b, std::complex<T> c) {
    std::complex<T> numerator = (a - c) * (norm(a) - norm(b)) - (a - b) * (norm(a) - norm(c));
    std::complex<T> denominator = (conj(a) - conj(b)) * (a - c) - (conj(a) - conj(c)) * (a - b);
    return numerator / denominator;
};

// ccw returns a counter clock wise type.
template <class T> int ccw(std::complex<T> a, std::complex<T> b, std::complex<T> c) {
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
template <class T> bool is_intersected(std::complex<T> a, std::complex<T> b, std::complex<T> c, std::complex<T> d) {
    return lib::geometry::ccw(a, b, c) * lib::geometry::ccw(a, b, d) <= 0
        && lib::geometry::ccw(c, d, a) * lib::geometry::ccw(c, d, b) <= 0;
};

}  // namespace lib::geometry

#endif  // LIB_GEOMETRY_UTILS
