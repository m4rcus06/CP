#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N, M, R; cin >> N >> M >> R;
    vector<int> c(N);
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
    }
    sort(c.begin(), c.end(), greater<int>());

    vector<int> q(M), p(M);
    for (int i = 0; i < M; ++i) {
        cin >> q[i] >> p[i]; 
    }

    vector<int> ord(M);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return p[i] > p[j];
    });

    vector<int> r(R);
    for (int i = 0; i < R; ++i) {
        cin >> r[i];
    }
    sort(r.begin(), r.end(), greater<int>());

    vector<int64_t> pre_prod(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        pre_prod[i + 1] = pre_prod[i] + q[ord[i]];
    }

    vector<int64_t> pre_cost(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        pre_cost[i + 1] = pre_cost[i] + 1LL * p[ord[i]] * q[ord[i]];
    }

    vector<int64_t> pre_rent(R + 1, 0);
    for (int i = 0; i < R; ++i) {
        pre_rent[i + 1] = pre_rent[i] + r[i];
    }

    int64_t total_prod = 0;
    int64_t ans = 0;
    for (int i = 0, j = 0; i < N; ++i) {
        total_prod += c[i];
        while (j + 1 <= M && total_prod >= pre_prod[j + 1]) {
            j++;
        }

        int addition = (j + 1 < M ? p[ord[j]] * min(total_prod - pre_prod[j], int64_t(q[ord[j]])) : 0);
        ans = max(ans, pre_cost[j] + addition + pre_rent[min(R, N - i - 1)]);
    }

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("rental.in", "r", stdin);
    freopen ("rental.out", "w", stdout);
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

