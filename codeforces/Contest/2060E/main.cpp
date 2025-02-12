#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

struct DisjointSetUnion {
    int n;
    vector <int> p, siz;

    DisjointSetUnion(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        siz.resize(n + 1, 1);
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return (x == p[x] ? x : p[x] = find(p[x]));
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (siz[u] < siz[v]) swap(u, v);
        siz[u] += siz[v];
        p[v] = u;
        return true;
    }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector <pair <int, int>> edge_f(m1);
    for (int i = 0; i < m1; ++i) {
        cin >> edge_f[i].first >> edge_f[i].second;
    }

    int g = n;
    DisjointSetUnion dsu_g(n);
    for (int i = 0; i < m2; ++i) {
        int u, v; cin >> u >> v;
        g -= dsu_g.unite(u, v);
    }

    int f = n;
    int ans = 0;
    DisjointSetUnion dsu_f(n);
    for (int i = 0; i < m1; ++i) {
        int u = dsu_g.find(edge_f[i].first);
        int v = dsu_g.find(edge_f[i].second);
        if (u != v) ans++;
        else f -= dsu_f.unite(edge_f[i].first, edge_f[i].second);
    }

    ans += abs(g - f);
    cout << ans << '\n';
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