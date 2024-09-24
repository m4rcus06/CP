#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int inf = 1e9 + 7;
 
void solve() {
    int N, U, M;
    cin >> N >> U >> M;
    vector<int> w(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i];
    }

    vector<int> a(N + 1), b(N + 1);
    for (int i = 0; i < N; ++i) {
        a[i + 1] = (w[i] + U - 1) / U;
        b[i + 1] = (w[i] + M - 1) / M;
    }

    for (int i = 0; i < N; ++i) {
        a[i + 1] += a[i];
        b[i + 1] += b[i];
    }
    
    auto calc = [&](int x) -> int {
        int res = inf;
        for (int i = 1; i <= N; ++i) {
            int j = (i + x - 2) % N + 1;

            if (j > i) {
                res = min(res, max(a[j] - a[i - 1], b[N] - b[j] + b[i - 1]));
            } else {
                res = min(res, max(a[N] - a[i - 1] + a[j], b[i - 1] - b[j]));
            }
        }
        return res;
    };

    int ans = min(calc(N / 2), calc((N + 1) / 2));
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

