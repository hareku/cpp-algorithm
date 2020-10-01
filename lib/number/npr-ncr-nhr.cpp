#include <bits/stdc++.h>
using namespace std;

// 順列の総数を求める
// 順列の総数は n(n-1)(n-2)...(n-r+1) で求められる
// 5P3 なら 5*4*3
template<typename T>
T npr(T n, T r){
    if(r == 0) return 1;

    T ans = 1;
    for(T i = 0; i < r; ++i) {
        ans *= (n - i);
    }
    return ans;
}

// 組み合わせの総数を求める
// 組み合わせの総数は nPr / r! で求められる
// 5C3 なら (5*4*3) / (3*2*1)
long long ncr(long long n, long long r){
    if(r == 0) return 1;

    long long ans = 1;
    for(long long i = 0; i < r; i++) {
        ans *= (n - i);
        ans /= i + 1;
    }
    return ans;
}

// nC2 を求める
template<typename T>
T nc2(T n){
    return n * (n - 1) / 2;
}

// 重複組合せの総数を求める
// 重複組合せの総数は (n+r-1)Cr で求められる
// 5H3 なら (5+3-1)C3 = (7*6*5) / (3*2*1)
template<typename T>
T nhr(T n, T r){
    return ncr(n + r - 1, r);
}

int main() {
    cout << ncr(11, 3) << endl;
}
