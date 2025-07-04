#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/mycp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N;
    cin >> N;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i]--;
    }

    vector <int> pos(N, N), nxt(N);
    for (int i = N - 1; i >= 0; --i) {
        nxt[i] = pos[A[i]];
        pos[A[i]] = i;
    }

    vector <int> mx(N);
    mx[0] = nxt[0];
    for (int i = 1; i < N; ++i) {
        mx[i] = max(mx[i - 1], nxt[i]);
    }

    vector <int> dp(N + 1);
    for (int i = N - 1; i >= 0; --i) {
        dp[i] = dp[mx[i]] + 1;
    }
    debug(dp);
    cout << *max_element(dp.begin(), dp.end()) << '\n';
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