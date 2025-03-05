#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MAXN = (int) 1e5 + 1;
const char gesture[] = {'H', 'P', 'S'};

int n, k;
int dp[MAXN][21][3];

void solve() {
    cin >> n >> k;
    vector <char> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    auto play = [&](char p1, char p2) -> int {
        if (p1 == 'H') return (p2 == 'S');
        else if (p1 == 'S') return (p2 == 'P');
        else return (p2 == 'H');
    };

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int c = 0; c < 3; ++c) {   
                //no changes
                dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][c] + play(gesture[c], a[i]));
                if (j > 0) {
                    for (int p = 0; p < 3; ++p) {
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j - (p != c)][p] + play(gesture[c], a[i]));
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; ++i) ans = max(ans, dp[n][k][i]);
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
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