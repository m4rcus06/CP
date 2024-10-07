#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N, K;
    cin >> N >> K;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = 0;
    for (int x = 1; x <= 1000; ++x) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt += A[i] / x;
        }

        if (cnt < K / 2) break;

        if (cnt >= K) {
            ans = max(ans, x * (K / 2));
            continue;
        }

        if (cnt >= K / 2) {
            int cur = x * (cnt - K / 2);
            int need = K - cnt;

            sort (A.begin(), A.end(), [&](int i, int j) {return (i % x) > (j % x);});

            for (int i = 0; i < need; ++i) cur += (A[i] % x);
            ans = max(ans, cur);
        }
    }

    cout << ans << '\n';
} 
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("berries.in", "r", stdin);
    freopen ("berries.out", "w", stdout);
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

