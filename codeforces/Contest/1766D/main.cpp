#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int INF = 1e9 + 7;
const int N_MAX = (int) 1e7 + 5;

int lp[N_MAX];
vector <int> pr;

void solve() {
    int x, y;
    cin >> x >> y;

    if (y - x == 1) {
        cout << -1 << '\n';
        return;
    }

    if (__gcd(x, y) > 1) {
        cout << 0 << '\n';
        return;
    }

    vector <int> prime_factor;
    int d = y - x;
    while (d > 1) {
        int cur = lp[d];
        while (d % cur == 0) d /= cur;
        prime_factor.emplace_back(cur);
    }

    int ans = INF;
    for (int &v: prime_factor) {
        ans = min(ans, v - (x % v));
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    for (int i = 2; i < N_MAX; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.emplace_back(i);
        }
        for (int j = 0; i * pr[j] < N_MAX; j++) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
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