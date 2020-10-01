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

int H,W,T;
int SH,SW; // Start position

bool bfs(vector<string>& G, ll cost) {
    vector<vector<ll>> D(H, vector<ll>(W, T + 1));
    D[SH][SW] = 0;

    queue<pair<P,ll>> Q;
    Q.push(make_pair(make_pair(SH, SW), 0LL));

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        auto pos = cur.first;

        if(G[pos.first][pos.second] == 'G') {
            return true;
        }

        rep(i, 4) {
            int nh = pos.first + dy[i];
            int nw = pos.second + dx[i];
            if(nh >= 0 && nh < H && nw >= 0 && nw < W) {
                ll nextCos = cur.second + (G[nh][nw] == '#' ? cost : 1);
                if(nextCos > T) continue;
                if(D[nh][nw] < nextCos) continue;

                D[nh][nw] = nextCos;
                Q.push(make_pair(make_pair(nh, nw), nextCos));
            }
        }
    }

    return false;
}

// https://atcoder.jp/contests/abc020/tasks/abc020_c
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W >> T;
    vector<string> G(H);
    rep(i, H) {
        cin >> G[i];
        rep(w, W) {
            if(G[i][w] == 'S') {
                SH = i;
                SW = w;
                break;
            }
        }
    }

    ll ans = 0;
    ll lo = 0, hi = T + 1;
    while(hi - lo > 1) {
        ll mid = (lo + hi) / 2LL;
        bool res = bfs(G, mid);
        if(res) {
            lo = mid;
            chmax(ans, mid);
        } else {
            hi = mid;
        }
    }

    cout << ans << endl;
}
