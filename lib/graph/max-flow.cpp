#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
     return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    if(v.size() >= 200) {
        return "Too big length";
    }

    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#define rep(i,n) for (int i = 0; i < n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef long double ld;
typedef pair<int,int> PINT;
typedef pair<ll,ll> PLL;
#define precout() cout << std::fixed << std::setprecision(20);
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
const long long MOD = 1e9+7;
// const long long MOD = 998244353;

template<class Cap>
struct MaxFlow {
    //to:行き先,cap:容量,rev:逆(G[e.to][e.rev]で逆辺の構造体にアクセスできる。)
    struct _Edge {
        int to;
        Cap cap;
        int rev;
    };

    vector<vector<_Edge>> _g;
    int _n;
    Cap CapInf = 1 << 30; // to be set

    MaxFlow(int n) {
        _n = n;
        _g = vector<vector<_Edge>>(n);
    }

    void add_edge(int from, int to, Cap cap) {
        _g[from].push_back( (_Edge){ to, cap, (int) _g[to].size() } );
        _g[to].push_back( (_Edge){ from, 0, (int) _g[from].size() - 1 });
    }

    Cap dfs(vector<bool>& used, int v, int t, Cap f) {
        if(v == t) return f;
        used[v] = 1;

        for(auto &e : _g[v]) {
            if(!used[e.to] && e.cap > 0) {
                Cap d = dfs(used, e.to, t, min(f,e.cap));
                if(d > 0) {
                    e.cap -= d;
                    _g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }

        return 0;
    }

    Cap solve(int s, int t) {
        Cap res = 0;
        while(true) {
            vector<bool> used(_n, 0);
            int flow = dfs(used, s, t, CapInf);
            if(flow == 0) return res;
            else res += flow;
        }

        return 0;
    }
};

// https://atcoder.jp/contests/abc010/tasks/abc010_4
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,G,E; cin >> N >> G >> E;
    vector<int> P(G);
    MaxFlow<int> mf(N + 1);

    rep(i, G) {
        cin >> P[i];
    }
    rep(i, E) {
        int a,b; cin >> a >> b;
        mf.add_edge(a, b, 1);
        mf.add_edge(b, a, 1);
    }

    rep(i, G) {
        mf.add_edge(P[i], N, 1);
    }

    int res = mf.solve(0, N);
    print(res);
}
