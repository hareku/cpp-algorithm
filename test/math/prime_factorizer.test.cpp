#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include <bits/stdc++.h>
#include "../../lib/math/prime_factorizer.hpp"
using namespace std;

int main() {
    long long N; cin >> N;
    auto fac = lib::math::prime_factorizer(N);
    auto res = fac.factorize(N);

    cout << N << ':';

    for(auto p : res) {
        for(int i = 0; i < p.second; ++i) {
            cout << " " << p.first;
        }
    }
    cout << endl;

    return 0;
}
