#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...)
#endif

const int N = 200005;

int n, k;
int cnt[N];
vector <vector <int>> g(N);

lli dfs(int u, int p) {
    lli res = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        res += dfs(v, u);
        cnt[u] += cnt[v];
    }
    res += min(cnt[u], 2 * k - cnt[u]);
    return res;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < 2 * k; ++i) {
        int u; cin >> u;
        --u;
        cnt[u] = 1;
    }

    for (int i = 0; i + 1 < n; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << dfs(0, 0) << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
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