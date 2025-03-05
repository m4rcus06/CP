#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MAXN = 10005;

int n, k;
int cows[MAXN];
lli dp[MAXN];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> cows[i];

    for (int i = 1; i <= n; ++i) {
        int cur_max = 0;
        for (int j = 1; j <= k; ++j) {
            if (j > i) break;
            cur_max = max(cur_max, cows[i - j + 1]);
            dp[i] = max(dp[i], dp[i - j] + (lli) cur_max * j);
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
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