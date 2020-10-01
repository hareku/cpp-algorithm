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

// https://atcoder.jp/contests/abc021/tasks/abc021_c
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,A,B,M; cin >> N >> A >> B >> M;
    --A,--B;
    vector<vector<int>> G(N);
    rep(i, M) {
        int x,y; cin >> x >> y; --x,--y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    queue<P> q;
    q.push({A, 0});

    vector<int> dist(N, -1);
    vector<int> count(N, 0);
    dist[A] = 0;
    count[A] = 1;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if(cur.first == B) break;

        for(auto&next:G[cur.first]) {
            bool seen = dist[next] != -1;
            if(!seen || dist[next] == cur.second + 1) {
                dist[next] = cur.second + 1;
                count[next] += count[cur.first];
                count[next] %= MOD;
            }
            if(!seen) {
                q.push(make_pair(next, cur.second + 1));
            }
        }
    }

    cout << count[B] << endl;
}
