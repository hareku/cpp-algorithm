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

// innercenter returns the inner center of the given 3 points.
// This function doesn't check whether 3 points are on a same line.
template <class T> std::complex<T> innercenter(std::complex<T> a, std::complex<T> b, std::complex<T> c) {
    a -= c;
    b -= c;
    std::complex<T> z = (a * std::complex<T>(std::abs(b), 0) + b * std::complex<T>(std::abs(a), 0)) / std::complex<T>(std::abs(a) + std::abs(b) + std::abs(b - a), 0);
    return z + c;
};

// ccw returns a clockwise type.
// type 1: if p2 is counter-clockwise from p1 centered on p0.
// type -1: if p2 is clockwise from p1 centered on p0.
// type 2: if p2 is opposite of p1 centered on p0.
// type -2: if p1 and p2 are on the same line, and p2 is larger norm than p1.
// type 0: if p1 and p2 are on the same line, and p1 is larger norm than p2.
template <class T> int ccw(std::complex<T> p0, std::complex<T> p1, std::complex<T> p2, const T eps = std::numeric_limits<T>::epsilon()) {
    if(lib::geometry::cross(p1 - p0, p2 - p0) > eps) {
        return 1;
    }
    if(lib::geometry::cross(p1 - p0, p2 - p0) < -eps) {
        return -1;
    }
    if(lib::geometry::dot(p1 - p0, p2 - p0) < -eps) {
        return 2;
    }
    if(norm(p1 - p0) + eps < norm(p2 - p0)) {
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

// is_parallel checks whether line "ab" and "cd" are parallel.
template <class T> bool is_parallel(std::complex<T> a, std::complex<T> b, std::complex<T> c, std::complex<T> d, const T eps = std::numeric_limits<T>::epsilon()) {
    std::complex<T> e = (b - a) / (d - c);
    return std::abs(e.imag()) < eps;
};

// is_orthogonal checks whether line "ab" and "cd" are orthogonal.
template <class T> bool is_orthogonal(std::complex<T> a, std::complex<T> b, std::complex<T> c, std::complex<T> d, const T eps = std::numeric_limits<T>::epsilon()) {
    std::complex<T> e = (d - c) / (b - a);
    return std::abs(e.real()) < eps;
};

// crosspoint returns the cross point of "ab" and "cd".
template <class T> std::complex<T> crosspoint(std::complex<T> a, std::complex<T> b, std::complex<T> c, std::complex<T> d) {
    return a + std::complex<T>(lib::geometry::cross(a - c, d - c) / lib::geometry::cross(d - c, b - a), 0) * (b - a);
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

// distance_p2l returns the minimum distance of "p" to "ab".
template <class T> T distance_p2l(std::complex<T> p, std::complex<T> a, std::complex<T> b, const T eps = std::numeric_limits<T>::epsilon()) {
    // point to edges
    T distance = std::min(std::abs(p - a), std::abs(p - b));

    // point to projection point
    {
        auto prj = lib::geometry::projection(p, a, b);
        if(lib::geometry::ccw(a, prj, b, eps) == -2) {
            distance = std::min(distance, std::abs(p - prj));
        }
    }

    return distance;
};

// distance_l2l returns the minimum distance between "ab" and "cd".
template <class T> T distance_l2l(std::complex<T> a, std::complex<T> b, std::complex<T> c, std::complex<T> d, const T eps = std::numeric_limits<T>::epsilon()) {
    if(lib::geometry::is_intersected(a, b, c, d)) {
        return T{0};
    }

    return std::min<T>(
        std::min(lib::geometry::distance_p2l(a, c, d, eps), lib::geometry::distance_p2l(b, c, d, eps)),
        std::min(lib::geometry::distance_p2l(c, a, b, eps), lib::geometry::distance_p2l(d, a, b, eps))
    );
};

// area returns the area of the given polygon.
// The given points should be sorted clockwise or counter-clockwise.
template <class T> T area(const std::vector<std::complex<T>>& points) {
    int n = int(points.size());
    if(n <= 1) {
        return T{0};
    }

    T area = 0;
    for(int i = 0; i < n; ++i) {
        area += lib::geometry::cross(points[i], points[(i + 1) % n]);
    }
    return std::abs(area / T{2});
};

// is_convex checks whether is the given polygon convex.
// The given points should be sorted counter-clockwise.
template <class T> T is_convex(const std::vector<std::complex<T>>& points, const T eps = std::numeric_limits<T>::epsilon()) {
    int n = int(points.size());
    for(int i = 0; i < n; ++i) {
        if(lib::geometry::cross(points[i] - points[(i + 2) % n], points[(i + 1) % n] - points[(i + 2) % n]) < -eps) {
            return false;
        }
    }
    return true;
};

// in_polygon checks whether is the given "p" in the given polygon.
// If "p" is on the polygon's line, return 1.
// If "p" is in the polygon, return 2.
// If "p" is not on the polygon, return 0.
template <class T> int in_polygon(std::complex<T> p, const std::vector<std::complex<T>>& points, const T eps = std::numeric_limits<T>::epsilon()) {
    int n = int(points.size());
    bool in = 0;
    for(int i = 0; i < n; ++i) {
        std::complex<T> a = points[i] - p;
        std::complex<T> b = points[(i + 1) % n] - p;

        if(std::abs(lib::geometry::cross(a, b)) < eps && lib::geometry::dot(a, b) < eps) {
            return 1;
        }

        if(a.imag() > b.imag()) {
            std::swap(a, b);
        }
        if((a.imag() * b.imag() < eps && b.imag() > eps) && lib::geometry::cross(a, b) < eps) {
            in = !in;
        }
    }
    return in ? 2 : 0;
};

// convex_hull returns the convex hull of the given points.
// Time complexity is [N * log N].
template <class T> std::vector<std::complex<T>> convex_hull(std::vector<std::complex<T>>& ps) {
    // algorithm is Andrew's Monotone Chain.
    // ref: http://www.prefield.com/algorithm/geometry/convex_hull.html

    int n = int(ps.size());

    auto cpm_y = [](std::complex<T>& a, std::complex<T>& b)->bool {
        return a.imag() != b.imag() ? a.imag() < b.imag() : a.real() < b.real();
    };
    std::sort(ps.begin(), ps.end(), cpm_y);

    int k = 0;
    std::vector<std::complex<T>> convex(n * 2);
    for(int i = 0; i < n; i++) {
        while (k >= 2 && lib::geometry::ccw(convex[k - 2], convex[k - 1], ps[i]) == -1) k--;
        convex[k++] = ps[i];
    }
    for(int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && lib::geometry::ccw(convex[k - 2], convex[k - 1], ps[i]) == -1) k--;
        convex[k++] = ps[i];
    }
    convex.resize(k - 1);
    return convex;
};

// diameter_convex_polygon returns the maximum diameter of convex polygon.
// Time complexity is [N * log N].
template <class T> T diameter_convex_polygon(const std::vector<std::complex<T>>& ps, const T eps = std::numeric_limits<T>::epsilon()) {
    int n = ps.size();
    auto cpm_y = [](const std::complex<T>& a, const std::complex<T>& b) {
        return a.imag() != b.imag() ? a.imag() < b.imag() : a.real() < b.real();
    };

    int i = std::min_element(ps.begin(), ps.end(), cpm_y) - ps.begin();
    int j = std::max_element(ps.begin(), ps.end(), cpm_y) - ps.begin();

    T maxD = 0;
    for(int _ = 0; _ < (n * 2); _++) {
        if(maxD < abs(ps[i] - ps[j])) {
            maxD = abs(ps[i] - ps[j]);
        }
        if(lib::geometry::cross(ps[i] - ps[(i+1) % n], ps[(j+1) % n] - ps[j]) < eps) {
            j = (j+1) % n;
        } else {
            i = (i+1) % n;
        }
    }
    return maxD;
};

// cut_convex returns the cut polygon which is on the left-hand side of the line "ab".
template <class T>
std::vector<std::complex<T>> cut_convex(const std::vector<std::complex<T>>& ps, std::complex<T> a, std::complex<T> b) {
    std::vector<std::complex<T>> res;
    int n = (int) ps.size();

    for(int i = 0; i < n; ++i) {
        if(lib::geometry::ccw(a, b, ps[i]) != -1) {
            res.push_back(ps[i]);
        }
        if(lib::geometry::ccw(a, b, ps[i]) * lib::geometry::ccw(a, b, ps[(i + 1) % n]) == -1) {
            res.push_back(lib::geometry::crosspoint(a, b, ps[i], ps[(i + 1) % n]));
        }
    }

    return res;
};

// closest_pair returns the distance of the closest pair.
// Time complexity is [N * log N].
template <class T> T closest_pair(std::vector<std::complex<T>>& ps) {
    const T inf = std::numeric_limits<T>::max();
    auto cmp_x = [](const std::complex<T>& a, const std::complex<T>& b) {
        return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
    };
    std::sort(ps.begin(), ps.end(), cmp_x);

    auto cmp_y = [](const std::complex<T>& a, const std::complex<T>& b) {
        return a.imag() != b.imag() ? a.imag() < b.imag() : a.real() < b.real();
    };

    auto f = [&](auto self, int l, int r)->T {
        if(r - l <= 1) {
            return inf;
        }

        int m = (l + r) / 2;
        T x = ps[m].real();
        T d = std::min<T>(self(self, l, m), self(self, m, r));
        std::inplace_merge(std::begin(ps) + l, std::begin(ps) + m, std::begin(ps) + r, cmp_y);

        std::vector<std::complex<T>> b;
        for(int i = l; i < r; ++i) {
            if(std::abs(ps[i].real() - x) >= d) continue;
            int bn = (int) b.size();
            for(int j = bn - 1; j >= 0; --j) {
                T dx = ps[i].real() - b[j].real();
                T dy = ps[i].imag() - b[j].imag();
                if(dy >= d) break;
                d = std::min<T>(d, std::sqrt(dx * dx + dy * dy));
            }
            b.push_back(ps[i]);
        }

        return d;
    };

    return f(f, 0, int(ps.size()));
};

}  // namespace lib::geometry

#endif  // LIB_GEOMETRY_UTILS
