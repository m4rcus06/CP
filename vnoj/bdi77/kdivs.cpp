#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    lli N, K;
    cin >> N >> K;

    lli ans = 0, i = 1;
    while (i <= K) {
        lli nxt = N / (N / i);
        lli L = i, R = min(K, nxt) + 1;
        while (R - L > 1) {
            lli M = (L + R) / 2;
            if ((N + M - 1) / M == (N + i - 1) / i) L = M;
            else R = M;
        }

        ans += (L - i + 1) * ((N + i - 1) / i);
        i = R;
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("KDIVS.INP", "r", stdin);
    freopen("KDIVS.OUT", "w", stdout);
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
