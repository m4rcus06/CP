#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...)
#endif

void solve() {
    int n;
    lli x, y;
    cin >> n >> x >> y;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    lli sum = accumulate(a.begin(), a.end(), 0LL);
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        lli cur_sum = sum - a[i];

        //cur_sum - a[j] >= x => a[j] <= cur_sum - x;
        int lb = lower_bound(a.begin() + i + 1, a.end(), cur_sum - y) - a.begin();
        int rb = upper_bound(a.begin() + i + 1, a.end(), cur_sum - x) - a.begin();

        ans += max(0, rb - lb);
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