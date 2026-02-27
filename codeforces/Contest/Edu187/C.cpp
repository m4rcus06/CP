#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    lli s, m;
    cin >> s >> m;

    auto possible = [&](lli k) -> bool {
        lli cur_s = s;
        lli mx = 0;
        for (int i = 63; i >= 0; --i) {
            if ((m >> i) & 1) {
                lli add = min(k, cur_s / (1LL << i));
                mx = max(mx, add);
                cur_s -= (add << i);
            }
        }

        return (cur_s <= 0 && mx <= k);
    };
    
    lli l = 0, r = s + 1;
    while (r - l > 1) {
        lli mid = (l + r) >> 1;

        if (possible(mid))
            r = mid;
        else
            l = mid;
    }

    cout << (r == s + 1 ? -1 : r) << '\n';
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