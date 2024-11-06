#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const lli inf = 1e18 + 7;
 
void solve() {
    int N; cin >> N;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector <lli> P(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        P[i + 1] = P[i] + A[i];
    }

    vector <lli> S(N + 2, 0);
    for (int i = N; i > 0; --i) {
        S[i] = S[i + 1] + A[i - 1];
    }

    lli min_P = 0;
    vector <lli> max_prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        max_prefix[i] = P[i] - min_P;
        min_P = min(min_P, P[i]);
    }

    for (int i = 2; i <= N; ++i) {
        max_prefix[i] = max(max_prefix[i], max_prefix[i - 1]);
    }

    lli min_S = 0;
    vector <lli> max_suffix(N + 1, 0);
    for (int i = N; i >= 1; --i) {
        max_suffix[i] = S[i] - min_S;
        min_S = min(min_S, S[i]);
    }

    for (int i = N - 1; i >= 1; --i) {
        max_suffix[i] = max(max_suffix[i], max_suffix[i + 1]);
    }


    lli ans = -inf;
    lli prv_min = P[1] - max_prefix[1];
    for (int i = 2; i < N; ++i) {
        ans = max(ans, P[i] - prv_min + max_suffix[i + 1]);
        prv_min = min(prv_min, P[i] - max_prefix[i]);
    }

    cout << ans << '\n';
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

