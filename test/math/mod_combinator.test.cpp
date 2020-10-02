#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"
#include <bits/stdc++.h>
#include "../../lib/math/mod_combinator.hpp"
using namespace std;

const int MOD = 1e8 + 7;

int main() {
    int R,C,A1,A2,B1,B2;
    cin >> R >> C >> A1 >> A2 >> B1 >> B2;

    lib::math::mod_combinator comb(R + C, MOD);

    int x1 = abs(B1 - A1), x2 = min((R - A1) + B1, (R - B1) + A1);
    int y1 = abs(B2 - A2), y2 = min((C - A2) + B2, (C - B2) + A2);

    int ans = comb.ncr(min(x1, x2) + min(y1, y2), min(x1, x2));

    if(min(x1, x2) != 0 && x1 == x2) {
        ans *= 2;
        ans %= MOD;
    }
    if(min(y1, y2) != 0 && y1 == y2) {
        ans *= 2;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
