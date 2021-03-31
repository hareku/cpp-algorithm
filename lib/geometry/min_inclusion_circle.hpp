#ifndef LIB_GEOMETRY_MIN_INCLUSION_CIRCLE
#define LIB_GEOMETRY_MIN_INCLUSION_CIRCLE 1

#include <bits/stdc++.h>
#include "./utils.hpp"

namespace lib::geometry {

// min_inclusion_circle returns a pair, its first is the center of a minimum inclusion circle,
// and its second is circle's radius.
template <class T> std::pair<std::complex<T>, T> min_inclusion_circle(std::vector<std::complex<T>> ps, const T eps = std::numeric_limits<T>::epsilon()) {
    int n = int(ps.size());
    std::pair<std::complex<T>, T> res;
    bool updated = 0; // flag for first updation.

    auto is_includeing_all = [&n, &ps, &eps](std::complex<T> center, T radius)->bool {
        for(int i = 0; i < n; ++i) {
            bool including = (radius - abs(ps[i] - center)) > -eps;
            if(!including) {
                return false;
            }
        }

        return true;
    };

    for(int i = 0; i < (n - 1); ++i) {
        for(int j = i + 1; j < (n); ++j) {
            std::complex<T> midp = (ps[i] + ps[j]) / std::complex<T>(2, 0);
            T radius = abs(ps[i] - midp);

            if(!is_includeing_all(midp, radius)) {
                continue;
            }

            if(!updated || res.second > radius) {
                res.first = midp;
                res.second = radius;
                updated = 1;
            }
        }
    }

    for(int i = 0; i < (n - 2); ++i) {
        for(int j = i + 1; j < (n - 1); ++j) {
            for(int k = j + 1; k < (n); ++k) {
                if(lib::geometry::on_same_line(ps[i], ps[j], ps[k])) {
                    continue;
                }

                std::complex<T> circumcenter = lib::geometry::circumcenter(ps[i], ps[j], ps[k]);
                T radius = abs(ps[i] - circumcenter);

                if(!is_includeing_all(circumcenter, radius)) {
                    continue;
                }

                if(!updated || res.second > radius) {
                    res.first = circumcenter;
                    res.second = radius;
                    updated = 1;
                }
            }
        }
    }

    return res;
};

}  // namespace lib::geometry

#endif  // LIB_GEOMETRY_MIN_INCLUSION_CIRCLE
