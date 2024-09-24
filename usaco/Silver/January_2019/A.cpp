#include <bits/stdc++.h>
 
void solve() {
    int N; std::cin >> N;
    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i + 1 < N; ++i) {
        int u, v; std::cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = std::max(ans, 1 + (int) adj[i].size());
    }
    std::cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
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

