#ifndef LIB_STRING_KMP_HPP
#define LIB_STRING_KMP_HPP 1

#include <bits/stdc++.h>

namespace lib::string {

template <class T> std::vector<int> kmp_table(const std::vector<T>& pattern) {
    int m = int(pattern.size());
    if (m == 0) return {};
    std::vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

std::vector<int> kmp_table(const std::string& pattern) {
    int m = int(pattern.size());
    std::vector<int> pattern_vec(m);
    for (int i = 0; i < m; i++) {
        pattern_vec[i] = pattern[i];
    }
    return kmp_table(pattern_vec);
}

template <class T> std::vector<int> kmp_search(const std::vector<T>& text, const std::vector<T>& pattern) {
    int n = int(text.size());
    int m = int(pattern.size());
    if (m == 0) return {};

    std::vector<int> lps = kmp_table(pattern);
    std::vector<int> result;

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

std::vector<int> kmp_search(const std::string& text, const std::string& pattern) {
    int n = int(text.size());
    int m = int(pattern.size());
    std::vector<int> text_vec(n);
    std::vector<int> pattern_vec(m);
    for (int i = 0; i < n; i++) {
        text_vec[i] = text[i];
    }
    for (int i = 0; i < m; i++) {
        pattern_vec[i] = pattern[i];
    }
    return kmp_search(text_vec, pattern_vec);
}

}  // namespace lib::string

#endif  // LIB_STRING_KMP_HPP
