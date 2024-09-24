#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MX = int(4e3) + 5;
const int inf = int(1e9) + 7;
 
int N, Q;
int A[MX];
int64_t F[MX][MX];
void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            F[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; ++i) {
        int mx = -inf;
        int mn = inf;
        for (int j = i + 1; j <= N; ++j) {
            if (j - i > 1) {
                F[i][j] = max(1LL * A[i] * A[j] * mx, 1LL * A[i] * A[j] * mn);
            }
            F[i][j] += F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1];
            mx = max(mx, A[j]);
            mn = min(mn, A[j]);
        }
    }

    auto query = [&] (int x, int y, int u, int v) -> int64_t {
        return (F[u][v] - F[u][y - 1] - F[x - 1][v] + F[x - 1][y - 1]);
    };

    while (Q--) {
        int l, r; cin >> l >> r;
        cout << query(l, l, r, r) << '\n';
    }
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

