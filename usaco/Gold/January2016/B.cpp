#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int INF = int(1e9) + 7;

void solve() {
    int N, M;
    cin >> N >> M;
    int fx, fy, bx, by;
    cin >> fx >> fy >> bx >> by;
    string S, T;
    cin >> S >> T;
 
    vector <vector <int>> curF(N + 1, vector <int> (2, 0));
    curF[0] = {fx, fy};
    for (int i = 0; i < N; ++i) {
        curF[i + 1] = curF[i];
        if (S[i] == 'E') curF[i + 1][0] += 1;
        if (S[i] == 'W') curF[i + 1][0] -= 1;
        if (S[i] == 'N') curF[i + 1][1] += 1;
        if (S[i] == 'S') curF[i + 1][1] -= 1;
    }

    vector <vector <int>> curB(M + 1, vector <int> (2, 0));
    curB[0] = {bx, by};
    for (int i = 0; i < M; ++i) {
        curB[i + 1] = curB[i];
        if (T[i] == 'E') curB[i + 1][0] += 1;
        if (T[i] == 'W') curB[i + 1][0] -= 1;
        if (T[i] == 'N') curB[i + 1][1] += 1;
        if (T[i] == 'S') curB[i + 1][1] -= 1;
    }

    auto dist = [&](int x1, int y1, int x2, int y2) -> int {
        int x = (x2 - x1), y = (y2 - y1);
        return (x * x) + (y * y);
    };

    vector <vector <int>> dp(N + 1, vector <int> (M + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (i < N) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist(curF[i + 1][0], curF[i + 1][1], curB[j][0], curB[j][1]));
            }
            if (j < M) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dist(curF[i][0], curF[i][1], curB[j + 1][0], curB[j + 1][1]));
            }
            if (i < N && j < M) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + dist(curF[i + 1][0], curF[i + 1][1], curB[j + 1][0], curB[j + 1][1]));
            }
        }
    }
    cout << dp[N][M] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
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