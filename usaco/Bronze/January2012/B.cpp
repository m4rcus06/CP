#include <bits/stdc++.h>

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    using namespace std;

    int N, K; cin >> N >> K;
    vector<int> H(N + 1, 0);
    for (int i = 0; i < K; ++i) {
        int A, B; cin >> A >> B;

        H[A]++;
        if (B < N) H[B + 1]--;
    }

    for (int i = 1; i <= N; ++i) {
        H[i] += H[i - 1];
    }
    sort (1 + H.begin(), H.end());

    cout << H[(N + 1) / 2] << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("stacking.in", "r", stdin);
    freopen ("stacking.out", "w", stdout);
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

