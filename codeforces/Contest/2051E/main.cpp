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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector <int> prices;
    prices.insert(prices.end(), a.begin(), a.end());
    prices.insert(prices.end(), b.begin(), b.end());

    //a[i] <= price
    lli ans = 0;
    for (int i = 0; i < (int) prices.size(); ++i) {
        int bought = b.end() - (lower_bound(b.begin(), b.end(), prices[i]));
        int neg = bought - (a.end() - lower_bound(a.begin(), a.end(), prices[i]));

        if (neg <= k) {
            ans = max(ans, (lli) prices[i] * bought);
        }
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