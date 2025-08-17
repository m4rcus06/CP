#include <bits/stdc++.h>
using namespace std;
using lli = long long;

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

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    --k;

    Tvector <int, 2> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    auto BFS = [&](vector <int> &dist, vector <int> src) {
        queue <int> q;
        vector <bool> vis(n);
        for (auto x: src) {
            dist[x] = 0;
            q.push(x);
            vis[x] = true;
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v: g[u]) {
                if (vis[v] == false) {
                    vis[v] = true;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    };

    vector <int> dist1(n), dist2(n);
    vector <int> leaf;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            leaf.push_back(i);
        }
    }

    BFS(dist1, vector <int>{k});
    BFS(dist2, leaf);

    int ans = 0;
    vector <bool> vis(n);
    queue <int> q;

    vis[k] = true;
    q.push(k);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist2[u] <= dist1[u]) {
            ++ans;
            continue;
        }

        for (int v: g[u]) {
            if (vis[v] == false) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
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