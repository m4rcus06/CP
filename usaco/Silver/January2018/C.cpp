#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

const int MAXN = 5000;

int N, Q;
vector <array <int, 2>> g[MAXN];

int DFS(int u, int parent, int at_least, int current_min = -1) {
    int res = (current_min >= at_least);
    for (auto   [v, r]: g[u]) {
        if (v != parent) {
            int next_min = (current_min == -1 ? r : min(current_min, r));
            res += DFS(v, u, at_least, next_min);
        }
    }
    return res;
}
 
void solve() {
    cin >> N >> Q;
    for (int i = 0; i + 1 < N; ++i) {
        int u, v, r;
        cin >> u >> v >> r;
        --u, --v;

        g[u].push_back({v, r});
        g[v].push_back({u, r});
    }

    while (Q--) {
        int k, v;
        cin >> k >> v;
        --v;

        cout << DFS(v, v, k) << '\n';
    }
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
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