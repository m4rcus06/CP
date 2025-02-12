#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N, K; cin >> N >> K;
    vector <int> cnt(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for (int i = 1; i <= K / 2; ++i){
        if (K - i <= N) ans += min(cnt[i], cnt[K - i]);
    }
    if (K % 2 == 0) ans -= (cnt[K / 2] + 1) / 2;
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