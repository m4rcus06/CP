#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int mod = 1e9 + 7;

int inv(int x) {
    return (x <= 1 ? x : mod - 1LL * mod / x * inv(mod % x) % mod);
}

void solve() {
    int N, M; cin >> N >> M;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    vector <pair <int, int>> value;
    for (int i = 0; i < N; ++i) {
        if (value.empty() || A[i] != value.back().first) value.emplace_back(A[i], 1);
        else value.back().second += 1;
    }

    int ans = 0, tot = 1;
    for (int l = 0, r = 0; r < (int) value.size(); ++r) {
        tot = 1LL * tot * value[r].second % mod;
        while (r - l + 1 > M) {
            tot = 1LL * tot * inv(value[l].second) % mod;
            l++;
        }
        if (r - l + 1 == M && value[r].first - value[l].first < M) {
            ans = (ans + tot) % mod;
        }
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