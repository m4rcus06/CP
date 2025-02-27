#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int SIZE = 50010 * 5;

void solve() {
    int N; cin >> N;
    vector <vector <int>> A(N, vector <int> (5));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> A[i][j];
        }
        sort (A[i].begin(), A[i].end());
    }

    map <vector <int>, int> Mp;
    vector <vector <int>> cur(N);
    for (int mask = 0; mask < (1 << 5); ++mask) {
        for (int j = 0; j < 5; ++j) {
            if (mask & (1 << j)) {
                for (int i = 0; i < N; ++i) cur[i].emplace_back(A[i][j]);
            }
        }

        for (int i = 0; i < N; ++i) {
            Mp[cur[i]] += 1;
        }

        for (int i = 0; i < N; ++i) cur[i].clear();
    }

    lli ans = 0;
    for (auto it : Mp) {
        int cnt = it.first.size();
        int v = it.second;

        if (cnt & 1) ans -= 1LL * v * (v - 1) / 2;
        else ans += 1LL * v * (v - 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else 
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
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