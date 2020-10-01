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
template<typename T> inline void add(T& a, T b) { a += b; if (a >= MOD) a -= MOD; }

int N;
string S[200];
int Colors[200]; // none:0 white:1 black:2

bool dfs(int pos, int color) {
  Colors[pos] = color;

  int next_color = color == 1 ? 2 : 1;
  rep(i, S[pos].size()) {
    if(S[pos][i] == '1') {
      if(color == Colors[i]) return false;
      if(Colors[i] == 0) {
        if(!dfs(i, next_color)) return false;
      }
    }
  }

  return true;
}

// https://atcoder.jp/contests/agc039/tasks/agc039_b
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  rep(i, N) cin >> S[i];

  bool is_bipartite_graph = dfs(0, 1);

  if(!is_bipartite_graph) {
    cout << -1 << endl;
    return 0;
  }

  vector<vector<int>> G(N, vector<int>(N, 1e9));
  rep(i, N) {
    rep(j, N) {
      if(i == j) G[i][j] = 0, G[j][i] = 0;
      if(S[i][j] == '1') G[i][j] = 1, G[j][i] = 1;
    }
  }

  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        chmin(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }

  int d = 0;
  rep(i, N) {
    chmax(d, *max_element(G[i].begin(), G[i].end()));
  }

  cout << d + 1 << endl;
}
