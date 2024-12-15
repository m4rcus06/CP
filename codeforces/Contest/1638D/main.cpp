#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> grid(n, vector <int> (m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector <vector <int>> marked(n, vector <int> (m, 0));
    auto get_color = [&](int i, int j) -> int {
        if (i < 0 || j < 0 || i + 1 >= n || j + 1 >= m) return -1;

        int c = -1;
        for (int u = 0; u < 2; ++u) {
            for (int v = 0; v < 2; ++v) {
                if (c == -1 && !marked[i + u][j + v]) c = grid[i + u][j + v];
                if (!marked[i + u][j + v] && c != grid[i + u][j + v]) return -1;
            }
        }
        return c;
    };

    queue <pair <int, int>> q;
    vector <array <int, 3>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (get_color(i, j) != -1) q.push({i, j});
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (get_color(x, y) != -1) {
            ans.push_back({x + 1, y + 1, get_color(x, y)});
        } else continue;

        marked[x][y] = true;
        if (x + 1 < n) marked[x + 1][y] = true;
        if (y + 1 < n) marked[x][y + 1] = true;
        if (x + 1 < n && y + 1 < n) marked[x + 1][y + 1] = true;

        for (int i = 0; i < 8; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (get_color(u, v) != -1) q.push({u, v});
        }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!marked[i][j]) ok = false;
        }
    }

    if (ok) {
        reverse(ans.begin(), ans.end());
        cout << (int) ans.size() << '\n';
        for (auto [i, j, c]: ans) {
            cout << i << ' ' << j << ' ' << c << '\n';
        }
    } else cout << -1 << '\n';
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