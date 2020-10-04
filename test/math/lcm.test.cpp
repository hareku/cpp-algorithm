#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"
#include <bits/stdc++.h>
#include "../../lib/math/lcm.hpp"
using namespace std;

int main() {
    int N; cin >> N;

    long long ans = 1;
    for(int i = 0; i < N; ++i) {
        long long a; cin >> a;
        ans = lib::math::lcm(ans, a);
    }

    cout << ans << endl;

    return 0;
}
