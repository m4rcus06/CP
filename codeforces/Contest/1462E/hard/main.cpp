#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int NMAX = 2e5 + 5;
const int mod = 1e9 + 7;

int fac[NMAX];

int inv(int x) {
    return x <= 1 ? x : mod - 1LL * mod / x * inv(mod % x) % mod;
}

int choose(int N, int K) {
    if (K > N) return 0;
    return 1LL * fac[N] * inv(fac[K]) % mod * inv(fac[N - K]) % mod;
}

void solve() {
    int N, K, M;
    cin >> N >> M >> K;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    int ans = 0;
    for (int L = 0, R = 0; R < N; ++R) {
        while (A[R] - A[L] > K) L++;
        //must include A[R]
        ans = ((lli) ans + choose(R - L, M - 1)) % mod;
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    fac[0] = 1;
    for (int i = 1; i < NMAX; ++i) {
        fac[i] = 1LL * fac[i - 1] * i % mod;
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