#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int N, M;
int nums[11];

// https://atcoder.jp/contests/abc165/tasks/abc165_c
// 広義単調増加の数列を列挙する
// 計算量は(N+M-1)C(M-1)
void enumerate_monotonic_increasing(int cur) {
  if(cur == N + 1) {
    rep1(i, 10) cout << nums[i];
    cout << endl;
    return;
  }

  for(int i = nums[cur - 1]; i <= M; ++i) {
    nums[cur] = i;
    enumerate_monotonic_increasing(cur + 1);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  nums[0] = 1;
  enumerate_monotonic_increasing(1);
}
