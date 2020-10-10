#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include <bits/stdc++.h>
#include "../../lib/math/primes.hpp"
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<long long> primes = lib::math::enumerate_primes(N);
    int nn = int(primes.size());

    vector<int> ans;
    for(int i = B; i < nn; i += A) {
        ans.push_back(primes[i]);
    }
    int an = int(ans.size());

    cout << nn << " " << an << endl;

    for(int i = 0; i < int(ans.size()); ++i) {
        cout << ans[i];
        if(i != an - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
