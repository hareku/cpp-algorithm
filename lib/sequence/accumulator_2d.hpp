#ifndef LIB_ACCUMULATOR_2D_HPP
#define LIB_ACCUMULATOR_2D_HPP 1

#include <bits/stdc++.h>

namespace lib::sequence {

// accumulator_2d accumulates 2 dimentions sequences.
template <class T> struct accumulator_2d {
  public:
    accumulator_2d(int h, int w):
        _h(h),
        _w(w),
        raw(h, std::vector<T>(w, 0)),
        memo(h + 1, std::vector<T>(w + 1, 0))
    {}

    // update a raw grid.
    void update_raw(int h, int w, T val) {
        assert(h >= 0 && h < _h);
        assert(w >= 0 && w < _w);
        raw[h][w] = val;
    }

    // preprocess for accumulate().
    void preprocess() {
        for(int h = 0; h < _h; ++h) {
            for(int w = 0; w < _w; ++w) {
                memo[h + 1][w + 1] = memo[h][w + 1] + memo[h + 1][w] - memo[h][w] + raw[h][w];
            }
        }
    }

    T accumulate(int h1, int w1) {
        return accumulate(0, 0, h1, w1);
    }

    T accumulate(int h1, int w1, int h2, int w2) {
        assert(h1 >= 0 && h1 < _h);
        assert(w1 >= 0 && w1 < _w);
        assert(h2 >= 0 && h2 < _h);
        assert(w2 >= 0 && w2 < _w);
        assert(h1 <= h2);
        assert(w1 <= w2);

        return memo[h2 + 1][w2 + 1] - memo[h1][w2 + 1] - memo[h2 + 1][w1] + memo[h1][w1];
    }

  private:
    int _h, _w;
    std::vector<std::vector<T>> raw, memo;
};

}  // namespace lib::sequence

#endif  // LIB_ACCUMULATOR_2D_HPP
