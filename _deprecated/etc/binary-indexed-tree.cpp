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
        return "Too big container";
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
const long long MOD = 1e9+7;
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

// ref: https://yosupo.hatenablog.com/entry/2016/12/04/121927
template<class T>
struct BinaryIndexedTree {
    int N;
    vector<T> seg;

    BinaryIndexedTree(int N) : N(N) {
        seg.resize(N + 1);
        fill_n(begin(seg), N + 1, 0);
    }

    /// i番目の要素にxを追加する
    void add(int i, T x) {
        while (i <= N) {
            seg[i] += x;
            i += i & -i;
        }
    }

    /// [0, i)のsum
    T sum(int i) {
        T s{0};
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }

    /// [l, r)のsum
    T rangesum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

// https://atcoder.jp/contests/abc174/tasks/abc174_f
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,Q; cin >> N >> Q;
    vector<int> C(N + 1);
    rep1(i, N) cin >> C[i];

    vector<vector<int>> QL(N + 1);
    vector<vector<int>> QID(N + 1);
    rep(i, Q) {
        int l,r; cin >> l >> r;
        QL[r].push_back(l);
        QID[r].push_back(i);
    }

    BinaryIndexedTree<int> bit(N);
    vector<int> A(N + 1, 0);
    vector<int> ans(Q);

    rep1(i, N) {
        if(A[C[i]] > 0) {
            bit.add(A[C[i]], -1);
        }

        bit.add(i, 1);
        A[C[i]] = i;

        rep(j, QL[i].size()) {
            ans[QID[i][j]] = bit.rangesum(QL[i][j], i);
        }
    }

    rep(i, Q) {
        print(ans[i]);
    }
}
