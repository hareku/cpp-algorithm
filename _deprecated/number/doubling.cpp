#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

const int D = 60;
int to[D][200005];

// https://atcoder.jp/contests/abc167/tasks/abc167_d
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n,k; cin >> n >> k;
  rep(i, n) {
    cin >> to[0][i];
    --to[0][i];
  }

  rep(i, D - 1) {
    rep(j, n) {
      to[i + 1][j] = to[i][to[i][j]];
    }
  }

  int v = 0;
  for(int i = D - 1; i >= 0; --i) {
    ll l = 1ll << i;
    if(k >= l) {
      v = to[i][v];
      k -= l;
    }
  }

  cout << v + 1 << endl;
}
