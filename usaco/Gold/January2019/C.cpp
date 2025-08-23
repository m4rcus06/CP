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
    int N, M, T;
    cin >> N >> M >> T;
    vector <int> c(N);
    for (int i = 0; i < N; ++i) cin >> c[i];

    Tvector <pair <int, int>, 2> G(N);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;

        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    vector <int> dist(N, -1), par(N);
    vector <bool> vis(N);
    priority_queue <pair <int, int>> Q;

    dist[0] = 0;
    Q.emplace(0, 0);
    while (!Q.empty()) {
        auto [d, u] = Q.top(); Q.pop();
        d = -d, u = -u;
        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w]: G[u]) {
            if (dist[v] == -1 || dist[v] > d + w) {
                dist[v] = d + w;
                par[v] = u;
                Q.emplace(-dist[v], -v);
            } else if (dist[v] == d + w && u < par[v]) {
                par[v] = u;
                Q.emplace(-dist[v], -v);
            }
        }
    }

    //this must form a tree
    Tvector <int, 2> subG(N);
    for (int i = 0; i < N; ++i) {
        if (par[i] == i) continue;
        subG[i].push_back(par[i]);
        subG[par[i]].push_back(i);
    }

    vis.assign(N, false);
    function <void(int)> DFS = [&](int u) {
        vis[u] = true;
        for (int v: subG[u]) {
            if (!vis[v]) {
                DFS(v);
                c[u] += c[v];
            }
        }
    };
    DFS(0);

    lli ans = 0;
    for (int i = 0; i < N; ++i) {
        if (dist[i] >= T) {
            ans = max(ans, (lli) c[i] * (dist[i] - T));
        }
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
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

