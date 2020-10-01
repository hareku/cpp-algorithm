#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define per1(i,n) for (int i = n; i >= 1; --i)
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
// if(nextY >= 0 && nextY < H && nextX >= 0 && nextX < W)
static const long double pi = acos(-1.0);
typedef complex<ld> cd;

// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
// O(logn)
template<typename T>
T modinv(T a) {
    T b = MOD, u = 1, v = 0;
    while (b) {
        T t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

template<typename T>
T ncr(T n, T r){
    if(r == 0) return 1;

    T ans = 1;
    for(T i = 0; i < r; i++) {
        ans *= (n - i);
        ans %= MOD;
        ans *= modinv(i + 1);
        ans %= MOD;
    }
    return ans;
}

// https://atcoder.jp/contests/arc039/tasks/arc039_b
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N,K; cin >> N >> K;
    ll ans;

    if(N == K) {
        ans = 1;
    } else if(N > K) {
        ans = ncr(N + K - 1, K);
    } else {
        ans = ncr(N, K % N);
    }

    cout << ans << endl;
}
