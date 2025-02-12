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
    string S; cin >> S;
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            int d1 = 0, d2 = 0;
            for (int j = 0; j < i; ++j) {
                for (int k = j; k < N; k += i) {
                    if (S[k] != S[j]) d1++;
                }
                for (int k = N - j - 1; k >= 0; k -= i) {
                    if (S[k] != S[N - j - 1]) d2++;
                }
            }
            if (min(d1, d2) <= 1) {
                cout << i << '\n';
                return;
            }
        }
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