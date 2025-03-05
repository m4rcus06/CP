#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int NMAX = 101;
const int INF = (int) 1e9 + 7;

int n;
int a[NMAX], cnt[NMAX][NMAX];
int dp[NMAX][NMAX];
void preprocess() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            cnt[i][j] = cnt[i][j - 1] + (a[j] != (j - i));
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1] + (a[i] != (i - 1));
        for (int j = 2; j <= n; ++j) dp[i][j] = i;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    preprocess();

    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            for (int p = i; p >= j; --p) {
                dp[i][j] = min(dp[i][j], dp[p - 1][j - 1] + cnt[p][i]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) cout << dp[n][i] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
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