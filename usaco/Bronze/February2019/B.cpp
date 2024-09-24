#include <bits/stdc++.h>

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#endif
 
void solve() {
    using namespace std;

    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < N; ++i) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    vector<int> ans(N, 0);
    for (int i = 0; i < N; ++i) {
        vector<int> avail(4, 1);
        for (int j: adj[i]) {
            if (ans[j] != 0) {
                avail[ans[j] - 1] = 0;
            }
        }

        for (int j = 1; j <= 4; ++j) {
            if (avail[j - 1] == 1) {
                ans[i] = j;
                break;
            }
        }
    }

    for (int &a: ans) cout << a;
    cout << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("revegetate.in", "r", stdin);
    freopen ("revegetate.out", "w", stdout);
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

