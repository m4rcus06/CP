#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/mycp/Library/debug.h>
#else
#define debug(...) 
#endif

const int INF = int(1e9) + 7;

void solve() {
    int N, M;
    cin >> N >> M;

    vector <int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector <int> B(M);
    for (int i = 0; i < M; ++i) cin >> B[i];

    vector <lli> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix_sum[i + 1] = prefix_sum[i] + A[i];

    vector <vector <int>> dp(M + 1, vector <int> (N + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= M; ++i) {
        dp[i][0] = 0;
        int p = 0;

        for (int j = 1; j <= N; ++j) {
            while (prefix_sum[j] - prefix_sum[p] > B[i - 1])
                p += 1;
            dp[i][j] = min(dp[i - 1][j], dp[i][p] + M - i);
        }
    }

    int ans = dp[M][N];
    if (ans == INF) ans = -1;
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