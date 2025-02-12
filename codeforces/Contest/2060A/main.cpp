#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    vector <int> a(5);
    cin >> a[0] >> a[1] >> a[3] >> a[4];

    a[2] = a[0] + a[1];
    int ans = 1;
    for (int i = 2, cnt = 0; i <= 4; ++i) {
        if (a[i] == a[i - 1] + a[i - 2]) ++cnt;
        ans = max(ans, cnt);
    }

    a[2] = a[4] - a[3];
    for(int i = 2, cnt = 0; i <= 4; ++i) {
        if (a[i] == a[i - 1] + a[i - 2]) ++cnt;
        ans = max(ans, cnt);
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