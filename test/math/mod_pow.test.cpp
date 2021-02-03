#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include <bits/stdc++.h>
#include "../../lib/math/mod_pow.hpp"
using namespace std;

int main() {
    long long m,n;
    cin >> m >> n;

    long long mod = 1e9 + 7;
    long long res = lib::math::mod_pow(m, n, mod);

    cout << res << endl;

    return 0;
}
