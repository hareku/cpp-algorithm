#ifndef LIB_GEOMETRY_CIRCLE_INTERSECTION
#define LIB_GEOMETRY_CIRCLE_INTERSECTION 1

#include <bits/stdc++.h>

namespace lib::geometry {

// circles_cross checks whether circle a and circle b intersect.
template <class T> bool circles_cross(std::complex<T> a, T ar, std::complex<T> b, T br, const T eps = std::numeric_limits<T>::epsilon()) {
    T d = std::abs(a - b);
    return (ar + br - d) > eps;
};

// circles_circumscribed checks whether is a or b circle is circumscribed in the other circle.
template <class T> bool circles_circumscribed(std::complex<T> a, T ar, std::complex<T> b, T br, const T eps = std::numeric_limits<T>::epsilon()) {
    T d = std::abs(a - b);
    return std::abs(ar + br - d) < eps;
};

// circles_inscribed checks whether is a or b circle is inscribed in the other circle.
template <class T> bool circles_inscribed(std::complex<T> a, T ar, std::complex<T> b, T br, const T eps = std::numeric_limits<T>::epsilon()) {
    T d = std::abs(a - b);
    return std::abs(std::abs(ar - br) - d) < eps;
};

// circle_includes checks whether does circle include other circle.
template <class T> bool circle_includes(std::complex<T> a, T ar, std::complex<T> b, T br, const T eps = std::numeric_limits<T>::epsilon()) {
    // set the small circle to a
    if(ar > br) {
        std::swap(a, b);
        std::swap(ar, br);
    }

    return br - (std::abs(a - b) + ar) >- eps;
};

}  // namespace lib::geometry

#endif  // LIB_GEOMETRY_CIRCLE_INTERSECTION
