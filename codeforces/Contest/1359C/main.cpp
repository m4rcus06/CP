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
    lli h, c, t;
    cin >> h >> c >> t;

    lli l = -1, r = 1e9 + 7;
    while (r - l > 1) {
        lli m = (l + r) / 2;

        if (h * (m + 1) + c * m >= t * (2 * m + 1)) l = m;
        else r = m;
    }

    int ans;
    lli d1 = abs(h * (l + 1) + c * l - t * (2 * l + 1));
    lli d2 = abs(h * (l + 2) + c * (l + 1) - t * (2 * l + 3));

    if (h + c >= 2 * t) ans = 2;
    else if (d1 * (2LL * l + 3) <= d2 * (2LL * l + 1)) ans = 2 * l + 1;
    else ans = 2 * l + 3;

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