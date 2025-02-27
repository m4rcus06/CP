#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector <int> l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    vector <int> cnt(2 * n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cnt[l[i]] += 1;
        cnt[r[i]] -= 1;
    }

    vector <int> pw2(n + 1, 1);
    for (int i = 1; i <= n; ++i) pw2[i] = pw2[i - 1] * 2 % MOD;

    int ans = 0;
    int closed = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (cnt[i] == 1) {
            ans = ans * 2 % MOD;
            ans = (ans + pw2[closed]) % MOD;
        } else {
            ++closed;
        }
    }

    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
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