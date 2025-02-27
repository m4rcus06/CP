#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MOD = 1e9 + 7;
const int NMAX = (int) 2e6 + 1;

int fast_pow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return res;
}

int fac[NMAX], invfac[NMAX];
void init(int N) {
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = 1LL * fac[i - 1] * i % MOD;

    invfac[N] = fast_pow(fac[N], MOD - 2);
    for (int i = N - 1; i >= 0; --i) invfac[i] = 1LL * invfac[i + 1] * (i + 1) % MOD;
}

int choose(int N, int K) {
    if (K > N) return 0;
    return 1LL * fac[N] * invfac[K] % MOD * invfac[N - K] % MOD;
}

void solve() {
    int K; cin >> K;
    string S; cin >> S;

    int sz = S.size();
    init(K + sz);

    lli ans = 0;
    for (int i = 0; i <= K; ++i) {
        //fix S_n and then calculate sjdlasjdldlasdasd
        lli place_S = choose(sz - 1 + i, sz - 1);
        lli place_front = fast_pow(25, i);
        lli place_back = fast_pow(26, K - i);
        ans = (ans + place_S * place_front % MOD * place_back % MOD) % MOD;
    }
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