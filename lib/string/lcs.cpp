#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
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

// Longest Common Subsequence
int lcs(string& text1, string& text2) {
  int n1 = text1.size(), n2 = text2.size();
  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

  for(int j = n2 - 1; j >= 0; --j) {
    for(int i = n1 - 1; i >= 0; --i) {
      if(text1[i] == text2[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 1;
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  return dp[0][0];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

}
