#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector<int> L(N);
    int l = 0;
    for (int r = 0; r < N; ++r) {
        while (A[r] - A[l] > K) l++;
        L[r] = r - l + 1;
    }

    for (int i = 1; i < N; ++i) {
        L[i] = max(L[i], L[i - 1]);
    }

    int ans = 0;
    for (int i = 0, j = 0; i < N; ++i) {
        ans = max(ans, L[i] + 1);
        while (A[i] - A[j] > K) j++;
        if (j > 0) ans = max(ans, i - j + 1 + L[j -1]);
    }

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
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

