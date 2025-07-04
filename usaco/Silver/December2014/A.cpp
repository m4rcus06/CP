#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/mycp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N, M, P, E, B;
    cin >> B >> E >> P >> N >> M;

    vector g(N, vector <int> ());
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> sources = {0, 1, N - 1};
    vector dist(3, vector <int> (N, -1));
    for (int i = 0; i < 3; ++i) {
        queue <int> q;
        q.push(sources[i]);
        dist[i][sources[i]] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v: g[u]) {
                if (dist[i][v] == -1) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int ans = int(1e9) + 7;
    for (int i = 0; i < N; ++i) {
        ans = min(ans, dist[0][i] * B + dist[1][i] * E + dist[2][i] * P);
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
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