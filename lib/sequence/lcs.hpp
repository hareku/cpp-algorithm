#ifndef LIB_SEQUENCE_LCS_HPP
#define LIB_SEQUENCE_LCS_HPP 1

#include <bits/stdc++.h>

namespace lib::sequence {

template <class T> int lcs(std::vector<T>& s1, std::vector<T>& s2) {
    int n1 = s1.size(), n2 = s2.size();
    std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));

    for(int i = n1 - 1; i >= 0; --i) {
        for(int j = n2 - 1; j >= 0; --j) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    return dp[0][0];
}

}  // namespace lib::sequence

#endif  // LIB_SEQUENCE_LCS_HPP
