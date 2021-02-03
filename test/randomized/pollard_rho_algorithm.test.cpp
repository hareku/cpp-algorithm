#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include <bits/stdc++.h>
#include "../../lib/randomized/pollard_rho_algorithm.hpp"
using namespace std;

int main() {
    long long N; cin >> N;
    auto res = lib::randomized::pollard_rho_prime_factorization(N);

    cout << N << ':';

    for(auto & p : res) {
        for(int i = 0; i < p.second; ++i) {
            cout << " " << (long long) p.first;
        }
    }
    cout << endl;

    return 0;
}
