#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int NMAX = 1001;
const lli INF = 1e18 + 7;

int H, G;
pair <int, int> cows[2][NMAX];
lli dp[NMAX][NMAX][2];

int dist(const pair <int, int> &A, const pair <int, int> &B) {
    int x = A.first - B.first;
    int y = A.second - B.second;
    return x * x + y * y;
}

void solve() {
    cin >> H >> G;
    for (int i = 1; i <= H; ++i) cin >> cows[0][i].first >> cows[0][i].second;
    for (int i = 1; i <= G; ++i) cin >> cows[1][i].first >> cows[1][i].second;

    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(lli), INF);
    dp[1][0][0] = 0;
    for (int i = 0; i <= H; ++i) {
        for (int j = 0; j <= G; ++j) {
            if (i > 1) dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + dist(cows[0][i - 1], cows[0][i]));
            if (j > 1) dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dist(cows[1][j - 1], cows[1][j]));
            if (i > 0 && j > 0) {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + dist(cows[1][j], cows[0][i]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dist(cows[0][i], cows[1][j]));
            }
        }
    }
    cout << dp[H][G][0] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
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