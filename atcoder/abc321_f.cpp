#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MOD = 998244353;

void solve() {
    int Q, K; cin >> Q >> K;
    vector <int> dp(K + 1, 0);
    dp[0] = 1;

    while (Q--) {
        char t; cin >> t;
        int x; cin >> x;
        if (t == '+') {
            for (int i = K; i >= x; --i) dp[i] = (dp[i] + dp[i - x]) % MOD;
        } else {
            for (int i = x; i <= K; ++i) {
                dp[i] -= dp[i - x];
                if (dp[i] < 0) dp[i] += MOD;
            }
        }

        cout << dp[K] << '\n';
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