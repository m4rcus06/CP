#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...)
#endif

lli sum(lli l, lli r) {
    if (l > r) return 0;
    return (l + r) * (r - l + 1) / 2;
}

void solve() {
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector <int> p(n);
    for (int i = 0; i < n; ++i) {
        p[a[i]] = i;
    }

    int l = n + 1, r = -1;
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        l = min(l, p[i]);
        r = max(r, p[i]);

        int mex = i + 1;
        if (2 * mex < r - l + 1) continue;
        if (mex < n && l <= p[mex] && p[mex] <= r) continue;

        if (mex < n && p[mex] < l) {
            for (int j = l; j > p[mex]; --j) {
                int max_rb = min(n - 1, j + 2 * mex - 1);
                ans += max(0, max_rb - r + 1);
            }
        }
        if (mex < n && p[mex] > r) {
            for (int j = r; j < p[mex]; ++j) {
                int min_lb = max(0, j - 2 * mex + 1);
                ans += max(0, l - min_lb + 1);
            }
        }
    }
    ans += 1;
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