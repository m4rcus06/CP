#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int mod = 1e9 + 7;

int fac[200005], invfac[200005];

int inv(int x) {
    return (x <= 1 ? x : mod - 1LL * mod / x * inv(mod % x) % mod);
}

int C(int N, int K) {
    if (K > N) return 0;
    return 1LL * fac[N] * invfac[K] % mod * invfac[N - K] % mod;
}

void solve() {
    int N, K; cin >> N >> K;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int ones = 0, zeroes = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) ones++;
        else zeroes++;
    }

    int ans = 0;
    for (int i = (K + 1) / 2; i <= K; ++i) {
        ans = ((lli) ans + (lli) C(ones, i) * C(zeroes, K - i) % mod) % mod;
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    fac[0] = 1;
    for (int i = 1; i <= 200000; ++i) {
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }

    invfac[200000] = inv(fac[200000]);
    for (int i = 199999; i >= 0; --i) {
        invfac[i] = 1LL * invfac[i + 1] * (i + 1) % mod;
    }

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