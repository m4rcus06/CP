#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int X, N;
    cin >> X >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];
    sort(P.begin(), P.end());

    P.erase(unique(P.begin(), P.end()), P.end());

    vector<int64_t> dp(X + 1, 0);
    dp[0] = 1;
    for (int num: P) {
        for (int i = 0; i <= X; ++i) {
            if (i + num <= X) {
                dp[i + num] += dp[i];
            }
        }
    }

    cout << dp[X] << '\n';
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

