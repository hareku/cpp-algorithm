#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const long double pi = acos(-1.0);
typedef complex<ld> cd;

// https://atcoder.jp/contests/arc025/tasks/arc025_2
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H,W; cin >> H >> W;
  vector<vector<int>> raw(H, vector<int>(W, 0));

  rep(h, H) {
    rep(w, W) {
      cin >> raw[h][w];
      if((h + w) & 1) {
        raw[h][w] *= -1;
      }
    }
  }

  // 二次元累積和
  vector<vector<int>> memo(H + 1, vector<int>(W + 1, 0));
  rep(h, H) {
    rep(w, W) {
      memo[h + 1][w + 1] = memo[h][w + 1] + memo[h + 1][w] - memo[h][w] + raw[h][w];
    }
  }

  int ans = 0;

  rep(h, H) {
    rep(w, W) {
      reps(h2, h, H) {
        reps(w2, w, W) {
          int sum = memo[h2 + 1][w2 + 1] - memo[h][w2 + 1] - memo[h2 + 1][w] + memo[h][w];
          if(sum == 0) {
            chmax(ans, (h2 - h + 1) * (w2 - w + 1));
          }
        }
      }
    }
  }

  cout << ans << endl;
}
