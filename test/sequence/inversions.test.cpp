#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include <bits/stdc++.h>
#include "../../lib/sequence/inversions.hpp"
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long res = lib::sequence::inversions(A);
    cout << res << endl;

    return 0;
}
