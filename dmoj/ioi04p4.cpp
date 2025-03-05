#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MAXN = 605;

int N, W, H;
int dp[MAXN][MAXN];

void solve() {
    cin >> W >> H >> N;
    for (int i = 1; i <= N; ++i) {
        int x, y; cin >> x >> y;
        dp[x][y] = x * y;
    }

    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= H; ++j) {
            for (int k = 1; k <= max(i, j); ++k) {
                if (i >= k) dp[i][j] = max(dp[i][j], dp[i - k][j] + dp[k][j]);
                if (j >= k) dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[i][k]);
            }
        }
    }
    cout << W * H - dp[W][H] << '\n';
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