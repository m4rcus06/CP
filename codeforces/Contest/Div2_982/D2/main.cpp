#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/mycp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MOD = int(1e9) + 7;
const int INF = int(1e9) + 7;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void subtract(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector <int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector <int> B(M);
    for (int i = 0; i < M; ++i) cin >> B[i];

    vector <lli> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix_sum[i + 1] = prefix_sum[i] + A[i];

    vector <vector <int>> dp(M + 1, vector <int> (N + 1, INF));
    vector <vector <int>> ways(M + 1, vector <int> (N + 1));
    //how many ways to achieve dp[i][j]

    dp[0][0] = 0;
    for (int i = 1; i <= M; ++i) {
        map <int, int> cnt;
        dp[i][0] = 0;
        cnt[0] = ways[i][0] = 1;
        int p = 0;

        for (int j = 1; j <= N; ++j) {
            while (prefix_sum[j] - prefix_sum[p] > B[i - 1]) {
                subtract(cnt[dp[i][p]], ways[i][p]);
                p++;
            }

            dp[i][j] = dp[i][p] + M - i;
            if (dp[i][j] == dp[i - 1][j]) {
                add(ways[i][j], ways[i - 1][j]);
                add(ways[i][j], cnt[dp[i][p]]);
            } else if (dp[i][j] > dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
                ways[i][j] = ways[i - 1][j];
            } else {
                add(ways[i][j], cnt[dp[i][p]]);
            }

            add(cnt[dp[i][j]], ways[i][j]);
        }
    }
    
    int ans = dp[M][N];
    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << ' ' << ways[M][N] << '\n';
    }
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