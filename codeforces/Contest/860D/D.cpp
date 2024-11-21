#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

const int N = (int) 2e5;

int n, m;
vector <int> graph[N];
vector <array <int, 3>> ans;

int timer = 0, in[N];
bool DFS(int u, int parent) {
    in[u] = ++timer;

    vector <int> vertex;
    for (int v: graph[u]) {
        if (v != parent) {
            if (in[v] != 0) {
                if (in[u] < in[v]) vertex.push_back(v); 
            }
            else {
                if (DFS(v, u)) vertex.push_back(v);
            }
        } 
    }

    for (int i = 0; i + 1 < (int) vertex.size(); i += 2) {
        ans.push_back({vertex[i], u, vertex[i + 1]});
    }

    if ((int) vertex.size() % 2 == 0) return true;
    if (parent != u) ans.push_back({parent, u, vertex.back()});

    return false;
}
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) DFS(i, i);
    }

    cout << (int) ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << ans[i][j] + 1 << ' ';
        }
        cout << '\n';
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