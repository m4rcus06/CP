#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int mod = 998244353;

int inv(int x) {
    if (x <= 1) return x;
    return mod - 1LL * mod / x * inv(mod % x) % mod;
}

void solve() {
    int n; cin >> n;
    vector <vector <int>> want(n);
    int max_v = 0;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        want[i].resize(k);
        for (int &v: want[i]) {
            cin >> v;
            max_v = max(max_v, v);
        }
    }

    vector <int> cnt(max_v + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int &v: want[i]) cnt[v]++;
    }

    int inv_n = inv(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;

        int k = (int) want[i].size();
        for (int &v: want[i]) sum = (sum + 1LL * cnt[v] * inv_n % mod) % mod;
        sum = 1LL * sum * inv(k) % mod;

        ans = (ans + sum) % mod;
    }
    ans = 1LL * ans * inv_n % mod;
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    int tt = 1;
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