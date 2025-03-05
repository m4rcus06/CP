#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MOD = (int) 1e9 + 7;
const int NMAX = 101;
const int HMAX = 1001;

int n, a[NMAX], dp[NMAX][HMAX];

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int calc(int p) {
    for (int i = 0; i <= a[1] - p; ++i) dp[1][i] = 1;
    for (int i = 2; i <= n; ++i) {
        int sum = 0;
        for (int j = a[i] - p; j >= 0; --j) {
            add(sum, dp[i - 1][a[i] - p - j]);
            dp[i][j] = sum;
        }
    }
    return dp[n][0];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int ans = 0;
    if (n % 2 == 0) ans = calc(0);
    else {
        int mn = *min_element(a + 1, a + n + 1);
        for (int i = 0; i <= mn; ++i) {
            memset(dp, 0, sizeof dp);
            int x = calc(i);
            add(ans, x);
        }
    }
    cout << ans << '\n';
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