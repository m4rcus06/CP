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
int marked[N], cnt[N], dep[N];
vector <vector <int>> g(N);
lli ans = 0;

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}

int find_midpoint(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        if (cnt[v] > k) return find_midpoint(v, u);
    }
    return u;
}

void calculate(int u, int p) {
    if (marked[u]) ans += dep[u];
    for (int v : g[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        calculate(v, u);
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < 2 * k; ++i) {
        int u; cin >> u;
        --u;
        cnt[u] = marked[u] = 1;
    }

    for (int i = 0; i + 1 < n; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);

    int m = find_midpoint(0, 0);
    calculate(m, m);

    cout << ans << '\n';
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