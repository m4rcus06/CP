#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N, Q; cin >> N >> Q;
    vector <int> h(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    vector <int> L(N), R(N);
    for (int i = 0; i < N; ++i) {
        L[i] = i;
        if (i > 0) --L[i];
    }

    for (int i = N - 1; i >= 0; --i) {
        R[i] = i;
        if (i + 1 < N) ++R[i];
    }

    for (int i = 0; i < N; ++i) {
        while (L[i] > 0 && h[i] <= h[L[i]]) {
            L[i] = L[L[i]];
        }
    }

    for (int i = N - 1; i >= 0; --i) {
        while (R[i] + 1 < N && h[i] <= h[R[i]]) {
            R[i] = R[R[i]];
        }
    }

    vector <int> max_depth(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int len = R[i] - L[i] - 1;
        max_depth[len] = max(max_depth[len], h[i]);
    }

    for (int i = N - 1; i > 0; --i) {
        max_depth[i] = max(max_depth[i], max_depth[i + 1]);
    }

    while (Q--) {
        int s, d; cin >> s >> d;

        cout << (s >= max_depth[d] ? 1 : 0) << '\n';
    }
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else 
    freopen ("snowboots.in", "r", stdin);
    freopen ("snowboots.out", "w", stdout);
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

