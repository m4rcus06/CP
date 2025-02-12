#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

lli derangements(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    return (n - 1) * (derangements(n - 1) + derangements(n - 2));
}

lli cache[1001][5];
lli C(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || n == 0) return 1;
    if(cache[n][k] != -1) return cache[n][k];
    return cache[n][k] = C(n - 1, k) + C(n - 1, k - 1);
}

void solve() {
    int N, K;
    cin >> N >> K;

    memset(cache, -1, sizeof cache);
    lli ans = 0;
    for (int i = 0; i <= K; ++i) {
        ans += derangements(i) * C(N, i);
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