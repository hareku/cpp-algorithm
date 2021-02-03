#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include <bits/stdc++.h>
#include "../../lib/randomized/pollard_rho_algorithm.hpp"
using namespace std;

int main() {
    int N; cin >> N;

    for(int i = 0; i < N; ++i) {
        long long x;
        cin >> x;

        vector<long long> res;
        auto factorized = lib::randomized::pollard_rho_prime_factorization(x);
        for(auto& f : factorized) {
            for(int j = 0; j < f.second; ++j) {
                res.push_back(f.first);
            }
        }

        int rn = (int) res.size();
        cout << rn;

        for(int j = 0; j < rn; ++j) {
            cout << " " << res[j];
        }
        cout << endl;
    }

    return 0;
}
