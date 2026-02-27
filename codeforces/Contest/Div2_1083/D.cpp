#include <bits/stdc++.h>
#define MASK(i) (1LL << (i))
using namespace std;
using lli = long long;

void solve() {
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    const int LG = 31 - __builtin_clz(n);
    vector <vector <int>> spt(LG + 1);
    spt[0].resize(n);
    for (int i = 0; i < n; ++i) spt[0][i] = i;
    for (int j = 1; j <= LG; ++j) {
        spt[j].resize(n - (1 << j) + 1);
        for (int i = 0; i <= n - (1 << j); ++i) {
            int x = spt[j - 1][i], y = spt[j - 1][i + MASK(j - 1)];
            spt[j][i] = (a[x] > a[y] ? x : y);
        }
    }

    auto get = [&](int l, int r) {
        assert(0 <= l && l <= r && r < n);
        int lg = 31 - __builtin_clz(r - l + 1);
        int x = spt[lg][l], y = spt[lg][r - (1 << lg) + 1];
        return (a[x] > a[y] ? x : y);
    };

    function <int(int, int)> f = [&](int l, int r) -> int {
        if (r - l <= 1) return 0;
        int p = get(l, r);
        int ans_l = f(l, p - 1) + r - p;
        int ans_r = f(p + 1, r) + p - l;
        return min(ans_l, ans_r);
    };


    cout << f(0, n - 1) << '\n';
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