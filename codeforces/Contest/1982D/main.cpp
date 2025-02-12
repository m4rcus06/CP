#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector <vector <int>> height(N, vector <int> (M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> height[i][j];
    }

    lli difference = 0;
    vector <vector <int>> P(N + 1, vector <int> (M + 1));
    for (int i = 0; i < N; ++i) {
        string S; cin >> S;
        for (int j = 0; j < M; ++j) {
            P[i + 1][j + 1] = P[i + 1][j] + P[i][j + 1] - P[i][j] + (S[j] - '0');
            if (S[j] == '0') difference += height[i][j];
            else difference -= height[i][j];
        }
    }

    auto query = [&](int x, int y, int u, int v) -> int {
        return P[u][v] - P[u][y - 1] - P[x - 1][v] + P[x - 1][y - 1];
    };

    int g = 0;
    for (int i = 1; i + K - 1 <= N; ++i) {
        for (int j = 1; j + K - 1 <= M; ++j) {
            g = __gcd(g, abs(K * K - 2 * query(i, j, i + K - 1, j + K - 1)));
        }
    }

    cout << ((difference == 0 || (g != 0 && difference % g == 0)) ? "YES" : "NO") << '\n';
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