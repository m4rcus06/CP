#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> pre(N);
    pre[0] = A[0];
    for (int i = 1; i < N; ++i) {
        pre[i] = __gcd(pre[i - 1], A[i]);
    }

    vector<int> suf(N);
    suf[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        suf[i] = __gcd(suf[i + 1], A[i]);
    }

    int ans = suf[0];
    ans = max(ans, pre[N - 2]);
    ans = max(ans, suf[1]);
    for (int i = 1; i + 1 < N; ++i) {
        ans = max(ans, __gcd(pre[i - 1], suf[i + 1]));
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

