#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N, Q; cin >> N >> Q;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector <int> B;
    for (int i = 1; i < N; ++i) {
        B.push_back(abs(A[i] - A[i - 1]));
    }

    int new_size = N - 1;
    int max_log = 32 - __builtin_clz(new_size);
    vector <vector <int>> S(max_log);
    S[0] = B;
    for (int j = 1; j < max_log; ++j) {
        S[j].resize(new_size - (1 << j) + 1);
        for (int i = 0; i + (1 << j) <= new_size; ++i) {
            S[j][i] = __gcd(S[j - 1][i], S[j - 1][i + (1 << (j - 1))]);
        }
    }

    auto get = [&](int l, int r) {
        int lg = 31 - __builtin_clz(r - l + 1);
        return __gcd(S[lg][l], S[lg][r - (1 << lg) + 1]);
    };

    while (Q--) {
        int l, r; cin >> l >> r;
        --l, --r;

        if (l == r) cout << 0 << ' ';
        else cout << get(l, r - 1) << ' ';
    }
    cout << '\n';
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