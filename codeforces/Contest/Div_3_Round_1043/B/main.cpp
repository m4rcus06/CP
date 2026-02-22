#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    lli n;
    cin >> n;

    //n = x * (10^k + 1)
    vector <lli> ans;
    lli pw = 10;
    while (pw <= n) {
        if (n % (pw + 1) == 0) ans.push_back(n / (pw + 1));
        pw *= 10;
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (auto x: ans) cout << x << ' ';
    cout << '\n';
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

