#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"
#include <bits/stdc++.h>
#include "../../lib/math/matrix.hpp"
using namespace std;

int main() {
    int N,M,L; cin >> N >> M >> L;

    lib::math::matrix<long long> A(N, M), B(M, L);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> A.M[i][j];
        }
    }

    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < L; ++j) {
            cin >> B.M[i][j];
        }
    }

    A *= B;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < L; ++j) {
            cout << A.M[i][j];
            if(j + 1 < L) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
