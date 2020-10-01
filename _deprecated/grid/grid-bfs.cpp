#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

// BFSで最短経路を求められる
// https://atcoder.jp/contests/abc088/tasks/abc088_d
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H,W; cin >> H >> W;

  vector<string> M(H);
  int white = 0;

  rep(h, H) {
    cin >> M[h];
    rep(w, W) {
      if(M[h][w] == '.') white++;
    }
  }

  vector<vector<int>> D(H, vector<int>(W, -1));
  D[0][0] = 0;

  queue<pair<int,int>> Q;
  Q.push(make_pair(0, 0));

  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    rep(i, 4) {
      int nh = cur.first + dy[i];
      int nw = cur.second + dx[i];
      if(nh >= 0 && nh < H && nw >= 0 && nw < W && M[nh][nw] == '.') {
        if(D[nh][nw] != -1) continue;
        D[nh][nw] = D[cur.first][cur.second] + 1;
        Q.push(make_pair(nh, nw));
      }
    }
  }

  if(D[H-1][W-1] != -1) {
    cout << white - D[H-1][W-1] - 1 << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
