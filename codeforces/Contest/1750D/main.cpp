#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int mod = 998244353;

void solve() {
    int N, M; cin >> N >> M;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    for (int i = 0; i + 1 < N; ++i) {
        if (A[i] % A[i + 1] != 0) {
            cout << 0 << '\n';
            return;
        }
    }

    vector <int> p;
    int v = A[0];
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            p.push_back(i);
            while (v % i == 0) v /= i;
        }
    }
    if (v > 1) p.push_back(v);

    int ans = 1;
    for (int i = 1; i < N; ++i) {
        int x = A[i - 1] / A[i];

        vector <int> prime_factor;
        for (int &v: p) {
            if (x % v == 0) prime_factor.push_back(v);
        }

        int sz = prime_factor.size();
        int ways = 0;
        int bound = M / A[i];
        for (int mask = 0; mask < (1 << sz); ++mask) {
            int mult = 1;
            for (int j = 0; j < sz; ++j) {
                if ((mask >> j) & 1) mult *= prime_factor[i];
            }

            int parity = __builtin_popcount(mask);
            if (parity % 2 == 0) {
                ways = (ways + bound / mult) % mod;
            }
            else {
                ways = (ways - bound / mult);
                if (ways < 0) ways += mod;
            }
        }
        ans = 1LL * ans * ways % mod;
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