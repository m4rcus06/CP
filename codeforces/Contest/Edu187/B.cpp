#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    string x; cin >> x;
    int n = x.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += x[i] - '0';

    int ans = 0;
    while (sum >= 10) {
        int cur = x[0] - '1';
        int pos = 1;
        for (int i = 1; i < n; ++i) {
            if (x[i] > x[pos]) pos = i;
        }

        if ((x[pos] - '0') < cur) {
            sum -= cur;
            x[0] = '1';
        } else {
            sum -= x[pos] - '0';
            x[pos] = '0';
        }
        ++ans;
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