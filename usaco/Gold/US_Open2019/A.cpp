#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int inf = (int) 1e9 + 7;
const int MAXN = 401;

int n, k, a[MAXN];
int dp[MAXN][MAXN];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) dp[i][j] = inf;
    }

    for (int i = 0; i <= k; ++i) dp[1][i] = 0;

    int cur_max = a[1], cur_sum = a[1];
    for (int i = 2; i <= n; ++i) {
        cur_max = max(cur_max, a[i]);
        cur_sum += a[i];
        dp[i][0] = i * cur_max - cur_sum;
        for (int j = 1; j <= k; ++j) {
            int mx = 0, sum = 0;
            for (int p = i; p >= 1; --p) {
                mx = max(mx, a[p]);
                sum += a[p];
                dp[i][j] = min(dp[i][j], dp[p - 1][j - 1] + mx * (i - p + 1) - sum);
            }
        }
    }
    cout << dp[n][k] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
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