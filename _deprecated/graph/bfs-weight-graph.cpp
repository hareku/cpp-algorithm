#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge {
        int to;
        ll weight;
        Edge(int t, ll w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;
ll C[100001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;

    Graph G(N + 1);
    rep(_, N - 1) {
        int from, to, weight;
        cin >> from >> to >> weight;
        G[from].push_back(Edge(to, weight));
        G[to].push_back(Edge(from, weight));
    }

    int Q,K; cin >> Q >> K;
    queue<int> QU;
    QU.push(K);

    while(!QU.empty()) {
        int cur = QU.front(); QU.pop();
        rep(i, G[cur].size()) {
            Edge next = G[cur][i];
            if(C[next.to] == 0) {
                QU.push(next.to);
                C[next.to] = C[cur] + next.weight;
            } else {
                C[next.to] = min(C[next.to], C[cur] + next.weight);
            }
        }
    }

    rep(i, Q) {
        int from, to;
        cin >> from >> to;

        cout << C[from] + C[to] << endl;
    }

    return 0;
}
