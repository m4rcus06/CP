#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }

    vector <int> candidate, d(n, -1);
    queue <int> q;
    d[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            } else {
                candidate.push_back(u);
            }
        }
    }
    sort(candidate.begin(), candidate.end());
    candidate.resize(unique(candidate.begin(), candidate.end()) - candidate.begin());

    vector <int> dp(n);
    for (int i = 0; i < n; ++i) dp[i] = d[i];
    for (int u: candidate) {
        for (int v: g[u]) {
            if (d[u] >= d[v]) dp[u] = min(dp[u], d[v]);
        }
    }

    vector <int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return d[i] > d[j];
    });

    for (int i = 0; i < n; ++i) {
        int u = ord[i];
        for (int v: g[u]) {
            if (d[u] < d[v]) dp[u] = min(dp[u], dp[v]);
        }
    }

    for (int i = 0; i < n; ++i) cout << dp[i] << ' ';
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