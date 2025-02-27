#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int inf = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s; cin >> s;
    s.push_back('L');

    vector <int> dp(n + 2, -inf);
    dp[0] = k;
    for (int i = 1; i <= n + 1; ++i) {
        if (s[i - 1] == 'C') continue;
        for (int j = 1; j <= m; ++j) {
            if (i - j < 0) break;
            if ((i - j == 0) || (i - j - 1 >= 0 && s[i - j - 1] == 'L')) {
                dp[i] = max(dp[i], dp[i - j]);
            }
        }
        if (i > 1 && s[i - 2] == 'W') dp[i] = max(dp[i], dp[i - 1] - 1);
    }
    cout << (dp[n + 1] >= 0 ? "YES" : "NO") << '\n';
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