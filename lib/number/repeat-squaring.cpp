#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef long double ld;

// http://satanic0258.hatenablog.com/entry/2016/04/29/004730
// 繰り返し自乗法
// 愚直な方法は計算量がO(P)であるのに対し、繰り返し自乗法ではO(logP)になる

ll repeat_squaring(ll N, ll P) {
  if(P == 0) return 1;
  if(P % 2 == 0) {
    ll t = repeat_squaring(N, P / 2);
    return t * t;
  }
  return N * repeat_squaring(N, P - 1);
}

ll repeat_squaring_mod(ll N, ll P, ll M) {
  if(P == 0) return 1;
  if(P % 2 == 0) {
    ll t = repeat_squaring_mod(N, P / 2, M);
    return t * t % M;
  }
  return N * repeat_squaring_mod(N, P - 1, M);
}

ld repeat_squaring_negative(ld N, ll P) {
  if(P == 0) return 1;
  ld t = repeat_squaring(N, P / 2);
  if(P % 2 == 0) {
    return t * t;
  } else {
    return N * t * t;
  }
}

int main() {
  //
}

class Solution {
public:
  ld myPow(ld x, int n) {
    ll N = n;
    if(N < 0) {
      x = 1 / x;
      N -= n;
    }

    return repeat_squaring_negative(x, n);
  }
};
