#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

// z-algorhythm
// 文字列Sを0番目からとi番目からを同時に見ていった時に、最大で何文字一致しているかを探索する
// 別名 LCP (Longest common prefix)
// 計算量はO(|S|)
vector<int> z_algorhythm(const string &S) {
  const int N = S.size();
  vector<int> res(N);
  res[0] = N;

  int i = 1, j = 0;
  while (i < N) {
    while (i + j < N && S[j] == S[i + j]) ++j; // j = 開始位置 i から何文字等しいか
    res[i] = j;
    if (j == 0) {++i; continue;} // 何文字も等しくなければ continue

    int k = 1;
    while (i + k < N && k + res[k] < j) {
      res[i + k] = res[k];
      ++k;
    }
    i += k, j -= k;
  }
  return res;
}
