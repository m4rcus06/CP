#include <bits/stdc++.h>
#define BIT(x, i) (((x) >> (i)) & 1)
using namespace std;
using lli = long long;

const int N = 18;

int n;
lli ans[1 << N], f[1 << N];

int dp(const vector <int>& g) {
    auto satisfy = [&](int cow, int gift) -> int {
        return BIT(g[cow], gift);
    };

    memset(f, 0, sizeof f);
    f[0] = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int cow = __builtin_popcount(mask);
        for (int i = 0; i < n; ++i) {
            if (BIT(mask, i)) continue;
            if (satisfy(cow, i)) {
                f[mask | (1 << i)] += f[mask];
            }
        }
    }
    return f[(1 << n) - 1];
}

int solve_subset(int mask, const vector <int>& g) {
    if (ans[mask] != -1) return ans[mask];
    vector <int> on_bits;
    for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) on_bits.push_back(i);
    }

    vector <int> new_graph(n);
    for (int i = 0; i < n; ++i) new_graph[i] |= 1 << i;
    for (auto u: on_bits) {
        for (auto v: on_bits) {
            if (BIT(g[u], v)) new_graph[u] |= 1 << v;
        }
    }

    return ans[mask] = dp(new_graph);
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    vector <int> graph(n);
    for (int i = 0; i < n; ++i) {
        vector <int> v;
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            v.push_back(--x);
        }
        for (auto x: v) {
            graph[i] |= 1 << x;
            if (x == i) break;
        }
    }
    
    memset(ans, -1, sizeof ans);
    int Q; cin >> Q;
    int full_mask = (1 << n) - 1;
    while (Q--) {
        string S; cin >> S;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            if (S[i] == 'G') mask |= 1 << i;
        }

        int ans = solve_subset(mask, graph) * solve_subset(full_mask ^ mask, graph);
        cout << ans << '\n';
    }
    return 0;
}