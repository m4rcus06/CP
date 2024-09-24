#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int inf = 1e9 + 7;
 
void solve() {
    int N; cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        int xx, yy;
        cin >> xx >> yy;

        x[i] = xx - yy;
        y[i] = xx + yy;
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        if (x[i] == x[j]) return y[i] > y[j];
        return x[i] < x[j];
    });

    int ans = N;
    int right_most = -inf;
    for (int i = 0; i < N; ++i) {
        if (y[ord[i]] <= right_most) --ans;
        right_most = max(right_most, y[ord[i]]);
    }

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("mountains.in", "r", stdin);
    freopen ("mountains.out", "w", stdout);
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

