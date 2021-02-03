#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include <bits/stdc++.h>
#include "../../lib/randomized/miller_rabin_primality_test.hpp"
using namespace std;

int main() {
    int N; cin >> N;

    int res = 0;
    for(int i = 0; i < N; ++i) {
        long long x;
        cin >> x;

        if(lib::randomized::miller_rabin_primality_test(x, 50)) {
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}
