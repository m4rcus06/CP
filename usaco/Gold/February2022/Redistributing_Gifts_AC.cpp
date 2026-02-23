#include <bits/stdc++.h>
#define MASK(x) (1LL << (x))
#define BIT(x, i) (((x) >> (i)) & 1)
using namespace std;
using lli = long long;

const int N = 18;

lli ans[1 << N], dp[1 << N][N];

void solve() {
    int n; cin >> n;
    vector <int> adj(n);
    for (int i = 0; i < n; ++i) {
        vector <int> values;
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            values.push_back(--x);
        }
        for (auto x: values) {
            adj[i] |= 1 << x;
            if (x == i) break;
        }
    }

    ans[0] = 1;
    for (int i = 0; i < n; ++i) dp[MASK(i)][i] = 1;
    for (int mask = 1; mask < MASK(n); ++mask) {
        int msb = 31 - __builtin_clz(mask);
        for (int lst = 0; lst <= msb; ++lst) {
            if (BIT(mask, lst)) { //current vertex
                for (int k = 0; k < msb; ++k) {
                    if (!BIT(mask, k) && BIT(adj[lst], k)) { //jump to next vertex, meaning we didn't close this cycle
                        dp[mask | MASK(k)][k] += dp[mask][lst];
                    }
                }
                if (BIT(adj[lst], msb)) { //close this cycle, this mask is done
                    ans[mask] += dp[mask][lst];
                }
            }
        }
        //start new cycle
        for (int k = msb + 1; k < n; ++k) dp[mask | MASK(k)][k] += ans[mask];
    }

    int Q; cin >> Q;
    while (Q--) {
        string s; cin >> s;
        int g = 0, h = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'G') {
                g |= MASK(i);
            } else {
                h |= MASK(i);
            }
        }

        cout << ans[g] * ans[h] << '\n';
    }
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