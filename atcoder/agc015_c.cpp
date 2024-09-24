#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> g(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char c; cin >> c;
            g[i][j] = (c - '0');
        }
    }
    
    //change in connected components
    vector<vector<int>> change(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            change[i][j] = change[i - 1][j] + change[i][j - 1] - change[i - 1][j - 1];
            if (g[i][j] == 1) {
                if (g[i - 1][j] == 0 && g[i][j - 1] == 0) ++change[i][j];
                if (g[i - 1][j] == 1 && g[i][j - 1] == 1) --change[i][j];
            }
        }
    }

    vector<vector<int>> cols(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> rows(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cols[i][j] = cols[i - 1][j] + (g[i][j] == 1 && g[i - 1][j] == 0);
            rows[i][j] = rows[i][j - 1] + (g[i][j] == 1 && g[i][j - 1] == 0);
        }
    }

    while (Q--) {
        int x, y, u, v; cin >> x >> y >> u >> v;

        int ans = g[x][y];
        ans += cols[u][y] - cols[x][y];
        ans += rows[x][v] - rows[x][y];
        ans += change[u][v] - change[x][v] - change[u][y] + change[x][y];

        cout << ans << '\n';
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

