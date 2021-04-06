#ifndef LIB_GEOMETRY_INTERSECTIONS
#define LIB_GEOMETRY_INTERSECTIONS 1

#include <bits/stdc++.h>
#include "../sequence/compressor.hpp"
#include "../sequence/fenwick_tree.hpp"

namespace lib::geometry {

template <class T> long long count_intersections(const std::vector<std::pair<std::complex<T>, std::complex<T> > >& ls) {
    struct EventY {
        T y_low, y_high, x;
        bool operator<(EventY r) const {
            return x < r.x;
        }
    };
    std::vector<EventY> y_events;

    struct EventX {
        T x, y;
        bool add; // add or remove
        bool operator<(EventX r) const {
            return x < r.x;
        }
    };
    std::vector<EventX> x_events;

    const int n = (int) ls.size();
    for(int i = 0; i < n; ++i) {
        if(ls[i].first.real() == ls[i].second.real()) {
            y_events.push_back({
                std::min(ls[i].first.imag(), ls[i].second.imag()),
                std::max(ls[i].first.imag(), ls[i].second.imag()),
                ls[i].first.real()
            });
        } else {
            x_events.push_back({
                std::min(ls[i].first.real(), ls[i].second.real()),
                ls[i].first.imag(),
                1
            });
            x_events.push_back({
                std::max(ls[i].first.real(), ls[i].second.real()) + 1,
                ls[i].first.imag(),
                0
            });
        }
    }

    std::sort(x_events.begin(), x_events.end());
    std::sort(y_events.begin(), y_events.end());

    const int xn = (int) x_events.size(), yn = (int) y_events.size();

    lib::sequence::compressor<T> compressor;
    for(int i = 0; i < xn; ++i) {
        compressor.add(x_events[i].y);
    }
    for(int i = 0; i < yn; ++i) {
        compressor.add(y_events[i].y_low);
        compressor.add(y_events[i].y_high);
    }
    std::unordered_map<T, int> y2i = compressor.compress();
    lib::sequence::fenwick_tree<long long> ft((int) y2i.size());

    long long cnt = 0;
    int xi = 0;
    for(int yi = 0; yi < yn; ++yi) {
        while(xi < xn && x_events[xi].x <= y_events[yi].x) {
            if(x_events[xi].add) {
                ft.add(y2i[x_events[xi].y], 1);
            } else {
                ft.add(y2i[x_events[xi].y], -1);
            }
            ++xi;
        }
        cnt += ft.sum(y2i[y_events[yi].y_low], y2i[y_events[yi].y_high] + 1);
    }

    return cnt;
};

}  // namespace lib::geometry

#endif  // LIB_GEOMETRY_INTERSECTIONS
