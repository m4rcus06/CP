#include <bits/stdc++.h>

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    using namespace std;

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> P(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        P[i] = (P[i - 1] + A[i - 1]) % 7;
    }

    vector<int> lst(8, -1);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (lst[P[i]] == -1) {
            lst[P[i]] = i;
        } else {
            ans = max(ans, i - lst[P[i]]);
        }
    }
    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
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

