#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const lli INF = (lli) 1e18 + 7;
const int NMAX = 101;

int n, k, r[2 * NMAX];
lli dp[NMAX][8];

int dist(int i, int j) {
    if (i <= j) return j - i;
    return n - (i - j);
}

void reset() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) dp[i][j] = INF;
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
        r[i + n] = r[i];
    }

    lli ans = INF;
    for (int org = 1; org <= n; ++org) {
        reset();
        //now we solve for the range[org, org + n - 1]
        for (int i = org; i <= org + n - 1; ++i) {
            dp[i - org + 1][1] = dp[i - org][1] + r[i] * dist(org, i);
            for (int j = 2; j <= k; ++j) {
                lli cur_dist = 0;
                int sum = 0;
                for (int p = i; p > org; --p) {
                    cur_dist += sum;
                    sum += r[p];
                    dp[i - org + 1][j] = min(dp[i - org + 1][j], dp[p - org][j - 1] + cur_dist);
                }
            }
        }
        ans = min(ans, dp[n][k]);
    }

    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
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