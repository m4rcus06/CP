#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int INF = 1e9 + 7;

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    vector <lli> c(N);
    for (int i = 0; i < N; ++i) cin >> c[i];
    sort(c.begin(), c.end());

    int delta = __gcd(A, B);
    for (int i = 0; i + 1 < N; ++i) {
        c[i] += ((c[N - 1] - c[i]) / delta) * delta;
    }
    sort(c.begin(), c.end());

    lli ans = c[N - 1] - c[0];
    for (int i = 0; i + 1 < N; ++i) {
        ans = min(ans, c[i] + delta - c[i + 1]);
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