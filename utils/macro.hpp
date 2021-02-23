#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> PINT;
typedef pair<long long, long long> PLL;

#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define reps(i,s,n) for (ll i = s; i < (ll)(n); ++i)
#define rep1(i,n) for (ll i = 1; i <= (ll)(n); ++i)
#define per(i,n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define all(c) begin(c),end(c)

template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
void precout(int n = 20) { cout << std::fixed << std::setprecision(n); }
#define print(a) cout << a << endl;
const int INFI = (1 << 30) - 1;
const long long INFLL = (1LL << 62) - 1;
template<typename T> void printv(vector<T>&v) {
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << " ";
    cout << v.back() << endl;
}
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
const int dy8[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
const int dx8[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
double deg2rad(double deg) { return deg * M_PI / 180; }
double rad2deg(double rad) { return rad * 180 / M_PI; }
void yesorno(bool flag) {
    if(flag) print("Yes")
    else print("No");
}
template<typename T> T ceil_int(T A, T B) {
    return (A + (B - T(1))) / B;
}
vector<vector<char>> rps_winner_table() {
    vector<vector<char>> t(300, vector<char>(300));

    t['R']['R'] = t['R']['S'] = t['S']['R'] = 'R';
    t['S']['S'] = t['S']['P'] = t['P']['S'] = 'S';
    t['P']['P'] = t['P']['R'] = t['R']['P'] = 'P';

    t['r']['r'] = t['r']['s'] = t['s']['r'] = 'r';
    t['s']['s'] = t['s']['p'] = t['p']['s'] = 's';
    t['p']['p'] = t['p']['r'] = t['r']['P'] = 'p';

    return t;
}
