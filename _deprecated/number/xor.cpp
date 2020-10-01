#include <bits/stdc++.h>
using namespace std;

// 1...Nのxor値を求める
// O(1)
// https://atcoder.jp/contests/abc121/tasks/abc121_d
long long repeatXor(long long N) {
    if(N & 1) {
        return (N + 1) / 2 % 2;
    }

    return ((N + 1) / 2 % 2) ^ N;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long A,B; cin >> A >> B;
    long long ans = repeatXor(B) ^ repeatXor(A - 1);
    cout << ans << endl;
}
