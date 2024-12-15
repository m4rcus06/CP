#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...)
#endif

const int N = (int) 1e5 + 5;

vector <vector <int>> g(N);
bool on_stack[N], vis[N];
bool dfs(int u) {
    vis[u] = true;
    on_stack[u] = true;
    for (int v : g[u]) {
        if (on_stack[v]) return false;
        if (!vis[v]) {
            if (!dfs(v)) return false;
        }
    }
    on_stack[u] = false;
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    if (count(d.begin(), d.end(), 0) != 1) {
        cout << -1 << '\n';
        return;
    }

    vector <int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return d[i] < d[j];
    });

    int root = ord[0];
    vector <pair <int, int>> edges;
    vector <vector <int>> avail(n);
    avail[0].push_back(root);
    vector <int> deg(n, 0);
    for (int x = 1; x < n; ++x) {
        int i = ord[x];
        auto &vec = avail[d[i] - 1];

        while (!vec.empty() && deg[vec.back()] == k) vec.pop_back();
        if (vec.empty()) {
            cout << -1 << '\n';
            return;
        }

        edges.emplace_back(vec.back(), i);
        g[vec.back()].push_back(i);
        deg[vec.back()] += 1;
        deg[i] += 1;
        avail[d[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        if (!dfs(i)) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << edges.size() << '\n';
    for (auto e : edges) {
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
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