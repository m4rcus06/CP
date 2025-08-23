#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

/*How to use:
  Tvector <int, 2> g(n); //graph
  Tvector <int, 3> f(n, k, 2) = f[n][k][2]
*/
template <class Tp, int D = 1>
struct Tvector : public vector<Tvector<Tp, D - 1>> {
  template <class... Args>
  Tvector(int n = 0, Args... args) : vector<Tvector<Tp, D - 1>>(n, Tvector<Tp, D - 1>(args...)) {}
};
 
template <class Tp>
struct Tvector<Tp, 1> : public vector<Tp> {
  Tvector(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {}
};

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    Tvector <pair <int, int>, 2> g(N);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector <int> yummy_value(N);
    for (int i = 0; i < K; ++i) {
        int idx, y;
        cin >> idx >> y;
        --idx;
        yummy_value[idx] = y;
    }

    Tvector <int, 2> dist(N, 2, -1);
    Tvector <bool, 2> vis(N, 2);
    priority_queue <array <int, 3>> pq;

    pq.push({0, N - 1, (yummy_value[N - 1] > 0)});
    while (!pq.empty()) {
        auto [d, u, t] = pq.top(); pq.pop();
        d = -d;
        if (vis[u][t]) continue;

        for (auto [v, w]: g[u]) {
            int cost = w;
            if (dist[v][t] == -1 || dist[v][t] > dist[u][t] + cost) {
                dist[v][t] = dist[u][t] + cost;
                pq.push({-dist[v][t], v, t});
            }
            if (t == 0 && yummy_value[v] > 0) {
                cost -= yummy_value[v];
                if (dist[v][1] == -1 || dist[v][1] > dist[u][t] + cost) {
                    dist[v][1] = dist[u][t] + cost;
                    pq.push({-dist[v][1], v, 1});
                }
            }
        }
    }

    for (int i = 0; i + 1 < N; ++i) {
        cout << (dist[i][0] >= dist[i][1] ? 1 : 0) << '\n';
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
#endif

    int tt = 1;
    while (tt--) {
        solve();
    }

#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
#endif
    return 0;
}

