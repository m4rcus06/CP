#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int mxN = 2500;

int N;
int t[mxN];
vector <int> g[mxN];

int DFS(int u, int p) {
    int cur_t = t[u];
    for (int v : g[u]) {
        if (v != p) {
            cur_t += (DFS(v, u));
            cur_t %= 12;
        }
    }
    return 12 - cur_t;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i + 1 < N; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int x = DFS(i, i);
        if (12 - x <= 1) ++ans;
    }

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
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

