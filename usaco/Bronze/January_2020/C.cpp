#include <bits/stdc++.h>
using namespace std;

int64_t sum (int l, int r) {
    if (l > r) return 0;
    return 1ll * (l + r) * (r - l + 1) / 2;
}
 
void solve() {
    int K, N; cin >> K >> N;

    auto find_max_speed = [&](int limit) {
        int l = 1, r = K;
        while (r - l > 1) {
            int m = (l + r) / 2;

            if (sum(1, m) > K - sum(limit, m - 1)) r = m;
            else l = m;
        }
        return l;
    };

    for (int i = 0; i < N; ++i) {
        int X; cin >> X;

        int ans = K;
        int j = find_max_speed(X);
        int L = sum(1, j);
        int R = K - sum(X, j - 1); 
        if (L <= R) {
            ans = min(ans, j + (R - L + j - 1) / j + max(0, j - X));
        }
        cout << ans << '\n';
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = chrono::high_resolution_clock::now();
#else
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
#endif
 
    int tt = 1;
    while (tt--) {
        solve();
    }
 
#ifdef LOCAL
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
#endif
 
    return 0;
}

