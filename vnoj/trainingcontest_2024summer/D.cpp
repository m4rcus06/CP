#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int64_t mod = int64_t(1e18) + 3;
const int64_t INV2 = 500000000000000002;
const int64_t INV6 = 833333333333333336;

int64_t binary_multiply(int64_t a, int64_t b) {
    int64_t res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int64_t N; cin >> N;

    int64_t X = binary_multiply(N, N);
    X = binary_multiply(X, N + 1);
    X = binary_multiply(X, N + 1);
    X = binary_multiply(X, INV2);
    X = binary_multiply(X, INV2);

    int64_t Y = binary_multiply(N, N + 1);
    Y = binary_multiply(Y, 2LL * N + 1);
    Y = binary_multiply(Y, INV6);

    int64_t ans = (X + Y) % mod;
    ans = binary_multiply(ans, INV2);
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

