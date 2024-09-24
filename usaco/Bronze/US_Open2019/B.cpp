#include <bits/stdc++.h>
 
void solve() {
    int N; std::cin >> N;
    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i + 1 < N; ++i) {
        int u, v; std::cin >> u >> v;
        --u, --v;
        adj[v].push_back(u);
    }
    
    std::vector<int> vis(N);
    std::function<int(int)> dfs = [&](int u) {
        if (vis[u]) return 0;
        vis[u] = true;
        int res = 1;
        for (int v : adj[u]) {
            res += dfs(v);
        }
        return res;
    };

    for (int i = 0; i < N; ++i) {
        std::fill(vis.begin(), vis.end(), 0);
        int cnt = dfs(i);
        if (cnt == N) {
            std::cout << i + 1 << '\n';
            return;
        }
    }

    std::cout << -1 << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
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

