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

// 2方向のみの移動の最短経路をDPで求める
// https://atcoder.jp/contests/agc043/tasks/agc043_a
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H,W; cin >> H >> W;
  vector<string> G(H);
  rep(i, H) cin >> G[i];

  vector<vector<int>> DP(H, vector<int>(W, (int)1e9));
  DP[0][0] = 0;

  rep(h, H) {
    rep(w, W) {
      if(h) {
        DP[h][w] = min(DP[h][w], DP[h-1][w] + (G[h-1][w] == '.' && G[h][w] == '#' ? 1 : 0));
      }
      if(w) {
        DP[h][w] = min(DP[h][w], DP[h][w-1] + (G[h][w-1] == '.' && G[h][w] == '#' ? 1 : 0));
      }
    }
  }

  if(G[0][0] == '#') {
    DP[H-1][W-1]++;
  }

  cout << DP[H-1][W-1] << endl;
  return 0;
}
