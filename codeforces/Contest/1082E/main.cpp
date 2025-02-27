#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N, C; cin >> N >> C;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int totalC = count(A.begin(), A.end(), C);

    int mx = *max_element(A.begin(), A.end());
    vector <int> dp(mx + 1, 0);
    int ans = totalC;
    int curC = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == C) curC++;
        else {
            dp[A[i]] = max(dp[A[i]] + 1, curC + 1);

            int remainC = totalC - curC;
            ans = max(ans, dp[A[i]] + remainC);
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