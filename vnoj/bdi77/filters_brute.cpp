#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int N = (int) 2e5 + 5;

int n, q;
lli a[N], t[N];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> t[i];
    }

    for (int i = 1; i <= q; ++i) {
        lli x; cin >> x;
        for (int j = 1; j <= n; ++j) {
            if (t[j] == 1) x += a[j];
            if (t[j] == 2) x = max(x, a[j]);
            if (t[j] == 3) x = min(x, a[j]);
        }
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    freopen("filters_in", "r", stdin);
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