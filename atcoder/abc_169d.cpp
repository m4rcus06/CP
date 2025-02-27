#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    lli N; cin >> N;
    int ans = 0;
    for (lli i = 2; i * i <= N; ++i) {
        int cnt = 0;
        while (N % i == 0) {
            cnt++;
            N /= i;
        }

        if (cnt > 0) {
            for (lli j = 1; j * (j + 1) / 2 <= cnt; ++j) {
                ans++;
            }
        }
    }
    if (N > 0) ans += 1;

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