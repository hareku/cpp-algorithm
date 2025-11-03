#ifndef LIB_MATH_MOD_HPP
#define LIB_MATH_MOD_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

template<typename T> T add(const T a, const T b, const T mod){
    return (a + b) % mod;
}

template<typename T> T mul(const T a, const T b, const T mod){
    return a * b % mod;
}

template<typename T> T inv(T a, T mod) {
    T b = mod, u = 1, v = 0;
    while (b) {
        T t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

// ref: https://kopricky.github.io/code/Computation_Advanced/garner.html
template<typename T> T garner(const std::vector<T>& a, std::vector<T> p, const T mod){
    const unsigned int sz = a.size();
    vector<T> kp(sz + 1, 0), rmult(sz + 1, 1);
    p.push_back(mod);
    for(unsigned int i = 0; i < sz; ++i){
        T x = mul(a[i] - kp[i], inv(rmult[i], p[i]), p[i]);
        x = (x < 0) ? (x + p[i]) : x;
        for(unsigned int j = i + 1; j < sz + 1; ++j){
            kp[j] = add(kp[j], rmult[j] * x, p[j]);
            rmult[j] = mul(rmult[j], p[i], p[j]);
        }
    }
    return kp[sz];
}

}  // namespace lib::math

#endif  // LIB_MATH_MOD_HPP
