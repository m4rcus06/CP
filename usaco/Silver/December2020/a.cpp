#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MAXN = 100000;
int N;
vector <int> g[MAXN];

int DFS(int u, int parent) {
    int cows = (int) g[u].size();
    if (u == parent) ++cows;

    int res = 0, cur = 1;
    while (cur < cows) {
        res += 1;
        cur *= 2;
    }

    for (int v: g[u]) {
        if (v != parent) {
            res += DFS(v, u) + 1;
        }
    }

    return res;
}

void solve() {
    cin >> N;
    for (int i = 0; i + 1 < N; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << DFS(0, 0) << '\n';
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

