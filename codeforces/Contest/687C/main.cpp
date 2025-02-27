#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int n, k; cin >> n >> k;
    vector <vector <int>> dp(k + 1, vector <int> (k + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        for (int j = k; j >= 0; --j) {
            for (int l = k; l >= 0; --l) {
                if (j + x <= k) dp[j + x][l] |= dp[j][l];
                if (l + x <= k) dp[j][l + x] |= dp[j][l];
            }
        }
    }

    vector <int> ans;
    for (int i = 0; i <= k; ++i) {
        if (dp[i][k - i]) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int &v: ans) cout << v << ' ';
    cout << '\n';
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