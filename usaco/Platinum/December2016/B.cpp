#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int NMAX = 1001;
const int MOD = 1'000'000'009;

int n, m, k, a[NMAX], b[NMAX];
int dp[NMAX][NMAX][11];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void subtract(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(b, b + m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int c = 1; c <= k; ++c) {
                add(dp[i][j][c], dp[i - 1][j][c]);
                add(dp[i][j][c], dp[i][j - 1][c]);
                subtract(dp[i][j][c], dp[i - 1][j - 1][c]);
                if (a[i] > b[j]) add(dp[i][j][c], dp[i - 1][j - 1][c - 1] + (c == 1));
            }
        }
    }
    cout << dp[n][m][k] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
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