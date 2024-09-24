#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N, M; cin >> N >> M;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        --P[i];
    }

    vector<vector<pair<int, int>>> g(N);
    int up_bound = 0;
    for (int i = 0; i < M; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        up_bound = max(up_bound, w);
    }

    vector<int> vis(N);
    function<void(int, int, int)> dfs = [&](int u, int bound, int idx) {
        if (vis[u] != -1) return;
        vis[u] = idx;

        for (auto e: g[u]) {
            int v = e.first, w = e.second;

            if (w >= bound) dfs(v, bound, idx);
        }
    };

    auto check = [&](int x) -> bool {
        fill(vis.begin(), vis.end(), -1);
        for (int i = 0, idx = 0; i < N; ++i) {
            if (vis[i] == -1) {
                dfs(i, x, idx++);
            }
        }

        for (int i = 0; i < N; ++i) {
            if (vis[i] != vis[P[i]]) return false;
        }
        return true;
    };

    int l = -1, r = up_bound + 2;
    while (r - l > 1) {
        int m = (l + r) / 2;

        if (check(m)) l = m;
        else r = m;
    }

    cout << (l > up_bound ? -1 : l) << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
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

