#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int mxN = int(1e5) + 5;

int n, m;
vector <pair <int, int>> g[mxN], new_g[mxN];

int in[mxN], low[mxN], root[mxN];
bool isDeleted[mxN];
int timer = 0;
stack <int> stk;

lli cost_at[mxN];
void tarjan(int u, int par_cost) {
    stk.push(u);
    in[u] = low[u] = ++timer;
    for (auto e: g[u]) {
        int v = e.first, w = e.second;
        if (isDeleted[v]) continue;
        if (in[v] == 0) {
            tarjan(v, w);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], in[v]);
        }
    }
    if (in[u] == low[u]) {
        int v;
        do {
            v = stk.top();
            stk.pop();
            root[v] = u;
            isDeleted[v] = true;
        } while (v != u);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) tarjan(i, 0);
    }

    vector <int> inDeg(n + 1);
    map <pair <int, int>, int> edges;
    for (int i = 1; i <= n; ++i) {
        for (auto e: g[i]) {
            int j = e.first, w = e.second;
            int u = root[i], v = root[j];
            if (u == v) cost_at[u] += w;
            else edges[{u, v}] = max(edges[{u, v}], w);
        }
    }

    for (auto t: edges) {
        int u = t.first.first, v = t.first.second;
        int w = t.second;
        new_g[u].emplace_back(v, w);
        inDeg[v]++;
    }


    queue <int> q;
    vector <int> topo;
    vector <bool> seen(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (seen[root[i]]) continue;
        seen[root[i]] = true;
        if (inDeg[root[i]] == 0) q.push(root[i]);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto e: new_g[u]) {
            if (--inDeg[e.first] == 0) q.push(e.first);
        }
    }

    vector <lli> f(n + 1);
    seen.assign(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (seen[root[i]]) continue;
        seen[root[i]] = true;
        f[root[i]] += cost_at[root[i]];
    }

    while (!topo.empty()) {
        int u = topo.back();
        topo.pop_back();
        lli mx = 0;
        for (auto e: new_g[u]) {
            int v = e.first, w = e.second;
            mx = max(mx, f[v] + w);
        }
        f[u] += mx;
    }

    for (int i = 1; i <= n; ++i) {
        cout << f[root[i]] << '\n';
    }
    return 0;
}
