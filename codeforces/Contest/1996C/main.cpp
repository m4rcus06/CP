#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N, Q;
    cin >> N >> Q;
    string A, B;
    cin >> A >> B;

    vector <vector <int>> cnt_A(N + 1, vector <int> (26, 0)), cnt_B(N + 1, vector <int>(26, 0));
    for (int i = 0; i < N; ++i) {
        cnt_A[i + 1] = cnt_A[i];
        cnt_A[i + 1][A[i] - 'a'] += 1;
        cnt_B[i + 1] = cnt_B[i];
        cnt_B[i + 1][B[i] - 'a'] += 1;
    }

    while (Q--) {
        int l, r; cin >> l >> r;

        int ans = 0;
        for (int c = 0; c < 26; ++c) {
            int ca = cnt_A[r][c] - cnt_A[l - 1][c];
            int cb = cnt_B[r][c] - cnt_B[l - 1][c];
            ans += abs(ca - cb);
        }
        ans /= 2;

        cout << ans << '\n';
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