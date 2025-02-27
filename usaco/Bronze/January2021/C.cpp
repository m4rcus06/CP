#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N; cin >> N;
    vector <int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = 0; i < N; ++i) cin >> B[i];
    sort(B.begin(), B.end());

    vector <int> can_place(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) can_place[i] += (A[i] <= B[j]);
    }

    lli ans = 1;
    for (int i = N - 1; i >= 0; --i) {
        ans *= can_place[i] - (N - 1 - i);
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