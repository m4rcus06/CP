#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int SIZE = 26;
const int NMAX = 100001;

int n, m, k;
int dp[NMAX][SIZE], dist[SIZE][SIZE];
char S[NMAX];

int pref[NMAX][SIZE];
int cost(int l, int r, int c) {
    return pref[r][c] - pref[l - 1][c];
}

void init() {
    for (int k = 0; k < m; ++k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int c = 0; c < m; ++c) {
            pref[i][c] = pref[i - 1][c] + dist[S[i] - 'a'][c];
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> S[i];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> dist[i][j];
        }
    }

    init();

    for (int i = 1; i <= min(n, 2 * k - 1); ++i) {
        for (int c = 0; c < m; ++c) {
            dp[i][c] = cost(1, i, c);
        }
    }
    for (int i = 2 * k; i <= n; ++i) {
        for (int c1 = 0; c1 < m; ++c1) {
            dp[i][c1] = dp[i - 1][c1] + cost(i, i, c1);
            for (int c2 = 0; c2 < m; ++c2) {
                dp[i][c1] = min(dp[i][c1], dp[i - k][c2] + cost(i - k + 1, i, c1));
            }
        }
    }

    int ans = *min_element(dp[n], dp[n] + m);
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
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