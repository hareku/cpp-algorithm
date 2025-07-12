#ifndef LIB_STRING_MANACHER_HPP
#define LIB_STRING_MANACHER_HPP 1

#include <bits/stdc++.h>

namespace lib::string {

// O(S.size())
// R[i] = iを中心とした回文の長さの半径, 直径をkとして(k+1)/2
// ref: https://snuke.hatenablog.com/entry/2014/12/02/235837
template <class T> std::vector<int> manacher(const std::vector<T> &S) {
    std::vector<int> R(S.size());
    int i = 0, j = 0;
    while (i < S.size()) {
        while (i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
        R[i] = j;
        int k = 1;
        while (i-k >= 0 && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
        i += k; j -= k;
    }
    return R;
}

std::vector<int> manacher(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return manacher(s2);
}

}  // namespace lib::string

#endif  // LIB_STRING_MANACHER_HPP
