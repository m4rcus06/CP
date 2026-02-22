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

template <typename T>
using minHeap = priority_queue <T, vector <T>, greater <T>>; 

void solve() {
    int n, m;
    cin >> n >> m;
    Tvector <pair <int, int>, 2> g(n);
    vector <pair <int, int>> e;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
        e.emplace_back(u, v);
    }

    vector <int> in(n), low(n);
    vector <int> bridge_on_path;
    int timer = 0;
    function <bool(int, int)> dfs = [&](int u, int p) {
        in[u] = low[u] = ++timer;
        bool ok = (u == n - 1);
        for (auto [v, idx]: g[u]) {
            if (v == p) continue;
            if (in[v] == 0) {
                bool correct_path = dfs(v, u);
                if (correct_path) {
                    ok = true;
                    if (in[v] == low[v]) {
                        bridge_on_path.push_back(idx);
                    }
                }
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], in[v]);
            }
        }
        return ok;
    };
    dfs(0, 0);

    minHeap <array <int, 3>> Q;
    vector <bool> vis(n);
    vector <pair <int, int>> dist(n, {n + 1, -2});
    for (auto x: bridge_on_path) {
        auto [u, v] = e[x];
        if (make_pair(0, x) < dist[u]) {
            Q.push({0, x, u});
            dist[u] = {0, x};
        }
        if (make_pair(0, x) < dist[v]) {
            Q.push({0, x, v});
            dist[v] = {0, x};
        }
    }

    while (!Q.empty()) {
        auto [cur_dist, idx, u] = Q.top(); Q.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, _]: g[u]) {
            if (dist[v] > make_pair(cur_dist + 1, idx)) {
                dist[v] = make_pair(cur_dist + 1, idx);
                Q.push({cur_dist + 1, idx, v});
            }
        }
    }

    int qu;
    cin >> qu;
    while (qu--) {
        int x; cin >> x;
        x--;
        int ans = dist[x].second;
        cout << ans + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    int tt = 1;
    cin >> tt;
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

