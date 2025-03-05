#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MAXDAY = 1000;
const int NMAX = 1001;

int n, m, c;
int a[NMAX], dp[NMAX][NMAX];
vector <int> g[NMAX];

void solve() {
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);  
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int t = 0; t < MAXDAY; ++t) {
        for (int u = 0; u < n; ++u) {
            if (dp[u][t] == -1) continue;
            for (int v: g[u]) dp[v][t + 1] = max(dp[v][t + 1], dp[u][t] + a[v]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= MAXDAY; ++i) ans = max(ans, dp[0][i] - c * i * i);
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
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