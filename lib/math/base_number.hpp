#ifndef LIB_MATH_BASE_NUMBER_HPP
#define LIB_MATH_BASE_NUMBER_HPP 1

#include <bits/stdc++.h>

namespace lib::math {

// 10進数`num`を`n`進数に変換し、1桁目が先頭のvectorを返す.
std::vector<int> base_ten2n(int num, int n) {
    std::vector<int> res;
    while(num) {
        res.push_back(num % n);
        num /= n;
    }
    return res;
}

}  // namespace lib::math

#endif  // LIB_MATH_BASE_NUMBER_HPP
