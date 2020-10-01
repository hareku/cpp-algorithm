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
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define per1(i,n) for (int i = n; i >= 1; --i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
void chmax(string &a, string b) {
    if (a == "-") a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef tuple<int,int,int> Tint;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
#define print(a) cout << a << endl;
const long long INFLL = (1LL << 62) - 1;
const int INFI = (1 << 30) - 1;
template<typename T> void printv(vector<T>&v) {
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << " ";
    cout << v.back() << endl;
}
typedef complex<ld> cd;
static const long double pi = acos(-1.0);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
// if(nextH >= 0 && nextH < H && nextW >= 0 && nextW < W)

struct Graph {
    struct Edge {
        int to;
        long long weight;
        Edge(int t, long long w) : to(t), weight(w) { }
    };
    using Dist = vector<long long>;
    using PL = pair<long long, long long>;

    vector<vector<Edge>> edges;
    int n;
    Graph(int initN) {
        n = initN;
        edges = vector<vector<Edge>>(n);
    }

    void insertDirectedEdge(int from, int to, long long weight) {
        edges[from].push_back(Edge(to, weight));
    }

    void insertUndirectedEdge(int a, int b, long long weight) {
        edges[a].push_back(Edge(b, weight));
        edges[b].push_back(Edge(a, weight));
    }

    Dist dijkstra(int s) {
        Dist dist(n, -1);
        priority_queue<PL, vector<PL>, greater<PL>> pq;

        dist[s] = 0;
        pq.push(PL(0, s));

        while (!pq.empty()) {
            PL cur = pq.top(); pq.pop();
            if(dist[cur.second] < cur.first) continue;

            for(auto& nextEdge : edges[cur.second]) {
                long long nextCost = cur.first + nextEdge.weight;
                if(dist[nextEdge.to] == -1 || dist[nextEdge.to] > nextCost) {
                    dist[nextEdge.to] = nextCost;
                    pq.push(PL(nextCost, nextEdge.to));
                }
            }
        }

        return dist;
    }

    vector<bool> findReachable(int start) {
        vector<bool> reachable(n, 0);
        findReachable_dfs(reachable, start);
        return reachable;
    }

private:
    void findReachable_dfs(vector<bool>& reachable, int cur) {
        if(reachable[cur]) return;
        reachable[cur] = 1;
        for(auto&next:edges[cur]) {
            findReachable_dfs(reachable, next.to);
        }
    }
};

struct NegativeWeightGraph {
    struct Edge {
        int from;
        int to;
        long long weight;
        Edge(int f, int t, long long w) : from(f),  to(t), weight(w) { }
    };
    using Dist = vector<long long>;
    using BellmanFordResult = pair<bool, Dist>;

    vector<Edge> edges;
    int n;
    NegativeWeightGraph(int initN) {
        n = initN;
    }

    void insertDirectedEdge(int from, int to, long long weight) {
        edges.push_back(Edge(from, to, weight));
    }

    BellmanFordResult bellmanFordWithRestiction(int start, vector<bool>& canUseV) {
        Dist d(n, INFLL);
        d[start] = 0;

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < (int)edges.size(); j++) {
                auto& e = edges[j];
                if(!canUseV[e.from] || !canUseV[e.to]) continue;

                if (d[e.to] > d[e.from] + e.weight) {
                    d[e.to] = d[e.from] + e.weight;
                    if (i == n - 1) {
                        return BellmanFordResult(false, d);
                    }
                }
            }
        }

        return BellmanFordResult(true, d);
    }
};

struct AdjacencyGraph {
    vector<vector<long long>> g;
    int n;
    long long inf = 1e15;
    vector<vector<ll>> dist;

    AdjacencyGraph(int initN) {
        n = initN;
        g = vector<vector<long long>>(n, vector<long long>(n, inf));
    }

    void insertDirectedEdge(int from, int to, long long weight) {
        chmin(g[from][to], weight);
    }

    void insertUndirectedEdge(int a, int b, long long weight) {
        insertDirectedEdge(a, b, weight);
        insertDirectedEdge(b, a, weight);
    }

    void warshallFloyd() {
        dist = g;
        rep(k, n) {
            rep(i, n) {
                rep(j, n) {
                    if(i == j) continue;
                    chmin(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    void updateUndirectedEdge(int a, int b, long long weight) {
        rep(i, n) {
            rep(j, n) {
                if(i == j) continue;
                chmin(dist[i][j], min(p2p(i, a) + p2p(b, j) + weight, p2p(i, b) + p2p(a, j) + weight));
            }
        }
    }

    long long p2p(int from, int to) {
        return from == to ? 0 : dist[from][to];
    }

    long long sumDist() {
        long long res = 0;
        rep(i, n) {
            reps(j, i + 1, n) {
                res += dist[i][j];
            }
        }
        return res;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);


}
