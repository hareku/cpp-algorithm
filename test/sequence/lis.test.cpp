#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
#include <bits/stdc++.h>
#include "../../lib/sequence/lis.hpp"
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int res = lib::sequence::lis(A, false);
    cout << res << endl;
}
