#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int NMAX = 251;
const lli INF = 1e18 + 7;

void solve() {
    int N, W; cin >> N >> W;
    vector <int> w(N), t(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> t[i];
    }

    auto good = [&](int x) -> bool {
        vector <lli> v(N);
        for (int i = 0; i < N; ++i) {
            v[i] = 1000 * t[i] - 1LL * x * w[i];
        }

        vector <vector <lli>> dp(N + 1, vector <lli> (W + 1, -INF));
        dp[0][0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= W; ++j) {
                int next_w = min(W, j + w[i]);
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][next_w] = max(dp[i + 1][next_w], dp[i][j] + v[i]);
            }
        }

        return dp[N][W] >= 0;
    };

    int l = 0, r = (int) 1e6 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (good(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
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