#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

const int N = int(2e6) + 5;
const int mod = int(1e9) + 7;

int inv(int x) {
    return (x <= 1 ? x : mod - (lli) mod / x * inv(mod % x) % mod);
}

int fac[N], invfac[N];
void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = (lli) fac[i - 1] * i % mod;

    invfac[n] = inv(fac[n]);
    for (int i = n - 1; i >= 0; --i) {
        invfac[i] = (lli) invfac[i + 1] * (i + 1) % mod;
    }
}

int nCk(int n, int k) {
    if (k > n || k < 0) return 0;
    return (lli) fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}

void solve() {
    int n, k, p;
    cin >> n >> k >> p;

    if (n < (lli) k * p) {
        cout << 0 << '\n';
        return;
    }
    n -= k * p;

    init(n + k);
    int ans = nCk(n + k - 1, k - 1);
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

