#ifndef LIB_STRING_PALINDROME_HPP
#define LIB_STRING_PALINDROME_HPP 1

#include <bits/stdc++.h>

namespace lib::string {

bool is_palindrome(const std::string &s){
    int n = int(s.length());
    for (int i = 0; i < (n + 1) / 2; ++i) {
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}

}  // namespace lib::string

#endif  // LIB_STRING_PALINDROME_HPP
