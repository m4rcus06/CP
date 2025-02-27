#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MOD = 1e9 + 7;
const int AMAX = 1e6 + 1;

int fast_pow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = 1LL * res * a % MOD;
        }
        a = 1LL * a * a % MOD;
        n /= 2;
    }
    return res;
}

int fac[AMAX];
void init() {
    fac[0] = 1;
    for (int i = 1; i < AMAX; ++i) fac[i] = 1LL * fac[i - 1] * i % MOD;
}

int choose(int N, int K) {
    if (K > N) return 0;
    return 1LL * fac[N] * fast_pow(1LL * fac[K] * fac[N - K] % MOD, MOD - 2) % MOD;
}

void solve() {
    int N; cin >> N;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    init();

    vector <int> ans(N);
    ans[0] = 1;
    for (int i = 1; i < N; ++i) {
        int x = A[i - 1] / 2;
        int y = A[i] / 2;
        if (x >= y) ans[i] = 1LL * ans[i - 1] * choose(x, y) % MOD;
        else ans[i] = 1LL * ans[i - 1] * choose(y - 1, x - 1) % MOD;
    }
    cout << ans[N - 1] << '\n';
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