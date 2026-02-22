#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

/*How to use:
  Tvector <int, 2> g(n); //graph
  Tvector <int, 3> f(n, k, 2) = f[n][k][2]
*/
template <class Tp, int D = 1>
struct Tvector : public vector<Tvector<Tp, D - 1>> {
  template <class... Args>
  Tvector(int n = 0, Args... args) : vector<Tvector<Tp, D - 1>>(n, Tvector<Tp, D - 1>(args...)) {}
};
 
template <class Tp>
struct Tvector<Tp, 1> : public vector<Tp> {
  Tvector(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {}
};

struct UnionFind {
    int n;
    vector <int> f, siz;
    vector <bool> hasCyc;

    UnionFind(int _n): n(_n) {
        f.resize(n);
        hasCyc.resize(n);
        siz.resize(n, 1);
        iota(f.begin(), f.end(), 0);
    }

    int find(int u) {
        return (u == f[u] ? u : f[u] = find(f[u]));
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) {
            if (hasCyc[u]) return false;
            hasCyc[u] = true;
            return true;
        }
        if (hasCyc[u] && hasCyc[v]) return false;
        if (siz[u] < siz[v]) swap(u, v);

        f[v] = u;
        siz[u] += siz[v];
        hasCyc[u] = hasCyc[u] || hasCyc[v];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> m >> n;
    vector <array <int, 3>> edges;
    for (int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    vector <array <int, 3>> not_used;
    UnionFind dsu(m);
    lli ans = 0;
    for (auto [w, u, v]: edges) {
        if (dsu.unite(u, v)) {
            ans += w;
        }
    }

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

