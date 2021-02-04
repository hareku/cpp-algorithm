#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"
#include <bits/stdc++.h>
#include "../../lib/math/extended_euclidean.hpp"
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    auto res = lib::math::extended_euclidean_algorithm(A, B);
    cout << res.first << " " << res.second << endl;

    return 0;
}
