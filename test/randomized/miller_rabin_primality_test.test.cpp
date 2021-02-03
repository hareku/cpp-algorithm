#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include <bits/stdc++.h>
#include "../../lib/randomized/miller_rabin_primality_test.hpp"
using namespace std;

bool is_prime(int a) {
    return lib::randomized::miller_rabin_primality_test(a, 50);
}

int main() {
    int N; cin >> N;

    int res = 0;
    for(int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        if(is_prime(x)) {
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}
