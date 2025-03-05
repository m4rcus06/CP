#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int TMAX = 5'000'001;

bool dp[TMAX][2];

void solve() {
    int T, A, B;
    cin >> T >> A >> B;

    dp[0][0] = 1;
    for (int j = 0; j <= T; ++j) {
        if (dp[j][0]) {
            if (j + A <= T) dp[j + A][0] = true;
            if (j + B <= T) dp[j + B][0] = true;
            dp[j / 2][1] = true;
        }
    }
    for (int j = 0; j <= T; ++j) {
        if (dp[j][0]) dp[j][1] = true;
        if (dp[j][1]) {
            if (j + A <= T) dp[j + A][1] = true;
            if (j + B <= T) dp[j + B][1] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i <= T; ++i) {
        if (dp[i][0] || dp[i][1]) ans = i;
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
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