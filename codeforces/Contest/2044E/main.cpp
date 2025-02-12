#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

lli exp(lli a, int n) {
    lli res = 1;
    for (; n; a *= a, n /= 2)
        if (n & 1) res = res * a;
    return res; 
}

void solve() {
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    lli ans = 0;
    for (int n = 0; l1 <= r2 / exp(k, n); ++n) {
        lli mul = exp(k, n);
        lli x = max((lli) l2, l1 * mul);
        lli y = (r1 <= r2 / mul ? r1 * mul : r2);

        ans += max((lli) 0, y / mul - (x - 1) / mul); 
    }
    cout << ans << '\n';
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