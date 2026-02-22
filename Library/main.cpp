#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector <pair <int, int>> pa;
    for (int i = 0; i < n; ++i) {
        if (pa.empty() || a[i] != pa.back().second) {
            pa.emplace_back(1, a[i]);
        } else {
            pa.back().first++;
        }
    }
    sort(pa.begin(), pa.end());

    lli ans0 = 0, ans1 = 0;
    int t = 1;
    while (!pa.empty()) {
        auto [x, y] = pa.back(); pa.pop_back();
        ans0 += (lli) (y + t) / 2 * x;
        ans1 += (lli) (y + 1 - t) / 2 * x;
        if (y % 2 != 0) t ^= 1;
    }

    cout << ans0 << ' ' << ans1 << '\n';
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

